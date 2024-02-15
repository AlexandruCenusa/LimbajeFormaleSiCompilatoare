#include <iostream>
#include <cstring>
using namespace std;

//1
char A[3] = { 'A', 'B', 'C' };
char B[3] = { 'x', 'y', 'z' };
char C[3] = { '1', '2', '3' };

//2
char M1[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
char M3[10] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
char M2[10] = { 'x1','y1', 'x2', 'y2', 'x3', 'y3', 'x4', 'y4', 'x5', 'y5'};

string concatenate(string s1, string s2) {
    return s1 + s2;
}

//1
string inverse(string s) {
    const int l = s.length();
    string inverse(l, ' ');
    for (int i = 0; i <= l - 1; ++i) {
        inverse[i] = s[l - 1 - i];
    }
    return inverse;
}

void substitute(string &s, char a, char b) {
    for (int i = 0; i <= s.length() - 1; ++i) {
        if (s[i] == a) {
            s[i] = b;
        }
    }
}

int lungime(string s) {
    return s.length();
}


//2
string extract(string s, int i, int j) {
    string substr;
    for (int x = i; x <= j; ++x) {
        substr += s[x];
    }
    return substr;
}

string repeat(string s, int n) {
    string str;
    while (n) {
        str += s;
        --n;
    }
    return str;
}

    

int main()
{
    string s1 = "ABC";
    string s2 = "123";
    cout << s1 << ' ' << s2 << '\n';

    cout << concatenate(s1, s2) << '\n';
    
    cout << inverse(s1) << '\n';
    
    substitute(s1, 'A', 'S');
    cout << s1 << '\n';

    cout << lungime(s1) << '\n';

    cout << extract(repeat(s1, 5), 3, 7) << '\n';
    return 0;
}
