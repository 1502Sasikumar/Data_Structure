#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct CharNode
{
	char data;
	struct CharNode *next;
};

struct DigitNode
{
	int data;
	struct DigitNode *next;
};

// insertAtEnd charnode
void insertChar(struct CharNode **head, char ch)
{
	struct CharNode *newnode=(struct CharNode*)malloc(sizeof(struct CharNode));
	newnode->data=ch;
	newnode->next=NULL;
	if(*head==NULL)
	*head=newnode;
	else{
	struct CharNode *temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	}
}
//insertAtEnd digitnode
void insertDigit(struct DigitNode **head,int data)
{
	struct DigitNode *newnode=(struct DigitNode*)malloc(sizeof(struct DigitNode));
	newnode->data=data;
	newnode->next=NULL;
	if(*head==NULL)
	*head=newnode;
	else
	{
	struct DigitNode *temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	}
}
//countvowels
int countvowels(struct CharNode *head)
{
	int count=0;
	while(head)
	{
		char ch= tolower(head->data);
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		count++;
		head=head->next;
	}
	return count;
}
//display charnode
void displayCharNode(struct CharNode *head)
{
	struct CharNode *temp=head;
	while(temp!=NULL)
	{
		printf("%c -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
//display digitnode
void displaydigitNode(struct DigitNode *head)
{
	struct DigitNode *temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	FILE *file=fopen("insert.txt","r");
	if(file==NULL){
	printf("Error in opening file.\n");
	return 1;
	}
	
	struct CharNode *Charlist=NULL;
	struct DigitNode *Digitlist=NULL;
	char ch;
	
	while ((ch = fgetc(file)) != EOF)

	{
		if(isdigit(ch))
		insertDigit(&Digitlist, ch-'0');
		else if(isalpha(ch))
		insertChar(&Charlist,ch);
	}
	fclose(file);
	
	printf("Char Linkedlist:\n");
	displayCharNode(Charlist);
	printf("Digit Linkedlist:\n");
	displaydigitNode(Digitlist);
	
	int vowelcount=countvowels(Charlist);
	printf("The vowels are : %d\n",vowelcount);
	
	return 0;
}
		
	
	
		 





	
