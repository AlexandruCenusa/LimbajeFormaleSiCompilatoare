#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-------------EX1----------------
char schimbareStare(char currentState, char input) {
    if (currentState == 'A') {
        if (input == '0')
            return 'B';
        else if (input == '1')
            return 'A';
    }
    else if (currentState == 'B') {
        if (input == '1') 
            return 'B';
        else if (input == '0')
            return 'A';
    }
    return currentState;
}

void ex1() {
    string stringuri[] = { "010", "110", "1001", "0" };
    char stareCurenta;

    for (int i = 0; i <= stringuri->length(); ++i) {
        stareCurenta = 'A';
        for (char cifra : stringuri[i]) {
            stareCurenta = schimbareStare(stareCurenta, cifra);
        }
        cout << stringuri[i] << ": " << stareCurenta << endl;
    }
}


//-------------EX2----------------
int locuriLibere = 10;
int locuriParcare[10] = {0};

void cerere_sofer(int loc, char input) {
    if (input == 'P') {
        if (locuriLibere > 0) {
            for (int i = 0; i < 10; ++i) {
                if (locuriParcare[i] == 0) {
                    locuriParcare[i] = 1;
                    locuriLibere--;
                    cout << "Locul " << i + 1 << " s-a ocupat.\n";
                    break;
                }
            }
        }
        else {
            cout << "Parcare plina";
        }
       
    }
    else if (input == 'L') {
        if (loc >= 1 && loc <= 10 && locuriParcare[loc - 1] == 1) {
            locuriParcare[loc - 1] = 0;
            locuriLibere++;
            cout << "Locul " << loc << " a fost ocupat.\n";
        }
        else {
            cout << "Locul " << loc << " este deja liber\n";
        }
    }
}

void status_parcare() {
    if (locuriLibere == 10) {
        cout << "Starea parcarii: Parcare goala\n";
    }
    else if (locuriLibere == 0) {
        cout << "Starea parcarii: Parcare plina\n";
    }
    cout << "Locuri libere: " << locuriLibere << '\n';
}

void ex2() {
    int loc;
    while (true) {
        char input;
        cout << "\n(P - parcare | L - plecare) : \n-> ";
        cin >> input;
        if (input == 'P') {
            cerere_sofer(0, input);
        }
        else if (input == 'L') {
            cout << "Introduceti nr locului: ";
            cin >> loc;
            cerere_sofer(loc, input);
        }
        else {
            cout << "Optiune invalida.\n";
        }
        status_parcare();
    }
}

//-------------EX3----------------
class NFA {
private:
    vector<vector<vector<int>>> tranzitii;
    int stare_accept;

public:
    NFA(int num_states) : tranzitii(num_states, vector<vector<int>>(26)) {}

    void adaugare_tranzitie(int from, int to, char symbol) {
        tranzitii[from][symbol - 'a'].push_back(to);
    }

    void adaugare_stare_accept(int stare) {
        stare_accept = stare;
    }

    bool verifica(const string& str) {
        vector<int> current_states = { 0 };

        for (char c : str) {
            vector<int> next_states;
            for (int state : current_states) {
                for (int next_state : tranzitii[state][c - 'a']) {
                    next_states.push_back(next_state);
                }
            }
            current_states = next_states;
        }

        for (int stare : current_states) {
            if (stare == stare_accept) {
                return true;
            }
        }
        return false;
    }
};

void ex3() {
    NFA nfa(4);

    nfa.adaugare_tranzitie(0, 2, 'a');
    nfa.adaugare_tranzitie(0, 3, 'b');
    nfa.adaugare_tranzitie(2, 1, 'b');
    nfa.adaugare_tranzitie(2, 2, 'a');
    nfa.adaugare_tranzitie(3, 3, 'a');
    nfa.adaugare_tranzitie(3, 1, 'b');

    nfa.adaugare_stare_accept(1);

    string input;
    while (true) {
        cout << "Introduceti un sir: ";
        cin >> input;

        cout << "Sirul \"" << input << "\" este ";
        if (nfa.verifica(input)) {
            cout << "acceptat." << endl;
        }
        else {
            cout << "respins." << endl;
        }
    }
}

    
int main() {
    //ex1();
   // ex2();
   ex3();
    return 0;
}
