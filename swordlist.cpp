#include <iostream>
#include <stack>
//using namespace std;

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

/************ 反转链表 ***********/
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
	return pReversedHead;
}

/************　打印链表 *********/

void printList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	while(pNode != nullptr)
	{
		std::cout << pNode->val << std::endl;
		pNode = pNode->next;
	}
}

/************　反向打印链表 *********/

void printListfromTailtoHead(ListNode *pHead)
{
	std::stack<ListNode *> nodes;
	ListNode *pNode = pHead;
	while(pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		std::cout << pNode->val << std::endl;
		nodes.pop();
	}
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
	printList(head);
	std::cout << "addToTail" << std::endl;
	std::cout << "-------------" << std::endl;

	/****** remove *********/
	removeNode(&head, 3);
	removeNode(&head, 0);
	removeNode(&head, 9);
	removeNode(&head, 11);
	ListNode *pNullPtr = nullptr;
	removeNode(&pNullPtr, 2);
	removeNode(&pNullPtr, 12);

	/****** print *******/
	printList(head);
	std::cout << "removeNode" << std::endl;
	std::cout << "-------------" << std::endl;

	/******* reverse *********/
	ListNode *reverseHead = reverseList(head); 
	
	/****** print *******/
	printList(reverseHead);
	std::cout << "reverseList" << std::endl;
	std::cout << "-------------" << std::endl;

	/****** printListfromTailtoHead *******/
	printListfromTailtoHead(reverseHead);
	std::cout << "printListfromTailtoHead" << std::endl;
	std::cout << "-------------" << std::endl;

	return 0;
}
