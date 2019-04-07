#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "VERSION.h"

using namespace std;

#define pause() system("pause")

string dir;
struct Words{
    string name;
    string meaning;
    Words() {
        name = "";
        meaning = "";
    }
    bool operator < (Words &b) {
        return name < b.name;
    }
};
vector<Words> wordsList;


int getDir() {
	char tmp_dir[200];  
    GetCurrentDirectory(200,tmp_dir);
    dir = tmp_dir;
    // If didn't get the directory, return 0
    return dir == "";
}

void printTitle(string str = "") {
    cout << APP_NAME << " " << VERSION << endl;
    if (str != "") {
        cout << str << endl;
    }
    cout << "------------------\n";
}

int readFile(const char* path) {
    ifstream fin;
    fin.open(path);
    string s;
    fin >> s;
    fin.close();
    return s != "";
}

inline bool isLetter(char c) {
    return 
        (c >= 'a' && c <= 'z') || 
        (c >= 'A' && c <= 'Z') || 
        c == '(' || 
        c == ')' ||
        c == '.' ;
}

bool isWord(string &s) {
    int n = s.length();
    if (s == "n." ||
        s == "v." ||
        s == "adj." ||
        s == "conj." ||
        s == "prep." ||
        s == "adv." ||
        s == "int." ||
        s == "art." ||
        s == "vi." ||
        s == "vt." ||
        s == "pron." ||
        s == "num." ||
        s == "pl." 
    ) return false;
    for (int i = 0; i < n; i++) {
        if (!isLetter(s[i])) return false;
    }
    return true;
}

int readWords() {
    string stmp;
    Words wtmp;
    bool succeed = 0, wording = 1, first = 1;
    ifstream fin;
    fin.open((dir + "\\Wordlist.txt").c_str());
    while (fin >> stmp) {
        succeed = 1;
        if (stmp == "|") {
            wording = 0;
        } else {
            if (wording) {
                if (!first) {
                    wtmp.name += " " + stmp;
                } else {
                    wtmp.name += stmp;
                    first = false;
                }
            } else {
                if (isWord(stmp)) {
                    wording = 1;
                    wordsList.push_back(wtmp);
                    wtmp.name = "";
                    wtmp.meaning = "";
                    wtmp.name += stmp;
                } else {
                    wtmp.meaning += " " + stmp;
                }
            }
        }
    }
    wordsList.push_back(wtmp);
    if (succeed) {
        sort(wordsList.begin(), wordsList.end());
    }
    return succeed;
}

int selfCheck() {
    // Return 1 if nothing is wrong.
    printTitle("Self Check");
    // Get the current directory.
    if (getDir()) {  
        cout << "[Error] Can't get the directory.\n";
        return 0;
    } else {
        cout << "[OK] Directory: " << dir << endl;
    }
    // read the words list
    if (readWords() == 1) {
        cout << "[OK] Word Reading Successful\n";
    } else {
        cout << "[Warning] You should add a word in WordList.txt first.\n";
        return 0;
    }
    return 1;
}

void printWords() {
    int n = wordsList.size();
    for (int i = 0; i < n; i++) {
        cout << wordsList[i].name << " ";
        cout << wordsList[i].meaning << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    if (!selfCheck()) {
        pause();
        return 0;
    }
    system("cls");
    printTitle("Word List");
    cout << "Hello! Here is your words to practice:\n";
    printWords();
    cout << "Imput \"e\" to get into reciting mode, and \"c\" to get into memory model";
    char c;
    while(c = getch(), c != 'e' && c != 'c');
    system("cls");
    if (c == 'e') {
        while (1) {
            int randomNum = rand() % wordsList.size();
        }
    } else {
        while (1) {
            int randomNum = rand() % wordsList.size();
            cout << wordsList[randomNum].name;
            getch();
            cout << wordsList[randomNum].meaning << endl;
            cout << endl;
            //cout << "Have you remembered it? (y/n):";
            //while(c = getch(), c != 'y' && c != 'n');
        }
    }
    pause();
    return 0;
}
