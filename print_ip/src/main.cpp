#include "print_ip.hpp"

int main()
{
    int a = 33;
    print_ip((char)-1);

    std::tuple<int, int, int> m_tuple(1, 2, 3);
    print_ip(m_tuple);

    return 0;
}