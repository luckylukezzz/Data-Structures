#include <iostream>
using namespace std;


struct Node{
    int key;
    Node* left;
    Node* right;

};

Node* createNode(int key){

    Node* newNode = new Node;
    newNode->key = key;
    newNode->left =nullptr;
    newNode->right =nullptr;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* delNode(Node* root, int key){
    if ( root == nullptr ){
        return root;
    }
    if (root->key > key){
        root->left = delNode(root->left,key);
    }
    else if (root->key < key){
        root->right = delNode(root->right,key);
    }
    else{
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            return root;
        }
        if (root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* node = root->right;
        while (node->left != nullptr)
            node = node->left;
        root->key = node->key;
        root->right = delNode(root->right, node->key);
    }
    return root;
    
}

void preOrder(Node* root ){
    cout<<root->key<<" ";
    if (root->left != nullptr){
        preOrder(root->left);
    }
    if (root->right != nullptr){
        preOrder(root->right);
    }

}

void postOrder(Node* root ){
   
    if (root->left != nullptr){
        preOrder(root->left);
    }
    if (root->right != nullptr){
        preOrder(root->right);
    }
    cout<<root->key<<" ";

}
void inOrder(Node* root ){
   
    if (root->left != nullptr){
        preOrder(root->left);
    }
    cout<<root->key<<" ";
    if (root->right != nullptr){
        preOrder(root->right);
    }
    
}

bool searchNode(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key < root->key) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}


int main(){
    Node* b=nullptr;
    b=insert(b,7);
    insert(b,4);
    insert(b,10);
    insert(b,2);
    insert(b,1);
    insert(b,3);
    insert(b,5);
    insert(b,6);
    insert(b,9);
    insert(b,12);
    insert(b,11);
    insert(b,13);
    preOrder(b);
    cout<<"\n";
    cout<<searchNode(b,7)<<endl;
    cout<<searchNode(b,4)<<endl;
    cout<<searchNode(b,3)<<endl;
    delNode(b,10);
    preOrder(b);



    return 0;
}