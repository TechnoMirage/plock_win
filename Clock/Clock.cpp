#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    time_t current_time;
    int previous_minute = -1;

    while (true) {
        time(&current_time);
        tm ltm;
        localtime_s(&ltm, &current_time);

        int current_minute = ltm.tm_min;

        if (current_minute != previous_minute) {
            system("cls");
            cout << ltm.tm_hour << ":" << ltm.tm_min << endl;
            previous_minute = current_minute;
        }

        Sleep(1000);
    }

    return 0;
}
