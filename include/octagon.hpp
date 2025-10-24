#pragma once

#include <iostream>
#include <memory>
#include "point.hpp"
#include "figure.hpp"

class Octagon : public Figure {
public:
    // Конструкторы
    Octagon();

    Octagon(Point* verts);

    // Конструктор копирования
    Octagon(const Octagon& other);

    // Оператор присваивания копиованием
    Octagon& operator=(const Octagon& other);

    // Конструктор перемещения
    Octagon(Octagon&& other) noexcept;

    // Конструктор присваивания перемещением
    Octagon& operator=(Octagon&& other) noexcept;

    // Деструктор
    virtual ~Octagon() = default;

    // Геометрический центр (центроид)
    virtual Point center() const;

    // Чтение/запись
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

    // Тип фигуры
    virtual std::string type() const override { return "octagon"; }

    // Клонирование
    virtual Figure* clone() const override;

    // Площадь через приведение к double
    virtual operator double() const;

    // Проверка на равенство
    virtual bool equals(const Figure& other) const override;

protected:
    static constexpr size_t OCTAGON_VERTICES = 8;
};