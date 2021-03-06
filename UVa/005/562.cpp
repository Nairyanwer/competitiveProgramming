#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int mx = 0;
		for (int i = 0; i < n; i++) { cin >> v[i]; mx += v[i]; }
		vector<vector<int>> dp(n + 1, vector<int>(mx + 1));
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) for (int d = 0; d <= mx; d++)
			if (dp[i][d]) {
				dp[i + 1][d + v[i]] = 1;
				dp[i + 1][abs(d - v[i])] = 1;
			}
		for (int i = 0; i <= mx; i++) if (dp[n][i]) {
			cout << i << endl;
			break;
		}
	}
}