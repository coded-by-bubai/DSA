#include <iostream>

using namespace std;
bool CheckKnightTour(int Solgrid[][5], int r, int c, int n, int expectVal)
{
    if (r < 0 || c < 0 || r >= n || c >= n || Solgrid[r][c] != expectVal)
    {
        return false;
    }
    if (expectVal == n * n - 1)
    {
        return true;
    }

    // bool ans1 = CheckKnightTour(Solgrid, r - 2, c + 1, n, expectVal + 1);
    // bool ans2 = CheckKnightTour(Solgrid, r - 2, c - 1, n, expectVal + 1);
    // bool ans3 = CheckKnightTour(Solgrid, r - 1, c + 2, n, expectVal + 1);
    // bool ans4 = CheckKnightTour(Solgrid, r - 1, c - 2, n, expectVal + 1);
    // bool ans5 = CheckKnightTour(Solgrid, r + 1, c + 2, n, expectVal + 1);
    // bool ans6 = CheckKnightTour(Solgrid, r + 1, c - 2, n, expectVal + 1);
    // bool ans7 = CheckKnightTour(Solgrid, r + 2, c + 1, n, expectVal + 1);
    // bool ans8 = CheckKnightTour(Solgrid, r + 2, c - 1, n, expectVal + 1);

    // return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);

    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        if (CheckKnightTour(Solgrid, r + dx[i], c + dy[i], n, expectVal + 1))
            return true; // it breaks early
    }

    return false;
}
int main()
{

    int Solgrid[5][5] = {
        {0, 3, 8, 13, 18},
        {9, 14, 19, 2, 7},
        {4, 1, 12, 17, 20},
        {15, 10, 21, 6, 23},
        {22, 5, 16, 11, 24}};

    int n = 5;
    if (!CheckKnightTour(Solgrid, 0, 0, n, 0))
    {
        cout << "Invalid Configuration" << endl;
    }
    else
    {
        cout << "Valid Configuration" << endl;
    }
    return 0;
}