/*
    Arthur Carlos da Rocha Silva
    Tabelas Hash
    https://www.urionlinejudge.com.br/judge/pt/problems/view/1256\
*/

#include <stdio.h>
#include <stdlib.h>
int i, j,i1,i2,i3; //site version of gcc does not understand declarations in for loop

typedef struct ListNodes
{
    struct ListNodes *nextNode; //points to the following node
    int nodeValue; //the value in the node
} ListNode ;

typedef struct Lists
{
    ListNode *data; //Points to the first node of the list  
    ListNode *lastNode;
    int size;  
} List ;

List* createList()
{
    List *newList ;
    newList = (List*)malloc(sizeof(List)); 
    if (newList != NULL)
    {
        (*newList).size = 0;
        (*newList).data = NULL; 
        (*newList).lastNode = NULL; 
    }
    return newList; 
} // createList function

void removeFromList(List *inputList,  int valueToRemove)
{
    ListNode *aux, *anterior; 
    aux = (*inputList).data; // aux will now point to the first node of the input list
    anterior = NULL;
    while(aux != NULL) //aux will loop throgh the list till it points to a null node
    {
        if ((*aux).nodeValue == valueToRemove) //if the value in the current node is the value to be removed
        {
            if (anterior == NULL) //if it is the first value of the list (anterior is still NULL)
            {
                (*inputList).data = (*aux).nextNode; //the first node of the list will now be the aux`s next node
            }
            else
            {
                (*anterior).nextNode = (*aux).nextNode; //the node anteiror to the one to be removed will point to the following
            }
            (*inputList).size = (*inputList).size - 1; 
            break; 
        }
    	anterior = aux; //anterior will point to the current node
        aux = (*aux).nextNode; // aux will now point to the next node in the list
    }
}// removeFromList function

void addToList(List *inputList, int valueToAdd)
{
    ListNode *newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    if ((*inputList).data  == NULL) //if the list is empty
    {
        (*newNode).nextNode = NULL; //the new node will point to null
        inputList->lastNode = newNode; //the last node of the list will point to the new node
        (*newNode).nodeValue = valueToAdd; 
        (*inputList).data = newNode; //the beginning of the list will be the new node
        (*inputList).size ++;
    }
    else 
    {
        (*newNode).nextNode = NULL ; 
        (*newNode).nodeValue = valueToAdd;
        inputList->lastNode->nextNode = newNode; //the last element of the list will point to the new node
        (*inputList).lastNode = newNode; //the new node will now be the last element of the upgrated list
        (*inputList).size ++;
    }
}//addToList

void printList(List *inputList)
{ 
    ListNode *aux = (*inputList).data ;
    while(aux != NULL)
    {
        printf("%d -> ",(*aux).nodeValue);
        aux = (*aux).nextNode; 
    }
    printf("\\\n");
}

List** createTable(int newTableSize)
{
    List **newTable; 
    newTable = (List**)malloc(newTableSize * sizeof(List*)); 
    for(  i1 = 0 ; i1 < newTableSize ; i1++) 
    {
        newTable[i1] = createList(); 
    }
    return newTable; 
}

void printTable(List **inputTable,int sizeOfTable){
    for(i2 = 0 ; i2 < sizeOfTable ; i2++)
    {
            printf("%d -> ",i2);
            printList(inputTable[i2]);
    }
}

int main()
{
    int key,numberOfKeys,numberOfTests,tableSize; 
    List **table; 
    scanf("%d",&numberOfTests);
    for(i3 = 0 ; i3 < numberOfTests ; i3++)
    {
        scanf("%d %d",&tableSize, &numberOfKeys);
        table = createTable(tableSize);
        for(j = 0 ; j < numberOfKeys ; j++)
        { 
            scanf("%d",&key);
            addToList(*(table + key % tableSize), key);
        }
        printTable(table,tableSize); 
        if (i3 != numberOfTests - 1)
        {
           printf("\n"); 
        }
    }
    return 0; 
}   