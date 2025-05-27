#ifndef CONTROL_H
#define CONTROL_H

#include "Boundary.h"

// Control Classes - 실제 처리 로직
class Logout { // 로그아웃 클래스로, 로그아웃 인터페이스를 출력하고 현재 로그인된 사용자를 로그아웃하는 기능을 제공
public:
    Logout(ifstream& in_fp, ofstream& out_fp, System& system);
};

class BikeRentLog { // 자전거 대여 리스트 클래스로, 현재 로그인된 사용자의 대여한 자전거 목록을 출력하는 기능을 제공
public:
    BikeRentLog(ifstream& in_fp, ofstream& out_fp, System& system);
};

class Login { // 로그인 클래스로, 로그인 인터페이스를 출력하고 사용자의 ID와 비밀번호를 입력받아 인증하는 기능을 제공
public:
    Login(ifstream& in_fp, ofstream& out_fp, System& system);
    void inputLogin(string id, string pwd, ofstream& out_fp, System& system); // 로그인 함수, id와 pwd를 받아서 userList에서 찾고, 로그인 성공시 인증 상태를 true로 설정
};

class Register { // 회원가입 클래스로, 회원가입 인터페이스를 출력하고 사용자의 ID, 비밀번호, 전화번호를 입력받아 새로운 계정을 생성하는 기능을 제공
public:
    Register(ifstream& in_fp, ofstream& out_fp, System& system);
    void createNewAccount(string id, string pwd, string tel, ofstream& out_fp, System& system); // 회원가입 함수
};

class BikeRegister { // 자전거 등록 클래스로, 자전거 등록 인터페이스를 출력하고 사용자가 자전거 ID와 이름을 입력받아 새로운 자전거를 등록하는 기능을 제공
public:
    BikeRegister(ifstream& in_fp, ofstream& out_fp, System& system);
    void addNewBike(string bikeID, string bikeName, ofstream& out_fp, System& system); // 자전거 등록 함수
};

class BikeRent { // 자전거 대여 클래스로, 자전거 대여 인터페이스를 출력하고 사용자가 대여할 자전거 ID를 입력받아 대여하는 기능을 제공
public:
    BikeRent(ifstream& in_fp, ofstream& out_fp, System& system);
    void rentBikeID(string bikeID, ofstream& out_fp, System& system); // 자전거 대여 함수
};

class Exit { // 종료 클래스로, 종료 인터페이스를 출력하는 기능을 제공
public:
    Exit(ifstream& in_fp, ofstream& out_fp, System& system);
};


#endif 
