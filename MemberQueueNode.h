#pragma once
#include <string>

using namespace std;

class MemberQueueNode
{
private:
    string name;
    int age;
    string date;
    string terms;

public:
    MemberQueueNode() : age(0) {}  // 기본 생성자 추가
    MemberQueueNode(const string& n, int a, const string& d, const string& t) : name(n), age(a), date(d), terms(t) {}
    ~MemberQueueNode() {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getDate() const { return date; }
    string getTerms() const { return terms; }
};