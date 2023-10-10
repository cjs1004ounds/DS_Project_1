#include "TermsBST.h"
#include <iostream>

using namespace std;

TermsBST::TermsBST() : root(nullptr)
{

}

TermsBST::~TermsBST()
{
    if (root != nullptr)
    {
        deleteSubtree(root);
    }
}

void TermsBST::deleteSubtree(TermsBSTNode* node)
{
    if (node == nullptr)
        return;

    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());

    delete node;
}

void TermsBST::insert(const string& name, int age, const string& collectionDate, const string& expirationDate)
{
    root = insertRec(root, name, age, collectionDate, expirationDate);
}

TermsBSTNode* TermsBST::insertRec(TermsBSTNode* node, const string& name, int age, const string& collectionDate, const string& expirationDate)
{
    if (node == nullptr)
    {
        return new TermsBSTNode(name, age, collectionDate, expirationDate);
    }

    if (expirationDate < node->getExpirationDate())
    {
        node->setLeft(insertRec(node->getLeft(), name, age, collectionDate, expirationDate));
    }
    else if (expirationDate > node->getExpirationDate())
    {
        node->setRight(insertRec(node->getRight(), name, age, collectionDate, expirationDate));
    }

    return node;
}

void TermsBST::printInOrder(TermsBSTNode* node) const
{
    if (node != nullptr)
    {
        printInOrder(node->getLeft());
        cout << "Name: " << node->getMemberName() << ", Age: " << node->getAge()
            << ", Collection Date: " << node->getCollectionDate()
            << ", Expiration Date: " << node->getExpirationDate() << endl;
        printInOrder(node->getRight());
    }
}

void TermsBST::deleteNode(const string& name)
{
    root = deleteRec(root, name);
}

TermsBSTNode* TermsBST::deleteRec(TermsBSTNode* node, const string& name)
{
    if (node == nullptr)
        return node;

    if (name < node->getMemberName())
    {
        node->setLeft(deleteRec(node->getLeft(), name));
    }
    else if (name > node->getMemberName())
    {
        node->setRight(deleteRec(node->getRight(), name));
    }
    else
    {
        if (node->getLeft() == nullptr)
        {
            TermsBSTNode* temp = node->getRight();
            delete node;
            return temp;
        }
        else if (node->getRight() == nullptr)
        {
            TermsBSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        TermsBSTNode* temp = minValueNode(node->getRight());
        node->setMemberName(temp->getMemberName());
        node->setAge(temp->getAge());
        node->setCollectionDate(temp->getCollectionDate());
        node->setExpirationDate(temp->getExpirationDate());
        node->setRight(deleteRec(node->getRight(), temp->getMemberName()));
    }
    return node;
}

TermsBSTNode* TermsBST::minValueNode(TermsBSTNode* node)
{
    TermsBSTNode* current = node;
    while (current && current->getLeft() != nullptr)
    {
        current = current->getLeft();
    }
    return current;
}

TermsBSTNode* TermsBST::deleteByExpirationDate(const string& expirationDate)
{
    root = deleteByExpirationDateRec(root, expirationDate);
    return root;
}

TermsBSTNode* TermsBST::deleteByExpirationDateRec(TermsBSTNode* node, const string& expirationDate)
{
    if (node == nullptr)
        return node;

    if (expirationDate < node->getExpirationDate())
    {
        node->setLeft(deleteByExpirationDateRec(node->getLeft(), expirationDate));
    }
    else if (expirationDate > node->getExpirationDate())
    {
        node->setRight(deleteByExpirationDateRec(node->getRight(), expirationDate));
    }
    else
    {
        if (node->getLeft() == nullptr)
        {
            TermsBSTNode* temp = node->getRight();
            delete node;
            return temp;
        }
        else if (node->getRight() == nullptr)
        {
            TermsBSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        TermsBSTNode* temp = minValueNode(node->getRight());
        node->setMemberName(temp->getMemberName());
        node->setAge(temp->getAge());
        node->setCollectionDate(temp->getCollectionDate());
        node->setExpirationDate(temp->getExpirationDate());
        node->setRight(deleteByExpirationDateRec(node->getRight(), temp->getExpirationDate()));
    }
    return node;
}