#include <bits/stdc++.h>
using namespace std;

/**
 * We want that the product (p) mod n = 1            --------- (1)
 * But also we know that gcd(p, n) == gcd(p mod n, n)
 * From equation number 1, gcd(p, n) == gcd(1, n) == 1
 * And for gcd(p, n) to be 1, every factor of p should be coprime to n
 * Now there is one thing that we are sure of, gcd(p, n) == 1
 * But what if p mod n doesn't come out to be 1, it'll surely be less than n
 * We can remove that pmodn from our list of factors for creating the p
 * and remaining ones will be our ans
 */

bool ok[100005];
int main() {
    int n;
    scanf("%d", &n);
    long long prod = 1;
    for (int i = 1; i < n; i++) {
        if (__gcd(n, i) == 1) {
            ok[i] = 1;
            prod = (prod * i) % n;
        }
    }
    if (prod != 1)
        ok[prod] = 0;
    printf("%d\n", count(ok + 1, ok + n, 1));
    for (int i = 1; i < n; i++) {
        if (ok[i])
            printf("%d ", i);
    }
}
