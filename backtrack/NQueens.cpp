#include<iostream>
#include<vector>
//https://leetcode.com/problems/n-queens/
class Solution
{
    public:
    bool safe(std::vector<std::string> & puzzle ,int row, int col)
    {
        int n=puzzle[0].length();
        
        //row wise 
        for(int i=0;i<n;i++)
        {
            if(i==row)
            {
                continue;
            }
            if(puzzle[i][col]=='Q')
            {
                return false;
            }
        }
        //col wise 
        for(int i=0;i<n;i++)
        {
            if(i==col) continue ;

            if(puzzle[row][i]=='Q')
            {
                return false;
            }
        }
        
        //cross right to left 
         //upside
        int i=row-1,j=col+1; 
        while(i>=0 && j<n)
        {
            if(puzzle[i][j]=='Q')
            {
                return false;
            }
            i-=1;
            j+=1;
        }
        //downside 
        i=row+1,j=col-1;
        while(i<n && j>=0)
        {
            if(puzzle[i][j]=='Q')
            {
                return false;
            }
            i+=1;
            j-=1;
        }


        //left to right 

        //aproach toward top 
        i=row-1,j=col-1;
        while(i>=0 && j>=0)
        {
            if(puzzle[i][j]=='Q')
            {
                return false ;
            }
            i-=1;
            j-=1;
        }
        //towards dowside
        i=row+1,j=col+1;
        while(i<n && j<n)
        {
            if(puzzle[i][j]=='Q')
            {
                return false ;
            }
            i+=1;
            j+=1;
        }
        return true;
        


    }
    
    void  solve(int row,int n,std::vector<std::vector<std::string>>& puzzle,std::vector<std::string> & temp)
    {
        if(row==n)
        {
                puzzle.emplace_back(temp);
                return ;
        }
            
        
        
            for(int j=0;j<temp[row].length();j++)
            { 
                if(temp[row][j]=='.')
                {
                    //temp[i][j]='Q';
                    if(safe(temp,row,j)==true) 
                    {
                        temp[row][j]='Q';
                        solve(row+1,n,puzzle,temp);
                    }
                    temp[row][j]='.';
                    
                }

            }
        
        return ;
    }
    std::vector<std::vector<std::string>>   solveNQueens(int n)
    {

        std::vector<std::vector<std::string>> ans;
        std::vector<std::vector<std::string>> temp;
        std::vector<std::string> _vect(n,std::string(n,'.'));
       
        solve(0,n,temp,_vect);
        return temp;


    }

};