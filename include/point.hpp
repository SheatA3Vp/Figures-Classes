#pragma once

#include <iostream>

struct Point {
    double x = 0.0;
    double y = 0.0;

    bool operator!=(const Point& other) {
        if (other.x != this->x || other.y != this->y) return false;
        return true;
    }

    Point operator+(const Point& other) {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        return p;
    }

    Point operator/(const size_t n) {
        Point p;
        double n_dbl = static_cast<double>(n);
        p.x = this->x / n_dbl;
        p.y = this->y / n_dbl;
        return p;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << '(' << p.x << ", " << p.y << ')';
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Point& p) {
        in >> std::ws; // Пропускаем пробелы
        if (!in)
            return in;

        if (!(in >> p.x >> p.y)) {
            in.setstate(std::ios::failbit);
            return in;
        }

        return in;
    }
};