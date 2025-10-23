#include "../include/triangle.hpp"

// Конструкторы
Triangle::Triangle() : Figure(TRIANGLE_VERTICES) {}

Triangle::Triangle(Point* verts) : Figure(TRIANGLE_VERTICES, verts) {}

// Конструктор копирования
Triangle::Triangle(const Triangle& other) : Figure(other) {}

// Оператор присваивания копиованием
Triangle& Triangle::operator=(const Triangle& other) {
    Figure::operator=(other);
    return *this;
}

// Конструктор перемещения
Triangle::Triangle(Triangle&& other) : Figure(other) {}

// Конструктор присваивания перемещением
Triangle& Triangle::operator=(Triangle&& other) {
    Figure::operator=(other);
    return *this;
}

// Геометрический центр (центроид)
Point Triangle::center() const {
    return Figure::center();
}

// Чтение/запись
void Triangle::read(std::istream& in) {}
void Triangle::write(std::ostream& out) const {}

// Площадь через приведение к double
Triangle::operator double() const {}

// Проверка на равенство
bool Triangle::equals(const Triangle& other) const {
    return Figure::equals(other);
}