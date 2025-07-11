//Treasure Hunt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct clue
{
    char *discript;
    struct clue *next;
};

struct clue *head=NULL;

void addClue(char *discript)
{
    struct clue *newnode=(struct clue*)malloc(sizeof(struct clue));
    newnode->discript=(char*)malloc(strlen(discript)+1);
    strcpy(newnode->discript,discript);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct clue *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void starthunt()
{
    struct clue *curr=head;
    int clueNumber=1;
    
    while(curr!=NULL)
    {
        printf("\n Clue %d: %s\n",clueNumber,curr->discript);
        
        if(curr->next!=NULL)
        {
            printf("Press Enter to go for next clue");
            getchar();
        }
        else
        printf("Congrulations! you found the Treassure\n");
        
        curr=curr->next;
        clueNumber++;
    }
}

// void delhunt()
// {
//     struct clue *temp=head;
//     head=temp->next;
//     free(temp);
//     temp=NULL;
// }

int main()
{
    addClue( "Go to the big oak tree in the backyard.");
    addClue( "Look under the bench near the garden.");
    addClue( "Check the mailbox for the next clue.");
    addClue( "Find the old well behind the barn.");
    addClue( "The treasure is buried under the stone with a cross mark!");

    printf("Welcome to the Scavenger Hunt!\n");
    printf("Follow the clues to find the treasure.\n");
    
    starthunt();
    
    // delhunt();
    return 0;
}
