#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include <iostream>
# include "shape.hpp"

// this subclass 

class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle() : width(0), height(0) {}
        Rectangle(double width, double height) : width(width), height(height) {
            if (width < 0 || height < 0) {
                throw std::runtime_error("Rectangle sides cannot be negative!");
            }
        }
        ~Rectangle() {}

    public:
        virtual double calculate_area() const {
            return (width * height);
        }

        virtual double calculate_perimeter() const {
            return ((width + height) * 2);
        }
};

#endif