#pragma once

#include <iostream>
#include <memory>
#include "point.hpp"


//TODO: Убрать ненужные виртуал и добавить консты и ноэксепт
class Figure {
public:

    // Конструкторы
    Figure();

    Figure(size_t n);

    Figure(size_t n, Point* verts);

    // Конструктор копирования
    Figure(const Figure& other);

    // Оператор присваивания копиованием
    Figure& operator=(const Figure& other);

    // Конструктор перемещения
    Figure(Figure&& other);

    // Конструктор присваивания перемещением
    Figure& operator=(Figure&& other);

    // Деструктор
    virtual ~Figure();

    // Геометрический центр (центроид)
    virtual Point center() const;

    // Чтение/запись
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

    // Площадь через приведение к double
    virtual operator double() const = 0;

    // Проверка на равенство
    virtual bool equals(const Figure& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Figure& f) {
        f.write(out);
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Figure& f) {
        f.read(in);
        return in;
    }

protected:
    size_t vertices_num;
    Point* vertices;
};