#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

void PrintNumber(int number, int ligne) {
    std::string number0[] = {
        " ######\\   ",
        "### __##\\  ",
        "####\\ ## | ",
        "##\\##\\## | ",
        "## \\#### | ",
        "## |\\### | ",
        "\\######  / ",
        " \\______/  "
    };

    std::string number1[] = {
        "  ##\\    ",
        "#### |   ",
        "\\_## |   ",
        "  ## |   ",
        "  ## |   ",
        "  ## |   ",
        "######\\  ",
        "\\______| "
    };

    std::string number2[] = {
        " ######\\   ",
        "##  __##\\  ",
        "\\__/  ## | ",
        " ######  | ",
        "##  ____/  ",
        "## |       ",
        "########\\  ",
        "\\________| "
    };

    std::string number3[] = {
        " ######\\   ",
        "## ___##\\  ",
        "\\_/   ## | ",
        "  ##### /  ",
        "  \\___##\\  ",
        "##\\   ## | ",
        "\\######  | ",
        " \\______/  "
    };

    std::string number4[] = {
        "##\\   ##\\  ",
        "## |  ## | ",
        "## |  ## | ",
        "######## | ",
        "\\_____## | ",
        "      ## | ",
        "      ## | ",
        "      \\__| "
    };

    std::string number5[] = {
            "#######\\   ",
            "##  ____|  ",
            "## |       ",
            "#######\\   ",
            "\\_____##\\  ",
            "##\\   ## | ",
            "\\######  | ",
            " \\______/  "
    };

    std::string number6[] = {
            " ######\\   ",
            "##  __##\\  ",
            "## /  \\__| ",
            "#######\\   ",
            "##  __##\\  ",
            "## /  ## | ",
            " ######  | ",
            " \\______/  "
    };

    std::string number7[] = {
            "########\\  ",
            "\\____##  | ",
            "    ##  /  ",
            "   ##  /   ",
            "  ##  /    ",
            " ##  /     ",
            "##  /      ",
            "\\__/       "
    };

    std::string number8[] = {
            " ######\\   ",
            "##  __##\\  ",
            "## /  ## | ",
            " ######  | ",
            "##  __##<  ",
            "## /  ## | ",
            "\\######  | ",
            " \\______/  "
    };

    std::string number9[] = {
            " ######\\   ",
            "##  __##\\  ",
            "## /  ## | ",
            "\\####### | ",
            " \\____## | ",
            "##\\   ## | ",
            "\\######  | ",
            " \\______/  "
    };

    std::string point[] = {
            "     ",
            "     ",
            "##\\  ",
            "\\__| ",
            "     ",
            "##\\  ",
            "\\__| ",
            "     "
    };

    switch (number) {
    case 0:
        std::cout << number0[ligne];
        break;
    case 1:
        std::cout << number1[ligne];
        break;
    case 2:
        std::cout << number2[ligne];
        break;
    case 3:
        std::cout << number3[ligne];
        break;
    case 4:
        std::cout << number4[ligne];
        break;
    case 5:
        std::cout << number5[ligne];
        break;
    case 6:
        std::cout << number6[ligne];
        break;
    case 7:
        std::cout << number7[ligne];
        break;
    case 8:
        std::cout << number8[ligne];
        break;
    case 9:
        std::cout << number9[ligne];
        break;
    default:
        std::cout << point[ligne];
        break;
    }
}

void PrintDay(int number) {
    switch (number) {
    case 0: //Sunday
        std::cout << "Dimanche";
        break;
    case 1: //Monday
        std::cout << "Lundi";
        break;
    case 2: //Tuesday
        std::cout << "Mardi";
        break;
    case 3: //Wednesday
        std::cout << "Mercredi";
        break;
    case 4: //Thursday
        std::cout << "Jeudi";
        break;
    case 5: //Friday
        std::cout << "Vendredi";
        break;
    case 6: //Saturday
        std::cout << "Samedi";
        break;
    }
}

void PrintMonth(int number) {
    switch (number) {
    case 0: //January
        std::cout << "janvier";
        break;
    case 1: //February
        std::cout << "Fevrier";
        break;
    case 2: //March
        std::cout << "Mars";
        break;
    case 3: //April
        std::cout << "Avril";
        break;
    case 4: //May
        std::cout << "Mai";
        break;
    case 5: //June
        std::cout << "Juin";
        break;
    case 6: //July
        std::cout << "Juillet";
        break;
    case 7: //August
        std::cout << "Aout";
        break;
    case 8: //September
        std::cout << "Septembre";
        break;
    case 9: //October
        std::cout << "Octobre";
        break;
    case 10: //November
        std::cout << "Novembre";
        break;
    case 11: //December
        std::cout << "Decembre";
        break;
    }
}

int main() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

    time_t current_time;
    int previous_minute = -1;
    int current_minute = 0;

    while (true) {
        time(&current_time);
        tm ltm;
        localtime_s(&ltm, &current_time);
        current_minute = ltm.tm_min;

        int hour1 = (ltm.tm_hour) / 10;
        int hour2 = (ltm.tm_hour) % 10;
        int minute1 = (ltm.tm_min) / 10;
        int minute2 = (ltm.tm_min) % 10;

        int day = ltm.tm_wday;
        int monthDay = ltm.tm_mday;
        int month = ltm.tm_mon;
        int year = ltm.tm_year + 1900;

        if (current_minute != previous_minute) {
            system("cls");

            std::cout << "\033[0;31m";
            for (int l = 0; l < 8; l++) {
                for (int c = 0; c < 5; c++) {
                    if (c == 0)
                    {
                        PrintNumber(hour1, l);
                    }
                    else if (c == 1) {
                        PrintNumber(hour2, l);
                    }
                    else if (c == 2) {
                        PrintNumber(99, l);
                    }
                    else if (c == 3) {
                        PrintNumber(minute1, l);
                    }
                    else if (c == 4) {
                        PrintNumber(minute2, l);
                        std::cout << std::endl;
                    }
                }
            }

            PrintDay(day);
            std::cout << " " << monthDay << " ";
            PrintMonth(month);
            std::cout << " " << year << " ";

            previous_minute = current_minute;
        }

        Sleep(100);
    }

    return 0;
}
