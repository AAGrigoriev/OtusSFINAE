#pragma once

#include <tuple>
#include <ostream>

namespace tuple_helper
{
    /* T - tuple , N - index element tuple ( 0  - Max_Index), Max_Index  = (sizeof...(tuple) - 1 ) */
    template <typename T, unsigned N, unsigned Max_Index>
    struct print_helper
    {
        inline static void print_ip_imp(T &t, std::ostream &out = std::cout)
        {
            out << std::get<N>(t) << ".";
            print_helper<T, N + 1, Max_Index>::print_ip_imp(t, out);
        }
    }

    template <typename T, unsigned Max_Index>
    struct print_helper<T, Max_Index, MaxIdex>
    {
        inline static void print_ip_imp(T &t, std::ostream &out = std::cout)
        {
            out << std::get<Max_Index>(t);
        }
    };

} // namespace tuple_helper