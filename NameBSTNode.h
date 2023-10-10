#pragma once
#include <string>

using namespace std;

class NameBSTNode
{
private:
    string memberName;
    int age;
    string collectionDate;
    string expirationDate;
    string termsType;
    NameBSTNode* left;
    NameBSTNode* right;

public:
    NameBSTNode(const string& name, int age, const string& collectionDate, const string& expirationDate, const string& termsType);
    ~NameBSTNode();

    string getMemberName() const;
    void setMemberName(const string& name);
    int getAge() const;
    void setAge(int age);
    string getCollectionDate() const;
    void setCollectionDate(const string& date);
    string getExpirationDate() const;
    void setExpirationDate(const string& date);
    string getTermsType() const;
    void setTermsType(const string& type);

    NameBSTNode* getLeft() const;
    void setLeft(NameBSTNode* left);
    NameBSTNode* getRight() const;
    void setRight(NameBSTNode* right);
};