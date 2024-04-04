#include <bits/stdc++.h>
using namespace std;

struct segment {
    int x, y;
    
    segment(int x, int y) : x(x), y(y) {}
    
    bool operator<(const segment &rhs) const {
        return y < rhs.y;
    }
    
    bool operator>(const segment &rhs) const {
        return rhs < *this;
    }
    
    bool operator<=(const segment &rhs) const {
        return !(rhs < *this);
    }
    
    bool operator>=(const segment &rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    int n, res = 0;
    int last = -1;
    priority_queue<segment, vector<segment>, greater<>> pq;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pq.emplace(x, y);
    }
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        if (last < top.x) {
            last = top.y;
            ++res;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
