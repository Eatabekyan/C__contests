#include <stdio.h>
#include <stdlib.h>

int main() {
    float eps = 1e-8;
    float f;
    scanf("%f", &f);
    for (int i = 0;; ++i) {
        long long int num = f * (1 << i);
        if (num - (f * (1LL << i)) < (eps * (1LL << i)) && num - (f * (1LL << i)) > -(eps * (1LL << i))) {
            long long int k = num / (1LL << i);
            num %= 1LL << i;
            printf("%Ld (%Ld/%Ld)", k, num, 1LL << i);
            break;
        }
    }
}
