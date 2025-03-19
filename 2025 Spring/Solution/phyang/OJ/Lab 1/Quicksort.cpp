#include <iostream>
using namespace std;
int Read();
int n, a[100010];
long long sum;

int Partition(int p, int r) {
	int x = a[p], i = p - 1;
	swap(a[p], a[r]);
	for (int j = p; j < r; j++)
		if (a[j] <= x) swap(a[++i], a[j]);
	swap(a[i + 1], a[r]);
	sum += (long long)a[i + 1] * (r - p + 1LL);
	return i + 1;
}

void QuickSort(int p, int r) {
	if (p < r) {
		int q = Partition(p, r);
		QuickSort(p, q - 1);
		QuickSort(q + 1, r);
	}
	return ;
}

int main() {
	n = Read();
	for (int i = 1; i <= n; i++) a[i] = Read();
	QuickSort(1, n);
	printf("%lld", sum);
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
