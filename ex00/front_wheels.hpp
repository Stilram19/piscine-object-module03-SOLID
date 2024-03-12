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
        FrontWheels(FrontWheel *left_wheel, FrontWheel *right_wheel) \
            : left_wheel(left_wheel), right_wheel(right_wheel) {}
        ~FrontWheels() {}

    public:
        void turn(float angle) {
            if (left_wheel == NULL || right_wheel == NULL) {
                std::cout << "FrontWheels missing wheels!" << std::endl;
                return ;
            }

            left_wheel->turn(angle);
            right_wheel->turn(angle);
        }

        void straighten() {
            if (left_wheel == NULL || right_wheel == NULL) {
                std::cout << "FrontWheels missing wheels!" << std::endl;
                return ;
            }

            left_wheel->straighten();
            right_wheel->straighten();
        }
};

#endif