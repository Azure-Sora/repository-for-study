#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sourceArray[][5] = {"I ","II ","III ","IV ","V "};
char* toLetters(int source)
{
    return sourceArray[source];
}
int main()
{

    char** toArray;
    toArray = (char**)malloc(5*sizeof(char*));
    for(int i = 0; i < 5; i++)
    {
        toArray[i] = (char*)malloc(6*sizeof(char));
    }
    for(int i = 0; i < 5; i++)
    {
        int num;
        scanf("%d",&num);
        strcpy(toArray[i], toLetters(num));
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n",toArray[i]);
    }
    return 0;
    //a waste of time.
}
