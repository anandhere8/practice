#include <limits.h>
#include <stdio.h>

int main() {
	int i, j, n, min, max, cnt;
	static int a[200000];

	scanf("%d", &n);
	min = INT_MAX;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (min > a[i]) {
			j = i;
			min = a[i];
		}
	}
	cnt = max = 0;
	for (i = (j + 1) % n; i != j; i = (i + 1) % n) {
		if (min == a[i])
			cnt = 0;
		else
			cnt++;
		if (max < cnt)
			max = cnt;
	}
	printf("%lld\n", (long long) min * n + max);
	return 0;
}
