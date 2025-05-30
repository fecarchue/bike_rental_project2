#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// Ŭ���� ���� ����
class User;
class Manager;
class Member;
class Bike;
class BikeRentCollection;
class System;

// Entity Classes
class Bike { // ������ Ŭ������, ������ ID�� �̸��� ����
private:
    string BikeID;  // ������ ID
    string BikeName; // ������ �̸�

public:
    Bike(string id, string name); // ������, ������ ID�� �̸��� �ʱ�ȭ
    pair<string, string> getBikeDetail();  // ������ ID�� �̸��� ��ȯ�ϴ� �Լ�, pair�� ��ȯ�� first, second�� ���� id�� name ��ȯ
};

class BikeRentCollection { // ������ �뿩 ����� �����ϴ� Ŭ������, �뿩�� ������ ����� vector�� �����ϰ�, �뿩�� �����Ÿ� ��ȸ�� �� �ִ� ����� ����
private:
    vector<Bike*> rentedBike;   //member �뿩 ������ ��� vector�� ����
    int currentIndex; // ���� ������ �ε���, getNext() ȣ��� ���� �����Ÿ� ��ȯ�ϱ� ���� ���

public:
    BikeRentCollection(); // ������, currentIndex�� 0���� �ʱ�ȭ
    void addNewBikeRent(Bike* bike); // �����Ÿ� �뿩 ��Ͽ� �߰��ϴ� �Լ�
    Bike* findFirst(); // �뿩�� ������ �� ù ��° �����Ÿ� ��ȯ
    Bike* getNext(); // ���� �����Ÿ� ��ȯ
};

class User { // ����� Ŭ������, ���� ���¸� �����ϰ�, ID�� ��й�ȣ�� Ȯ���ϴ� ����� ����
protected:
    bool isAuthenticated; // ���� ���¸� ��Ÿ���� ����
public:
    User();
    virtual ~User();
    void authenticateUser(); // ���� ���¸� true�� ����
    void deauthenticateUser(); // ���� ���¸� false�� ����
    bool authenticatedStatus(); // ���� ���¸� ��ȯ�ϴ� �Լ�, �α��εǾ��ִ��� Ȯ��

    virtual string getUserID() = 0; // ID�� ��ȯ�ϴ� �Լ�,virtual�� ����, logout�� manager, member ���ʿ��� ȣ���
    virtual bool checkPassword(string id, string pwd) = 0; // ID�� ��й�ȣ�� Ȯ���ϴ� �Լ�, virtual�� ����, login�� manager, member ���ʿ��� ȣ���
    virtual bool isMember() = 0;    // member���� Ȯ���ϴ� �Լ�(0�̸� admin)
};

class Manager : public User { // ������ Ŭ������, ������ ID�� ��й�ȣ�� �����ϸ�, User Ŭ������ ��ӹ޾� virtual �Լ��� ����
private:
    string managerID; // ������ ID
    string managerPWD; // ������ ��й�ȣ

public:
    Manager(string id, string pwd);
    string getManagerID(); // ������ ID ��ȯ
    string getManagerPWD(); // ������ ��й�ȣ ��ȯ

    // Virtual �Լ��� ����
    string getUserID() override; // manager ID ��ȯ
    bool checkPassword(string id, string pwd) override; // manager ID�� ��й�ȣ Ȯ��
    bool isMember() override; // manager�� member�� �ƴϹǷ� false ��ȯ
};

class Member : public User { // ȸ�� Ŭ������, ȸ�� ID, ��й�ȣ, ��ȭ��ȣ�� �����ϸ�, User Ŭ������ ��ӹ޾� virtual �Լ��� ����
private:
    string memberID; // ȸ�� ID
    string memberPWD; // ȸ�� ��й�ȣ
    string memberTEL; // ȸ�� ��ȭ��ȣ
    BikeRentCollection* rentedBikeCollection; // �뿩�� ������ ����� �����ϴ� BikeRentCollection ������

public:
    Member(string id, string pwd, string tel); // ������
    ~Member(); // �Ҹ��ڿ��� �뿩�� ������ ��� ��ü ����
    BikeRentCollection* getRentList(); // �뿩�� ������ ����� ��ȯ�ϴ� �Լ�, ������ �뿩 ����Ʈ ��ȸ�� ���
    BikeRentCollection* getBikeCollection(); // �뿩�� ������ ����� ��ȯ�ϴ� �Լ�, ������ �뿩�� ���
    string getUserID() override; // member ID ��ȯ
    bool checkPassword(string id, string pwd) override; // member ID�� ��й�ȣ Ȯ��
    bool isMember() override; // member�� member�̹Ƿ� true ��ȯ
};

class System { // �ý��� Ŭ������, ����ڿ� ������ �����͸� �����ϸ�, ����� ���� �� ������ ���/�뿩 ����� ����
private:
    User* currentUser_ptr; //current user�� System ���ο��� ����
    vector<User*> userList; // user data�� System ���ο��� ����
    vector<Bike*> bikeList;  //bike data�� System ���ο��� ����

public:
    System(); // �⺻ admin ���� ���� ����
    ~System(); // �Ҹ��ڿ��� user �� bike data ����
    void setCurrentUser(User* user); // ���� �α��ε� user ����, login�� ���
    User* getCurrentUser(); // ���� �α��ε� user ��ȯ, logout, bikeRentLog�� ���
    void createMember(string id, string pwd, string tel); // userList�� ���ο� member �߰�, ȸ�����Խ� ���
    User* findUserByIDPWD(string id, string pwd); // userList���� id�� pwd�� �α��� Ȯ��
    void addBike(string bikeID, string bikeName); // ������ ��� �Լ�, �����ŵ�Ͻ� ���
    Bike* findBikeByID(string bikeID); // bikeList���� bikeID�� ������ ã��, �����Ŵ뿩�� ���
};

#endif // SYSTEM_H