#pragma once
#include <string>
#include "TermsBSTNode.h"


using namespace std;
class TermsBST
{
private:
    TermsBSTNode* root;

public:
    TermsBST();
    ~TermsBST();

    TermsBSTNode* getRoot();

    void insert(const string& name, int age, const string& collectionDate, const string& expirationDate);
    void printInOrder(TermsBSTNode* node) const;
    void deleteNode(const string& name);
    void deleteSubtree(TermsBSTNode* node);
    TermsBSTNode* deleteByExpirationDate(const string& expirationDate);

private:
    TermsBSTNode* insertRec(TermsBSTNode* node, const string& name, int age, const string& collectionDate, const string& expirationDate);
    TermsBSTNode* minValueNode(TermsBSTNode* node);
    TermsBSTNode* deleteRec(TermsBSTNode* node, const string& name);
    TermsBSTNode* deleteByExpirationDateRec(TermsBSTNode* node, const string& expirationDate);
};