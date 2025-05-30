#ifndef CONTROL_H
#define CONTROL_H

#include "Boundary.h"

// Control Classes - ���� ó�� ����
class Logout { // �α׾ƿ� Ŭ������, �α׾ƿ� �������̽��� ����ϰ� ���� �α��ε� ����ڸ� �α׾ƿ��ϴ� ����� ����
public:
    Logout(ifstream& in_fp, ofstream& out_fp, System& system);
};

class BikeRentLog { // ������ �뿩 ����Ʈ Ŭ������, ���� �α��ε� ������� �뿩�� ������ ����� ����ϴ� ����� ����
public:
    BikeRentLog(ifstream& in_fp, ofstream& out_fp, System& system);
};

class Login { // �α��� Ŭ������, �α��� �������̽��� ����ϰ� ������� ID�� ��й�ȣ�� �Է¹޾� �����ϴ� ����� ����
public:
    Login(ifstream& in_fp, ofstream& out_fp, System& system);
    void inputLogin(string id, string pwd, ofstream& out_fp, System& system); // �α��� �Լ�, id�� pwd�� �޾Ƽ� userList���� ã��, �α��� ������ ���� ���¸� true�� ����
};

class Register { // ȸ������ Ŭ������, ȸ������ �������̽��� ����ϰ� ������� ID, ��й�ȣ, ��ȭ��ȣ�� �Է¹޾� ���ο� ������ �����ϴ� ����� ����
public:
    Register(ifstream& in_fp, ofstream& out_fp, System& system);
    void createNewAccount(string id, string pwd, string tel, ofstream& out_fp, System& system); // ȸ������ �Լ�
};

class BikeRegister { // ������ ��� Ŭ������, ������ ��� �������̽��� ����ϰ� ����ڰ� ������ ID�� �̸��� �Է¹޾� ���ο� �����Ÿ� ����ϴ� ����� ����
public:
    BikeRegister(ifstream& in_fp, ofstream& out_fp, System& system);
    void addNewBike(string bikeID, string bikeName, ofstream& out_fp, System& system); // ������ ��� �Լ�
};

class BikeRent { // ������ �뿩 Ŭ������, ������ �뿩 �������̽��� ����ϰ� ����ڰ� �뿩�� ������ ID�� �Է¹޾� �뿩�ϴ� ����� ����
public:
    BikeRent(ifstream& in_fp, ofstream& out_fp, System& system);
    void rentBikeID(string bikeID, ofstream& out_fp, System& system); // ������ �뿩 �Լ�
};

class Exit { // ���� Ŭ������, ���� �������̽��� ����ϴ� ����� ����
public:
    Exit(ifstream& in_fp, ofstream& out_fp, System& system);
};


#endif 
