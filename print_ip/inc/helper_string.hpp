#pragma once 

#include <string>

template <typename T>
std::string to_string(T t)
{
    return std::to_string(t);
}

std::string to_string(char ch)
{
    return to_string(static_cast<unsigned char>(ch));
}

std::string to_string(std::string const & str)
{
    return str;
}

std::string to_string(const char *ch) {

  return std::string(ch);
}