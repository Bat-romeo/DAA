#include <iostream>
using namespace std;
class nqueens
{
public:
void Queen(int board[][10], int col, int n);
bool place(int board[][10], int row, int col, int n);
void display(int board[][10], int n);
};
void nqueens::Queen(int board[][10], int col, int n)
{
if (col >= n)
{
display(board, n);
return;
}
for (int i = 0; i < n; i++)
{
if (place(board, i, col, n))
{
board[i][col] = 1;
Queen(board, col + 1, n);
board[i][col] = 0;
}
}
}
bool nqueens::place(int board[][10], int row, int col, int n)
{
int i, j;
for (i = 0; i < col; i++)
if (board[row][i])
return false;
for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
if (board[i][j])
return false;
for (i = row, j = col; j >= 0 && i < n; i++, j--)
if (board[i][j])
return false;
return true;
}
void nqueens::display(int board[][10], int n)
{
cout << endl << "*******************************************" << endl;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
cout << " " << board[i][j];
cout << "\n";
}
cout << endl << "*******************************************" << endl;
}
int main()
{
int n;
cout << "Enter the Number of Queens: ";
cin >> n;
nqueens nq;
int board[10][10];
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
board[i][j] = 0;
nq.Queen(board, 0, n);
return 0;
}
