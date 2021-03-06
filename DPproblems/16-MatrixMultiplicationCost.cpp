#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 101;
int mem[MAX][MAX];
vector<pair<int, int>> matrices;
int matrixMultiplicationCost(int left, int right) {
	if (left >= right)return 0;
	int& rt = mem[left][right];
	if (~rt)return rt;
	rt = oo;
	for (int i = left; i < right; i++) {
		rt = min(rt, matrixMultiplicationCost(left, i) + matrixMultiplicationCost(i + 1, right)
			+ matrices[left].first * matrices[i].second * matrices[right].second);
	}
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		clr(mem, -1);
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& it : v)cin >> it;
		matrices.clear();
		for (int i = 1; i < n; i++)
			matrices.emplace_back(v[i - 1], v[i]);
		cout << matrixMultiplicationCost(0, sz(matrices) - 1) << endl;
	}
}
