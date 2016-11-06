#include <stdio.h>
#include <stdbool.h>
#include "utils/leetcode.h"

typedef bool(*fptr)(struct TreeNode *);

/**
 * 4ms (192 cases) on LeetCode recursion solution 
 */
bool checkSymmetric(struct TreeNode* r1, struct TreeNode* r2) {
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL || r2 == NULL) return false;
    return r1->val == r2->val &&
        checkSymmetric(r1->left, r2->right) &&
        checkSymmetric(r2->left, r1->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return checkSymmetric(root->left, root->right);
}

bool isSymmetricIteration(struct TreeNode* root) {
    return false;
}

int main(int argc, char** argv) {
    struct TreeNode* r = NULL;
    char boolStr[][8] = { "false", "true" };
    int i = 1; 
    char *line = NULL;
    fptr f = isSymmetric;
    while (i < argc && line == NULL && f == isSymmetric) {
        if (!strcmp(argv[i], "-i")) {
            f = isSymmetricIteration;
        }
        else if (line == NULL) {
            line = argv[i];
        }
        i++;
    }
    r = str2Tree(line, ",");
    printf("Symmetric: %s\n", boolStr[f(r)]);
    freeTree(r);
    return 0;
}