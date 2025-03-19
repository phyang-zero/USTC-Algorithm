#include <iostream>
using namespace std;

int Read();
int a[100010], b[100010];
int n;
long long ans = 0;

void radixSort(int l, int r, int w, int *in, int *out) {
	if (l >= r || w < 0) return;

	int count_1 = 0;
	for (int i = l; i <= r; i++)
		if ((in[i] >> w) & 1) count_1++;
	int total = r - l + 1, count_0 = total - count_1;
	int idx0 = l, idx1 = l + count_0;

	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if ((in[i] >> w) & 1) {
			cnt++;
			out[idx1++] = in[i];
		} else {
			ans += (long long)(w + 1) * cnt;
			out[idx0++] = in[i];
		}
	}

	if (count_0 > 1) radixSort(l, l + count_0 - 1, w - 1, out, in);
	if (total - count_0 > 1) radixSort(l + count_0, r, w - 1, out, in);
	return ;
}

int main() {
	n = Read();
	for (int i = 1; i <= n; i++) a[i] = Read();
	radixSort(1, n, 20, a, b);
	printf("%lld", ans);
	return 0;
}

int Read()  {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')  f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
