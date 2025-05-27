#include "Control.h"

void doTask() { // 모든 파일입출력작업, 메뉴입력 및 처리해주는 함수
    ifstream in_fp;
    ofstream out_fp;
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);
    System system; // System 객체 생성
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        in_fp >> menu_level_1 >> menu_level_2;
        switch (menu_level_1) {
        case 1:
            if (menu_level_2 == 1) Register(in_fp, out_fp, system); // 회원가입
            break;
        case 2:
            if (menu_level_2 == 1) Login(in_fp, out_fp, system); // 로그인
            else if (menu_level_2 == 2) Logout(in_fp, out_fp, system); // 로그아웃
            break;
        case 3:
            if (menu_level_2 == 1) BikeRegister(in_fp, out_fp, system); // 자전거 등록
            break;
        case 4:
            if (menu_level_2 == 1) BikeRent(in_fp, out_fp, system); // 자전거 대여
            break;
        case 5:
            if (menu_level_2 == 1) BikeRentLog(in_fp, out_fp, system); // 자전거 대여 리스트
            break;
        case 6:
            if (menu_level_2 == 1) {
                Exit(in_fp, out_fp, system); // 종료
                is_program_exit = 1;
            }
            break;
        }
    }

    in_fp.close();
    out_fp.close();
}

int main() {
    doTask();
    return 0;
}


