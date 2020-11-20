#include <type_traits>
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
    out << (int)bytes[0] << std::endl;
}