#include <iostream>
#include <stdio.h>

using namespace std;

int n = 0;
int x[20];

void candy()
{
	int Xor = x[0];
    int sum = Xor;
    int min = Xor;
	for (int i = 1; i < n; ++i) {
		Xor ^= x[i];
		sum += x[i];
        min = (min > x[i]) ? x[i] : min;
	}
	if (Xor != 0) {
		printf("NO");
	} else {
		printf("%d", sum - min);
	}
}

int main()
{
    string sn;
    string sval;
	getline(cin, sn);
    n = stoi(sn);
	if (n <= 0) {
		printf("NO");
		return 0;
	}
	getline(cin, sval);
    string sub_str;
    int weight = 0;
    for (int i = 0; i < n; i++) {
        sub_str = sval.substr(0, sval.find(' '));
        x[i] = stoi(sub_str);
        sval.erase(0, sval.find(' ') + 1);
    }
    candy();
    return 0;
}