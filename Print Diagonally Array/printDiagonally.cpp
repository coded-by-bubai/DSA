#include <iostream>
#include<vector>
using namespace std;

vector<int> diagView(vector<vector<int>>& mat)
{
    int n = mat.size();
    vector<int> res;
    // Upper half (including main diagonal)
    for (int col = 0; col < n; col++)
    {
        int i = 0;
        int j = col;

        while (i < n && j >= 0)
        {
            res.push_back(mat[i][j]);
            i++;
            j--;
        }
    }

    // Lower half
    for (int row = 1; row < n; row++)
    {
        int i = row;
        int j = n - 1;

        while (i < n && j >= 0)
        {
            res.push_back(mat[i][j]);
            i++;
            j--;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> res = diagView(arr);

    for (int x : res)
        cout << x << " ";
    return 1;
}