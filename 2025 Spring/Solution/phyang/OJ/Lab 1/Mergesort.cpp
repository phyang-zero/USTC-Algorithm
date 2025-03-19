#include <iostream>
#include <string.h>
using namespace std;

int Read();
struct Node {
	int value;
	int ans;
} a[100010], temp[100010];

void merge(int l, int mid, int r) {
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (a[i].value <= a[j].value) {
			a[i].ans += (j - mid - 1);
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		a[i].ans += (j - mid - 1);
		temp[k++] = a[i++];
	}
	while (j <= r) temp[k++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = temp[i];
	return ;
}

void mergeSort(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
	return ;
}

int main() {
	int n = Read();
	for (int i = 1; i <= n; i++) a[i] = {Read(), 0};
	mergeSort(1, n);
	int xor_ans = 0;
	for (int i = 1; i <= n; i++) {
//        cout << a[i].ans << " ";
		xor_ans ^= a[i].ans;
	}
	printf("%d\n", xor_ans);
	return 0;
}

int Read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
