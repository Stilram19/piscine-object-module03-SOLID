#ifndef BRAKEPEDAL_HPP
# define BRAKEPEDAL_HPP

# include <iostream>
# include "front_wheels.hpp"
# include "rear_wheels.hpp"

enum e_special_forces {
    LOW_FORCE = 5, MID_FORCE = 10, HIGH_FORCE = 20
};

class BrakePedal {
    private:
        FrontWheels *front_wheels;
        RearWheels *rear_wheels;

    private:
        BrakePedal(const BrakePedal &other) {}
        BrakePedal &operator=(const BrakePedal &other) { return (*this); }

    public:
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
                    this->front_wheels->change_speed(-1);
                    this->rear_wheels->change_speed(-1);
                }
            }
            catch (const std::runtime_error &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        void set_wheels(FrontWheels *front_wheels, RearWheels *rear_wheels) {
            this->front_wheels = front_wheels;
            this->rear_wheels = rear_wheels;
        }
};

#endif