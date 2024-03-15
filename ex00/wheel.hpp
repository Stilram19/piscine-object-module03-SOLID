#ifndef WHEEL_HPP
# define WHEEL_HPP

# include <iostream>

class Wheel {
    protected:
        float   rotation_speed;

    private:
        enum e_special_speeds {
            NO_ROTATION_SPEED = 0, MAX_SPEED = 100, BRAKE_AMOUNT = -10
        };

    private:
        Wheel(const Wheel &other);
        Wheel &operator=(const Wheel &other);

    public:
        Wheel() : rotation_speed(NO_ROTATION_SPEED) {}
        virtual ~Wheel() {}

    public:
        // the added speed can be positive as well as negative.
        virtual void change_speed(float added_speed) {
 
            // these two checks are here to catch overflows and underflows
            if (added_speed > MAX_SPEED) {
                added_speed = MAX_SPEED;
            }

            if (added_speed < (-1) * MAX_SPEED) {
                added_speed = (-1) * this->rotation_speed; // this->rotation_speed can't be negative
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

        float get_rotation_speed() const {
            return (this->rotation_speed);
        }

    public:
        void reset_speed() {
            this->rotation_speed = NO_ROTATION_SPEED;
        }

        int get_current_speed() const {
            return (this->rotation_speed);
        }
};

#endif