#ifndef BRAKEPEDAL_HPP
# define BRAKEPEDAL_HPP

# include <iostream>
# include "front_wheel.hpp"
# include "rear_wheel.hpp"
# include "two_wheels.hpp"

class BrakePedal {
    private:
        TwoWheels<FrontWheel>   *front_wheels;
        TwoWheels<RearWheel>  *rear_wheels;

    private:
        enum e_special_forces {
            LOW_FORCE = 5, MID_FORCE = 10, HIGH_FORCE = 20
        };

    private:
        BrakePedal(const BrakePedal &other);
        BrakePedal &operator=(const BrakePedal &other);

    public:
        BrakePedal() : front_wheels(NULL), rear_wheels(NULL) {}
        ~BrakePedal() {}

    public:
        void apply_force(float force) {
            if (this->front_wheels == NULL || this->rear_wheels == NULL) {
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
                    this->rear_wheels->change_speed(-1);// always try rear wheels first, because emergency brakes might be applied
                    this->front_wheels->change_speed(-1);
                }
            }
            catch (const std::runtime_error &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        void set_wheels(TwoWheels<FrontWheel> *front_wheels, TwoWheels<RearWheel> *rear_wheels) {
            this->front_wheels = front_wheels;
            this->rear_wheels = rear_wheels;
        }
};

#endif