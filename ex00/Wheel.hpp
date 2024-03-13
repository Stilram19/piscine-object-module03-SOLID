#ifndef WHEEL_HPP
# define WHEEL_HPP

# include <iostream>
# include "emergency_brakes.hpp"

enum e_special_speeds {
    NO_ROTATION_SPEED = 0, MAX_SPEED = 100, BRAKE_AMOUNT = -10
};

class Wheel {
    protected:
        float           rotation_speed;
        EmergencyBrakes *current_car_emergency_brakes;

    private:
        Wheel(const Wheel &other) {}
        Wheel &operator=(const Wheel &other) { return (*this); }

    public:
        Wheel() : rotation_speed(NO_ROTATION_SPEED), current_car_emergency_brakes(NULL) {}
        ~Wheel() {}

    private:
        bool is_emergency_brakes_applied() {
            if (this->current_car_emergency_brakes) {
                return (this->current_car_emergency_brakes->is_applied());
            }
            return (false);
        }

    public:
        // the added speed can be positive as well as negative.
        void change_speed(float added_speed) {

            if (this->is_emergency_brakes_applied()) {
                std::cout << "Can't change speed! emergency brakes are applied!" << std::endl;
                return ;
            }
 
            // these two checks are here to catch overflows and underflows
            if (added_speed > MAX_SPEED) {
                added_speed = MAX_SPEED;
            }

            if (added_speed < (-1) * MAX_SPEED) {
                added_speed = NO_ROTATION_SPEED;
            }

            this->rotation_speed += added_speed;

            // ensure that the speed is within the range.
            if (this->rotation_speed > MAX_SPEED) {
                this->rotation_speed = MAX_SPEED;
            }

            if (this->rotation_speed < NO_ROTATION_SPEED) {
                this->rotation_speed = NO_ROTATION_SPEED;
            }

            std::cout << "Speed change called! Current Speed: " << this->rotation_speed << std::endl;
        }

        float get_rotation_speed() {
            return (this->rotation_speed);
        }

    public:
        void reset_speed() {
            this->rotation_speed = NO_ROTATION_SPEED;
        }

        void attach_emergency_brake(EmergencyBrakes *emergency_brakes) {
            this->current_car_emergency_brakes = emergency_brakes;
        }
};

#endif