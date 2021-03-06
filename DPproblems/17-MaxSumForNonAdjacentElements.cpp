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
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 1000001;
int mem[MAX], memC[MAX][2];
vector<int> v;
int maxSum(int index) {
	if (index >= sz(v))return 0;
	int& rt = mem[index];
	if (~rt)return rt;
	rt = maxSum(index + 1);
	rt = max(rt, v[index] + maxSum(index + 2));
	return rt;
}

int maxSumCycle(int index,bool takeFirst) {
	if (index >= sz(v))return 0;
	int& rt = memC[index][takeFirst];
	if (~rt)return rt;
	rt = maxSumCycle(index + 1, takeFirst);
	if (index + 1 != sz(v) || !takeFirst)
		rt = max(rt, v[index] + maxSumCycle(index + 2, takeFirst));
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	clr(memC, -1);
	int n; cin >> n;
	v.resize(n);
	for (auto& it : v)cin >> it;
	cout << maxSum(0) << endl;
	cout << max(maxSumCycle(1, 0), maxSumCycle(2, 1) + v[0]) << endl;
}
