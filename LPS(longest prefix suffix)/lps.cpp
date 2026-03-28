#include <iostream>
#include <vector>

using namespace std;

int lps(string patt)
{
    int n = patt.size();
    int pre = 0, suff = 1;
    vector<int> lpsArr(n, 0);
    while (suff < n)
    {
        // matched
        if (patt[suff] == patt[pre])
        {
            lpsArr[suff] = pre + 1;
            pre++;
            suff++;
        }
        // not matched
        else
        {
            if (pre == 0)
            {
                lpsArr[suff] = 0;
                suff++;
            }
            else
            {
                pre = lpsArr[pre - 1];
            }
        }
    }
    return lpsArr[n-1];
}
int main()
{
    string pattern = "aabcdaabc";
    cout << "lps is : " << lps(pattern);
}