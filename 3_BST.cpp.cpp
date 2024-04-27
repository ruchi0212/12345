#include<iostream>
using namespace std;
class node
{
public:
int data;
node* left;
node* right;
};
class BST
{
public:
node *root;
int cnt;
BST()
{
root=NULL;
cnt=0;
}
void insert();
void inorder(node *temp);
void preorder(node *temp);
void postorder(node *temp);
int search(int key);
void smallest();
void greatest();
void mirror(node *root);
int height(node *root);
};
void BST::insert()
{
int flag=0;
node *new_node,*temp;
new_node=new node(); //memory allocation
new_node->left=NULL;
new_node->right=NULL;
cout<<"Enter node data:";
cin>>new_node->data;
if(root==NULL)
{
root=new_node;
}
else
{
temp=root;
while(flag==0)
{
if(new_node->data < temp->data)
{
if(temp->left==NULL)
{
temp->left=new_node;
flag=1;
}
else
{
temp=temp->left;
}
}
else if(new_node->data > temp->data)
{
if(temp->right==NULL)
{
temp->right=new_node;
flag=1;
}
else
{
temp=temp->right;
}
}
else
{
cout<<"Data already exists.";
}
}
}
}
int BST::search(int key)
{
node *temp;
temp=root;
while(1)
{
if(key<temp->data)
{
if(temp->left!=NULL)
{
temp=temp->left;
}
else
{
return(0);
}
}
else if(key>temp->data)
{
if(temp->right!=NULL)
{
temp=temp->right;
}
else
{
return(0);
}
}
else
return 1;
}
}
void BST::inorder(node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
cout<<" "<<temp->data;
inorder(temp->right);
}
}
void BST::preorder(node *temp)
{
if(temp!=NULL)
{
cout<<" "<<temp->data;
preorder(temp->left);
preorder(temp->right);
}
}
void BST::postorder(node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
cout<<" "<<temp->data;
}
}
void BST::smallest()
{
node *temp;
temp=root;
while(temp->left!=NULL)
{
temp=temp->left;
}
cout<<"Smallest node in BST is "<<temp->data;
}
void BST::greatest()
{
node *temp;
temp=root;
while(temp->right!=NULL)
{
temp=temp->right;
}
cout<<"Greatest node in BST is "<<temp->data;
}
void BST::mirror(node *root)
{
node *temp;
if(root!=NULL)
{
temp=root->left;
root->left=root->right;
root->right=temp;
mirror(root->left);
mirror(root->right);
}
}
int BST::height(node *root)
{
int left_height,right_height;
if(root==NULL)
{
return 0;
}
else if(root->left==NULL && root->right==NULL)
{
return 0;
}
left_height=height(root->left);
right_height=height(root->right);
if(left_height>right_height)
{
return(left_height+1);
}
else
{
return(right_height+1);
}
}
int main()
{
BST b;
int ch,key;
do
{
cout<<"\n *****MENU*****";
cout<<"\n 1.Insert data";
cout<<"\n 2.Search data";
cout<<"\n 3.Inorder";
cout<<"\n 4.Preorder";
cout<<"\n 5.Postorder";
cout<<"\n 6.Smallest node";
cout<<"\n 7.Greatest node";
cout<<"\n 8.Mirror tree";
cout<<"\n 9.Height";
cout<<"\n 10.Exit";
cout<<"\n Enter a choice:";
cin>>ch;
switch(ch)
{
case 1:
b.insert();
break;
case 2:
cout<<"Enter element to be search:";
cin>>key;
if(b.search(key))
{
cout<<"Element found";
}
else
{
cout<<"Element not found";
}
break;
case 3:
cout<<"Inorder is ";
b.inorder(b.root);
break;
case 4:
cout<<"Preorder is ";
b.preorder(b.root);
break;
case 5:
cout<<"Postorder is ";
b.postorder(b.root);
break;
case 6:
b.smallest();
break;
case 7:
b.greatest();
break;
case 8:
cout<<"Mirror of tree is ";
b.mirror(b.root);
b.inorder(b.root);
break;
case 9:
int temp;
b.height(b.root);
temp=b.height(b.root);
cout<<"Height of the tree is "<<temp;
break;
case 10:
cout<<"End of program";
break;
};
}while(ch!=10);
}
