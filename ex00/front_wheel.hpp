#ifndef FRONT_WHEEL_HPP
# define FRONT_WHEEL_HPP

# include "wheel.hpp"

class FrontWheel : public Wheel
{
    private:
        float angle;

    private:
        enum e_special_angles {
            STRAIGHT_ANGLE = 0, MIN_ANGLE = -30, MAX_ANGLE = 30
        };

    private:
        FrontWheel(const FrontWheel &other);
        FrontWheel &operator=(const FrontWheel &other);

    public:
        FrontWheel() : Wheel(), angle(STRAIGHT_ANGLE) {}
        ~FrontWheel() {}

    public:
        void turn(float angle) {

            // these two checks are here to catch overflows and underflows
            if (angle > MAX_ANGLE * 2) {
                angle = MAX_ANGLE * 2;
            }
            if (angle < MIN_ANGLE * 2) {
                angle = MIN_ANGLE * 2;
            }

            this->angle += angle;

            // ensure that the angle is within the range.
            if (this->angle > MAX_ANGLE) {
                this->angle = MAX_ANGLE;
            }
            if (this->angle < MIN_ANGLE) {
                this->angle = MIN_ANGLE;
            }

            std::cout << "Wheels turned! current angle: " << this->angle << std::endl;
        }

        void straighten() {
            this->angle = STRAIGHT_ANGLE;
            std::cout << "Wheels are straight! current angle: " << this->angle << std::endl;
        }

        float get_angle() const {
            return (this->angle);
        }
};

#endif