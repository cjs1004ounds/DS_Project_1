#include "MemberQueue.h"
#include <cstdlib>

using namespace std;

MemberQueue::MemberQueue()
{
    maxSize = 100;
    queueArray = new MemberQueueNode[maxSize];
    frontIndex = 0;
    rearIndex = -1;
    currentSize = 0;
}

MemberQueue::~MemberQueue()
{
    delete[] queueArray;
}

bool MemberQueue::empty()
{
    return currentSize == 0;
}

bool MemberQueue::full()
{
    return currentSize == maxSize;
}

void MemberQueue::push(const MemberQueueNode& newNode)
{
    if (full())
    {
        // Queue�� �� �� ���� �� ó�� (���� ó�� ��)
        // ���⼭�� ������ ���α׷� ����
        exit(1);
    }
    else
    {
        rearIndex = (rearIndex + 1) % maxSize;
        queueArray[rearIndex] = newNode;
        currentSize++;
    }
}

MemberQueueNode MemberQueue::pop()
{
    if (empty())
    {
        // Queue�� ��� ���� �� ó�� (���� ó�� ��)
        // ���⼭�� ������ ���α׷� ����
        exit(1);
    }
    else
    {
        MemberQueueNode poppedNode = queueArray[frontIndex];
        frontIndex = (frontIndex + 1) % maxSize;
        currentSize--;
        return poppedNode;
    }
}

MemberQueueNode MemberQueue::front()
{
    if (empty())
    {
        // Queue�� ��� ���� �� ó�� (���� ó�� ��)
        // ���⼭�� ������ ���α׷� ����
        exit(1);
    }
    else
    {
        return queueArray[frontIndex];
    }
}

bool MemberQueue::isEmpty() const
{
    return currentSize == 0;
}

bool MemberQueue::enqueue(const MemberQueueNode& newNode)
{
    if (full())
    {
        // Queue�� �� �� ���� �� ó�� (���� ó�� ��)
        // ���⼭�� ������ ���α׷� ����
        exit(1);
    }
    else
    {
        rearIndex = (rearIndex + 1) % maxSize;
        queueArray[rearIndex] = newNode;
        currentSize++;
        return true; // ��� �߰� ����
    }
}