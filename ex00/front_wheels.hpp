#ifndef FRONT_WHEELS_HPP
# define FRONT_WHEELS_HPP

# include "front_wheel.hpp"
# include "two_wheels.hpp"

class FrontWheels :public TwoWheels<FrontWheel>
{
    private:
        FrontWheels(const FrontWheels &other);
        FrontWheels &operator=(const FrontWheels &other);

    public:
        FrontWheels(FrontWheel *left_wheel, FrontWheel *right_wheel) : TwoWheels<FrontWheel>(left_wheel, right_wheel) {}
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

    public:
        FrontWheel *get_left_wheel() const {
            return (this->left_wheel);
        }

        FrontWheel *get_right_wheel() const {
            return (this->right_wheel);
        }
};

#endif