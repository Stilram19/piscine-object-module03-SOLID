#ifndef CAR_HPP
# define CAR_HPP

# include "header.hpp"

class Car {
    // Attributes
    private:
        // engine, brakes, accelerator, gear_lever, wheel
        Engine engine;
        GearLever gear_lever;
        

    public:
        Car() {}
        ~Car() {}

    public:
        void start() {
            this->engine.start();
        }

        void stop() {
            this->engine.stop();
            this->apply_emergency_brakes();
        }

        void accelerate(float speed) {

        }

        void shift_gears_up() {
            this->gear_lever.switch_up();
        }

        void shift_gears_down() {
            this->gear_lever.switch_down();
        }

        // puts the transmission in reverse gear
        void reverse() {
            this->gear_lever.reverse();
        }

        void turn_wheel(float angle) {
        }

        void straighten_wheels() {}

        void apply_force_on_brakes(float force) {}

        void apply_emergency_brakes() {}
};

#endif