#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <iostream>
# include <cmath>
# include "shape.hpp"

class Triangle : public Shape {
    public:
        double a;
        double b;
        double c;

    public:
        Triangle() : a(0), b(0), c(0) {}

        Triangle(double a, double b, double c) : a(a), b(b), c(c) {
            if (a < 0 || b < 0 || c < 0) {
                throw std::runtime_error("Triangle sides cannot be negative!");
            }

            if (a + b <= c || a + c <= b || b + c <= a) {
                throw std::runtime_error("The given sides violates the triangle's inequality!");
            }
        }

        ~Triangle() {}

    public:
        virtual double calculate_area() const {
            double s = this->calculate_perimeter() / 2.0;

            return (sqrt(s * (s - this->a) * (s - this->b) * (s - this->c)));
        }

        virtual double calculate_perimeter() const {
            return (this->a + this->b + this->c);
        }
};

#endif