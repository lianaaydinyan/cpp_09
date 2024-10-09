#ifndef _merge_insertion_
#define _merge_insertion_

# include <algorithm>
# include <sstream>
# include <iomanip>
# include <vector>
# include <deque>
# include <ctime>
// # include <sys/time.h>
// time_t
# include <cmath>

class PmergeMe
{
    public:
        PmergeMe(int ac, char **av);
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        void     FordJohnson(); // ba
    private:
        std::vector<int> container1;
        std::deque<int> container2;
        void parser(int ac, char **av);
        template<typename T>
        void    merge_insertion(T &container);
        template<typename T>
        void    insertion(T &container1, T &container2);
        template<typename T>
        void    forthran();

    private:


};




#endif