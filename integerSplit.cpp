#include<iostream>
#include<cstring>
using namespace std;

const int MAX_NUM = 100;
int n;
int x[MAX_NUM];

void dfs(int sum, int len)
{
	if(sum == n) {
		cout << n << "=" << x[1];
		for(int i = 2; i < len; i++) {
			cout << "+" << x[i];
		}
		cout << endl;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(i >= x[len - 1] && sum + i <= n) {
			x[len] = i;
			dfs(sum + i, len + 1);
			x[len] = 0;
		}
	}
	return ;
}

int main()
{
	while(cin >> n) {
		dfs(0, 1);
	}
	return 0;
}