#include <iostream>
using namespace std;

int balik(int x) {
    if (x == 0) return 0;

    bool negatif = (x < 0);
    if (negatif) x = -x;

    int hasil = 0;
    while (x > 0) {
        int digit = x % 10;
        hasil = hasil * 10 + digit;
        x /= 10;
    }

    return negatif ? -hasil : hasil;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += balik(arr[i]);
        } else {
            sum += arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}
