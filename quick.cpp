#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
#define int32_t long long

int32_t n;
int x;

int32_t partition( vector<int>&a, int32_t st, int32_t dr ) {

    int pivot = a[dr];

    int32_t i = st;
    for (int32_t j=st; j<dr; ++j)
        if (a[j] <= pivot)
            swap (a[i++], a[j]);

    swap (a[i], a[dr]);

    return i;
}

void quickSort( vector<int>&a, int32_t st, int32_t dr ) {

    if (st < dr) {
        int32_t index = partition(a, st, dr);
        quickSort( a, st, index-1 );
        quickSort( a, index+1, dr );
    }
}

signed main()
{
    cin >> n;
    vector <int> a;

    for (int32_t i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

   clock_t start = clock();
    quickSort (a, 0, n - 1);

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;

    assert( is_sorted(a.begin(), a.end()) );


    return 0;
}




//#include <bits/stdc++.h>
//using namespace std;
//using namespace std::chrono;
//#define int double
//int32_t n;
//int x;
//
//pair <int, int32_t>medianOf5( vector<int>& a, int32_t st, int32_t dr ) {
//
//    //generam aleator 5 indici in int [st, dr]
//    int32_t lungime = dr - st + 1;
//
//    set<int32_t> indici;
//
//    while (indici.size() < min(5, lungime) ) {
//        int32_t indiceRandom = rand() % lungime + st;
//        indici.insert( indiceRandom );
//    }
//
//    vector< pair<int,int32_t> > v;
//
//    set<int32_t>::iterator X;
//    for (X = indici.begin(); X!=indici.end(); ++X) {
//        v.push_back( {a[*X], *X} );
//    }
//
//    for (int32_t i=0; i<v.size(); ++i)
//    {
//        int mi = v[i].first;
//        int32_t miIndex = i;
//        for( int32_t j = i+1; j<v.size(); ++j )
//            if( v[j].first < mi ) {
//                mi = v[j].first;
//                miIndex = j;
//            }
//        if (miIndex != i)
//            swap (v[i], v[miIndex]);
//    }
//
//    return v[ (v.size()/2) ];
//
//}
//
//int32_t Partition( vector<int>&a, int32_t st, int32_t dr ) {
//
//    pair <int, int32_t> pivotPair = medianOf5(a, st, dr);
//    int pivot = pivotPair.first;
//    int32_t pivotIndex = pivotPair.second;
//
//    swap(a[dr], a[pivotIndex]);
//
//    int32_t i = st;
//    for (int32_t j=st; j<dr; ++j)
//        if (a[j] <= pivot)
//            swap (a[i++], a[j]);
//
//    swap (a[i], a[dr]);
//
//    return i;
//}
//
//void quickSort( vector<int>&a, int32_t st, int32_t dr ) {
//
//    if (st < dr) {
//        int32_t index = Partition(a, st, dr);
//        quickSort( a, st, index-1 );
//        quickSort( a, index+1, dr );
//    }
//}
//
//signed main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);  cout.tie(0);
//
//    cin >> n;
//    vector <int> a;
//
//    for (int32_t i=0; i<n; ++i) {
//        cin >> x;
//        a.push_back(x);
//    }
//
//    srand(time(0));
//
//    clock_t start = clock();
//
//    quickSort(a, 0, n-1);
//
//    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;
//
//
//
//    assert( is_sorted(a.begin(), a.end()) );
//    return 0;
//}
