#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    PmergeMe sentence(ac, av);
    sentence.merge_insertion();
    return 0;
}