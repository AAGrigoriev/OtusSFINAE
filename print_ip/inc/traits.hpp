#pragma once

#include <type_traits>


/*!
    \brief  Метафункции для проверки типов которые содержат методы begin и end
*/
template<typename T,typename U = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T,std::void_t<
                                 decltype(std::declval<T>().begin()),
                                 decltype(std::declval<T>().end())
                                >
                   > :std::true_type {};

template<typename T>
inline constexpr bool is_iterable_v = is_iterable<T>::value;


/*!
    \brief Метафункции для проверки входного типа на tuple

*/
template <typename T>
struct is_tuple_imp : std::false_type {};

template <typename... U>
struct is_tuple_imp<std::tuple <U...>> : std::true_type {};
