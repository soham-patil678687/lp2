#include<iostream>
#include <vector>

using namespace std;

bool issafe(int row,int col,int n,int **board)
{
    int x=row;
    int y=col;

    while(y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
    }

    int x=row;
    int y=col;

    //up diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
        x--;
    }

    int x=row;
    int y=col;

    //down diagonal
    while(x<n && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

bool solve(int col,int row,int n,int **board )
{
    if(col==n)
    {   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
                if(j%3==0)
                {
                    cout<<"\n";
                }
            }
        }
        return true;
    }

    for(int row=0;row<n;row++)
    {
        if(issafe(row,col,n,board))
        {
            board[row][col]==1;
            if(solve(col+1,row,n,board))
            {
                return true;
            }
            board[row][col]=0;
        }
    }


}

int main()
{
    int n=5;
    int **board=new int*[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    bool a=solve(0,0,n,board);
    return 0;
}