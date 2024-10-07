#include "RPN.hpp"


int main(int ac, char **av)
{
    rpn_calculator expression;
    try
    {
        if (ac <= 1)
            throw std::runtime_error("no enough arguments");
        // expression.scaning(ac, av);
        int i = 0;
        while ( i < ac)
        {
            std::cout << av[i] << std::endl;
            i++;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}