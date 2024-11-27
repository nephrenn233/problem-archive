#include<bits/stdc++.h>
using i64 = long long;
using PII = std::pair<int, int>;

void solve()
{
    int n, m, k;

	std::cin >> n >> m >> k;

	std::vector<PII> seg(m);
	std::vector<int> a(n + 2, 0);

	for(auto &[l, r] : seg)
	{
		std::cin >> l >> r;
		++a[l], --a[r + 1];
	}

	std::sort(seg.begin(), seg.end());

	std::vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
	int cnt0 = 0;

	for(int i = 1; i <= n; ++i)
	{
		a[i] += a[i - 1];

		cnt0 += (a[i] == 0);
		cnt1[i] = cnt1[i - 1] + (a[i] == 1);
		cnt2[i] = cnt2[i - 1] + (a[i] == 2);
	}	

	// case 1
	int mx1 = 0, mx2 = 0, ans1 = 0;
	for(int i = 0; i < m; ++i)
	{
		auto [l, r] = seg[i];
		int res = cnt1[r] - cnt1[l - 1];
		if(res > mx1)
		{
			mx2 = mx1;
			mx1 = res;
		}
		else if(res > mx2) mx2 = res;
	}
	ans1 = mx1 + mx2;

	int p = 0, ans2 = 0;
	std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
	for(int i = 1; i <= n; ++i)
	{
		while(q.size() && q.top().first < i) q.pop();
		while(p < m && seg[p].first == i) {
            q.push(std::make_pair(seg[p].second, p));
            ++p;
        }

		if(a[i] != 2) continue;

		auto id1 = q.top().second;
        q.pop();

		auto id2 = q.top().second;

		auto [l1, r1] = seg[id1];
		auto [l2, r2] = seg[id2];

		int res = 0;
		res += cnt2[std::min(r1, r2)] - cnt2[std::max(l1, l2) - 1];
		res += cnt1[r1] - cnt1[l1 - 1] + cnt1[r2] - cnt1[l2 - 1];

		ans2 = std::max(ans2, res);
		q.push(std::make_pair(seg[id1].second, id1));
	}

	std::cout << std::max(ans1, ans2) + cnt0 << "\n";
}	

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while(t--) {
        solve();
    }

	return 0;
}