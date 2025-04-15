
#include <bits/stdc++.h>
#define int32_t long long
#define int long long

using namespace std;
using namespace std::chrono;
void heapify(vector<int>& v, int32_t n, int32_t i) {
    int32_t largest = i;
    int32_t l = 2 * i + 1;
    int32_t r = 2 * i + 2;
    if (l < n && v[l] > v[largest]) {
        largest = l;
    }
    if (r < n && v[r] > v[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heap_sort(vector<int>& v) {
    int32_t n = v.size();
    for (int32_t i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int32_t i = n - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
signed main() {
    ifstream cin ("random_10000000.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    int32_t n;
    int val;
    vector <int> UnsortedArray;
    int32_t i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> val;
        UnsortedArray.push_back(val);
    }

    clock_t start = clock();
    heap_sort(UnsortedArray);

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;

    assert( is_sorted(UnsortedArray.begin(), UnsortedArray.end()) );




    return 0;
}
