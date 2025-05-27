#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "System.h"

// Boundary Classes - UI ��� ����
class LogoutUI { // �α׾ƿ� UI Ŭ������, �α׾ƿ� �������̽��� ����ϴ� ����� ����
public:
    void startInterface(ofstream& out_fp);
};

class BikeRentLogUI { // ������ �뿩 ����Ʈ UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
};

class LoginUI { // �α��� UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
    pair<string, string> inputLogin(ifstream& in_fp); // �α��� ���� �Է� �Լ�
};

class RegisterUI { // ȸ������ UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
    tuple<string, string, string> createNewAccount(ifstream& in_fp); // ȸ������ ���� �Է� �Լ�
};

class BikeRegisterUI { // ������ ��� UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
    pair<string, string> addNewBike(ifstream& in_fp); // ������ ��� ���� �Է� �Լ�
};

class BikeRentUI { // ������ �뿩 UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
    string rentBikeID(ifstream& in_fp); // ������ �뿩 ID �Է� �Լ�
};

class ExitUI { // ���� UI Ŭ����
public:
    void startInterface(ofstream& out_fp);
};

#endif 
