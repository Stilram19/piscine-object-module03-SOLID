#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include <iostream>
# include <cmath>
# include "shape.hpp"

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle() : radius(0) {}

        Circle(double radius) : radius(radius) {
            if (radius < 0) {
                throw std::runtime_error("Radius cannot be negative!");
            }
        }

        ~Circle() {}

    public:
        virtual double calculate_area() const {
            return (M_PI * this->radius * this->radius);
        }

        virtual double calculate_perimeter() const {
            return (2 * M_PI * this->radius);
        }
};

#endif