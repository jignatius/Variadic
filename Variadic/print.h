#pragma once

#include <iostream>

template<typename T>
void print(T arg)
{
    std::cout << arg;
}

template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg;
	print(args...);
}

template<class ...Args>
void printf(Args&&...args)
{
    auto seq_started = false;

    auto print_impl = [&seq_started](auto&& value) mutable {
        if (seq_started) {
            std::cout << " " << value;
        }
        else {
            seq_started = true;
            std::cout << value;
        }
    };

    (print_impl(args), ...);
}

template<typename T>
class AddSpace
{
private:
    T const& ref;

public:
    AddSpace(T const& r) : ref(r) {
    }

    friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s)
    {
        return os << s.ref << ' ';
    }
};

template<typename... Types>
void printF(Types const&... args)
{
    (std::cout << ... << AddSpace(args) ) << '\n';
}

/*
template<typename It>
using EnableIf = typename std::enable_if<
    std::is_same<It, typename std::list<typename std::iterator_traits<It>::value_type>::iterator>::value ||
    std::is_same<It, typename std::list<typename std::iterator_traits<It>::value_type>::const_iterator>::value>::type;

template<
    typename It,
    typename = EnableIf<It>>
    auto operator<<(std::ostream& os, const It& x) {
    return os << "&" << *x;
}*/