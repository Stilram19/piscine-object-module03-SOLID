#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape {
    public:
        virtual double calculate_area() const = 0;
        virtual double calculate_perimeter() const = 0;
};

#endif