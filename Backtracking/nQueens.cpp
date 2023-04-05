#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void solve(int n, int col, vector<string> board, vector<int> leftRow, vector<int> upperDiagonal, vector<int> lowerDiagonal)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "\n\n\n\n\n";
        return;
    }
    
    for (int row = 0; row < n; row++)
    {

        if (leftRow[row] == 0 and upperDiagonal[n - 1 + col - row] == 0 and lowerDiagonal[col + row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[col + row] = 1;

            solve(n, row + 1, board, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[col + row] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(n,0,board,leftRow,upperDiagonal,lowerDiagonal);
    return 0;
}