#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 100;
int n, k;
int dp[maxn][maxn];
int x[maxn];

//输出最大拆分方案数 
int DP()
{
	//先解决第一行和第一列的边界情况 
	for(int j = 1; j <= k; j++) {
		dp[1][j] = 1;
	}
	for(int i = 1;i <= n;i++) {
		dp[i][1] = 1;
	}
	//再解决常规情况 
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= k; j++) {
			if(j > i){
				dp[i][j] = dp[i][i];
			} else if (j == i) {
				dp[i][j] = dp[i][j - 1] + 1;
			} else if (j < i) {
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];
			}
		}
	}
	return dp[n][k];
}

//输出具体拆分方案 
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
	for(int i = 1; i <= k; i++) {
		if(i >= x[len - 1] && sum + i <= n) {
			x[len] = i;
			dfs(sum + i, len + 1);
			x[len] = 0;
		}
	}
	return ;
}

void getInput()
{
	string s;
	int n;
	int x[15] = {0};
	cin >> n;
	if (n <= 0) {
		printf("NO");
		return;
	}
	cin.ignore();
	cin >> s;
	for (int i = 0; i < n; ++i) {
		x[i] = s[i * 2]; 
	}
	//for(int i = 0; i < n; i++) {
//		getline(cin,s);
		//cout << s <<endl;
//	}
}

void candy(int n, int[] x)
{
	int sum = 0;
	int xor = 0;
	int min = 0;
	for (int i = 0; i < n; ++i) {
		xor ^= x[i];
		sum += x[i];
		min = (min > x[i]) ? x[i] : min;
	}
	if (xor != 0) {
		printf("NO");
	} else {
		printf("%d", sum - min);
	}
}

int main()
{
	while(scanf("%d%d", &n, &k) != EOF) {
		memset(dp, 0, sizeof(0));
		cout << "拆分总数为：" << DP() << endl;
		dfs(0, 1);
	}
	return 0;
}