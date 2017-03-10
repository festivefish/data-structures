Node *build(int a[], int size){
    root->key = a[0];
    root->parent = NULL;
    cout<<"root: "<<root->key<<" parent: "<<root->parent<<endl;
    
    for(int i=1;i<size;i++){
        Node *parent = NULL;
        Node *current = root;
        Node *n = new Node(NULL,NULL,NULL);
        n->key = a[i];
        while(current != NULL){
            parent = current;
            if(n->key < current->key){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(n->key < parent->key){
            parent->left = n;
            cout<<"node: "<<current->key<<" left child of: "<<parent->key<<endl;
        }
        else{
            parent->right = n;
            cout<<"node: "<<current->key<<" right child of: "<<parent->key<<endl;
        }
    }
    return root;
}