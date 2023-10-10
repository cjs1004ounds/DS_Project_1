#pragma once
#include "TermsBST.h"

using namespace std;

class TermsListNode
{
private:
    string type;
    int memberCount;
    TermsBST* bst;

    TermsListNode* next;

public:
    TermsListNode(const string& type, int count, TermsBST* bst);
    ~TermsListNode();

    string getType() const;
    int getMemberCount() const;
    TermsBST* getBST() const;

    void setType(const string& type);
    void setMemberCount(int count);
    void setBST(TermsBST* bst);

    TermsListNode* getNext() const;
    void setNext(TermsListNode* next);
};