#include <bits/stdc++.h>
using namespace std;

const int MAX = 131072;

int a[MAX];
int t;
int n, k;

bool fond_sub_sequence(const int &mid) {
    int last = a[0];
    int len = 1;
    
    for (int i = 1; i < n; ++i) {
        if (a[i] - last >= mid) {
            last = a[i];
            ++len;
            
            if (len == k) {
                return true;
            }
        }
    }
    
    return false;
}

int max_distance_sub_sequence() {
    sort(a, a + n);
    int res = -1;
    
    int left = 1;
    int right = a[n - 1];
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        if (fond_sub_sequence(mid)) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return res;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << max_distance_sub_sequence() << endl;
    }
    
    return 0;
}
