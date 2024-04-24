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
        case 'v':
            return 1;
        case '^':
            return 2;
        case '-':
            return 3;
        default:
            return 0;
    }
}

TreeNode* buildTree(char* expression, int left, int right) {
    if (left > right)
        return NULL;

    int minPrio = 10;
    int minPrioPos = -1;
    int parenCount = 0;

    for (int i = right; i >= left; i--) {
        if (expression[i] == '(')
            parenCount++;
        else if (expression[i] == ')')
            parenCount--;
        else if (!parenCount) {
            int priority = getPriority(expression[i]);
            if (priority > 0 && priority <= minPrio) {
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


int height(TreeNode* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void printLevel(TreeNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

void treePointerlogicTree(char* expression) {
    TreeNode* root = buildTree(expression, 0, strlen(expression) - 1);
    levelOrder(root);
    printf("\n");
}

int main() {

    char expression[100];

    while(scanf("%s", expression) != EOF){
        if(expression[0] == '0'){
            printf("quit\n");
            break;
        }
        treePointerlogicTree(expression);
    }

    return 0;
}
