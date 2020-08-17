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
