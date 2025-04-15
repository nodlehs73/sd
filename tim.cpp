#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
#define int32_t long long
const int32_t run = 32;
int32_t n;
int x;

// sorteaza o bucata mica din vector
void insertionSort (vector<int>& a, int32_t st, int32_t dr) {

    for (int32_t i=st+1; i<=dr; ++i) {
        int32_t aux = a[i];
        int32_t j = i - 1;

        while (j >= st && a[j] > aux) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = aux;
    }
}

// lipeste bucatile sortate
void Merge( vector<int>& a, int32_t st, int32_t mij, int32_t dr ) {

    int32_t len1 = mij - st + 1;
    int32_t len2 = dr - mij;
    vector<int> L(len1), R(len2);

    for (int32_t i=0; i<len1; ++i)
        L[i] = a[st+i];
    for (int32_t i=0; i<len2; ++i)
        R[i] = a[mij+1+i];

    int32_t i=0, j=0, k=st;

    while (i < len1 && j < len2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++i; ++k;
        }
        else {
            a[k] = R[j];
            ++j; ++k;
        }
    }

    while (i < len1) {
        a[k] = L[i];
        ++i; ++k;
    }

    while (j < len2) {
        a[k] = R[j];
        ++j; ++k;
    }
}


void timSort( vector<int>&a, int32_t n ) {

    for (int32_t i=0; i<n; i+=run)
        insertionSort( a, i, min( (i+run-1), (n-1) ) );

    for (int32_t s=run; s<n; s*=2) {

        for (int32_t l=0; l<n; l+=2*s) {

            int32_t mij = l + s - 1;
            int32_t r = min( (l + 2*s - 1), (n-1) );

            if (mij < r)
                Merge(a, l, mij, r);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> n;
    vector<int> a;

    for (int32_t i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    clock_t start = clock();
   timSort (a, n);

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;

    assert( is_sorted(a.begin(), a.end()) );


    return 0;
}
