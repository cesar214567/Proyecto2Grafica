#include <bits/stdc++.h>
using namespace std;
using triplet = pair<float, pair<float, float>>;
int main()
{
  vector<triplet> temp;
  temp.push_back({1, {1, 1}});
  temp.push_back({2, {2, 2}});
  temp.push_back({3, {3, 3}});
  temp.push_back({4, {4, 4}});
  float* p1 = &temp[0].first;
  cout<<p1[7]<<endl;
}
