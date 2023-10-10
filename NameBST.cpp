#include "NameBST.h"
#include <iostream>

using namespace std;

NameBST::NameBST() : root(nullptr)
{

}

NameBST::~NameBST()
{
    if (root != nullptr)
    {
        deleteSubtree(root);
    }
}

NameBSTNode* NameBST::getRoot() const
{
    return root;
}

void NameBST::insert(const string& name, int age, const string& collectionDate, const string& expirationDate, const string& termsType)
{
    root = insertRec(root, name, age, collectionDate, expirationDate, termsType);
}

NameBSTNode* NameBST::insertRec(NameBSTNode* node, const string& name, int age, const string& collectionDate, const string& expirationDate, const string& termsType)
{
    if (node == nullptr)
    {
        return new NameBSTNode(name, age, collectionDate, expirationDate, termsType);
    }

    if (name < node->getMemberName())
    {
        node->setLeft(insertRec(node->getLeft(), name, age, collectionDate, expirationDate, termsType));
    }
    else if (name > node->getMemberName())
    {
        node->setRight(insertRec(node->getRight(), name, age, collectionDate, expirationDate, termsType));
    }

    return node;
}

NameBSTNode* NameBST::search(const string& name) const
{
    return searchRec(root, name);
}

NameBSTNode* NameBST::searchRec(NameBSTNode* node, const string& name) const
{
    if (node == nullptr || node->getMemberName() == name)
    {
        return node;
    }

    if (name < node->getMemberName())
    {
        return searchRec(node->getLeft(), name);
    }

    return searchRec(node->getRight(), name);
}

void NameBST::printInOrder(NameBSTNode* node) const
    {
    if (node != nullptr)
    {
        printInOrder(node->getLeft());
        cout << "Name: " << node->getMemberName() << ", Age: " << node->getAge()
            << ", Collection Date: " << node->getCollectionDate()
            << ", Expiration Date: " << node->getExpirationDate()
            << ", Terms Type: " << node->getTermsType() << endl;
        printInOrder(node->getRight());
    }
}

void NameBST::deleteNode(const string& name, TermsBST& termsBST)
{
    root = deleteRec(root, name, termsBST);
}

NameBSTNode* NameBST::deleteRec(NameBSTNode* node, const string& name, TermsBST& termsBST)
{
    if (node == nullptr)
        return node;

    if (name < node->getMemberName())
    {
        node->setLeft(deleteRec(node->getLeft(), name, termsBST));
    }
    else if (name > node->getMemberName())
    {
        node->setRight(deleteRec(node->getRight(), name, termsBST));
    }
    else
    {
        if (node->getLeft() == nullptr)
        {
            NameBSTNode* temp = node->getRight();
            delete node;
            return temp;
        }
        else if (node->getRight() == nullptr)
        {
            NameBSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        NameBSTNode* temp = minValueNode(node->getRight());
        node->setMemberName(temp->getMemberName());
        node->setAge(temp->getAge());
        node->setCollectionDate(temp->getCollectionDate());
        node->setExpirationDate(temp->getExpirationDate());
        node->setTermsType(temp->getTermsType());
        node->setRight(deleteRec(node->getRight(), temp->getMemberName(), termsBST));

        termsBST.deleteNode(name);
    }
    return node;
}

NameBSTNode* NameBST::minValueNode(NameBSTNode* node)
{
    NameBSTNode* current = node;
    while (current && current->getLeft() != nullptr)
    {
        current = current->getLeft();
    }
    return current;
}

void NameBST::deleteSubtree(NameBSTNode* node)
{
    if (node == nullptr)
        return;

    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());

    delete node;
}