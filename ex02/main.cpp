# include "circle.hpp"
# include "rectangle.hpp"
# include "triangle.hpp"

#include <cassert> // for assert()

int main() {
    // Test Circle
    Circle circle1(5.0);
    assert(circle1.calculate_area() == 78.53981633974483); // area of circle with radius 5.0
    assert(circle1.calculate_perimeter() == 31.41592653589793); // perimeter of circle with radius 5.0

    // Test Triangle
    Triangle triangle(3.0, 4.0, 5.0);
    assert(triangle.calculate_area() == 6.0); // area of triangle with sides 3, 4, 5 (a Pythagorean triple)
    assert(triangle.calculate_perimeter() == 12.0); // perimeter of triangle with sides 3, 4, 5

    // Test Rectangle
    Rectangle rectangle(4.0, 6.0);
    assert(rectangle.calculate_area() == 24.0);
    assert(rectangle.calculate_perimeter() == 20.0);

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
