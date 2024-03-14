#ifndef FRONT_WHEEL_HPP
# define FRONT_WHEEL_HPP

# include "wheel.hpp"

enum e_special_angles {
    STRAIGHT_ANGLE = 0, MIN_ANGLE = -30, MAX_ANGLE = 30
};

class FrontWheel : public Wheel
{
    private:
        float angle;

    private:
        FrontWheel(const FrontWheel &other);
        FrontWheel &operator=(const FrontWheel &other);

    public:
        FrontWheel() : Wheel(), angle(STRAIGHT_ANGLE) {}
        ~FrontWheel() {}

    public:
        void turn(float angle) {

            // these two checks are here to catch overflows and underflows
            if (angle > MAX_ANGLE) {
                angle = MAX_ANGLE;
            }
            if (angle < MIN_ANGLE) {
                angle = MIN_ANGLE;
            }

            this->angle += angle;

            // ensure that the angle is within the range.
            if (this->angle > MAX_ANGLE) {
                this->angle = MAX_ANGLE;
            }
            if (this->angle < MIN_ANGLE) {
                this->angle = MIN_ANGLE;
            }

            std::cout << "Wheel turn called! current angle: " << this->angle << std::endl;
        }

        void straighten() {
            this->angle = STRAIGHT_ANGLE;
        }

        float get_angle() const {
            return (this->angle);
        }
};

#endif