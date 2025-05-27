#include "System.h"

// ----- Bike -----
Bike::Bike(string id, string name) : BikeID(id), BikeName(name) {} 
pair<string, string> Bike::getBikeDetail() {
    return make_pair(BikeID, BikeName);
}

// ----- BikeRentCollection -----
BikeRentCollection::BikeRentCollection() : currentIndex(0) {}
void BikeRentCollection::addNewBikeRent(Bike* bike) {
    if (bike) rentedBike.push_back(bike);
}
Bike* BikeRentCollection::findFirst() { // 대여한 자전거 중 첫 번째 자전거를 반환하는 함수
    currentIndex = 0;
    return rentedBike.empty() ? nullptr : rentedBike[0];
}
Bike* BikeRentCollection::getNext() { // 다음 자전거를 반환하는 함수
    currentIndex++;
    return (currentIndex < rentedBike.size()) ? rentedBike[currentIndex] : nullptr; // 다음 자전거가 없으면 nullptr 반환
}

// ----- User -----
User::User() : isAuthenticated(false) {}
User::~User() {}
void User::authenticateUser() { isAuthenticated = true; }
void User::deauthenticateUser() { isAuthenticated = false; }
bool User::authenticatedStatus() { return isAuthenticated; }

// ----- Manager -----
Manager::Manager(string id, string pwd) : managerID(id), managerPWD(pwd) {}
string Manager::getManagerID() { return managerID; }
string Manager::getManagerPWD() { return managerPWD; }
string Manager::getUserID() { return managerID; }
bool Manager::checkPassword(string id, string pwd) {
    return id == managerID && pwd == managerPWD;
}
bool Manager::isMember() { return false; }

// ----- Member -----
Member::Member(string id, string pwd, string tel) : memberID(id), memberPWD(pwd), memberTEL(tel) {
    rentedBikeCollection = new BikeRentCollection();
}
Member::~Member() {
    delete rentedBikeCollection;
}
BikeRentCollection* Member::getRentList() { return rentedBikeCollection; }
BikeRentCollection* Member::getBikeCollection() { return rentedBikeCollection; }
string Member::getUserID() { return memberID; }
bool Member::checkPassword(string id, string pwd) {
    return id == memberID && pwd == memberPWD;
}
bool Member::isMember() { return true; }

// ----- System -----
System::System() : currentUser_ptr(nullptr) {
    Manager* admin = new Manager("admin", "admin");
    userList.push_back(admin);
}
System::~System() {
    for (User* user : userList) delete user;
    for (Bike* bike : bikeList) delete bike;
}
void System::setCurrentUser(User* user) { currentUser_ptr = user; }
User* System::getCurrentUser() { return currentUser_ptr; }
void System::createMember(string id, string pwd, string tel) {
    Member* newMember = new Member(id, pwd, tel);
    userList.push_back(newMember);
}
User* System::findUserByIDPWD(string id, string pwd) { 
    for (User* user : userList) {
        if (user->checkPassword(id, pwd)) return user;
    }
    return nullptr;
}
void System::addBike(string bikeID, string bikeName) { // 자전거 등록 함수
    Bike* newBike = new Bike(bikeID, bikeName);
    bikeList.push_back(newBike);
}
Bike* System::findBikeByID(string bikeID) { // 자전거 ID로 자전거 찾기
    for (Bike* bike : bikeList) {
        if (bike->getBikeDetail().first == bikeID) return bike;
    }
    return nullptr;
}