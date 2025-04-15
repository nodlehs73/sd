#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
#define int32_t long long
int32_t n;
double x;

void Merge( vector<int>& a, int32_t left, int32_t mid, int32_t right ) {
    //copiez jumatate intr-un vector si jumatate in altul
    //apoi interclasez
    int32_t n1 = mid - left + 1;
    int32_t n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int32_t i=0; i<n1; ++i)
        L[i] = a[left + i];
    for (int32_t i=0; i<n2; ++i)
        R[i] = a[mid + i + 1];

    int32_t i=0, j=0, k=left;

    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++k;
            ++i;
        }
        else {
            a[k] = R[j];
            ++k;
            ++j;
        }
    }
    while (i < n1) {
        a[k] = L[i];
        ++k;
        ++i;
    }
    while (j < n2) {
        a[k] = R[j];
        ++k;
        ++j;
    }
}

void mergeSort( vector<int>& a, int32_t left, int32_t right ) {
    if (left >= right)
        return;

    int32_t mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    Merge(a, left, mid, right);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);

    cin >> n;
    vector <int> a;

    for (int32_t i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

   clock_t start = clock();
    mergeSort (a, (int32_t) 0, (int32_t) (n - 1));

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;

    assert( is_sorted(a.begin(), a.end()) );

    return 0;
}
