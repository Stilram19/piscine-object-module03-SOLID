#ifndef REAR_WHEELS_HPP
# define REAR_WHEELS_HPP

# include "rear_wheel.hpp"
# include "two_wheels.hpp"

class RearWheels : public TwoWheels<RearWheel>
{
    private:
        RearWheels(const RearWheels &other);
        RearWheels &operator=(const RearWheels &other);

    public:
        RearWheels() : TwoWheels<RearWheel>() {}
        RearWheels(RearWheel *left_wheel, RearWheel *right_wheel) :  TwoWheels<RearWheel>(left_wheel, right_wheel) {}
        ~RearWheels() {}

    public:
        void stop_wheels() {
            if (this->left_wheel) {
                this->left_wheel->stop_wheel();
            }
            if (this->right_wheel) {
                this->right_wheel->stop_wheel();
            }
        }

        void release_wheels() {
            if (this->left_wheel) {
                this->left_wheel->release_wheel();
            }
            if (this->right_wheel) {
                this->right_wheel->release_wheel();
            }  
        }

        RearWheel *get_left_wheel() const {
            return (this->left_wheel);
        }

        RearWheel *get_right_wheel() const {
            return (this->right_wheel);
        }
};

#endif
