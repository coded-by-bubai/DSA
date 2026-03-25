#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n){
    //column check
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
        
    }
    //left diagonal
    for (int i = row-1, j = col-1; i>=0 && j >=0 ; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        
    }
    //right diagonal
    for (int i = row-1, j =col+1; i >=0 && j<n ; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        
    }
    return true;
}
void solve(vector<string>& board, int row, int n){
    if (row == n)
    {
        for(auto r:board){
            cout<<r<<endl;
        }
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            solve(board, row+1, n);
            board[row][i] = '.';
        }
        
    }
    
}

int main(){
    int n = 4;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n);

    return 0;
}