#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
};

/************ 尾部添加元素 *************/
// 1、考虑链表为空的情况，pHead指向新添加的结点
// 2、二重指针，用来改变函数外指针的指向。传指针只能改变指针指向的内容，
// 要想改变函数外指针的指向，需传指针的地址或引用（ListNode **pHead 或 ListNode* &pHead）

void addToTail(ListNode **pHead, int value)
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

/************ 删除指定值节点 ***********/

void removeNode(ListNode **pHead, int value)
{
	if (*pHead == nullptr || pHead == nullptr)
	{
		return;
	}

	ListNode *pToBeDeleted = nullptr;

	if ((*pHead)->val == value)
	{
		pToBeDeleted = *pHead;
	 	*pHead = (*pHead)->next;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->val != value)
		{
			pNode = pNode->next;
		}
		if (pNode->next != nullptr && pNode->next->val == value)
		{
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
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
		if(pNext == nullptr)
		{
			pReversedHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	cout << "reverseList() 95: pReversedHead == " << pReversedHead << endl;
	return pReversedHead;
}

int main()
{
	ListNode *head = nullptr;

	/******* creat *********/
	for (int i = 0; i < 10; i++)
	{
		addToTail(&head, i);
	}

	/****** print *******/
	ListNode *pNode = head;
	while (pNode != nullptr)
	{
		cout << pNode->val << endl;
		pNode = pNode->next;
	}

	/****** remove *********/
	removeNode(&head, 3);
	removeNode(&head, 0);
	removeNode(&head, 9);

	/****** print *******/
	ListNode *pRemoveNode = head;
	while (pRemoveNode != nullptr)
	{
		cout << pRemoveNode->val << endl;
		pRemoveNode = pRemoveNode->next;
	}

	/******* reverse *********/
	ListNode *reverseHead = reverseList(head); 
	

	cout << "main() 120: reverseHead == " << reverseHead << endl;
	/****** print *******/
	ListNode *pReverseNode = reverseHead;
	while (pReverseNode != nullptr)
	{
		cout << pReverseNode->val << endl;
		pReverseNode = pReverseNode->next;
	}

	return 0;
}
