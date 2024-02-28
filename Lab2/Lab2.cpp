#include <iostream>
#include <string>
#include <vector>

using namespace std;

//---------EX I------------
int x[6], n = 5;
char E[3] = { '0', '1', '2' };

void afisare(int k)
{
    for (int j = 1; j <= k; j++)
        cout << E[x[j]] << " ";
    cout << endl;
}

bool palindrom(int k) {
    int i = 1, j = k;
    while (i < j) {
        if (x[i] != x[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

void back(int k) {
    if (k > n) {
        return;
    }
    for (int i = 0; i < strlen(E); ++i)
    {
        x[k] = i;
        if (palindrom(k)) {
            afisare(k);
        }
        back(k + 1);
    }
}

//---------EX II------------


//---------EX III------------


//---------EX IV------------
//Ex IV.1
int sol41[100];
char abc41[2] = { 'a', 'b' };

bool valid41(int k) {
    return true;
}
bool solutie41(int k) {
    bool hasA = false;
    bool hasB = false;
    for (int i = 0; i <= k; ++i) {
        if (abc41[sol41[i]] == 'a' && hasA == false) {
            hasA = true;
        }
        if (abc41[sol41[i]] == 'b' && hasB == false) {
            hasB = true;
        }
    }
    if (k < 10 && hasA == true && hasB == true)
        return true;
    return false;
}  

void afis41(int k) {
    for (int j = 0; j <= k; j++)
        cout << abc41[sol41[j]] << " ";
    cout << endl;
}
void back41(int k) {
    for (int i = 0; i < strlen(abc41); ++i)
    {
        sol41[k] = i;
        if (valid41(k))
            if (solutie41(k)) {
                afis41(k);
                back41(k + 1);
            }
    }
}


//Ex IV.2
int sol42[100];
char abc42[2] = { '0', '1' };

bool valid42(int k) {
    return true;
}
bool solutie42(int k) {
    return k == 3;
}

void afis42(int k) {
    for (int j = 1; j <= k; j++)
        cout << sol42[j] << " ";
    cout << endl;
}
void back42(int k) {
    for (int i = 0; i < strlen(abc42); ++i)
    {
        sol42[k] = i;
        if (valid42(k))
            if (solutie42(k)) {
                afis42(k);
            }
            else {
                back42(k + 1);
            }
    }
}

//Ex IV.3 - Identic cu Ex I

//Ex IV.4 - Identic cu IV.2 insa se schimba lungimea solutiei cu numere pare.

//Ex IV.5
int sol45[1000];
char abc45[2] = { 'a', 'b' };

bool valid45(int k) {
    return true;
}

bool solutie45(int k) {
    if (k < 3 && sol45[0] == sol45[k])
        return true;
    return false;
}

void afis45(int k) {
    for (int j = 0; j <= k; j++)
        cout << abc45[sol45[j]] << " ";
    cout << endl;
}

void back45(int k) {
    if (k >= 10) return;
    for (int i = 0; i < 2; ++i) {
        sol45[k] = i;
        if (valid45(k)) {
            if (solutie45(k)) {
                afis45(k);
            }
            back45(k + 1);
        }
    }
}

int main() {
  //apel catre back**() pentru fiecare exercitiu.
    return 0;
}
