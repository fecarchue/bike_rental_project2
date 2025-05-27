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

// 클래스 전방 선언
class User;
class Manager;
class Member;
class Bike;
class BikeRentCollection;
class System;

// Entity Classes
class Bike { // 자전거 클래스로, 자전거 ID와 이름을 관리
private:
    string BikeID;  // 자전거 ID
    string BikeName; // 자전거 이름

public:
    Bike(string id, string name); // 생성자, 자전거 ID와 이름을 초기화
    pair<string, string> getBikeDetail();  // 자전거 ID와 이름을 반환하는 함수, pair로 반환해 first, second로 각각 id와 name 반환
};

class BikeRentCollection { // 자전거 대여 목록을 관리하는 클래스로, 대여한 자전거 목록을 vector로 관리하고, 대여한 자전거를 순회할 수 있는 기능을 제공
private:
    vector<Bike*> rentedBike;   //member 대여 자전거 목록 vector로 관리
    int currentIndex; // 현재 자전거 인덱스, getNext() 호출시 다음 자전거를 반환하기 위해 사용

public:
    BikeRentCollection(); // 생성자, currentIndex를 0으로 초기화
    void addNewBikeRent(Bike* bike); // 자전거를 대여 목록에 추가하는 함수
    Bike* findFirst(); // 대여한 자전거 중 첫 번째 자전거를 반환
    Bike* getNext(); // 다음 자전거를 반환
};

class User { // 사용자 클래스로, 인증 상태를 관리하고, ID와 비밀번호를 확인하는 기능을 제공
protected:
    bool isAuthenticated; // 인증 상태를 나타내는 변수
public:
    User();
    virtual ~User();
    void authenticateUser(); // 인증 상태를 true로 설정
    void deauthenticateUser(); // 인증 상태를 false로 설정
    bool authenticatedStatus(); // 인증 상태를 반환하는 함수, 로그인되어있는지 확인

    virtual string getUserID() = 0; // ID를 반환하는 함수,virtual로 선언, logout시 manager, member 양쪽에서 호출됨
    virtual bool checkPassword(string id, string pwd) = 0; // ID와 비밀번호를 확인하는 함수, virtual로 선언, login시 manager, member 양쪽에서 호출됨
    virtual bool isMember() = 0;    // member인지 확인하는 함수(0이면 admin)
};

class Manager : public User { // 관리자 클래스로, 관리자 ID와 비밀번호를 관리하며, User 클래스를 상속받아 virtual 함수를 구현
private:
    string managerID; // 관리자 ID
    string managerPWD; // 관리자 비밀번호

public:
    Manager(string id, string pwd);
    string getManagerID(); // 관리자 ID 반환
    string getManagerPWD(); // 관리자 비밀번호 반환

    // Virtual 함수들 구현
    string getUserID() override; // manager ID 반환
    bool checkPassword(string id, string pwd) override; // manager ID와 비밀번호 확인
    bool isMember() override; // manager는 member가 아니므로 false 반환
};

class Member : public User { // 회원 클래스로, 회원 ID, 비밀번호, 전화번호를 관리하며, User 클래스를 상속받아 virtual 함수를 구현
private:
    string memberID; // 회원 ID
    string memberPWD; // 회원 비밀번호
    string memberTEL; // 회원 전화번호
    BikeRentCollection* rentedBikeCollection; // 대여한 자전거 목록을 관리하는 BikeRentCollection 포인터

public:
    Member(string id, string pwd, string tel); // 생성자
    ~Member(); // 소멸자에서 대여한 자전거 목록 객체 삭제
    BikeRentCollection* getRentList(); // 대여한 자전거 목록을 반환하는 함수, 자전거 대여 리스트 조회시 사용
    BikeRentCollection* getBikeCollection(); // 대여한 자전거 목록을 반환하는 함수, 자전거 대여시 사용
    string getUserID() override; // member ID 반환
    bool checkPassword(string id, string pwd) override; // member ID와 비밀번호 확인
    bool isMember() override; // member는 member이므로 true 반환
};

class System { // 시스템 클래스로, 사용자와 자전거 데이터를 관리하며, 사용자 인증 및 자전거 등록/대여 기능을 제공
private:
    User* currentUser_ptr; //current user도 System 내부에서 관리
    vector<User*> userList; // user data를 System 내부에서 관리
    vector<Bike*> bikeList;  //bike data도 System 내부에서 관리

public:
    System(); // 기본 admin 계정 생성 포함
    ~System(); // 소멸자에서 user 및 bike data 삭제
    void setCurrentUser(User* user); // 현재 로그인된 user 설정, login시 사용
    User* getCurrentUser(); // 현재 로그인된 user 반환, logout, bikeRentLog시 사용
    void createMember(string id, string pwd, string tel); // userList에 새로운 member 추가, 회원가입시 사용
    User* findUserByIDPWD(string id, string pwd); // userList에서 id와 pwd로 로그인 확인
    void addBike(string bikeID, string bikeName); // 자전거 등록 함수, 자전거등록시 사용
    Bike* findBikeByID(string bikeID); // bikeList에서 bikeID로 자전거 찾기, 자전거대여시 사용
};

#endif // SYSTEM_H