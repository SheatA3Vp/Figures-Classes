#include "../include/figure.hpp"

// Конструкторы
Figure::Figure() : Figure(1) {}

Figure::Figure(size_t n) : vertices_num(n) {
    this->vertices = new Point[n];

    for (size_t i = 0; i < n; ++i) {
        this->vertices[i] = Point();
    }
}

Figure::Figure(size_t n, Point* verts) : vertices_num(n) {
    if (verts != nullptr) {
        this->vertices = new Point[n];

        for (size_t i = 0; i < n; ++i) {
            this->vertices[i] = verts[i];
        }        
    }
}

// Конструктор копирования
Figure::Figure(const Figure& other) : vertices_num(other.vertices_num) {
    size_t n = other.vertices_num;
    this->vertices = new Point[n];

    for (size_t i = 0; i < n; ++i) {
        this->vertices[i] = other.vertices[i];
    }
}

// Оператор присваивания копированием
Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        delete[] this->vertices;
        this->vertices_num = other.vertices_num;
        this->vertices = new Point[other.vertices_num];

        for (size_t i = 0; i < this->vertices_num; ++i) {
            this->vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

// Конструктор перемещения
Figure::Figure(Figure&& other) noexcept : vertices_num(other.vertices_num), vertices(other.vertices) {
    other.vertices_num = 0;
    other.vertices = nullptr;
}

// Оператор присваивания перемещением
Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        delete[] this->vertices;
        this->vertices = other.vertices;
        this->vertices_num = other.vertices_num;
        other.vertices = nullptr;
        other.vertices_num = 0;
    }

    return *this;
}

// Деструктор
Figure::~Figure() {
    delete[] this->vertices;
}

// Чтение и запись
void Figure::read(std::istream& in) {
    size_t n;
    in >> n;
    this->vertices_num = n;

    for (size_t i = 0; i < n; ++i) {
        in >> this->vertices[i];
    }
}

void Figure::write(std::ostream& out) const {
    for (size_t i = 0; i < this->vertices_num; ++i) {
        Point p = this->vertices[i];
        out << p << " ";
    }
}

// Проверка на равенство
bool Figure::equals(const Figure& other) const {
    if (!(this->vertices_num == other.vertices_num)) return false;

    for (size_t i = 0; i < this->vertices_num; ++i) {
        if (this->vertices[i] != other.vertices[i]) return false;
    }

    return true;
}

// Нахождение центроида
Point Figure::center() const {
    Point center;
    for (size_t i = 0; i < this->vertices_num; ++i) {
        center = center + this->vertices[i];
    }
    return center / this->vertices_num;
}