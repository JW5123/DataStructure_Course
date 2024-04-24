#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getPriority(char op) {
    switch (op) {
        case '^':
            return 3;
        case 'v':
            return 2;
        case '-':
            return 1;
        default:
            return 0;
    }
}

TreeNode* buildTree(char* expression, int left, int right) {
    if (left > right)
        return NULL;

    int parenCount = 0;
    int minPrioPos = -1;
    int minPrio = 0;

    for (int i = right; i >= left; i--) {
        if (expression[i] == '(')
            parenCount++;
        else if (expression[i] == ')')
            parenCount--;
        else if (!parenCount) {
            int priority = getPriority(expression[i]);
            if (priority > minPrio) {
                minPrio = priority;
                minPrioPos = i;
            } else if (priority == minPrio && expression[i] == '-') {
                minPrio = priority;
                minPrioPos = i;
            }
        }
    }

    if (minPrioPos != -1) {
        TreeNode* root = createTreeNode(expression[minPrioPos]);
        root->left = buildTree(expression, left, minPrioPos - 1);
        root->right = buildTree(expression, minPrioPos + 1, right);
        return root;
    }

    if (expression[left] == '(' && expression[right] == ')') {
        return buildTree(expression, left + 1, right - 1);
    } else {
        return createTreeNode(expression[left]);
    }
}

void postorder(TreeNode* root) {
    if (root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

void treePointerlogicTree(char* expression) {
    TreeNode* root = buildTree(expression, 0, strlen(expression) - 1);
    postorder(root);
    printf("\n");
}

int main() {
    char expression[100];

    while(scanf("%s", expression) != EOF) {
        if(expression[0] == '0') {
            printf("quit\n");
            break;
        }
        treePointerlogicTree(expression);
    }

    return 0;
}
