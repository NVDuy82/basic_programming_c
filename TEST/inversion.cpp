#include <bits/stdc++.h>
using namespace std;

const long mod = 10e9 + 7;
const long MAX = 10e6 + 1;

int n;
int a[MAX];
long res = 0;

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int l, int mid, int r) {
    vector x(a + l, a + mid + 1);
    vector y(a + mid + 1, a + r + 1);
    int i = 0;
    int j = 0;
    
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[l] = x[i];
            ++i;
            ++l;
        } else {
            res += (long)x.size() - i;
            if (res >= mod) {
                res %= mod;
            }
            a[l] = y[j];
            ++j;
            ++l;
        }
    }
    while (i < x.size()) {
        a[l] = x[i];
        ++i;
        ++l;
    }
    while (j < y.size()) {
        a[l] = y[j];
        ++j;
        ++l;
    }
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    input();
    merge_sort(0, n - 1);
    cout << res << endl;
    
    return 0;
}
