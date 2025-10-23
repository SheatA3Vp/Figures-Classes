#pragma once

#include <iostream>
#include <memory>
#include "point.hpp"
#include "figure.hpp"

class Triangle : public Figure {
public:

    // Конструкторы
    Triangle();

    Triangle(Point* verts);

    // Конструктор копирования
    Triangle(const Triangle& other);

    // Оператор присваивания копиованием
    Triangle& operator=(const Triangle& other);

    // Конструктор перемещения
    Triangle(Triangle&& other);

    // Конструктор присваивания перемещением
    Triangle& operator=(Triangle&& other);

    // Деструктор
    virtual ~Triangle() = default;

    // Геометрический центр (центроид)
    virtual Point center() const;

    // Чтение/запись
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

    // Площадь через приведение к double
    virtual operator double() const;

    // Проверка на равенство
    virtual bool equals(const Triangle& other) const;

protected:
    static constexpr size_t TRIANGLE_VERTICES = 3;
};