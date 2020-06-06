#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto start = chrono::high_resolution_clock::now();

	int N = 501;
	vector <vector<ll>> grid(N, vector<ll>(N, 0));
	vector <vector<ll>> pref(N, vector<ll>(N, 0));
	vector <vector<ll>> vorz(N, vector<ll>(N, 0));
	for (int i = 1; i < N; ++i){
		for (int j = 1; j < N; ++j){
			cin >> grid[i][j];
		}
	}
	/*
	for (int i = 1; i < N; ++i){
		cout << "{";
		for (int j = 1; j < N; ++j){
			cout << grid[i][j] << ", ";
		}
		cout << "},\n";
	}
	*/
	ll iterations = 0;
	for (int i = 1; i < N; ++i){
		for (int j = 1; j < N; ++j){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + grid[i][j];
			vorz[i][j] = vorz[i-1][j] + vorz[i][j-1] - vorz[i-1][j-1];
			if (grid[i][j] == -1){
				vorz[i][j]++;
			}
		}
	}
	ll ans = 0;
	for (int si = 1; si < N; ++si){
		cout << si << endl << ans << endl;
		for (int sj = 1; sj < N; ++sj){
			ll beg = pref[si-1][sj-1];
			for (int ei = si; ei < N; ++ei){
				for (int ej = sj; ej < N; ++ej){
					ll cur = pref[ei][ej] - pref[si-1][ej] - pref[ei][sj-1] + beg;
					if (cur % 13 == 0){
						ans += (ll) cur * (ll) (pow(-1, (vorz[ei][ej] - vorz[si-1][ej] - vorz[ei][sj-1] + vorz[si-1][sj-1])));
					}
					iterations++;
				}
			}
			
		}
	}
	cout << ans << endl;

    auto stop = chrono::high_resolution_clock::now(); 

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 

	cout <<"time: " <<duration.count() << "ms" << endl; 
	cout << "iterations: " << iterations << endl;


	return 0;
}

