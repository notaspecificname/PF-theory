#include <stdio.h>

// Function to calculate and return the sum of proper divisors of a number
int sumOfProperDivisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int count = 0;
    printf("\nAmicable pairs up to %d:\n", n);

    // Loop through each number from 1 to n
    for (int a = 1; a <= n; a++) {
        int b = sumOfProperDivisors(a);

        if (b > a && b <= n) {
            if (sumOfProperDivisors(b) == a) {
                printf("(%d, %d)\n", a, b);
                count++;
            }
        }
    }

    // Display total count or a suitable message if none found
    if (count == 0) {
        printf("No amicable pairs found up to %d.\n", n);
    } else {
        printf("\nTotal amicable pairs found: %d\n", count);
    }

    return 0;
}