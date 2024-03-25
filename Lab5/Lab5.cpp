#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


//---------------EX2------------------
class Moore {
private:
    unordered_map<string, unordered_map<char, string>> tranzitii;
    unordered_map<string, string> outputs;
    string stare_curenta;

public:
    Moore(unordered_map<string, unordered_map<char, string>> trans, unordered_map<string, string> outs, string start)
        : tranzitii(trans), outputs(outs), stare_curenta(start) {}

    void next(char x) {
        if (tranzitii.count(stare_curenta) && tranzitii[stare_curenta].count(x)) {
            stare_curenta = tranzitii[stare_curenta][x];
        }
    }

    string output() const {
        auto it = outputs.find(stare_curenta);
        if (it != outputs.end()) {
            return it->second;
        }
        return "";
    }
};

void ex2() {
    unordered_map<string, unordered_map<char, string>> tranzitii = {
    {"S1", {{'A', "S1"}, {'B', "S2"}}},
    {"S2", {{'A', "S1"}, {'B', "S2"}}}
    };

    unordered_map<string, string> outputs = {
        {"S1", "O1"},
        {"S2", "O2"}
    };

    string stare_inceput = "S1";
    Moore moore(tranzitii, outputs, stare_inceput);

    string sir;
    cout << "Introduceti cuvant: ";
    cin >> sir;
    cout << "Output: ";
    for (char x : sir) {
        moore.next(x);
        cout << moore.output() << " ";
    }
    cout << endl;

}

//-------------EX3--------------------
class Mealy {
private:
    unordered_map<string, unordered_map<char, pair<string, string>>> tranzitii;
    string stare_curenta;

public:
    Mealy(unordered_map<string, unordered_map<char, pair<string, string>>> tranzitii, string start)
        : tranzitii(tranzitii), stare_curenta(start) {}

    pair<string, string> next(char symbol) {
        if (tranzitii.count(stare_curenta) && tranzitii[stare_curenta].count(symbol)) {
            return tranzitii[stare_curenta][symbol];
        }
        return { "", "" };
    }

    void afiseaza_output(const string& input_sequence) {
        cout << "Output: ";
        for (char x : input_sequence) {
            pair<string, string> result = next(x);
            stare_curenta = result.first;
            cout << result.second << " ";
        }
        cout << endl;
    }
};

void ex3() {
    unordered_map<string, unordered_map<char, pair<string, string>>> tranzitii = {
        {"Q1", {{'X', {"Q2", "O1"}}, {'Y', {"Q1", "O1"}}}},
        {"Q2", {{'X', {"Q1", "O2"}}, {'Y', {"Q2", "O2"}}}}
    };

    string stare_inceput = "Q1";
    Mealy mealy(tranzitii, stare_inceput);

    string sir;
    cout << "Introduceti cuvant: ";
    cin >> sir;
    mealy.afiseaza_output(sir);
}

int main() {
    cout << "Moore\n";
    ex2();
    cout << "\nMealy\n";
    ex3();
    return 0;
}
