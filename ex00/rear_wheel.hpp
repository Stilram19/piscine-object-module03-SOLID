#ifndef REAR_WHEEL_HPP
# define REAR_WHEEL_HPP

# include "wheel.hpp"

// this class might seem useless, but in the design it's very important,
// because in a serious implementation, rear wheels might have something to say

class RearWheel : public Wheel
{
    private:
        bool is_wheel_stoped; // this is for synchronization with emergency brakes

    private:
        RearWheel(const RearWheel &other);
        RearWheel &operator=(const RearWheel &other);

    public:
        RearWheel() : is_wheel_stoped(false) {}
        ~RearWheel() {}

    public:
        void stop_wheel() {
            this->is_wheel_stoped = true;
        }

        void release_wheel() {
            this->is_wheel_stoped = false;
        }

        virtual void change_speed(float speed) {
            if (this->is_wheel_stoped == true) {
                std::cout << "Can't change speed! emergency brakes are applied!" << std::endl;
                return ;
            }
            // if emergency brakes aren't applied, it's the same logic
            Wheel::change_speed(speed);
        }
};

#endif