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
        scanf("%d", &choice);

        //loop while user does not choose 3
        while (choice != 6)
        {
            switch (choice)
            {
                case 1:
                    printf("ENTER A CHARACTER: ");
                    scanf("\n%c", &item);
                    insert(&head, item); // insert item in list
                    printList (head);
                    break;
                
                case 2:
                    printf("ENTER A CHARACTER: ");
                    scanf("\n%c", &item);
                    insertAtEnd(&head, item); // insert item in list
                    printList (head);
                    break;

                case 3:
                    printf("ENTER A CHARACTER: ");
                    scanf("\n%c", &item);
                    insertAtBeginning(&head, item); // insert item in list
                    printList (head);
                    break;

                case 4: // delete an element
                   
                   //if list is not empty
                    if (!isEmpty(head))
                    {
                        printf("ENTER CHARACTER TO BE DELETED: ");
                        scanf("\n%c", &item);
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
            scanf("%d", &choice);
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

//insert a new value into the list in sorted order
void insert(ListNodePtr *head, char value)
{
	ListNodePtr newPtr; // pointer to the new node
	ListNodePtr previousPtr; // pointer to the previous node in the list
	ListNodePtr currentPtr; // pointer to the current node in the list

	newPtr = malloc(sizeof(node_t)); // create node

	if (newPtr != NULL) // if the space is available
	{
		newPtr->data = value; // place value in node
		newPtr->nextPtr = NULL; // node does not link to another node

	previousPtr = NULL;
	currentPtr = *head;

		// loop to find the correct location in the list
		while (currentPtr != NULL && value > currentPtr->data) // checking current pointer and while its not null and the value to be inserted is greater than the current current pointer.data
		{
			// its traversing the list to figure out where we need to put the pointer
			previousPtr = currentPtr; //walk to...
			currentPtr = currentPtr->nextPtr; // ...next node
		}

		//insert new node at the beginning of the list
		if ( previousPtr == NULL)
		{
			newPtr->nextPtr = *head; //sort the new node as the first node in the list
			*head = newPtr;
		}
		else // insert the new node between previousPtr and currentPtr
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
	{
		printf("%c not inserted. No memory available.\n", value);
	}
}

void	deleteAtBeginning(ListNodePtr *head)
{
	ListNodePtr tempPtr = NULL; // temporary node pointer

	if(head == NULL) // check if the list has anything in it
		return ; // that means we dont have anything in the list
	else
	{
		tempPtr = *head; // hold onto the node being removed
		*head = (*head) ->nextPtr; // de-thread the node
		free (tempPtr); // free the de-threaded node
	}
}

// delete a list element
char	delete(ListNodePtr *head, char value)
{
	ListNodePtr previousPtr; //pointer to the previous node in the list
	ListNodePtr currentPtr; //pointer to current node in the list
	ListNodePtr tempPtr; // temporary node pointer

	//delete the first node
	if (value == (*head)->data) // check the first element in the list matches the character in the first node of the list
	{
		tempPtr = *head; //hold onto node being removed
		*head = (*head)->nextPtr; // de-thread the node
		free(tempPtr); // free the de-threaded node
		//tempPtr will be used to free the underneath memory
		return (value); // return the character that was deleted from the list
	}
	else
	{
		previousPtr = *head;
		currentPtr = (*head)->nextPtr;

		//loop to find the correct location in the list
		while (currentPtr != NULL && currentPtr->data != value) // until we get to the end of the list and until we actually found the value
		{
			
			previousPtr = currentPtr; // walk to...
			currentPtr = currentPtr->nextPtr; // ... next node  // this locates the character to be deleted if it's contained in the list
		}

		//delete node at currentPtr
		if (currentPtr != NULL) // if this happens, we found something
		{
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free (tempPtr);
			return (value); // return the character that was deleted from the list
		}
	}
	return ('\0'); // if its equal to null, return the null character because we didn't find it and we got to the end list
}

// print the list
void	printList(ListNodePtr currentPtr)
{
	//if the list is empty
	if (currentPtr == NULL)
		printf("List is empty.\n\n");
	else
	{
		printf("The list is:\n");

		//while not the end of the list
		while (currentPtr != NULL)
		{
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr; // incrementing the pointer to go to the next pointer to check if it's null to see if we're at the end
		}

		printf("NULL\n\n"); // if the link is at the last node of the list and the list is not null
	}
}

//return 1 if the list is empty, 0 otherwise
int	isEmpty(ListNodePtr head)
{
	return head == NULL; // if the head of the list is not null, there's something in the list; if the nead of the list is null that means the list is empty
}

