// Programm for practicing pointers.

#include <stdio.h>
#include <string.h>

//Changing a string in main through a function
void changeStringInFunction(char* theString)
{
    theString[1] = 'U';
}

void changeWholeStringInFunction(char **theString)
{
    char* anotherString = "LI";
    *theString = anotherString;
    printf("print LI: %s\n", *theString);
}

int main()
{

// int pointer, pointers to pointers
    int a = 5;

    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;

    int **qq;
    qq = pp;

    printf("%d\n", **pp);


// Array pointers
    char name[5] = {'K','A','R','L','\0'};
    char *cp = &name[0];

    printf("The first letter: %c\n", *cp);

    char *cq;

    cq = cp + 2;

    printf("The 3. letter: %c\n", *cq);


// Strings and pointers
    printf("whole string: %s\nstring starting with 3. letter: %s\n", cp, cq);

// String pointers and functions
    changeStringInFunction(cp);

    printf("string with second letter changed: %s\n", cp);

    changeWholeStringInFunction(&cq);

    printf("%s\n", cp);
    printf("%s\n", cq);



    return 0;
}
