#pragma once
#include <string>
#include "TermsListNode.h"
#include "TermsBST.h"

using namespace std;

class TermsLIST
{
private:
    TermsListNode* head;

public:
    TermsLIST();
    ~TermsLIST();

    TermsListNode* getHead();

    void insert(const string& type, int count, TermsBST* bst);
    TermsListNode* search(const string& type);
    void deleteNode(const string& type);
};