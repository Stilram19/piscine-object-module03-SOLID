#ifndef WHEEL_HPP
# define WHEEL_HPP

# include <iostream>

enum e_special_speeds {
    NO_ROTATION_SPEED = 0, MAX_SPEED = 100
};

class Wheel {
    private:
        float rotation_speed;

    private:
        Wheel(const Wheel &other) {}
        Wheel &operator=(const Wheel &other) { return (*this); }

    public:
        Wheel() : rotation_speed(0) {}
};

#endif