#include <iostream>

struct ListNode
{
	int val;
	struct ListNode *next;
};

ListNode * reverseList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	ListNode *pPrev = nullptr;
	ListNode *pNext = nullptr;
	ListNode *pReversedHead = nullptr;

	while(pNode != nullptr)
	{
		pNext = pNode->next;
		if(pNode == nullptr)
		{
			pReversedHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pPreversedHead;
}
