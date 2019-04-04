#include <bits/stdc++.h>
#include "VERSION.h"

using namespace std;

#define PAUSE() system("pause")

void PrintTitle(string str = "") {
    cout << APP_NAME << " " << VERSION << endl;
    if (str != "") {
        cout << str << endl;
    }
    cout << "------------------\n";
}

int main() {
    PrintTitle();
    PAUSE();
    return 0;
}
