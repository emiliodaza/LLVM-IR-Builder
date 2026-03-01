#include <llvm-c/Core.h>
#include "ast/ast.h"

extern astNode* root;
extern int yyparse();
extern int semantic_analysis(astNode* root);

void var_names_unique(astNode* prog_node);
LLVMModuleRef main_algorithm(astNode* prog_node);

int main() {
    printf("Parsing the file...\n");
    yyparse(); // to update root with the necessary info
    printf("Performing semantic analysis...\n");
    semantic_analysis(root);
    printf("Making all variable names in the root node unique...\n");
    var_names_unique(root);
    printf("Constructing the module in LLVM using the root...\n");
    LLVMModuleRef module = main_algorithm(root);
    printf("Placing module content in terminal...\n");
    LLVMDumpModule(module); // see the output of the test in terminal
    printf("Disposing module...\n");
    LLVMDisposeModule(module);
    return 0;
}