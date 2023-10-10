#pragma once
#include "NameBSTNode.h"
#include "TermsBST.h" 

using namespace std;

class NameBST
{
private:
    NameBSTNode* root;

public:
    NameBST();
    ~NameBST();

    NameBSTNode* getRoot() const;

    void insert(const string& name, int age, const string& collectionDate, const string& expirationDate, const string& termsType);
    NameBSTNode* search(const string& name) const;
    void printInOrder(NameBSTNode* node) const;
    void deleteNode(const string& name, TermsBST& termsBST);
    NameBSTNode* deleteByName(const string& name, TermsBST& termsBST);

private:
    NameBSTNode* insertRec(NameBSTNode* node, const string& name, int age, const string& collectionDate, const string& expirationDate, const string& termsType);
    NameBSTNode* searchRec(NameBSTNode* node, const string& name) const;
    NameBSTNode* deleteRec(NameBSTNode* node, const string& name, TermsBST& termsBST);
    NameBSTNode* minValueNode(NameBSTNode* node);
    void deleteSubtree(NameBSTNode* node);
    NameBSTNode* deleteByNameRec(NameBSTNode* node, const string& name, TermsBST& termsBST);
};