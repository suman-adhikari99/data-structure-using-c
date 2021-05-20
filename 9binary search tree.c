#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree* max(struct tree *root,int data);
/*void insert(struct tree *root,int data)
{
strust tree *par;
struct tree*n=(struct tree*)malloc(sizeof(struct tree));
n->left=n->right=NULL;
n->data=data;
if(root=NULL)
root=n;
else{
par=root;
while(par!=NULL)
{
if(par->data>data)
{
if(par->left==NULL)
par->left=n;
par=par->left;
}
elseif(par->data<data){
if(par->right==NULL)
par=par->right;
}
}
}
}*/
struct tree* insert(struct tree *root,int data)
{
	if(root==NULL)
	{
		root=(struct tree*)malloc(sizeof(struct tree));
		root->left=root->right=NULL;
		root->data=data;
	}
	else
	{
		if(data<root->data)
		{
			root->left=insert(root->left,data);
		}
		else
		root->right=insert(root->right,data);
	}
}
/*struct tree* find(struct tree *root,int data)
{
	struct tree *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(data<temp->data)
		temp=temp->left;
		else if(data>tempt->data)
		temp=temp->right;
		else
		return(temp);//if(data==temp->data){return(temp);
		
	}
}*/
struct tree* find(struct tree *root,int data)
{
	if(root==NULL)
	{
		printf("\nno such element is exist");
		return(root);
	}
	 if(data<root->data)
	return(find(root->left,data));
	else if(data>root->data)
	return(find(root->right,data));
	return(root);
}
struct tree* delete(struct tree *root,int data)
{
	struct tree *temp;
	if(root==NULL)
	{
		printf("\nno such element is exist");
		return(root);
	}
	else if(data<root->data)
	root->left=delete(root->left,data);
	else if(data>root->data)
	root->right=delete(root->right,data);
	else
	{
		if(root->left&&root->right)
		{
			temp=max(root->left,data);
			root->data=temp->data;
			root->left=delete(root->left,root->data);
		}
		else
		{
			temp=root;
			if(root->left==NULL)
			root=root->right;
			if(root->right=NULL)
			root=root->left;
			free(temp);
		}
	}
	return(root);
}/*stepsn invovs in deletion
1.find data  which is to be deleted;
2.tyo data ko position ma tesko left side ma raheko subtree bata maximum value khojer replace gari dine
3.left ko maximum value delte garnu value ko position ma aayakole aba left ko maximum value lai delete garne tesko laagi feri delete operation dohoraune*/
struct tree* max(struct tree *ptr,int data)
{
	int val;
	struct tree *p;
	struct tree *p1;
	p=ptr;
	while(p!=NULL)
	{
		val=p->data;
		if(val<p->data)
		{
			val=p->data;
		}
		p=p->right;
	}
	p1=find(p,val);
	return(p1);
}
void preorder(struct tree *root)
{
	if(root!=NULL)
	{
		printf("    %d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("   %d",root->data);
		inorder(root->right);
	}
}
void postorder(struct tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("   %d",root->data);
	}
}
/*void levelorder(struct tree *root)
{
	struct tree *temp;
	struct queue *q=createqueue();
	if(!root)
	return;
	enqueue(q,root);
	while(!isemptyqueue(q))
	{
		temp=dequeue(q);
		printf("\n  %d",temp->data);
		if(temp->left)
		enqueue(q,temp->left);
		if(temp->right)
		enqueue(q,temp->right);
	}
	deletequeue(q);
}*/
int main()
{
	struct tree *root,*p;
	root=NULL;
	int choice,item;
	do
	{
		printf("\n1insert\n2.search\n3.delete\n4.preorder traversal\n5.inorder traversal\n6.postorder traversal\n7.exit");
		printf("\n\n        	enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nenter the element you want to insert:");
				scanf("%d",&item);
				root=insert(root,item);
				preorder(root);
				break;
		case 3:
			printf("enter the element you want to delete:");
			scanf("%d",&item);
			delete(root,item);
			break;
			case 2:
				printf("enter the element you want to search:");
				scanf("%d",&item);
				p=find(root,item);
				if(p!=NULL)
				printf("\nsearching is successfull element found at %d",p);
				break;
				case 4:
					printf("preorder traversal of tree:\t");
					preorder(root);
					break;
				case 5:
					printf("\nthe inorder traversal is:\n");
					inorder(root);
					break;
				case 6:
					printf("\n     the postorder traversal is:\n");
						postorder(root);
						break;
				case 7:
						return(NULL);
				default:
					printf("invalid choice tray again...");
		}
	}while(choice!=7);
}
