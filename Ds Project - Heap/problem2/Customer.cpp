#include "Customer.hpp"

// 1. Default Constructor
// بيدي قيم ابتدائية أصفار عشان لو عملنا مصفوفة
Customer::Customer() {
    this->id = 0;
    this->arrivalTime = 0;
    this->cookTime = 0;
}

// 2. Parameterized Constructor
// بياخد القيم ويحطها في المتغيرات
Customer::Customer(int id, float arrival, float cook) {
    this->id = id;
    this->arrivalTime = arrival;
    this->cookTime = cook;
}

// 3. Operator < Implementation
// اللوجيك بتاع المقارنة (Min-Heap Logic)
bool Customer::operator<(const Customer& other) const {
    // استخدمنا السهم -> مع this
    // واستخدمنا النقطة . مع other
    // المعنى: لو وقتي أنا أقل من وقتك أنت، يبقى النتيجة True (يعني أنا أهم)
    return this->cookTime < other.cookTime;
}
