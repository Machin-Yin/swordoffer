#include <iostream>

struct ListNode
{
	int val;
	struct ListNode *next;
};

/************ 尾部添加元素 *************/
// 1、考虑链表为空的情况，pHead指向新添加的结点
// 2、二重指针，用来改变函数外指针的指向。传指针只能改变指针指向的内容，
// 要想改变函数外指针的指向，需传指针的地址或引用（ListNode **pHead 或 ListNode* &pHead）

void addToTail(ListNode **pHead, int val)
{
	ListNode *pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while(pNode->next != nullptr)
		{
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

/************ 反转指针 ***********/
//三指针滑动法

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
