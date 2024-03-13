#ifndef STEERWHEEL_HPP
# define STEERWHEEL_HPP

# include "front_wheels.hpp"

class SteerWheel {
    private:
        FrontWheels *front_wheels;

    private:
        SteerWheel(const SteerWheel &other) {}
        SteerWheel &operator=(const SteerWheel &other) { return (*this); }

    public:
        SteerWheel(FrontWheels *front_wheels) : front_wheels(front_wheels) {}
        ~SteerWheel() {}

    public:
        void turn(float angle) {
            if (this->front_wheels) {
                this->front_wheels->turn(angle);
            }
        }

        void straighten() {
            if (this->front_wheels) {
                this->front_wheels->straighten();
            }
        }
};

#endif