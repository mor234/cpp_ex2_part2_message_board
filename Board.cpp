 #include <string>
#include "Direction.hpp"
#include "Board.hpp"
#include <iterator>
#include <map>
#include <bits/stdc++.h>

using namespace std;

namespace ariel {


    void Board::initiliezFirstTime (unsigned int row, unsigned int column)
    {
           if(isFirstTime)
           {    
               min_row=row;
               min_col=column;
               isFirstTime=false;
           }
    }

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

    void Board::postHorizontal(unsigned int row, unsigned int column, string const & message)
    {
        int str_len=message.length();  
        initiliezFirstTime (row,column);

        // if(isFirstTime())
        // {
        //     min_row=row;
        //     min_col=column;
        // }
        update_min_max_raw_col(row,column);

        //   //if the row doesnt exist already   
        // if(board_map.find(row)==board_map.end())
        // {
        //     map<int, char> empty_map;
        //     board_map.insert({row,empty_map} );
        // }

        for(size_t i=0;i<str_len;i++)
        {
            //column min-max update
            if(column>max_col)
            {
                max_col=column;
            }

            board_map[row][column]=message.at(i);
            column++;
        }
    }
    void  Board::postVertical(unsigned int row, unsigned int column, string const & message)
    {
        int str_len=message.length(); 

        initiliezFirstTime (row,column);
        update_min_max_raw_col(row,column);

        for(size_t i=0;i<str_len;i++)
        {
            //row min-max update
            if(row>max_row)
            {
                max_row=row;
            }

            board_map[row][column]=message.at(i);
            row++;
        }

    }
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
    
      
  
    // bool isEmptyLoc(unsigned int row,unsigned int column)
    // {

    // }
    string Board::readHorizontal(unsigned int row, unsigned int column, unsigned int length)
    {
        string ans;
        map<unsigned int,map<unsigned int,char>>::iterator itr_rows;
        map<unsigned int,char>::iterator itr_columns;
        char char_to_add=EMPTY_CHAR;
        for (size_t i = 0; i < length; i++)
        {
           itr_rows=board_map.find(row);
           if(itr_rows!=board_map.end())
           {
               itr_columns=(itr_rows->second).find(column+i);
               if(itr_columns!=(itr_rows->second).end())
               {
                   char_to_add=itr_columns->second;
               }
           }

           ans+=char_to_add;
            char_to_add=EMPTY_CHAR;
        }
        return ans;
    }
    string Board::readVertical(unsigned int row, unsigned int column, unsigned int length)
    {
        string ans;
        map<unsigned int,map<unsigned int,char>>::iterator itr_rows;
        map<unsigned int,char>::iterator itr_columns;
        char char_to_add=EMPTY_CHAR;
        for (size_t i = 0; i < length; i++)
        {
           itr_rows=board_map.find(row+i);
           if(itr_rows!=board_map.end())
           {
               itr_columns=(itr_rows->second).find(column);
               if(itr_columns!=(itr_rows->second).end())
               {
                   char_to_add=itr_columns->second;
               }
           }

           ans+=char_to_add;
            char_to_add=EMPTY_CHAR;
        }
        return ans;

    }
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
       switch (direction)
       {
       case Direction::Horizontal:
           return(readHorizontal(row, column, length));
        case Direction::Vertical:
           return(readVertical(row, column, length));
       }
    }
    void Board::show() {
        char char_to_print=EMPTY_CHAR;
        // cout<<"\t min col"<<min_col<<": ";
        map<unsigned int,map<unsigned int,char>>::iterator itr_rows;
        map<unsigned int,char>::iterator itr_columns;
       
          for(size_t i=min_row;i<=max_row;i++)
          {
            cout<<i<<": ";
            itr_rows=board_map.find(i);

            for(size_t j=min_col;j<=max_col;j++)
            {
                if(itr_rows!=board_map.end())
                    {
                        itr_columns=(itr_rows->second).find(j);
                        if(itr_columns!=(itr_rows->second).end())
                        {
                            char_to_print=itr_columns->second;
                        }
                    }
                cout<<char_to_print;
                char_to_print=EMPTY_CHAR;
            }
            cout<<endl;

         }
    }
};