#include <iostream>
using namespace std;


class BST{
private:
    int key;
    BST* left;
    BST* right;
public:
    BST(int data){
        this->key=data;
        this->left=nullptr;
        this->right=nullptr;
    }

    void insert(int data){
        if (data < this->key){
            if (this->left!=nullptr){
                this->left->insert(data); 
            }
            else{
                this->left=new BST(data);
            }
        }else{
            if (this->right!=nullptr){
                this->right->insert(data); 
            }
            else{
                this->right=new BST(data);
            }

        }

    }
    void preOrder(){
        cout<<this->key<<endl;
        if (this->left!=nullptr)
            this->left->preOrder();
        if (this->right!=nullptr)
            this->right->preOrder();
    }

    void inOrder(){
        if (this->left!=nullptr)
            this->left->preOrder();
        cout<<this->key<<endl;
        if (this->right!=nullptr)
            this->right->preOrder();

    }
    void postOrder(){
        if (this->left!=nullptr)
            this->left->postOrder();
        if (this->right!=nullptr)
            this->right->postOrder();
        cout<<this->key<<endl;
    }
    bool search(int data){
        if (this->key==data) return true;
        if (data > this->key){
            if (this->left!=nullptr){
                return this->left->search(data);
            }
            return false;
        }
        else{
            if (this->right!=nullptr){
                return this->right->search(data);
            }
            return false;
        }
    }
    BST* del(int data){
        if (data < this->key){
            if (this->left!=nullptr){
                this->left = this->left->del(data);
            }else{
                cout<<"node not present"<<endl;
                return this;
            }
        }
        else if (data > this->key){
            if (this->right!=nullptr){
                this->right = this->right->del(data);
            }else{
                cout<<"node not present"<<endl;
                return this;
            }   
        }
        else{
            if (this->left!=nullptr){
                BST* temp = this->right;
                delete(this);
                return temp;
            }
            if (this->right!=nullptr){
                BST* temp = this->left;
                delete(this);
                return temp;
            }
            BST* node = this->right;
            while (node->left!=nullptr){
                node=node->left;    
            }
            this->key = node->key;
            this->right = this->right->del(node->key);
    
        }
        return this;
    }

    int minNode(){
        BST* node = this;
        while (node->left != nullptr){
            node = node->left;
        }
        return node->key;
    }
     int maxNode(){
        BST* node = this;
        while (node->right != nullptr){
            node = node->right;
        }
        return node->key;
    }
};

int main(){
    BST* b=new BST(5);
    b->insert(6);
    b->insert(7);
    b->insert(10);
    b->insert(2);
    b->insert(5);
    b->insert(8);
    b->preOrder();
    cout<<boolalpha<<b->search(5)<<endl;
    b->del(10);
    b->postOrder();
    return 0;
}