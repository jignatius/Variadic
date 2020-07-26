#pragma once

#include <sstream>

template<typename T>
void toString(std::ostringstream& os, const T value)
{
    os << value;
}

template<typename T, typename... Ts>
void toString(std::ostringstream& os, const T value, const Ts...rest)
{
    toString(os, value);
    toString(os, rest...);
}

template<typename T, typename... Ts>
std::string StringifyRecursive(const T& value, const Ts...rest)
{
    std::ostringstream os;
    toString(os, value, rest...);
    return os.str();
}

template<typename... Ts>
std::string StringifyInitList(Ts... args)
{
    std::ostringstream os;
    const int size = sizeof...(args);
    // since initializer lists guarantee sequencing, this can be used to
    // call a function on each element of a pack, in order:
    int dummy[sizeof...(Ts)] = { (os << args, 0)... };
    return os.str();
}

template<typename... Ts>
std::string StringifyFold(Ts... args)
{
    std::ostringstream os;
    (os << ... << args);
    return os.str();
}
