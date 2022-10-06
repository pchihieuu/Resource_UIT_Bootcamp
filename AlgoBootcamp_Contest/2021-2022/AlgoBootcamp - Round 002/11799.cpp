#include <bits/stdc++.h>

using namespace std;
int main() {
	int t, n, Case = 0;
	cin >> t;
	while(t--) {
		cin >> n;
		int max = 0, c;
		while(n--) {
			cin >> c;
			if(max < c)
				max = c;
		}
		cout << "Case " << ++Case << ": " << max << endl;
	}
    return 0;
}