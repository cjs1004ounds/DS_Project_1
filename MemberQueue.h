#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
    MemberQueueNode* queueArray; // Queue�� ������ �迭
    int frontIndex; // Queue�� �� �� �ε���
    int rearIndex;  // Queue�� �� �� �ε���
    int maxSize;    // Queue�� �ִ� ũ��
    int currentSize; // ���� Queue�� ����ִ� �������� ����

public:
    MemberQueue();
    ~MemberQueue();

    bool empty();
    bool full();
    void push(const MemberQueueNode& newNode);
    MemberQueueNode pop();
    MemberQueueNode front();
    bool isEmpty() const; // MemberQueue�� ��� �ִ��� Ȯ���ϴ� �Լ�
    bool enqueue(const MemberQueueNode& newNode); // MemberQueue�� ��带 �߰��ϴ� �Լ�
};