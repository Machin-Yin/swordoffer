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

/************ 删除指定节点 ***********/
//在O(1)时间删除链表指定节点
//1.待删除节点next不为空
//2.待删除节点next为空，且为首节点（即仅有一个节点）
//3.待删除节点next为空，且不为首节点


void deleteNode(ListNode **pHead, ListNode *pToBeDeleted)
{
	if (pHead == nullptr || *pHead == nullptr || pToBeDeleted == nullptr)
	{
		return;
	}
	
	if (pToBeDeleted->next != nullptr)
	{
		ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == pToBeDeleted)
	{
		delete pToBeDeleted;

		*pHead = nullptr;
		pToBeDeleted = nullptr;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
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

	/****** deleteNode *******/
	ListNode *pDeleted = nullptr;
	ListNode *pDeleted1 = reverseHead;
	ListNode *pDeleted2 = reverseHead;
	ListNode *pDeleted3 = nullptr;

	deleteNode(&reverseHead, pDeleted);
	printList(reverseHead);
	std::cout << "pDeleted == nullptr" << std::endl;
	std::cout << "-------------" << std::endl;

	if (reverseHead->next->next->next != nullptr)
	{
		pDeleted1 = reverseHead->next->next;
	}
	deleteNode(&reverseHead, pDeleted1);
	printList(reverseHead);
	std::cout << "pDeleted1 为中间节点" << std::endl;
	std::cout << "-------------" << std::endl;

	while (pDeleted2->next != nullptr)
	{
		pDeleted2 = pDeleted2->next;
	}
	deleteNode(&reverseHead, pDeleted2);
	printList(reverseHead);
	std::cout << "pDeleted2 为尾节点" << std::endl;
	std::cout << "-------------" << std::endl;

	if (reverseHead != nullptr)
	{
		reverseHead->next = nullptr;
		pDeleted3 = reverseHead;
	}
	deleteNode(&reverseHead, pDeleted3);
	printList(reverseHead);
	std::cout << "pDeleted3 为首节点且为最后一个节点" << std::endl;
	std::cout << "-------------" << std::endl;

	return 0;
}
