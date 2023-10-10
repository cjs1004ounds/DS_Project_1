#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
    MemberQueueNode* queueArray; // Queue를 저장할 배열
    int frontIndex; // Queue의 맨 앞 인덱스
    int rearIndex;  // Queue의 맨 뒤 인덱스
    int maxSize;    // Queue의 최대 크기
    int currentSize; // 현재 Queue에 들어있는 데이터의 개수

public:
    MemberQueue();
    ~MemberQueue();

    bool empty();
    bool full();
    void push(const MemberQueueNode& newNode);
    MemberQueueNode pop();
    MemberQueueNode front();
    bool isEmpty() const; // MemberQueue가 비어 있는지 확인하는 함수
    bool enqueue(const MemberQueueNode& newNode); // MemberQueue에 노드를 추가하는 함수
};