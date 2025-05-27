#include "Control.h"

// ----- Logout -----
Logout::Logout(ifstream& in_fp, ofstream& out_fp, System& system) {
    LogoutUI ui;
    ui.startInterface(out_fp); // �α׾ƿ� 1�� ����
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser) {
        currentUser->deauthenticateUser(); // �α׾ƿ� 2�� ����
        out_fp << "> " << currentUser->getUserID() << endl;  // id���
        out_fp << endl;
    }
}

// ----- BikeRentLog -----
BikeRentLog::BikeRentLog(ifstream& in_fp, ofstream& out_fp, System& system) {
    BikeRentLogUI ui;
    ui.startInterface(out_fp); // �����Ŵ뿩����Ʈ 4�� ����
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {  // ���� �α��ε� user�� member���� Ȯ��
        Member* currentMember = (Member*)(currentUser); // member pointer�� user �ٿ�ĳ����
        BikeRentCollection* collection = currentMember->getRentList(); //�����Ŵ뿩����Ʈ 1�� ����
        if (collection) {
            Bike* bike = collection->findFirst(); //�����Ŵ뿩����Ʈ 2�� ����, ù bike�� ������
            while (bike != nullptr) {
                out_fp << "> " << bike->getBikeDetail().first << " " << bike->getBikeDetail().second << endl; // �����Ŵ뿩����Ʈ 4�� ����(���)
                bike = collection->getNext(); //�����Ŵ뿩����Ʈ 3�� ����
            }
            out_fp << endl;
        }
    }
}

// ----- Login -----
Login::Login(ifstream& in_fp, ofstream& out_fp, System& system) {
    LoginUI ui;
    ui.startInterface(out_fp); // �α��� 1�� ����
    pair<string, string> loginInfo = ui.inputLogin(in_fp); // �α��� 2�� ����
    inputLogin(loginInfo.first, loginInfo.second, out_fp, system); // �α��� 3�� ����
}

void Login::inputLogin(string id, string pwd, ofstream& out_fp, System& system) {
    User* user = system.findUserByIDPWD(id, pwd);
    if (user) {
        user->authenticateUser(); // �α��� 4�� ����
        system.setCurrentUser(user);
        out_fp << "> " << id << " " << pwd << endl;
        out_fp << endl;
    }
}

// ----- Register -----
Register::Register(ifstream& in_fp, ofstream& out_fp, System& system) {
    RegisterUI ui;
    ui.startInterface(out_fp); // ȸ������1�� ����
    tuple<string, string, string> accountInfo = ui.createNewAccount(in_fp); //ȸ������2�� ����
    createNewAccount(get<0>(accountInfo), get<1>(accountInfo), get<2>(accountInfo), out_fp, system); //ȸ������ 3�� ����
}

void Register::createNewAccount(string id, string pwd, string tel, ofstream& out_fp, System& system) {
    system.createMember(id, pwd, tel); // ȸ������4�� ����
    out_fp << "> " << id << " " << pwd << " " << tel << endl;
    out_fp << endl;
}

// ----- BikeRegister -----
BikeRegister::BikeRegister(ifstream& in_fp, ofstream& out_fp, System& system) {
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {
        return; // member�� ��� ������ ��� �Ұ�
    }
    BikeRegisterUI ui;
    ui.startInterface(out_fp); // �����ŵ�� 1�� ����
    pair<string, string> bikeInfo = ui.addNewBike(in_fp); // �����ŵ�� 2�� ����
    addNewBike(bikeInfo.first, bikeInfo.second, out_fp, system); // �����ŵ�� 3�� ����
}

void BikeRegister::addNewBike(string bikeID, string bikeName, ofstream& out_fp, System& system) {
    system.addBike(bikeID, bikeName); // �����ŵ�� 4�� ����
    out_fp << "> " << bikeID << " " << bikeName << endl;
    out_fp << endl;
}

// ----- BikeRent -----
BikeRent::BikeRent(ifstream& in_fp, ofstream& out_fp, System& system) {
    BikeRentUI ui;
    ui.startInterface(out_fp); // �����Ŵ뿩 1�� ����
    string bikeID = ui.rentBikeID(in_fp); // �����Ŵ뿩 2�� ����
    rentBikeID(bikeID, out_fp, system); // �����Ŵ뿩 3�� ����
}

void BikeRent::rentBikeID(string bikeID, ofstream& out_fp, System& system) {
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {
        Member* currentMember = (Member*)(currentUser); // user -> member ĳ����
        Bike* bike = system.findBikeByID(bikeID);
        if (bike) {
            pair<string, string> bikeDetail = bike->getBikeDetail(); // �����Ŵ뿩 4�� ����
            BikeRentCollection* collection = currentMember->getBikeCollection(); // �����Ŵ뿩 5�� ����
            collection->addNewBikeRent(bike); // �����Ŵ뿩 6�� ����
            out_fp << "> " << bikeDetail.first << " " << bikeDetail.second << endl;
            out_fp << endl;
        }
    }
}

// ----- Exit -----
Exit::Exit(ifstream& in_fp, ofstream& out_fp, System& system) {
    ExitUI ui;
    ui.startInterface(out_fp); // ���� 1�� ����
}
