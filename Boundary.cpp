#include "Boundary.h"

// ----- LogoutUI -----
void LogoutUI::startInterface(ofstream& out_fp) { // �α׾ƿ� �������̽� ���
    out_fp << "2.2. �α׾ƿ�" << endl; 
}

// ----- BikeRentLogUI -----
void BikeRentLogUI::startInterface(ofstream& out_fp) { // ������ �뿩 ����Ʈ �������̽� ���
    out_fp << "5.1. ������ �뿩 ����Ʈ" << endl;
}

// ----- LoginUI -----
void LoginUI::startInterface(ofstream& out_fp) { // �α��� �������̽� ���
    out_fp << "2.1. �α���" << endl;
}

pair<string, string> LoginUI::inputLogin(ifstream& in_fp) { // �α��� ���� �Է� �Լ�
    string id, pwd;
    in_fp >> id >> pwd;
    return make_pair(id, pwd);
}

// ----- RegisterUI -----
void RegisterUI::startInterface(ofstream& out_fp) { // ȸ������ �������̽� ���
    out_fp << "1.1. ȸ������" << endl;
}

tuple<string, string, string> RegisterUI::createNewAccount(ifstream& in_fp) { // ȸ������ ���� �Է� �Լ�
    string id, pwd, tel;
    in_fp >> id >> pwd >> tel;
    return make_tuple(id, pwd, tel);
}

// ----- BikeRegisterUI -----
void BikeRegisterUI::startInterface(ofstream& out_fp) { // ������ ��� �������̽� ���
    out_fp << "3.1. ������ ���" << endl;
}

pair<string, string> BikeRegisterUI::addNewBike(ifstream& in_fp) { // ������ ��� ���� �Է� �Լ�
    string bikeID, bikeName;
    in_fp >> bikeID >> bikeName;
    return make_pair(bikeID, bikeName);
}

// ----- BikeRentUI -----
void BikeRentUI::startInterface(ofstream& out_fp) { // ������ �뿩 �������̽� ���
    out_fp << "4.1. ������ �뿩" << endl;
}

string BikeRentUI::rentBikeID(ifstream& in_fp) { // ������ �뿩 ID �Է� �Լ�
    string bikeID;
    in_fp >> bikeID;
    return bikeID;
}

// ----- ExitUI -----
void ExitUI::startInterface(ofstream& out_fp) { // ���� �������̽� ���
    out_fp << "6.1. ����" << endl;
}