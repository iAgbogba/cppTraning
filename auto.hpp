#include <stdio.h>

template<typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a + b;
}

// C++11
template<typename T1, typename T2>
auto sumWithTralingType(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

template<typename F, typename T>
auto apply(F&& f, T value)
{
    return f(value);
}

int main()
{
    printf("Sum : %u \n", sum(1,3));
    auto twoTimes = [](auto i) {return i*2;};
    printf("double : %u \n", apply(twoTimes,3));
    return 0;
}
