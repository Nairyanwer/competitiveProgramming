#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };

class MegaFactorialDiv2 {
	const int MOD = 1e9 + 9;
	int mem[1001][101], vis[1001][101];
	vector<int> primes;
	ll countDivisors(int n, int k, int p) {
		if (n == 0)
			return 0;
		if (vis[n][k] == p)
			return mem[n][k];
		vis[n][k] = p;
		if (k == 0) {
			int cnt = 0;
			while (n % p == 0)
				n /= p, cnt++;
			return mem[n][k] = cnt;
		}
		return mem[n][k] = (countDivisors(n - 1, k, p)
				+ countDivisors(n, k - 1, p)) % (MOD - 1);
	}
public:
	MegaFactorialDiv2() {
		memset(vis, 0, sizeof vis);
		for (int i = 2; i < 1000; i++) {
			bool valid = true;
			for (auto &it : primes)
				if (i % it == 0) {
					valid = false;
					break;
				}
			if (valid)
				primes.push_back(i);
		}
	}
	int countDivisors(int n, int k) {
		ll cnt = 1;
		for (auto it : primes)
			cnt = (cnt * (countDivisors(n, k, it) + 1)) % MOD;
		return cnt;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	MegaFactorialDiv2 *obj;
	int answer;
	obj = new MegaFactorialDiv2();
	clock_t startTime = clock();
	answer = obj->countDivisors(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 1;
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 2;
	p2 = 18;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 3;
	p2 = 1392;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100;
	p1 = 2;
	p2 = 321266186;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 77;
	p1 = 11;
	all_right = KawigiEdit_RunTest(5, p0, p1, false, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING






//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
