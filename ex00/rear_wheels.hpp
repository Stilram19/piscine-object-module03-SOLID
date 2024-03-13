#ifndef REAR_WHEELS_HPP
# define REAR_WHEELS_HPP

# include "rear_wheel.hpp"

class RearWheels {
    private:
        RearWheel *left_wheel;
        RearWheel *right_wheel;

    private:
        RearWheels(const RearWheels &other) {}
        RearWheels &operator=(const RearWheels &other) { return (*this); }

    public:
        void add_left_wheel(RearWheel *left_wheel) {
            this->left_wheel = left_wheel;
        }

        void add_right_wheel(RearWheel *right_wheel) {
            this->right_wheel = right_wheel;
        }

        void change_speed(float speed) {
            if (left_wheel == NULL || right_wheel == NULL) {
                throw std::runtime_error("To change rear wheels speed, both wheels must exist");
            }

            this->left_wheel->change_speed(speed);
            this->right_wheel->change_speed(speed);
        }
};

#endif
