#ifndef REAR_WHEEL_HPP
# define REAR_WHEEL_HPP

# include "wheel.hpp"

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
            this->reset_speed();
        }

        void release_wheel() {
            this->is_wheel_stoped = false;
        }

        virtual void change_speed(float speed) {
            if (this->is_wheel_stoped == true) {
                throw std::runtime_error("Emergency brakes applied: cannot move rear wheels!");
            }
            // if emergency brakes aren't applied, it's the same logic
            Wheel::change_speed(speed);
        }
};

#endif