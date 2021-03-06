#pragma once

#include <tuple>
#include <iostream>
#include <helper_string.hpp>

namespace tuple_helper
{
    /*!
        @brief Метафукнция для печати tuple
        T - tuple , N - index element tuple ( 0  - Max_Index), Max_Index  = (sizeof...(tuple) - 1 ) 
     */
    template <typename T, unsigned N, unsigned Max_Index>
    struct print_helper
    {
        /*!
            @brief Основная часть рекурсии для вывода tuple
            param[in] - t   Tuple, который разбивается на кусочки
            param[in] - out Поток вывода, по умолчанию std::cout
       */
        inline static void print_ip_imp(T const &t, std::ostream &out = std::cout)
        {
            using typeNext = decltype(std::get<N + 1>(t));
            using typeCurrent = decltype(std::get<N>(t));

            static_assert(std::is_same<typeCurrent, typeNext>::value && "types in tupple are different");

            out << to_string(std::get<N>(t)) << ".";
            print_helper<T, N + 1, Max_Index>::print_ip_imp(t, out);
        }
    };

    /*!
        @brief Метафукнция для печати tuple. 
        Вызывается когда дошли до последнего элемента в std::tuple
     */
    template <typename T, unsigned N>
    struct print_helper<T, N, N>
    {
        /*!
            @brief Конец рекурсии для вывода tuple
            param[in] - t   Tuple, который разбивается на кусочки
            param[in] - out Поток вывода, по умолчанию std::cout
        */
        inline static void print_ip_imp(T const&t, std::ostream &out = std::cout)
        {
            out << to_string(std::get<N>(t));
        }
    };

} // namespace tuple_helper