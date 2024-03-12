#ifndef WHEEL_HPP
# define WHEEL_HPP

# include <iostream>

enum e_special_speeds {
    NO_ROTATION_SPEED = 0, MAX_SPEED = 100, BRAKE_AMOUNT = -10
};

class Wheel {
    protected:
        float rotation_speed;

    private:
        Wheel(const Wheel &other) {}
        Wheel &operator=(const Wheel &other) { return (*this); }

    public:
        Wheel() : rotation_speed(NO_ROTATION_SPEED) {}
        ~Wheel() {}

    public:
        // the added speed can be positive as well as negative.
        void change_speed(int added_speed) {
            this->rotation_speed += added_speed;

            // these two checks are here to catch overflows and underflows
            if (added_speed > MAX_SPEED) {
                this->rotation_speed = MAX_SPEED;
            }

            if (added_speed < (-1) * MAX_SPEED) {
                this->rotation_speed = NO_ROTATION_SPEED;
            }

            // these guards are safe from underflows and overflows
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
};

#endif