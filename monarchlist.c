/*
Inspired by a long-term project, but at this point really just a way for me to practice
working with linked lists (and pointers in general) in C.

Objectives:

    Make list with 3 components:
    - string containing name of monarch.
    - integer for year their reign begins.
    - integer for year their reign ends.


    Create a function for each of the following:
    - adding an element at the beginning of the list
    - removing an element
    - adding an element at the end of the list (not yet implemented)
    - finding and printing the monarch with the earliest start of reign and print the name
    - finding the monarch with the earliest start of reign and print and their name and the dates
    - deleting the whole list
    - printing the whole list
    - tbc
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    const char monarchname[40];
    int reignStart;
    int reignEnd;
    struct node *next;
};

struct node *head = NULL;

void addstart(){
    struct node *listnode;
    listnode=malloc(sizeof(struct node));
    printf("Name (no spaces): ");
    scanf ("%s", &listnode->monarchname);
    printf ("Reign in format year-year: ");
    scanf ("%d-%d", &listnode->reignStart, &listnode->reignEnd);

    if (head!=NULL){
        listnode->next=head;
        head=listnode;
    }
    else{
        head=listnode;
        listnode->next=NULL;
    }
}

void showlist(){
    struct node *traversenode;
    traversenode=head;
    while(traversenode!=NULL)
    {
        printf("%s", traversenode->monarchname);
        printf(" ");
        printf("%d-%d", traversenode->reignStart, traversenode->reignEnd);
        printf("\n");
        traversenode=traversenode->next;
    }

}


void earlieststart() //Programm should print the name of the monarch with the earliest staart of reigh
{
    struct node *traversenode;
    traversenode=head;
    int lowest, first=1, counter=0, lowestSpot=0;
    while (traversenode!=NULL)
    {
        if (first==0)
        {
            if (traversenode->reignStart < lowest)
            {
                lowest=traversenode->reignStart;
                lowestSpot=counter;
            }
        }
        else
        {
            lowest=traversenode->reignStart;
            first=0;
        }
        traversenode=traversenode->next;
        counter++;
    }

    traversenode=head;

    for(;lowestSpot>0;lowestSpot--)
        traversenode=traversenode->next;

    printf("Earliest: %s", traversenode->monarchname);
}


void oneRemoved() //removes one name; if appears several times, removes the first in the list
    {
        const char toBeRemovedString[40];
        int foundOne = 0;
        printf("Remove which? ");
        scanf("%s", &toBeRemovedString);

        if (!(strcmp(toBeRemovedString, head->monarchname))) //if first element is same
        {
            struct node *tempnode=head;
            head=head->next;
            free(tempnode);
            foundOne=1;
        }

        else
        {
            struct node *willBeRemovedNode=head->next;

            if (!(strcmp(toBeRemovedString, willBeRemovedNode->monarchname))) //if second element is same
            {
                head->next=willBeRemovedNode->next;
                free(willBeRemovedNode);
                foundOne=1;
            }

            else
            {
                struct node *rememberNode=willBeRemovedNode;
                willBeRemovedNode=willBeRemovedNode->next;

                for(;
                    willBeRemovedNode!=NULL;
                    rememberNode=willBeRemovedNode,
                    willBeRemovedNode=willBeRemovedNode->next)
                {
                    if(!(strcmp(toBeRemovedString, willBeRemovedNode->monarchname)))
                    {
                        rememberNode->next=willBeRemovedNode->next;
                        free(willBeRemovedNode);
                        foundOne=1;
                        break;
                    }
                }
            }
        }

        if (foundOne==1)
        {
            printf("Deleted %s\n", toBeRemovedString);
        }
        else
        {
            printf("No such name in list\n");
        }

    }

void begonelist()
{
    struct node *traversenode;
    while(head!=NULL)
    {
        traversenode=head;
        head=traversenode->next;
        free(traversenode);
    }
}

int main(){

/*
    To do:
    - adding a menu to choose which function to call.
    - adapting the function to the possibility of a different oder,
        (such as "showlist" before the list has any elements).
    - dealing with names with spaces.
    - dealing with mistakes in input format
    - ...
*/
    addstart();
    addstart();
    addstart();
    showlist();
    oneRemoved();
    showlist();

    begonelist();
return 0;
}
