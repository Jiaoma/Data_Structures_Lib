#include<cstdio>
void Merge(int sr[], int tr[], int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (sr[i]<sr[j]) tr[k] = sr[i++];
		else tr[k] = sr[j++];
	}
	if (i <= m)
		while (k <= n && i <= m) tr[k++] = sr[i++];
	if (j <= n)
		while (k <= n && j <= n) tr[k++] = sr[j++];
}
void MSort(int sr[], int tr1[], int s, int t)
{
	int m;
	int tr2[20];
	if (s == t) tr1[t] = sr[s];
	else
	{
		m = (s + t) / 2;
		MSort(sr, tr2, s, m);
		MSort(sr, tr2, m + 1, t);
		Merge(tr2, tr1, s, m, t);
	}
}
void MergeSort(int a[], int num)
{
	MSort(a, a, 1, num);
}
int main(int argc, const char * argv[]) {
	int num;
	int input[100005];
	while (scanf("%d", &num) != EOF) {
		for (int i = 1; i <= num; i++) {
			scanf("%d", &(input[i]));
		}
		MergeSort(input, num);
		for (int j = 1; j <= num; j++) {
			printf("%d ", input[j]);
		}
		printf("\n");
	}
	return 0;
}
