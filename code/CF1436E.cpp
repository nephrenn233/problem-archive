#include<bits/stdc++.h>
using i64 = long long;

struct presidentTree {
	struct node {
		int ls, rs, val;
		node() : ls(0), rs(0), val(0) {}
	};
	std::vector<node> tr;
	std::vector<int> rt;
	int n, idx;

	presidentTree(int _n) : n(_n) {
		idx = 0;
		tr.resize((n + 1) << 5);
		rt.resize(n + 1);
	}

	int clone(int u) {
		tr[++idx] = tr[u];
		return idx;
	}

	void push_up(int u) {
		tr[u].val = std::min(tr[tr[u].ls].val, tr[tr[u].rs].val);
	}

	int modify(int u, int l, int r, int qp, int k) {
		u = clone(u);
		if (l == r) {
			tr[u].val = k;
			return u;
		}
		int mid = (l + r) / 2;
		if (qp <= mid) tr[u].ls = modify(tr[u].ls, l, mid, qp, k);
		else tr[u].rs = modify(tr[u].rs, mid + 1, r, qp, k);
		push_up(u);
		return u;
	}

	int query(int u, int l, int r, int x) {
		if (l == r) {
			return l;
		}
		int t = tr[tr[u].ls].val, mid = (l + r) / 2;
		if (t < x) return query(tr[u].ls, l, mid, x);
		else return query(tr[u].rs, mid + 1, r, x);
	}
};

void solve() {
	int n;
	std::cin >> n;
	
	int up = n + 3;
	std::vector<std::vector<int>> b(up + 1);
	for (int i = 1; i <= up; ++i) {
		b[i].push_back(0);
	}
	
	std::vector<int> a(n + 1, 0);
	presidentTree tr(up);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		b[a[i]].push_back(i);
		tr.rt[i] = tr.modify(tr.rt[i - 1], 1, up, a[i], i);
	}

	for (int i = 1; i <= up; ++i) {
		b[i].push_back(n + 1);
		int f = 0;

		for (int j = 0; j + 1 < b[i].size(); ++j) {
			int l = b[i][j] + 1, r = b[i][j + 1] - 1;
			if (l <= r && tr.query(tr.rt[r], 1, up, l) == i) {
				f = 1;
				break;
			}
		}

		if (!f) {
			std::cout << i << "\n";
			return;
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> Task;
    while(t--) {
        solve();
    }

    return 0;
}