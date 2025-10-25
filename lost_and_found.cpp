#include <bits/stdc++.h>
using namespace std;

bool isVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string balikString(const string& str) {
    string reversed;
    for(int i = str.size() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

string encodePassword(const string& input) {
    string password;
    
    int asciiVal = static_cast<unsigned char>(input[0]);
    string asciiStr = to_string(asciiVal);
    
    for (char c : input) if (!isVocal(c)) password.push_back(c);
    password = balikString(password);

    int L = (int)password.size();
    int pos = (L + 1) / 2; // ceil(L/2)
    password = password.substr(0, pos) + asciiStr + password.substr(pos);
    return password;
}

string decodePassword(const string& password) {
    string pecahan;
    int asciiInt = 0;
    int n = password.size();
    int i = 0;

    while (i < n && !isdigit(password[i])) {
        pecahan.push_back(password[i]);
        i++;
    }
    while (i < n && isdigit(password[i])) {
        asciiInt = asciiInt * 10 + (password[i] - '0');
        i++;
    }
    while (i < n) {
        pecahan.push_back(password[i]);
        i++;
    }
    pecahan = balikString(pecahan);
    char asciiChar = static_cast<char>(asciiInt);

    if ( pecahan[0] == asciiChar ) {
        pecahan = pecahan;
    } else {
        pecahan = asciiChar + pecahan;
    }
    return pecahan;
}

int main() {
    string encode, decode;
    cout<<"Encode kata awal: ";
    cin>>encode;
    cout<<"Decode Password: ";
    cin>>decode;

    cout <<"Hasil encode kata :"<<encode<<" --> "<< encodePassword(encode) << endl;

    cout <<"Hasil Decode password :"<<decode<<" --> "<< decodePassword(decode) << endl;

    return 0;
}