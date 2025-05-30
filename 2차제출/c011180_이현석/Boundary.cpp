#include "Boundary.h"

// ----- LogoutUI -----
void LogoutUI::startInterface(ofstream& out_fp) { // 로그아웃 인터페이스 출력
    out_fp << "2.2. 로그아웃" << endl; 
}

// ----- BikeRentLogUI -----
void BikeRentLogUI::startInterface(ofstream& out_fp) { // 자전거 대여 리스트 인터페이스 출력
    out_fp << "5.1. 자전거 대여 리스트" << endl;
}

// ----- LoginUI -----
void LoginUI::startInterface(ofstream& out_fp) { // 로그인 인터페이스 출력
    out_fp << "2.1. 로그인" << endl;
}

pair<string, string> LoginUI::inputLogin(ifstream& in_fp) { // 로그인 정보 입력 함수
    string id, pwd;
    in_fp >> id >> pwd;
    return make_pair(id, pwd);
}

// ----- RegisterUI -----
void RegisterUI::startInterface(ofstream& out_fp) { // 회원가입 인터페이스 출력
    out_fp << "1.1. 회원가입" << endl;
}

tuple<string, string, string> RegisterUI::createNewAccount(ifstream& in_fp) { // 회원가입 정보 입력 함수
    string id, pwd, tel;
    in_fp >> id >> pwd >> tel;
    return make_tuple(id, pwd, tel);
}

// ----- BikeRegisterUI -----
void BikeRegisterUI::startInterface(ofstream& out_fp) { // 자전거 등록 인터페이스 출력
    out_fp << "3.1. 자전거 등록" << endl;
}

pair<string, string> BikeRegisterUI::addNewBike(ifstream& in_fp) { // 자전거 등록 정보 입력 함수
    string bikeID, bikeName;
    in_fp >> bikeID >> bikeName;
    return make_pair(bikeID, bikeName);
}

// ----- BikeRentUI -----
void BikeRentUI::startInterface(ofstream& out_fp) { // 자전거 대여 인터페이스 출력
    out_fp << "4.1. 자전거 대여" << endl;
}

string BikeRentUI::rentBikeID(ifstream& in_fp) { // 자전거 대여 ID 입력 함수
    string bikeID;
    in_fp >> bikeID;
    return bikeID;
}

// ----- ExitUI -----
void ExitUI::startInterface(ofstream& out_fp) { // 종료 인터페이스 출력
    out_fp << "6.1. 종료" << endl;
}