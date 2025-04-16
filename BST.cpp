#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data =val;
        left=right=nullptr;
    }
};

class BST
{
public:
  Node* root;
  BST() { root=nullptr;}
   

  Node* insert(Node* root, int value) {
   if(root==nullptr)return new Node(value);

   if(root->data>value){
    root->left = insert(root->left,value);
   }
   else{
    root->right = insert(root->right,value);
   }
  }

  Node* search(Node* root, int value) {
    while (root != nullptr) {
        if (root->data == value) return root;
        root = (value < root->data) ? root->left : root->right;
    }
    return nullptr;
}

  Node* deleteNode(Node* root,int value){
    if(root==NULL)return root;
    if(root->data==value)return nullptr;
    Node* dummy = root;
    while(root!=NULL){
       if(root->data>value){
          
        if(root->left!=NULL&& root->left->data==value){
            root->left=helper(root->left);
        }
        else{
            root=root->left;
        }
       }
       else if(root->data<value){
          
        if(root->right!=NULL&& root->right->data==value){
            root->right=helper(root->left);
        }
        else{
            root=root->right;
        }
       }
        
    }
    return dummy;
  }
  Node* helper(Node* root){
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;

    Node* rightChild = root->right;
    Node* largeright=findlastright(root->left);
    largeright->right=rightChild;
    return root;
  }
  Node* findlastright(Node* root){
    if(root->right==NULL) return root;
    else{
        findlastright(root->right);
    }
  }
  void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
  }
  Node* maxi(Node* root){
    if(root==NULL)return root;
    if(root->right==nullptr && root->left==nullptr) return root;
    Node* temp = root;
    while (temp->right!=nullptr)
    {
        temp=temp->right;
    }
    return temp;
  }
  Node* mini(Node* root){
    if(root==NULL)return root;
    
    Node* temp = root;
    while (root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
    
  }

 



};



int main(){
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    // Insert values into BST
    for (int value : values) {
        tree.root = tree.insert(tree.root, value);
    }

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    // Search for a key
    int key = 10;
    Node* ans =tree.search(tree.root, key);
    if(!ans){
        cout<<"Not found"<<endl;
    }
    Node* maxx = tree.maxi(tree.root);
    cout<<maxx->data<<endl;
    tree.deleteNode(tree.root,40);
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}