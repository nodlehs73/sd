#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
void RadixSort_baza2pow16(vector<int>& v)
{
    vector<int> negatives, nonNegatives;
    for (int num : v)
    {
        if (num < 0)
            negatives.push_back(-num);
        else
            nonNegatives.push_back(num);
    }

    if (!nonNegatives.empty())
    {
        int shift = 0;
        int mx = *max_element(nonNegatives.begin(), nonNegatives.end());
        while ((mx >> shift) > 0)
        {
            vector<int> position(65536, 0);
            vector<int> aux(nonNegatives.size());

            for (int i = 0; i < nonNegatives.size(); i++)
            {
                position[(nonNegatives[i] >> shift) & 0xFFFF]++;
            }

            for (int i = 1; i < 65536; i++)
            {
                position[i] += position[i - 1];
            }

            for (int i = (int) nonNegatives.size() - 1; i >= 0; i--)
            {
                aux[--position[(nonNegatives[i] >> shift) & 0xFFFF]] = nonNegatives[i];
            }

            nonNegatives = aux;
            shift += 16;
        }
    }

    if (!negatives.empty())
    {
        int shift = 0;
        int mx = *max_element(negatives.begin(), negatives.end());
        while ((mx >> shift) > 0)
        {
            vector<int> position(65536, 0);
            vector<int> aux(negatives.size());

            for (int i = 0; i < negatives.size(); i++)
            {
                position[(negatives[i] >> shift) & 0xFFFF]++;
            }

            for (int i = 1; i < 65536; i++)
            {
                position[i] += position[i - 1];
            }

            for (int i = (int) negatives.size() - 1; i >= 0; i--)
            {
                aux[--position[(negatives[i] >> shift) & 0xFFFF]] = negatives[i];
            }

            negatives = aux;
            shift += 16;
        }

        for (int& num : negatives)
        {
            num = -num;
        }

    }
    int index = (int) negatives.size() - 1;
    for(int i = 0; i < negatives.size(); ++i)
    {
        v[i] = negatives[index];
        index--;
    }
    for(int i = negatives.size(); i < v.size(); ++i)
    {
        v[i] = nonNegatives[i-(int)negatives.size()];
    }


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    ifstream cin ("partial_sortat_10000000.txt");

    int n, val;
    vector<int> UnsortedArray;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        UnsortedArray.push_back(val);
    }

   clock_t start = clock();
   RadixSort_baza2pow16(UnsortedArray);

    cout << 1.0f * (clock() - start) / CLOCKS_PER_SEC;


    assert(is_sorted(UnsortedArray.begin(), UnsortedArray.end()));


    return 0;
}
