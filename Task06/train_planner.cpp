#include <iostream>
#include <cmath>

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b)
{
    // Total minutes from start of day for both
    int totalA = a.h * 60 + a.m;
    int totalB = b.h * 60 + b.m;
    return std::abs(totalA - totalB);
}

inline bool earlier(const Time& a, const Time& b)
{
    int totalA = a.h * 60 + a.m;
    int totalB = b.h * 60 + b.m;
    return totalA < totalB;
}

int main()
{
    Time departure(9, 45), arrival(13, 10);
    std::cout << minutesBetween(departure, arrival) << ' '
              << std::boolalpha << earlier(arrival, departure) << '\n';

    // Test same time
    Time t1(10, 0), t2(10, 0);
    std::cout << "Same time: " << minutesBetween(t1, t2) << " " << earlier(t1, t2) << "\n";

    // Test across noon
    Time morning(11, 30), afternoon(14, 15);
    std::cout << "Across noon: " << minutesBetween(morning, afternoon) << " " << earlier(morning, afternoon) << "\n";

    return 0;
}
