#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sPerson
{
    int age;
};

//function to make a new sPerson
struct sPerson *getNewPerson(const int age)
{
    //make a pointer to a new structure
    struct sPerson *newPerson = NULL;
    //allocate some dynamic memory
    //malloc returns a pointer to the beginning of the allocated memory
    // we point the newPerson pointer to that allocated returned pointer
    newPerson = malloc(sizeof(struct sPerson));
    //assigned the age value
    newPerson->age = age;
    //we can print the memory address of where our pointer is pointing
    printf("new person at %p/n", newPerson);
    //return the pointer to the newly allocated memory
    return (newPerson);

}

void printPerson(const struct sPerson *person, const char *comment)
{
    //is that reference actually an address in the memory?
    if (person == NULL)
        printf("%s is NULL\n", comment);
    else
        printf("%s: age:%d address:%p\n", comment, person->age, person);
}

int main()
{
    printf("\n\n** START **\n\n");

    struct sPerson *first = NULL;
    struct sPerson *second = NULL;

    printPerson(first, "first");
    printPerson(second, "second");

    first = getNewPerson(125);
    second = getNewPerson(100);

    printPerson(first, "first");
    printPerson(second, "second");

    free (first);
    free(second);

    first = NULL;
    second = NULL;
    
    return (0);
    
}
