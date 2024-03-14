#ifndef BRAKEPEDAL_HPP
# define BRAKEPEDAL_HPP

# include <iostream>
# include "front_wheel.hpp"
# include "rear_wheel.hpp"
# include "two_wheels.hpp"

enum e_special_forces {
    LOW_FORCE = 5, MID_FORCE = 10, HIGH_FORCE = 20
};

class BrakePedal {
    private:
        TwoWheels<FrontWheel>   *first_two_wheels;
        TwoWheels<RearWheel>  *second_two_wheels;

    private:
        BrakePedal(const BrakePedal &other);
        BrakePedal &operator=(const BrakePedal &other);

    public:
        BrakePedal() {}
        ~BrakePedal() {}

    public:
        void apply_force(float force) {
            if (this->first_two_wheels == NULL || this->second_two_wheels == NULL) {
                std::cout << "There must be all four wheels, in order to use the brakes!" << std::endl;
                return ;
            }

            int speed = LOW_FORCE;

            force = (force < 0 ? (-1) * force : force);
            if (force >= LOW_FORCE && force <= MID_FORCE) {
                speed = MID_FORCE;
            }
            if (force > MID_FORCE) {
                speed = HIGH_FORCE;
            }

            std::cout << "Using brakes..." << std::endl;
            try {
                while (speed--) {
                    this->first_two_wheels->change_speed(-1);
                    this->second_two_wheels->change_speed(-1);
                }
            }
            catch (const std::runtime_error &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        void set_wheels(TwoWheels<FrontWheel> *first_two_wheels, TwoWheels<RearWheel> *second_two_wheels) {
            this->first_two_wheels = first_two_wheels;
            this->second_two_wheels = second_two_wheels;
        }
};

#endif