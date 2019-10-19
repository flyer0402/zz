/**
将2到n的整数写下来
此时表中最小的数字是2，所以2是素数，将所有2的倍数划去
这时表中剩下的最小数字是3，所以3是素数，接着将所有3的倍数划去
依此类推，如果表中剩余的最小数是m，则m是素数，此时将所有m的倍数划去，直到最后
 */
#include <iostream>
#include <bitset>

using namespace std;

const int MAX_N = 100000001;

void primeNumber(int n)
{
    bitset<MAX_N> isPrime;
    isPrime.set();
    isPrime.set(0, 0);
    isPrime.set(1, 0);
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i] == 1) {
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int primeCounts = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (isPrime[i] == 1 && isPrime[i + 2] == 1) {
            primeCounts++;
        }
    }
    printf("%d\n", primeCounts);
}

int main()
{
    int maxNum = 0;
    while (cin >> maxNum) {
        primeNumber(maxNum);
    }
    return 0;
}