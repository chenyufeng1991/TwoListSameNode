//
//  main.cpp
//  TwoListSameNode
//
//  Created by chenyufeng on 8/10/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

/**
 *  找到两个链表的第一个公共节点
 *
 */

using namespace std;

typedef struct ListNode{

    int element;
    struct ListNode *next;
}Node;

void CreateList(Node **pHead);

// 创建第二个链表，让其最后的指针指向第一个链表中的某个节点
void CreateSecondList(Node **pHead, Node *pFirstList);
void PrintSameNode(Node *pFirstList, Node *pSecondList);
void PrintList(Node *pListHead);
int ListLength(Node *pListHead);

int main(int argc, const char * argv[])
{
    Node *pFirstList;
    Node *pSecondList;

    CreateList(&pFirstList);
    PrintList(pFirstList);
    ListLength(pFirstList);

    CreateSecondList(&pSecondList, pFirstList->next->next);
    PrintList(pSecondList);
    ListLength(pSecondList);

    PrintSameNode(pFirstList, pSecondList);

    return 0;
}

void CreateList(Node **pHead)
{
    cout << "请输入节点值创建第一个链表，输入<=0时结束" << endl;

    *pHead = new Node;
    memset(*pHead, 0, sizeof(Node));
    (*pHead)->next = NULL;

    Node *pListNode = new Node;
    memset(pListNode, 0, sizeof(Node));
    pListNode->next = NULL;

    Node *pMove = *pHead;

    cin >> pListNode->element;
    while (pListNode->element > 0)
    {
        pMove->next = pListNode;
        pMove = pMove->next;

        pListNode = new Node;
        memset(pListNode, 0, sizeof(Node));
        pListNode->next = NULL;

        cin >> pListNode->element;
    }
}

void CreateSecondList(Node **pHead, Node *pFirstList)
{
    cout << "请输入节点值创建第二个链表，输入<=0时结束" << endl;

    *pHead = new Node;
    memset(*pHead, 0, sizeof(Node));
    (*pHead)->next = NULL;

    Node *pListNode = new Node;
    memset(pListNode, 0, sizeof(Node));
    pListNode->next = NULL;

    Node *pMove = *pHead;

    cin >> pListNode->element;
    while (pListNode->element > 0)
    {
        pMove->next = pListNode;
        pMove = pMove->next;

        pListNode = new Node;
        memset(pListNode, 0, sizeof(Node));
        pListNode->next = NULL;

        cin >> pListNode->element;
    }

    pMove->next = pFirstList;
}

void PrintSameNode(Node *pFirstList, Node *pSecondList)
{
    int pFirstListLength = ListLength(pFirstList);
    int pSecondListLength = ListLength(pSecondList);

    Node *pFirstMove = pFirstList->next;
    Node *pSecondMove = pSecondList->next;

    if (pFirstListLength > pSecondListLength)
    {
        int startStep = pFirstListLength - pSecondListLength;
        while (startStep--)
        {
            pFirstMove = pFirstMove->next;
        }
    }
    else if (pFirstListLength == pSecondListLength)
    {

    }
    else
    {
        int startStep = pSecondListLength - pFirstListLength;
        while (startStep--)
        {
            pSecondMove = pSecondMove->next;
        }
    }

    while (pFirstMove != pSecondMove)
    {
        pFirstMove = pFirstMove->next;
        pSecondMove = pSecondMove->next;
    }

    if (pFirstMove == pSecondMove)
    {
        cout << "第一个公共节点为:" << pFirstMove->element <<endl;
    }

    return;
}

void PrintList(Node *pListHead)
{
    Node *pMove = pListHead->next;

    while (pMove != NULL)
    {
        cout << pMove->element << " ";
        pMove = pMove->next;
    }

    cout << endl;
}

int ListLength(Node *pListHead)
{
    int length = 0;

    Node *pMove = pListHead->next;
    while (pMove != NULL)
    {
        length++;
        pMove = pMove->next;
    }

    cout << "链表的长度为：" << length << endl;

    return length;
}











