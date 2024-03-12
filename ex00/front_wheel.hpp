#ifndef FRONT_WHEEL_HPP
# define FRONT_WHEEL_HPP

enum e_special_angles {
    STRAIGHT_ANGLE = 0, MIN_ANGLE = -30, MAX_ANGLE = 30
};

class FrontWheel {
    private:
        float rotation_angle;

    private:
        FrontWheel(const FrontWheel &other) {}
        FrontWheel &operator=(const FrontWheel &other) { return (*this); }

    public:
        FrontWheel() : rotation_angle(0) {}
        ~FrontWheel() {}

    public:

}

#endif