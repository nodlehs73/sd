#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int double

int32_t n;
int x;

void shellSort( vector<int>& a, int32_t n )
{
    int32_t p = 1;
    while (p * p - 1 <= n )
        p *= 2;
    p /= 2;

    for (int32_t k = p; k > 1; k/=2) {
        int32_t gap = k-1;

        for (int32_t i=gap; i<n; ++i) {
            int32_t aux = a[i];

            int32_t j;
            for (j=i; j>=gap && a[j-gap] > aux; j-=gap)
                a[j] = a[j - gap];

            a[j] = aux;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> n;

    vector <int> a;

    for (int32_t i=0; i<n; ++i) {
        cin >> x;
      //  if (i < 100)std::cout << fixed << setprecision(10) << x << '\n';
        a.push_back(x);
    }

    clock_t start = clock();
    shellSort (a, n);

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;
    assert( is_sorted(a.begin(), a.end()) );


    return 0;
}
