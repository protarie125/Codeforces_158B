#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto cts = vi(4, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		++cts[x - 1];
	}

	auto ans = cts[3];

	ans += cts[2];
	cts[0] -= cts[2];
	if (cts[0] < 0) {
		cts[0] = 0;
	}

	ans += cts[1] / 2;
	cts[1] %= 2;

	if (1 == cts[1]) {
		ans += 1;
		cts[0] -= 2;
		if (cts[0] < 0) {
			cts[0] = 0;
		}
	}

	ans += cts[0] / 4;
	cts[0] %= 4;
	if (0 < cts[0]) {
		ans += 1;
	}

	cout << ans;

	return 0;
}