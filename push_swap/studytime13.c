#include <stdio.h>
#include <stdlib.h>


//self-referential structure = structure referring to itself kind of with an element inside of it
typedef struct node 
{
        char    data;
        struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void    insert(ListNodePtr *head, char value);
void    insertAtEnd(ListNodePtr *head, char value);
void    insertAtBeginning(ListNodePtr *head, char value);
char    delete(ListNodePtr *head, char value);
void    deleteAtBeginning(ListNodePtr *head);
int     isEmpty(ListNodePtr head);
void    printList(ListNodePtr currentPtr);

int     main()
{
        ListNodePtr head = NULL; //initially there are no nodes
        int     choice = 0; //user choice
        char    item = '\0'; //character entered by the user

        //display the menu
        printf("Enter your choice: \n" 
        "       1 to insert an element into the list in alphabetical order.\n"
        "       2 to insert an element at the end of the list.\n"
        "       3 to insert an element at the beginning of the list.\n"
        "       4 to delete an element from the list.\n"
        "       5 to delete an element from the beginning of the list.\n"
        "       6 to end.\n");

        printf(":: ");
        printf("%d", &choice);

        //loop while user does not choose 3
        while (choice != 6)
        {
            switch (choice)
            {
                case 1:
                    printf("ENTER A CHARACTER: ");
                    printf("\n%c", &item);
                    insert(&head, item); // insert item in list
                    printList (head);
                    break;
                
                case 2:
                    printf("ENTER A CHARACTER: ");
                    printf("\n%c", &item);
                    insertAtEnd(&head, item); // insert item in list
                    printList (head);
                    break;

                case 3:
                    printf("ENTER A CHARACTER: ");
                    printf("\n%c", &item);
                    insertAtBeginning(&head, item); // insert item in list
                    printList (head);
                    break;

                case 4: // delete an element
                   
                   //if list is not empty
                    if (!isEmpty(head))
                    {
                        printf("ENTER CHARACTER TO BE DELETED: ");
                        printf("\n%c", &item);
                        //if character is found, remove it
                        if (delete(&head, item))
                        {
                            printf("%c deleted.\n", item);
                            printList(head);
                        }
                        else
                            printf("%c not found.\n\n", item);
                    }
                    else
                        printf("LIST IS EMPTY.\n\n");
                    break;

                case 5: //delete an element at beginning

                    //if list is not empty
                    if (!isEmpty(head))
                    {
                        //if character is found, remove it
                        deleteAtBeginning(&head);
                        printf("%c deleted.\n", item);
                        printList(head);
                    }
                    else
                        printf("LIST IS EMPTY.\n\n");
                    break;
                
                default:
                    printf("INVALID CHOICE.\n\n");

                    //display the menu
                    printf("ENTER YOUR CHOICE:\n"
                           "    1 to insert an element into the list.\n"
                           "    2 to delete an element from the list.\n"
                           "    3 to end.\n");
                    break;
            }
            printf("?");
            printf("%d", &choice);
        }
        printf("END OF RUN.\n");
        return (0); //indicates successful termination
}

void    insertAtBeginning(ListNodePtr *head, char value)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

void    insertAtEnd(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;

    if(current != NULL)
    {
        while (current->nextPtr != NULL) // getting current pointer to point to the end of the list before it hits null
            current = current->nextPtr;

        //now we can add a new variable
        // node that points to the last element in the list
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current; // because there is nothing else in the list or already at the end, set the head to the current, so then we're resseting the head
    }
}

