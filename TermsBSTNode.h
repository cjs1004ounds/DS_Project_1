#pragma once

using namespace std;

class TermsBSTNode
{
private:
    string memberName;
    int age;
    string collectionDate;
    string expirationDate;

    TermsBSTNode* left;
    TermsBSTNode* right;

public:
    TermsBSTNode(const string& name, int age, const string& collectionDate, const string& expirationDate);
    ~TermsBSTNode();

    string getMemberName() const;
    int getAge() const;
    string getCollectionDate() const;
    string getExpirationDate() const;

    TermsBSTNode* getLeft() const;
    TermsBSTNode* getRight() const;

    void setMemberName(const string& name);
    void setAge(int age);
    void setCollectionDate(const string& collectionDate);
    void setExpirationDate(const string& expirationDate);

    void setLeft(TermsBSTNode* left);
    void setRight(TermsBSTNode* right);
};