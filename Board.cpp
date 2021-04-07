 #include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <iterator>
#include <map>
#include <bits/stdc++.h>

using namespace std;

namespace ariel {
    
    /*
     * Initializes the minimum row and minimum column
     * to be what is given in the question, 
     * if this is the first time something is added to the board.
     */
    void Board::initializesFirstTime (unsigned int row, unsigned int column)
    {
           if(isFirstTime)
           {    
               min_row=row;
               min_col=column;
               isFirstTime=false;
           }
    }

    /*
    *Function that updates the maximum and minimum row number,
    *the maximum and minimum column number, 
    *according to the values given and previous data of the table.
    */
    void Board::update_min_max_raw_col(unsigned int row, unsigned int column)
    {
        //row min-max update
        if(row>max_row)
        {
            max_row=row;
        }
        else if(row<min_row)
        {
            min_row=row;
        }
        //column min-max update
        if(column>max_col)
        {
            max_col=column;
        }
        if(column<min_col)
        {
            min_col=column;
        }
    }
    /*
    *Post horizantal messege on the board
    */
    void Board::postHorizontal(unsigned int row, unsigned int column, string const & message)
    {
        int str_len=message.length();  
        initializesFirstTime (row,column);
        update_min_max_raw_col(row,column);
        for(size_t i=0;i<str_len;i++)
        {
            //max column update
            if(column>max_col)
            {
                max_col=column;
            }
            board_map[row][column]=message.at(i);            
            column++;
        }
    }

    /*
    *Post vertical messege on the board
    */
    void  Board::postVertical(unsigned int row, unsigned int column, string const & message)
    {
        int str_len=message.length(); 

        initializesFirstTime (row,column);
        update_min_max_raw_col(row,column);

        for(size_t i=0;i<str_len;i++)
        {
            //max row update
            if(row>max_row)
            {
                max_row=row;
            }
            board_map[row][column]=message.at(i);
            row++;
        }

    }

    /*
    *Post messege on the board
    */
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const & message) {

        //empty meesege
        if (message.length()<0)
        {
            return;
        }
       switch (direction)
       {
       case Direction::Horizontal:
           postHorizontal(row, column, message);
           break;
        case Direction::Vertical:
           postVertical(row, column, message);
           break;
       }
    }
    
      
    /*
    *A function that receives a row and a column
    *and returns the corresponding character on the board.
    */
    char Board:: charInLoc(unsigned int row,unsigned int column)
    {
        map<unsigned int,map<unsigned int,char>>::iterator itr_rows;
        map<unsigned int,char>::iterator itr_columns;
        char char_in_loc=EMPTY_CHAR;
        itr_rows=board_map.find(row);
        //if the row exist in the map
        if(itr_rows!=board_map.end())
        {
            itr_columns=(itr_rows->second).find(column);
            //if the column exist in the map
            if(itr_columns!=(itr_rows->second).end())
            {
                char_in_loc=itr_columns->second;
            }
        }
        return char_in_loc;
    }
    /*
    *Read horizontal messege from the board
    */
    string Board::readHorizontal(unsigned int row, unsigned int column, unsigned int length)
    {
        string ans;
        for (size_t i = 0; i < length; i++)
        {
           ans+=charInLoc(row,column+i);
        }
        return ans;
    }
    /*
    *Read vertical messege from the board
    */
    string Board::readVertical(unsigned int row, unsigned int column, unsigned int length)
    {
        string ans;
        for (size_t i = 0; i < length; i++)
        {
           ans+=charInLoc(row+i,column);
        }
        return ans;

    }
    /*
    *Read horizontal messege from the board
    */
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
       switch (direction)
       {
        case Direction::Horizontal:
            return(readHorizontal(row, column, length));
        case Direction::Vertical:
           return(readVertical(row, column, length));
       }
    }
    /*
    *A function that displays the board to the screen
    */
    void Board::show() {
        cout<<"start column: "<<min_col<<" "<<endl<<endl;
        for(size_t row=min_row;row<=max_row;row++)
        {
            //print row number
            cout<<row<<": ";
            cout<<read( row, min_col, Direction::Horizontal,max_col-min_col+1);
            cout<<endl;
        }
    }
    
};