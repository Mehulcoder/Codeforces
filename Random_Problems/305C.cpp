#include <cstdio>
 
const int NMAX = 100005;
int a[NMAX], n, tmax, tcnt;
 
int main() {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[n - i - 1]);
        while (n > 0) {
                int j = n - 1, cnt;
                while (j > 0 && a[n - 1] == a[j - 1]) --j;
                cnt = n - j;
                if (cnt % 2 == 1) {
                        tcnt++, n--;
                        if (a[n] > tmax) tmax = a[n];
                }
                cnt /= 2;
                n -= cnt;
                for(int i = 0; i < cnt; i++) a[n - 1 - i]++;
        }
        printf("%d\n", tmax - tcnt + 1);
}