#include <iostream>
#include <string>

struct Parcel {
    double weight;
    std::string destination;
};

// Base calculation logic
double calculateBase(double weight, bool express, bool insured) {
    double price = weight * 10.0; // $10 per kg
    if (express) price += 5.0;
    if (insured) price += 2.0;
    return price;
}

// Overload 1: Weight in Grams (int)
double charge(int grams) {
    std::cout << "[Using charge(int grams)] ";
    return calculateBase(grams / 1000.0, false, false);
}

// Overload 2: Weight in KG (double) with default arguments
double charge(double kg, bool express = false, bool insured = false) {
    std::cout << "[Using charge(double kg, ...)] ";
    return calculateBase(kg, express, insured);
}

// Overload 3: Parcel object
double charge(const Parcel& p) {
    std::cout << "[Using charge(const Parcel&)] ";
    return calculateBase(p.weight, false, false);
}

int main() {
    Parcel myParcel = {2.5, "New York"};

    std::cout << "Call charge(500): " << charge(500) << "\n";
    std::cout << "Call charge(2.5): " << charge(2.5) << "\n";
    std::cout << "Call charge(2.0f): " << charge(2.0f) << "\n";
    std::cout << "Call charge(2.5, true): " << charge(2.5, true) << "\n";
    std::cout << "Call charge(myParcel): " << charge(myParcel) << "\n";
    std::cout << "Call charge(2.5, true, true): " << charge(2.5, true, true) << "\n";

    return 0;
}
