#include "Control.h"

void doTask() { // ��� ����������۾�, �޴��Է� �� ó�����ִ� �Լ�
    ifstream in_fp;
    ofstream out_fp;
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);
    System system; // System ��ü ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        in_fp >> menu_level_1 >> menu_level_2;
        switch (menu_level_1) {
        case 1:
            if (menu_level_2 == 1) Register(in_fp, out_fp, system); // ȸ������
            break;
        case 2:
            if (menu_level_2 == 1) Login(in_fp, out_fp, system); // �α���
            else if (menu_level_2 == 2) Logout(in_fp, out_fp, system); // �α׾ƿ�
            break;
        case 3:
            if (menu_level_2 == 1) BikeRegister(in_fp, out_fp, system); // ������ ���
            break;
        case 4:
            if (menu_level_2 == 1) BikeRent(in_fp, out_fp, system); // ������ �뿩
            break;
        case 5:
            if (menu_level_2 == 1) BikeRentLog(in_fp, out_fp, system); // ������ �뿩 ����Ʈ
            break;
        case 6:
            if (menu_level_2 == 1) {
                Exit(in_fp, out_fp, system); // ����
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


