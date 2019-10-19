#include <iostream>
#include <set>
using namespace std;

void standings(int n)
{
    if (n == 1) {
        cout << 1 << " " << 1;
        return;
    }
    set<int> factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.insert(i);
            if (i * i != n) {
                factors.insert(n / i);
            }
        }
    }
    cout << factors.size();
    for (auto iter = factors.begin(); iter != factors.end(); ++iter) {
        cout << " " << *iter;
    }
}

int main()
{
    int n;
    while (cin >> n) {
        if (n <= 0) {
            return 0;
        }
        standings(n);
    }
    return 0;
}