#ifndef FRONT_WHEELS_HPP
# define FRONT_WHEELS_HPP

# include "front_wheel.hpp"

class FrontWheels {
    private:
        FrontWheel *left_wheel;
        FrontWheel *right_wheel;

    private:
        FrontWheels(const FrontWheels &other) {}
        FrontWheels &operator=(const FrontWheels &other) { return (*this); }

    public:
        FrontWheels(FrontWheel *left_wheel, FrontWheel *right_wheel) :\
            left_wheel(left_wheel), right_wheel(right_wheel) {}
        ~FrontWheels() {}

    public:
        void turn(float angle) {
            this->left_wheel->turn(angle);
            this->right_wheel->turn(angle);
            std::cout << "FrontWheels turned!" << std::endl;
        }

        void straighten() {
            this->left_wheel->straighten();
            this->right_wheel->straighten();
        }

        void set_left_wheel(FrontWheel *left_wheel) {
            this->left_wheel = left_wheel;

            // ensuring that both wheels have the same speed
            if (this->left_wheel) {
                this->left_wheel->reset_speed();
            }

            if (this->right_wheel) {
                this->right_wheel->reset_speed();
            }
        }

        void set_right_wheel(FrontWheel *right_wheel) {
            this->right_wheel = right_wheel;
        }

        void change_speed(float speed) {
            if (left_wheel == NULL || right_wheel == NULL) {
                throw std::runtime_error("To change front wheels speed, both wheels must exist!");
            }

            this->left_wheel->change_speed(speed);
            this->right_wheel->change_speed(speed);
        }

        void reset_wheels() {
            if (this->left_wheel) {
                this->left_wheel->reset_speed();
            }
            if (this->right_wheel) {
                this->right_wheel->reset_speed();
            }
        }

    public:
        int get_max_speed() const {
            if (this->left_wheel) {
                return (this->left_wheel->get_max_speed());
            }
            if (this->right_wheel) {
                return (this->right_wheel->get_max_speed());
            }
            return (0);
        }
};

#endif