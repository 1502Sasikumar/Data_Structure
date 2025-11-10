//Scavenger hunt using linkedlist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Clue
{
	char *ch;
	struct Clue *prev;
	struct Clue *next;
};
struct Clue *head=NULL;
struct Clue *tail=NULL;

//insertAtEnd
void insertAtEnd(char *chr)
{
	struct Clue *newClue=(struct Clue*)malloc(sizeof(struct Clue));
	newClue->ch=chr;
	newClue->next=NULL;
	newClue->prev=tail;
	if(head==NULL)
	{
	    head=tail=newClue;
	}
	else
	{
	    tail->next=newClue;
	    tail->prev=tail;
	    tail=newClue;
	}
}
//delAtEnd
void delAtEnd(){
    tail=tail->prev;
    free(tail->next);
    tail->next=NULL;
}
// //display
void display()
{
	struct Clue *temp=head;
	while(temp!=NULL)
	{
		printf("%s ->",temp->ch);
		temp=temp->next;
	}
	printf("NULL\n");
}
void play(){
    display();
    char str[20];
    scanf("%s",str);
    while(strcmp(str,"CODE")){
        scanf("%s",str);
    }
    printf("You found treassure\n");
}
int main() {
	insertAtEnd("Ram");
 	insertAtEnd("Sasi");
    insertAtEnd("Sindhu");
 	insertAtEnd("Nivi");
	display();
	printf("\n");
// 	delAtEnd();
// 	display();
//play();

}
