#include "Control.h"

// ----- Logout -----
Logout::Logout(ifstream& in_fp, ofstream& out_fp, System& system) {
    LogoutUI ui;
    ui.startInterface(out_fp); // 로그아웃 1번 순서
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser) {
        currentUser->deauthenticateUser(); // 로그아웃 2번 순서
        out_fp << "> " << currentUser->getUserID() << endl;  // id출력
        out_fp << endl;
    }
}

// ----- BikeRentLog -----
BikeRentLog::BikeRentLog(ifstream& in_fp, ofstream& out_fp, System& system) {
    BikeRentLogUI ui;
    ui.startInterface(out_fp); // 자전거대여리스트 4번 순서
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {  // 현재 로그인된 user가 member인지 확인
        Member* currentMember = (Member*)(currentUser); // member pointer로 user 다운캐스팅
        BikeRentCollection* collection = currentMember->getRentList(); //자전거대여리스트 1번 순서
        if (collection) {
            Bike* bike = collection->findFirst(); //자전거대여리스트 2번 순서, 첫 bike를 가져옴
            while (bike != nullptr) {
                out_fp << "> " << bike->getBikeDetail().first << " " << bike->getBikeDetail().second << endl; // 자전거대여리스트 4번 순서(출력)
                bike = collection->getNext(); //자전거대여리스트 3번 순서
            }
            out_fp << endl;
        }
    }
}

// ----- Login -----
Login::Login(ifstream& in_fp, ofstream& out_fp, System& system) {
    LoginUI ui;
    ui.startInterface(out_fp); // 로그인 1번 순서
    pair<string, string> loginInfo = ui.inputLogin(in_fp); // 로그인 2번 순서
    inputLogin(loginInfo.first, loginInfo.second, out_fp, system); // 로그인 3번 순서
}

void Login::inputLogin(string id, string pwd, ofstream& out_fp, System& system) {
    User* user = system.findUserByIDPWD(id, pwd);
    if (user) {
        user->authenticateUser(); // 로그인 4번 순서
        system.setCurrentUser(user);
        out_fp << "> " << id << " " << pwd << endl;
        out_fp << endl;
    }
}

// ----- Register -----
Register::Register(ifstream& in_fp, ofstream& out_fp, System& system) {
    RegisterUI ui;
    ui.startInterface(out_fp); // 회원가입1번 순서
    tuple<string, string, string> accountInfo = ui.createNewAccount(in_fp); //회원가입2번 순서
    createNewAccount(get<0>(accountInfo), get<1>(accountInfo), get<2>(accountInfo), out_fp, system); //회원가입 3번 순서
}

void Register::createNewAccount(string id, string pwd, string tel, ofstream& out_fp, System& system) {
    system.createMember(id, pwd, tel); // 회원가입4번 순서
    out_fp << "> " << id << " " << pwd << " " << tel << endl;
    out_fp << endl;
}

// ----- BikeRegister -----
BikeRegister::BikeRegister(ifstream& in_fp, ofstream& out_fp, System& system) {
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {
        return; // member일 경우 자전거 등록 불가
    }
    BikeRegisterUI ui;
    ui.startInterface(out_fp); // 자전거등록 1번 순서
    pair<string, string> bikeInfo = ui.addNewBike(in_fp); // 자전거등록 2번 순서
    addNewBike(bikeInfo.first, bikeInfo.second, out_fp, system); // 자전거등록 3번 순서
}

void BikeRegister::addNewBike(string bikeID, string bikeName, ofstream& out_fp, System& system) {
    system.addBike(bikeID, bikeName); // 자전거등록 4번 순서
    out_fp << "> " << bikeID << " " << bikeName << endl;
    out_fp << endl;
}

// ----- BikeRent -----
BikeRent::BikeRent(ifstream& in_fp, ofstream& out_fp, System& system) {
    BikeRentUI ui;
    ui.startInterface(out_fp); // 자전거대여 1번 순서
    string bikeID = ui.rentBikeID(in_fp); // 자전거대여 2번 순서
    rentBikeID(bikeID, out_fp, system); // 자전거대여 3번 순서
}

void BikeRent::rentBikeID(string bikeID, ofstream& out_fp, System& system) {
    User* currentUser = system.getCurrentUser();
    if (currentUser->authenticatedStatus() && currentUser->isMember()) {
        Member* currentMember = (Member*)(currentUser); // user -> member 캐스팅
        Bike* bike = system.findBikeByID(bikeID);
        if (bike) {
            pair<string, string> bikeDetail = bike->getBikeDetail(); // 자전거대여 4번 순서
            BikeRentCollection* collection = currentMember->getBikeCollection(); // 자전거대여 5번 순서
            collection->addNewBikeRent(bike); // 자전거대여 6번 순서
            out_fp << "> " << bikeDetail.first << " " << bikeDetail.second << endl;
            out_fp << endl;
        }
    }
}

// ----- Exit -----
Exit::Exit(ifstream& in_fp, ofstream& out_fp, System& system) {
    ExitUI ui;
    ui.startInterface(out_fp); // 종료 1번 순서
}
