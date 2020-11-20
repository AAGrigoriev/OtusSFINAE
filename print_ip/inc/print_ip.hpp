#pragma once

#include <traits.hpp>
#include <ostream>

template<typename T,
typename = std::enable_if_t<std::is_integral<T>::value>>
void print_ip(T integer,std::ostream& out = std::cout)
{
    const std::size_t count_bytes = sizeof (T);

    union 
    {
        unsigned char bytes[count_bytes];
        T             value;
    };
    
    value = integer;

    for(std::size_t i = count_bytes - 1; i > 0 ; --i )
    {
        out << (int)bytes[i] << ".";
    }
    out << (int)*bytes << std::endl;
}


template<typename T,
typename = std::enable_if_t<is_iterable_v<T> && !std::is_same<T,std::string>::value>>
void print_ip(T const& containter,std::ostream& out = std::cout)
{
    auto iterBeg = container.cbegin();
    auto iterEnd = container.cend();

    for(auto iter = iterBeg; iter != iterEnd;++iter)
    {
        if(iter != iterBeg) out << ".";
        out << *iter;
    }
}


template<typename T,
typename = std::enable_if_t<is_same<T,std::string>::value>>
void print_ip(T const& string,std::ostream& out = std::cout)
{
    out << string;
}
