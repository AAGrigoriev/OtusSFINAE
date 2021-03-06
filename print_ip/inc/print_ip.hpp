#pragma once

#include <traits.hpp>
#include "print_tuple.hpp"
#include "helper_string.hpp"

namespace printIP
{

    /*!
    @brief Print IP
    Print Integer Value
    @param[in] - integer (see is_integral)
    @param[in] - out Output stream
    */
    template <typename T,
              std::enable_if_t<std::is_integral<T>::value, bool> = true>
    void print_ip(T integer, std::ostream &out = std::cout)
    {
        const std::size_t count_bytes = sizeof(T);

        union
        {
            unsigned char bytes[count_bytes];
            T value;
        };

        value = integer;

        for (std::size_t i = count_bytes - 1; i > 0; --i)
        {
            out << to_string(bytes[i]) << ".";
        }
        out << to_string(*bytes);
    }

    /*!
    @brief Print IP
    Print for any type with method cbegin() and cend()
    @param[in] - T STL container 
    @param[in] - out Output stream
    */
    template <typename T,
              std::enable_if_t<tuple_helper::is_iterable_v<T> && !std::is_same<T, std::string>::value, bool> = true>
    void print_ip(T const &container, std::ostream &out = std::cout)
    {
        auto iterBeg = container.cbegin();
        auto iterEnd = container.cend();

        for (auto iter = iterBeg; iter != iterEnd; ++iter)
        {
            if (iter != iterBeg)
                out << ".";
            out << to_string(*iter);
        }
    }
    
    /*!
    @brief Print IP
    Print for any type with method cbegin() and cend()
    @param[in] - T std::string
    @param[in] - out Output stream
    */
    template <typename T,
              std::enable_if_t<std::is_same<T, std::string>::value, bool> = true>
    void print_ip(T &str, std::ostream &out = std::cout)
    {
        out << to_string(str);
    }

    template <typename... Args>
    void print_tuple(std::tuple<Args...> const &tuple, std::ostream &out = std::cout)
    {
        tuple_helper::print_helper<std::tuple<Args...>, 0, sizeof...(Args) - 1>::print_ip_imp(tuple, out);
    }

    /*!
    @brief Print IP
    Print for any type with method cbegin() and cend()
    @param[in] - T std::tuple
    @param[in] - out Output stream
    */
    template <typename T,
              std::enable_if_t<tuple_helper::is_tuple<T>::value, bool> = true>
    void print_ip(T const &tuple, std::ostream &out = std::cout)
    {
        print_tuple(tuple, out);
    }
} // namespace printIP