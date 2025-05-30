#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "System.h"

// Boundary Classes - UI 기능 제공
class LogoutUI { // 로그아웃 UI 클래스로, 로그아웃 인터페이스를 출력하는 기능을 제공
public:
    void startInterface(ofstream& out_fp);
};

class BikeRentLogUI { // 자전거 대여 리스트 UI 클래스
public:
    void startInterface(ofstream& out_fp);
};

class LoginUI { // 로그인 UI 클래스
public:
    void startInterface(ofstream& out_fp);
    pair<string, string> inputLogin(ifstream& in_fp); // 로그인 정보 입력 함수
};

class RegisterUI { // 회원가입 UI 클래스
public:
    void startInterface(ofstream& out_fp);
    tuple<string, string, string> createNewAccount(ifstream& in_fp); // 회원가입 정보 입력 함수
};

class BikeRegisterUI { // 자전거 등록 UI 클래스
public:
    void startInterface(ofstream& out_fp);
    pair<string, string> addNewBike(ifstream& in_fp); // 자전거 등록 정보 입력 함수
};

class BikeRentUI { // 자전거 대여 UI 클래스
public:
    void startInterface(ofstream& out_fp);
    string rentBikeID(ifstream& in_fp); // 자전거 대여 ID 입력 함수
};

class ExitUI { // 종료 UI 클래스
public:
    void startInterface(ofstream& out_fp);
};

#endif 
