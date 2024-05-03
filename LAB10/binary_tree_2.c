#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct TreeNode{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* buildTree(TreeNode* node[], int n, int size) {
    if (n < size) {
        if (node[n] != NULL) {
            TreeNode* root = node[n];
            root->left = buildTree(node, 2 * n + 1, size);
            root->right = buildTree(node, 2 * n + 2, size);
            return root;
        }
    }
    return NULL;
}

TreeNode* inputNode() {
    TreeNode* temp[MAX_NODES];
    TreeNode* node = NULL;
    char input[10];
    int i = 0;

    while (1) {
        scanf("%s", input);
        if (input[0] == 'e'){
            printf("OK\n");
            break;
        }
        if (input[0] == 'x') {
            temp[i++] = NULL;
        } else {
            node = createNode(atoi(input));
            temp[i++] = node;
        }
    }

    return buildTree(temp, 0, i);
}

bool DFS(TreeNode* root, int sum) {
    if (!root)
        return false;
    if (!root->left && !root->right && root->value == sum)
        return true;
    return DFS(root->left, sum - root->value) || DFS(root->right, sum - root->value);
}

void findNumber(TreeNode* root) {
    if (!root) {
        printf("ERROR\n");
        return;
    }
    int target;
    scanf("%d", &target);
    printf(DFS(root, target) ? "YES\n" : "NO\n");
}

void printPaths(TreeNode* root, int target, int sum, int *path, int pathLen, bool* found){
    if (!root)
        return;

    path[pathLen++] = root->value;
    sum += root->value;

    if (sum == target){
        printf("%d", path[0]);
        for (int i = 1; i < pathLen; i++){
            if(path[i] != 0)
                printf("+%d", path[i]);
        }
        printf("=%d\n", target);
        *found = true;
    }

    printPaths(root->left, target, sum, path, pathLen, found);
    printPaths(root->right, target, sum, path, pathLen, found);
}

void findAllPath(TreeNode *root){
    if(!root){
        printf("ERROR\n");
        return;
    }

    int path[MAX_NODES];
    bool found = false;
    int sum;
    scanf("%d", &sum);
    printPaths(root, sum, 0, path, 0, &found);
    if(!found)
        printf("NO\n");
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main() {
    TreeNode* root = NULL;
    int option;

    while (1) {
        scanf("%d", &option);
        switch (option) {
            case 1:
                root = inputNode();
                break;
            case 2:
                findNumber(root);
                break;
            case 3:
                findAllPath(root);
                break;
            case 0:
                Quit();
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }

    return 0;
}