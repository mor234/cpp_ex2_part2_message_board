#pragma once
#include <string>
#include <map>
#include "Direction.hpp"
namespace ariel {
    class Board{
        private:
            std::map<unsigned int, std::map< unsigned int,char>> board_map;
            bool isFirstTime=true;
            unsigned  int max_row=0;
            unsigned int min_row=0;
            unsigned int max_col=0;
            unsigned  int min_col=0;
            const char EMPTY_CHAR='_'; 

            void initiliezFirstTime (unsigned int row, unsigned int column);
            void update_min_max_raw_col(unsigned int row, unsigned int column);
            void postHorizontal(unsigned int row, unsigned int column, std::string const & message);
            void postVertical(unsigned int row, unsigned int column, std::string const & message);
            std::string readHorizontal(unsigned int row, unsigned int column, unsigned int length);
            std::string readVertical(unsigned int row, unsigned int column, unsigned int length);

        public:
            void post(unsigned int row, unsigned int column,Direction direction,std::string const & message); 
            std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int  length ) ;
            void show();
    };
}
