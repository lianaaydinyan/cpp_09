#ifndef _polish_
#define _polish_


#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cstdlib>


class rpn_calculator // name ?
{
    private:
        std::stack<int> container;
        int             tmp_r;
        int             tmp_l;
        int             calculator(char); //
    public:
        void             rpn(char **);
        void             division_check(int right_operand);
        bool             valid_op(char op);
        void             scaning(int, char **); // private --
        void            fill_the_container(std::string &str);
       rpn_calculator();
       ~rpn_calculator();
    //    rpn_calculator(const rpn_calculator&);
    //    rpn_calculator& operator=(const rpn_calculator&);

};



#endif