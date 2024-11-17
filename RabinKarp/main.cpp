#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(string text, string pat, int q)
{
    int n = text.size(); // Length of text
    int m = pat.size();  // Length of pattern
    int i, j;
    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text
    int h = 1;

    // Calculate the value of h = d^(m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value for pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
      }

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
        // Check if the hash values match
        if (p == t) {
            // Check each character if hash values match
            for (j = 0; j < m; j++) {
                if (text[i + j] != pat[j])
                    break;
            }
            if (j == m) // If all characters match
                cout << "PATTERN FOUND AT INDEX " << i << endl;
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            // Convert negative value of t to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101;  // A prime number
    search(text, pat, q);
    return 0;
}
