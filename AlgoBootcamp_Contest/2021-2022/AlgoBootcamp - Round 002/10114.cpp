#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int month, n;
	double downPayment, loan, d[105];

	while (true) {
		cin >> month >> downPayment >> loan >> n;
		if (month < 0)
			break;

		int m;
		double p;
		while (n--) {
			cin >> m >> p;
			for (int i = m; i <= 100; i++)
				d[i] = p;
		}

		int now = 0;
		double monthlyPayment = loan / month;
		double val = (loan + downPayment) * (1 - d[0]);
		while (val < loan) {
			now++;
			loan -= monthlyPayment;
			val = val * (1 - d[now]);
		}

		cout << now;
		if(now != 1) cout << " months";
		else cout << " month";
		cout << '\n';
	}
}