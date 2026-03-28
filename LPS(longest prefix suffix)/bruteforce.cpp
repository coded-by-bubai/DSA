#include <iostream>
#include <vector>

using namespace std;

int lps(string patt)
{
    int n = patt.size();
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        int k = n-i;
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (patt[j] != patt[k+j])
            {
                flag = false;
                break;
            }
            
        }
        if (flag)
        {
            res = i;
        }
        
    }
    return res;
}
int main()
{
    string pattern = "aabcdaabc";
    int result = lps(pattern);
    if (result != -1)
    {
        cout << result;
    }
    else
    {
        cout << "no resut";
    }
}