#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

struct Customer {
    // 1. Data Members (Public by default)
    int id;
    float arrivalTime;
    float cookTime;

    // 2. Constructors (Declarations)
    Customer();
    Customer(int id, float arrival, float cook);

    // 3. Operator Overloading (Declaration)
    // بنعرفه إننا ناويين نغير معنى علامة <
    bool operator<(const Customer& other) const;
};

#endif