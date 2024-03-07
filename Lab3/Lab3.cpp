#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

// Functia care returneaza urmatoarea stare bazata pe starea curenta si input
string aparat(string currentState, char input) {
    if (currentState == "q0") {
        if (input == 'C')
            return "q1";
        else if (input == 'T')
            return "q2";
        else if (input == 'A')
            return "q3";
        else if (input == 'H')
            return "q4";
    }
    else if (currentState == "q1" || currentState == "q2" || currentState == "q3") {
        if (input == 'O')
            return "q4";
    }
    else if (currentState == "q4") {
        if (input == 'O')
            return "q0";
    }
    return currentState;
}

void ex1() {
    string currentState = "q0";

    while (true) {
        if (currentState == "q4") {
            cout << "Bautura este gata!\n\n";
            currentState = "q0";
        }

        cout << "Alegeti bautura (C - cafea, T - ceai, A - cappuccino, H - ciocolata calda):\n";

        char choice;
        cin >> choice;

        currentState = aparat(currentState, choice);

        if (currentState != "q0") {
            cout << "Apasati O pentru a confirma.\n";

            cin >> choice;

            if (choice == 'O') {
                currentState = aparat(currentState, choice);
            }
            else {
                cout << "Selectie invalida.\n";
                break;
            }
        }
        else {
            cout << "Selectie invalida.\n";
            break;
        }
    }
}

bool verifica_regex(const string& text, const string& regexString) {
    regex regexPattern(regexString);
    return regex_match(text, regexPattern);
}


int ex3() {
    string filePath = "C:\\Users\\aleee\\Desktop\\Lab3Ex1\\test.txt";
    //cout << "Introduceti calea catre fisierul text de verificat: ";
    //getline(cin, filePath);

    ifstream file(filePath);
    if (!file) {
        cerr << "Eroare: Nu s-a putut deschide fisierul.\n";
        return 1;
    }

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;

        string clientInfoRegex = "^Client: [A-Za-z]+ [A-Za-z]+$";
        string productDetailsRegex = "^Produs: [A-Za-z]+, Pret: \\d+(\\.\\d+)?, TVA: \\d+(\\.\\d+)?%, Cantitate: \\d+$";

        if (!verifica_regex(line, clientInfoRegex) && !verifica_regex(line, productDetailsRegex)) {
            cout << "Eroare la linia " << lineNumber << ": Formatul nu este valid.\n";
        }
    }

    file.close();
    return 0;
}

int main() {
    //ex1();
    ex3();
    return 0;
}