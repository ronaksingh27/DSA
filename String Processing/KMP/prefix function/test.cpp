#include <stdio.h>
#include <string.h>


// Driver function
int main() {
    char s[] = "ababcab";  // Example string
    int n = strlen(s);
    int pi[n];

    computePrefixFunction(s, n, pi);

    // Print the prefix function array
    printf("Prefix function values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");

    return 0;
}
