#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k ;
    cin >> n >> k;

    stack<int> coins;
    
    for (int i{0}; i < n; i++){
        int coin;
        cin >> coin;
        coins.push(coin);
    }

    int count{0};
    int sum{0};
    
    for (int i{0}; i < n; i++){
        int coin = coins.top(); coins.pop();

        if (coin <= k) {
            count += k/coin;
            k = k %= coin;
        }
    }

    cout << count;
}