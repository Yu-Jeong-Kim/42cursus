#include "polynomial.h"

LinkedList* createLinkedList()
{
	LinkedList	*pList;
	
	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!pList)
		return (NULL);
	return(pList);
}

ListNode* createNode(int coef, int degree)
{
    ListNode    *newNode;

    newNode = (ListNode *)calloc(1, sizeof(ListNode));
    if (!newNode)
        return (NULL);
    newNode->coef = coef;
    newNode->degree= degree;
    return (newNode);
}

int addLLElement(LinkedList* pList, int position, ListNode *element)
{
	ListNode	*pNode;

	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i < position; i++)
		pNode = pNode->pLink;
	element->pLink = pNode->pLink;
	pNode->pLink = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*pNode;
	ListNode	*delNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i < position; i++)
		pNode = pNode->pLink;
	delNode = pNode->pLink;
	pNode->pLink = delNode->pLink;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*pNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	pNode = &pList->headerNode;
	for (int i = 0; i <= position; i++)
		pNode = pNode->pLink;
	return (pNode);
}

void clearLinkedList(LinkedList* pList)
{
	int position = pList->currentElementCount - 1;
	for (; 0 <= position; position--)
		removeLLElement(pList, position);
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList *pList)
{
	
}