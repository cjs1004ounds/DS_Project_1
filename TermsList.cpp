#include "TermsList.h"

using namespace std;

TermsLIST::TermsLIST() : head(nullptr)
{

}

TermsLIST::~TermsLIST()
{
    TermsListNode* current = head;
    while (current != nullptr)
    {
        TermsListNode* next = current->getNext();
        delete current;
        current = next;
    }
}

TermsListNode* TermsLIST::getHead()
{
    return head;
}

void TermsLIST::insert(const string& type, int count, TermsBST* bst)
{
    TermsListNode* newNode = new TermsListNode(type, count, bst);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    TermsListNode* current = head;
    while (current->getNext() != nullptr)
    {
        current = current->getNext();
    }

    current->setNext(newNode);
}

TermsListNode* TermsLIST::search(const string& type)
{
    TermsListNode* current = head;
    while (current != nullptr)
    {
        if (current->getType() == type)
            return current;
        current = current->getNext();
    }
    return nullptr;
}

void TermsLIST::deleteNode(const string& type)
{
    TermsListNode* current = head;
    TermsListNode* prev = nullptr;

    while (current != nullptr)
    {
        if (current->getType() == type)
        {
            if (prev != nullptr)
                prev->setNext(current->getNext());
            else
                head = current->getNext();
            delete current;
            break;
        }
        prev = current;
        current = current->getNext();
    }
}