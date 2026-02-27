#include <llvm-c/Core.h>
#include <llvm-c/TargetMachine.h>
#include <unordered_map>
#include <unordered_set>
#include <string>

void algorithm(astNode* prog_node);
LLVMBasicBlockRef genIRStmt(astNode* statement_node, LLVMBuilderRef builder, LLVMBasicBlockRef startBB);
LLVMValueRef genIRExpr(astNode* expression, LLVMBuilderRef builder);
void set_insert_local_vars(std::unordered_set<std::string>* set_to_modify, vector<astNode*> * stmt_list);

// relevant objects that are meant to be accessible for functions they get initialized in algorithm
LLVMTypeRef int_data_type;
LLVMTypeRef void_data_type;
std::unordered_map <std::string, LLVMValueRef> var_map;
LLVMTypeRef read_type;
LLVMValueRef readFunc;

// main algorithm
void algorithm(astNode* prog_node) {
    // creating context to store all LLVM IR objects
    LLVMContextRef context = LLVMContextCreate();

    // getting the architecture from the machine
    char* triple = LLVMGetDefaultTargetTriple();
    
    // generating module and setting target architecture
    LLVMModuleRef module = LLVMModuleCreateWithNameInContext("module",
                                                context);

    LLVMSetTarget(module, triple);

    LLVMDisposeMessage(triple);
    
    // generating LLVMFunctions without bodies for print and read
    // creating data types definitions
    int_data_type = LLVMInt32TypeInContext(context);
    void_data_type = LLVMVoidTypeInContext(context);

    // int read 
    read_type = LLVMFunctionType(int_data_type, NULL, 0, 0);
    readFunc = LLVMAddFunction(module, "read", read_type);
    
    // void print(int)
    LLVMTypeRef params_for_print[] = {int_data_type};
    LLVMTypeRef print_type = LLVMFunctionType(void_data_type, params_for_print, 1, 0);
    LLVMValueRef print_func = LLVMAddFunction(module, "print", print_type);

    // visiting the function node of the astProg node
    astNode* function_node = prog_node -> prog.func;
    
    // creating LLVM builder
    LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);

    // reconstructing the function for LLVM IR

    // extracting type of params and count (if at least one then it is int otherwise it is void)

    LLVMTypeRef* param_types;
    unsigned param_count;
    astNode* pointer_to_param = function_node -> func.param;

    if (pointer_to_param == NULL) {
        param_types = NULL;
        param_count = 0; // since the pointer is NULL then it doesn't take any params
    } else {
        param_types = &int_data_type;
        param_count = 1;
    }

    LLVMTypeRef function_type = LLVMFunctionType(int_data_type,
                             param_types, param_count,
                             0);
    
    LLVMValueRef main_function = LLVMAddFunction(module, "main_function", functionType);

    // generating the entry basic block
    LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context,
                                                main_function,
                                                "main_function_body");
    // creating set with names of all parameters and local variables
    std::unordered_set <std::string> names_of_params_and_local_vars;
    
    // adding parameter if applicable
    if (param_count != 0) {
        char* name_of_param = pointer_to_param -> var.name;
        names_of_params_and_local_vars.insert(name_of_param);
    }
    // adding local variables if applicable
    astNode* body = function_node -> func.body;
    if (body->type == ast_stmt && body->stmt.type == ast_block) {
        vector<astNode*> * stmt_list = body -> stmt.block.stmt_list;
        // call to helper method to continue filling the set
        set_insert_local_vars(&names_of_params_and_local_vars, stmt_list);
    }

    // setting the position of the builder at the end of entryBB
    LLVMPositionBuilderAtEnd(builder, entryBB);

    // initializing var_map to an empty map
    var_map = {};
    for (std::string name_of_var : names_of_params_and_local_vars){
        LLVMValueRef alloca_object = LLVMBuildAlloca(builder, int_data_type, name_of_var.c_str());
        var_map[name_of_var] = alloca_object;
    }
    // generating the alloc instruction for the return value
    LLVMValueRef ret_ref = LLVMBuildAlloca(builder, int_data_type, "ret_ref");
    // generating the store instruction to store function parameter into respective alloca ptr
    if (param_count != 0) {
        // we get the param in LLVMValueRef type to feed as input to LLVMBuildStore
        LLVMValueRef main_function_llvm_param = LLVMGetParam(main_function, 0);
        
        // getting the relevant_alloca LLVMValueRef object that corresponds to the parameter
        char* name_of_param_for_lookup = pointer_to_param -> var.name;
        LLVMValueRef relevant_alloca = var_map[name_of_param_for_lookup];

        LLVMValueRef store_instruction_for_param = LLVMBuildStore(builder, main_function_llvm_param, relevant_alloca);
    }
    
    // generating retBB as the return basic block
    LLVMBasicBlockRef retBB = LLVMAppendBasicBlockInContext(context, main_function, "return");

    // setting the position of builder at the end of retBB
    LLVMPositionBuilderAtEnd(builder, retBB);

    // adding a load instruction from the ret_ref to retBB
    LLVMValueRef load_ins_to_retBB = LLVMBuildLoad2(builder, int_data_type, ret_ref,  "load")

    // adding return instruction for the load instruction
    LLVMValueRef return_ins = LLVMBuildRet(builder, load_ins_to_retBB);

    // generating iR for the function body
    LLVMBasicBlockRef exitBB = genIRStmt(body, builder, entryBB);

    // getting termiantor instruction of exitBB
    LLVMValueRef exitBB_terminator = LLVMGetBasicBlockTerminator(exitBB);
    if (exitBB_terminator == NULL) {
        LLVMPositionBuilderAtEnd(builder, exitBB);
        LLVMBuildBr(builder, retBB);
    }

    // removing all basic blocks that do not have any predecessor basic blocks


}

void set_insert_local_vars(std::unordered_set<std::string>* set_to_modify, vector<astNode*> * stmt_list) {

    if (stmt_list == NULL) {
        return;
    }

    for (astNode* stmt_node : *stmt_list) {
        astStmt stmt = stmt_node -> stmt;
        // base case: if the node is a declaration we just insert it
        if (stmt.type == ast_decl) {
            char* stmt_name = stmt.decl.name;
            set_to_modify->insert(stmt_name);
        }

        // everytime we encounter a type of statement that can contain a stmt_list we recurse to process its potential declarations

        if (stmt.type == ast_block) {
            vector<astNode*> * stmt_list_inner_block = stmt.block.stmt_list;
            set_insert_local_vars(set_to_modify, stmt_list_inner_block);
        }

        if (stmt.type == ast_while) {
            astNode* while_body = stmt.whilen.body;
            if (while_body != NULL) {
                if (while_body->type == ast_stmt){
                    if (while_body->stmt.type == ast_block) {
                        vector<astNode*>* stmt_list_while_block = while_body -> stmt.block.stmt_list;
                        set_insert_local_vars(set_to_modify, stmt_list_while_block);
                    }
                }
            }
        }

        if (stmt.type == ast_if) {

            // recurse the if body
            astNode* if_body = stmt.ifn.if_body;
            if (if_body != NULL) {
                if (if_body->type == ast_stmt) {
                    if (if_body->stmt.type == ast_block){
                        vector<astNode*>* stmt_list_if_body = if_body -> stmt.block.stmt_list;
                        set_insert_local_vars(set_to_modify, stmt_list_if_body);
                    }
                }
            }

            // recurse the else body if existent
            astNode* else_body = stmt.ifn.else_body;
            if (else_body != NULL) {
                if (else_body->type == ast_stmt) {
                    if (else_body->stmt.type == ast_block){
                        vector<astNode*>* stmt_list_else_body = else_body -> stmt.block.stmt_list;
                        set_insert_local_vars(set_to_modify, stmt_list_else_body);
                    }
                }
            }
        }
    }
}

LLVMBasicBlockRef genIRStmt(astNode* statement_node, LLVMBuilderRef builder, LLVMBasicBlockRef startBB) {
    // astStmt object
    astStmt stmt_object = statement_node -> stmt;
    if (stmt_object.type == ast_asgn) {
        LLVMPositionBuilderAtEnd(builder, startBB);
        // extracting the expression in the right hand side
        astNode* rhs = stmt_object.asgn.rhs;
        LLVMValueRef rhs_processed  = genIRExpr(rhs, builder);
        char* var_name = stmt_object.asgn.lhs->var.name;
        LLVMValueRef alloca_for_var = var_map[var_name];
        LLVMBuildStore(builder, rhs_processed, alloca_for_var);
        return startBB;
    } else if (stmt_object.type == ast_call) {
        LLVMPositionBuilderAtEnd(builder, startBB);

    }
}

LLVMValueRef genIRExpr(astNode* expression, LLVMBuilderRef builder) {
    if (expression -> type == ast_cnst) {
        int const_value = expression -> cnst.value;
        LLVMValueRef llvm_constant = LLVMConstInt(int_data_type, const_value, 0);

        return llvm_constant;

    } else if (expression -> type == ast_var) {
        char* name_of_var = expression -> var.name;
        LLVMValueRef memory_location = var_map[name_of_var];
        LLVMValueRef load_instruction = LLVMbuildLoad2(builder, int_data_type, memory_location, name_of_var);

        return load_instruction;

    } else if (expression -> type == ast_uexpr) {
        astNode* uexpression = expresion -> uexpr.expr;
        // recursion for the expr in the unary expression node and storing the simplified value
        LLVMValueRef simplified_expr_component = genIRExpr(uexpression, builder);
        // creating the constant 0 to make the unary expression
        LLVMValueRef zero_llvm = LLVMConstInt(int_data_type, 0, 0);
        // to finally get the unary
        LLVMValueRef unary = LLVMBuildSub(builder, zero_llvm, simplified_expr_component, "unary");

        return unary;

    } else if (expression -> type == ast_bexpr) {
        astNode* lhs = expression -> bexpr.lhs;
        LLVMValueRef processed_lhs = genIRExpr(lhs, builder);
        astNode* rhs = expression -> bexpr.rhs;
        LLVMValueRef processed_rhs = genIRExpr(rhs, builder);
        if ( expression -> bexpr.op == add ) {
            LLVMValueRef bexpr_addition = LLVMBuildAdd(builder, processed_lhs, processed_rhs, "bexpr_addition");

            return bexpr_addition;

        } else if (expression -> bexpr.op == sub) {
            LLVMValueRef bexpr_sub = LLVMBuildSub(builder, processed_lhs, processed_rhs, "bexpr_substraction");

            return bexpr_sub;

        } else if (expression -> bexpr.op == divide) {
            LLVMValueRef bexpr_div = LLVMBuildSDiv(builder, processed_lhs, processed_rhs, "bexpr_div");

            return bexpr_div;

        } else if (expression -> bexpr.op == mul) {
            LLVMValueRef bexpr_mul = LLVMBuildMul(builder, processed_lhs, processed_rhs, "bexpr_mul");

            return bexpr_mul;

        }
    } else if (expression -> type == ast_rexpr) {
        astNode* lhs = expression -> rexpr.lhs;
        LLVMValueRef lhs_processed = genIRExpr(lhs, builder);
        astNode* rhs = expression -> rexpr.rhs;
        LLVMValueRef rhs_processed = genIRExpr(rhs, builder);

        if (expression->rexpr.op == lt) {
            LLVMValueRef lt_cmp = LLVMBuildICmp(builder, LLVMIntSLT, lhs_processed, rhs_processed, "lt_cmp");

            return lt_cmp;

        } else if (expression -> rexpr.op == gt) {
            LLVMValueRef gt_cmp = LLVMBuildICmp(builder, LLVMIntSGT, lhs_processed, rhs_processed, "gt_cmp");

            return gt_cmp;

        } else if (expression -> rexpr.op == le) {
            LLVMValueRef le_cmp = LLVMBuildICmp(builder, LLVMIntSLE, lhs_processed, rhs_processed, "le_cmp");

            return le_cmp;

        } else if (expression -> rexpr.op == ge) {
            LLVMValueRef ge_cmp = LLVMBuildICmp(builder, LLVMIntSGE, lhs_processed, rhs_processed, "ge_cmp");

            return ge_cmp;

        } else if (expression -> rexpr.op == eq) {
            LLVMValueRef eq_cmp = LLVMBuildICmp(builder, LLVMIntEQ, lhs_processed, rhs_processed, "eq_cmp");

            return eq_cmp;
            
        } else if (expression -> rexpr.op == neq) {
            LLVMValueRef neq_cmp = LLVMBuildICmp(builder, LLVMIntNe, lhs_processed, rhs_processed, "neq_cmp");

            return neq_cmp;

        }
    } else if (expression -> type == ast_stmt && expression -> stmt.type == ast_call) {
        // for the read function the param field will be NULL so the count of params is 0
        LLVMValueRef call_llvm = LLVMBuildCall2(builder, read_type, readFunc, NULL, 0, "call_llvm");

        return call_llvm;

    }
}