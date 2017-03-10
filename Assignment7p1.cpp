void Inorder(TreeNode *current, Node *currentll, char m, char n){
    if(current->left != NULL && current->key <= m){
        Inorder(current->left,currentll,m,n);
    }
    Node *nextll = new Node;
    nextll->key = current->key;
    nextll->next = NULL;
    currentll->next = nextll;
    currentll = nextll;
    if(current->right != NULL && current->key >= n){
        Inorder(current->right,currentll,m,n);
    }
}

void RangeSearch(TreeNode *node, char m, char n){
    TreeNode *current = node;
    Node *currentll = head;
    //while(current->key < m){
        //current = current->right;
    //}
    //while(current->key > n){
        //current = current->right;
    //}
    Inorder(current,currentll,m,n);
}