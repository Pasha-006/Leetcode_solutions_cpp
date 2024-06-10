#include<iostream>
#include<vector>

class Solution {
public:
  bool validBox(std::vector<std::vector<char>> & board,int i,int j)
  {
    int rowRem=i%3;
    int rowDiv=i/3;
    int colRem=i%3;
    int colDiv=i/3;
    for(int m=rowDiv*3;m<rowDiv*3+3;m++)
    {
        for(int n=colDiv*3;n<colDiv*3+3;n++)
        {
            if(m==i && n==j)
            {
                continue;
            }
            if(board[m][n]==board[i][j] || board[i][j]=='.')
            {
                return false;
            }
        }
    }
    return true;
  }
  bool validRow(std::vector<std::vector<char>> & board,int i,int j)
  {
    for(int n=0;n<9;n++)
    {
        if(j==n)
        {
            continue;
        }
        if(board[i][j]==board[i][n]|| board[i][j]=='.')
        {
            return false;
        }
    }
    return true;
  }
   bool validCol(std::vector<std::vector<char>> & board,int i,int j)
  {
    for(int n=0;n<9;n++)
    {
        if(i==n)
        {
            continue;
        }
        if(board[i][j]==board[n][j]|| board[i][j]=='.')
        {
            return false;
        }
    }
    return true;
  }
  
   bool valid(std::vector<std::vector<char>> & board)
   {

     for(int i=0;i<board.size();i++)
     {
        for(int j=0;j<board[0].size();j++)
        {
            if(validBox(board,i,j) && validRow && validCol)
            {
                
                return true;
            }
        }
     }
     return false;
   }
   void print(std::vector<std::vector<char>> & board)
   {
    for(int i=0;i<board.size();i++)
     {
        for(int j=0;j<board[0].size();j++)
        {
            std::cout<<board[i][j];
        }
        std::cout<<" "<<std::endl;
     }
    
   }

   
    void solveSudoku(std::vector<std::vector<char>>& board) {
        int flag=0;
        
        for(int i=0;i<board.size();i++)
        {

            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {

                    for(int k=1;k<10;k++)
                    {
                        board[i][j]='0'+k;
                    
                        if(valid(board)==true)
                        {
                            print(board);
                            flag=1;
                            break;

                        }
                    }
                    if(flag==1)
                    {
                        break;
                    }
                }
            
            }
            if(flag==1)
            {
                break;
            }
        }


        
    }
};