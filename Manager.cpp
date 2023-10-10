#include "Manager.h"
#include <iostream>
#include <string>

using namespace std;

Manager::Manager()
{

}
Manager::~Manager()
{

}

void Manager::LOAD()
{
    // Check if memberQueue is already populated
    if (!memberQueue.isEmpty())
    {
        PrintErrorCode(100); // Error code 300: Data already loaded
        return;
    }

    // Open data file
    ifstream fdata("data.txt");
    if (!fdata)
    {
        PrintErrorCode(100); // Error code 200: Fail to open data file
        return;
    }

    string name, date, terms;
    int age;

    // Read data from file and populate memberQueue
    while (fdata >> name >> age >> date >> terms)
    {
        // Add data to memberQueue
        MemberQueueNode newNode(name, age, date, terms);
        memberQueue.enqueue(newNode);
    }

    fdata.close();

    // Print loaded data to log file
    flog << "===== LOAD =====" << endl;
    while (!memberQueue.isEmpty())
    {
        MemberQueueNode node = memberQueue.pop();
        flog << node.getName() << "/" << node.getAge() << "/" << node.getDate() << "/" << node.getTerms() << endl;
    }
    flog << "===============" << endl << endl;

    PrintSuccess("LOAD");
}

void Manager::ADD(const string& name, int age, const string& date, const string& terms)
{
    if (name.empty() || age < 10 || age > 99 || date.empty() || terms.empty())
    {
        PrintErrorCode(200); // Error code 100: Invalid input parameters
        return;
    }

    // Check for duplicate names
    MemberQueue tempQueue = memberQueue; // Create a temporary queue to preserve original data
    while (!tempQueue.isEmpty())
    {
        MemberQueueNode node = tempQueue.pop();
        if (node.getName() == name)
        {
            PrintErrorCode(200); // Error code 400: Duplicate patient name
            return;
        }
    }

    // Add data to memberQueue
    MemberQueueNode newNode(name, age, date, terms);
    memberQueue.enqueue(newNode);

    // Print added data to log file
    flog << "===== ADD =====" << endl;
    flog << newNode.getName() << "/" << newNode.getAge() << "/" << newNode.getDate() << "/" << newNode.getTerms() << endl;
    flog << "===============" << endl << endl;

    PrintSuccess("ADD");
}

void Manager::QPOP()
{
    if (memberQueue.isEmpty())
    {
        PrintErrorCode(300); // 에러 코드 300: Member_Queue에 데이터가 없음
        return;
    }

    // Process data from Member_Queue
    while (!memberQueue.isEmpty())
    {
        MemberQueueNode node = memberQueue.pop();

        termsList.insert(node.getTerms(), 1, &termsBST);

        nameBST.insert(node.getName(), node.getAge(), node.getDate(), node.getDate(), node.getTerms());

        // Print processed data to log file
        flog << "===== QPOP =====" << endl;
        flog << "Success" << endl;
        flog << "===============" << endl << endl;
    }

    PrintSuccess("QPOP");
}

void Manager::SEARCH(const string& name)
{
    // Search for the member in Name_BST
    NameBSTNode* result = nameBST.search(name);

    if (result != nullptr)
    {
        // Member found, print the information
        flog << "===== SEARCH =====" << endl;
        flog << result->getMemberName() << "/" << result->getAge() << "/" << result->getCollectionDate()
            << "/" << result->getExpirationDate() << endl;
        flog << "===============" << endl << endl;
    }
    else
    {
        // Member not found, print error code
        PrintErrorCode(400);
    }
}

void Manager::PRINT(const string& arg)
{
    if (arg == "D")
    {
        flog << "===== PRINT =====" << endl;
        flog << "Terms_BST D" << endl;
        flog << "================" << endl;
        termsBST.printInOrder(termsBST.getRoot());
        flog << "================" << endl << endl;
    }
    else if (arg == "NAME")
    {
        flog << "===== PRINT =====" << endl;
        flog << "Name_BST" << endl;
        flog << "================" << endl;
        nameBST.printInOrder(nameBST.getRoot());
        flog << "================" << endl << endl;
    }
    else
    {
        PrintErrorCode(500);
    }
}

void Manager::DELETE(const string& arg1, const string& arg2)
{
    if (arg1 == "DATE")
    {
        // Delete by DATE
        if (arg2.empty())
        {
            PrintErrorCode(600);
            return;
        }

        string date = arg2;
        TermsBSTNode* deletedNode = termsBST.deleteByExpirationDate(date);

        if (deletedNode != nullptr)
        {
            nameBST.deleteNode(deletedNode->getMemberName(), termsBST);

            flog << "===== DELETE =====" << endl;
            flog << "Success" << endl;
            flog << "================" << endl << endl;
        }
        else
        {
            PrintErrorCode(600);
        }
    }
    else if (arg1 == "NAME")
    {
        // Delete by NAME
        if (arg2.empty())
        {
            PrintErrorCode(600);
            return;
        }

        string name = arg2;
        NameBSTNode* deletedNode = nameBST.deleteByName(name, termsBST);

        if (deletedNode != nullptr)
        {
            flog << "===== DELETE =====" << endl;
            flog << "Success" << endl;
            flog << "================" << endl << endl;
        }
        else
        {
            PrintErrorCode(600);
        }
    }
    else
    {
        PrintErrorCode(600);
    }
}

void Manager::run(const char* command) {
    // 명령어 파일 열기
    fcmd.open(command);
    if (!fcmd) {
        PrintErrorCode(200); // 에러 코드 200: 명령어 파일 열기 실패
        return;
    }

    string cmd, name, date, terms;
    int age;

    // command.txt에서 명령어 읽고 처리하기
    while (fcmd >> cmd) {
        if (cmd == "LOAD") {
            LOAD();
        }
        else if (cmd == "ADD") {
            fcmd >> name >> age >> date >> terms;
            ADD(name, age, date, terms);
        }
        else if (cmd == "QPOP") {
            QPOP();
        }
        else if (cmd == "SEARCH") {
            fcmd >> name;
            SEARCH(name);
        }
        else if (cmd == "PRINT") {
            fcmd >> cmd; // PRINT 명령어의 매개변수 얻기
            PRINT(cmd);
        }
        else if (cmd == "DELETE") {
            fcmd >> cmd >> name; // DELETE 명령어의 매개변수 얻기
            DELETE(cmd, name);
        }
        else if (cmd == "EXIT") {
            // 로그 파일에 종료 메시지 출력
            flog << "===== EXIT =====" << endl;
            flog << "Success" << endl;
            flog << "===============" << endl << endl;

            // 명령어 파일 닫기
            fcmd.close();
            return; // 함수 종료 및 프로그램 종료
        }
        else {
            PrintErrorCode(300); // 에러 코드 300: 잘못된 명령어
        }
    }

    // 명령어 파일 닫기
    fcmd.close();
}