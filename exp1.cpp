#include <iostream>
#include<string>
using namespace std;
class node
{
public:
char data;
node *left;
node *right;
};
class stack
{
public:
int top;
node *a[20];
stack()
{
top = -1;
}
void push(node *temp)
{
if(!isfull())
{
a[++top]= temp;
}
else
{
cout<<"Stack is full...!";
}
}
node *pop()
{
if(!isempty())
{
return(a[top--]);
}
else
{
cout<<"Stack is empty...!";
}
}
int isfull()
{
if(top==19)
{
return (1);
}
else
{
return (0);
}
}
int isempty()
{
if(top== -1)
{
return (1);
}
else
{
return (0);
}
}
};
class Exp_Tree
{
public:
node *root;
Exp_Tree()
{
root= NULL;
}
void create_exp_tree();
void infix(node *temp);
void prefix(node *temp);
void postfix(node *temp);
void del(node *temp);
};
void Exp_Tree::create_exp_tree()
{
char ch;
node *new_node,*temp;
string str;
int i;
stack s;
cout<<"\nEnter a Prefix expression:";
cin>>str;
for(i=(str.length()-1);i>=0;i--)
{
ch=str[i];
new_node = new node();
new_node->data = ch;
new_node->left=NULL;
new_node->right=NULL;
if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
{
s.push(new_node);
}
else
{
temp=s.pop();
new_node->left=temp;
temp=s.pop();
new_node->right=temp;
s.push(new_node);
}
}
root = s.pop();
}
void Exp_Tree::prefix(node *temp)
{
if(temp != NULL)
{
cout<<" "<<temp->data;
prefix(temp->left);
prefix(temp->right);
}
}
void Exp_Tree::infix(node *temp)
{
if(temp!=NULL)
{
infix(temp->left);
cout<<""<<temp->data;
infix(temp->right);
}
}
void Exp_Tree::postfix(node *temp)
{
if(temp!=NULL)
{
postfix(temp->left);
postfix(temp->right);
cout<<""<<temp->data;
}
}
void Exp_Tree::del(node *temp)
{
if(temp==NULL)
return;
{
del(temp->left);
del(temp->right);
cout<<"\n deleting node "<<temp->data;
delete(temp);
}
}
int main()
{
Exp_Tree E;
E.create_exp_tree();
cout<<"\nPrefix expression is: ";
E.prefix(E.root);
cout<<endl;
cout<<"\n Infix expression is :";
E.infix(E.root);
cout<<endl;
cout<<"\n Postfix expression is :";
E.postfix(E.root);
cout<<endl;
cout<<"\n Deleted expression is :";
E.del(E.root);
cout<<endl;
}
