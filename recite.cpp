#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "VERSION.h"

using namespace std;

#define pause() system("pause")

void speak(string s) {
    ofstream fout;
    fout.open("TMPSPEAK.vbs");
    fout << "CreateObject(\"SAPI.SpVoice\").Speak \"" << s << "\"";
    fout.close();
    system("TMPSPEAK.vbs");
    system("del TMPSPEAK.vbs");
}
int main() {
    string s1, s2, sa;
    int ans = 0, r = 0;
    ifstream fin("test.txt");
    while(fin >> s1) {
        sa += s1 + " ";
    }
    while(getch()!='k')speak(sa);
    fin.close();
    fin.open("test.txt");
    while(fin >> s1) {
        cin >> s2;
        if (s1 == s2) {
            r++;
            cout <<"right!\n";
        }else {
            cout << "wrong!\n";
        }
        ans++;
    }
    printf("%d", r / ans);
    pause();
}