#include "print_ip.hpp"
#include <vector>

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */

using namespace printIP;

int main()
{

    print_ip(-1);
    
    std::cout << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};

    print_ip(vec);

    std::cout << std::endl;

    std::tuple<int, int, int> t(1, 2, 3);

    print_ip(t);

    std::cout << std::endl;

    std::string s1("blabla");

    print_ip(s1);

    std::cout << std::endl;

    return 0;
}