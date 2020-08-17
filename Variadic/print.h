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
