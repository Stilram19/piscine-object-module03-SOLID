#ifndef TRANSMISSION_HPP
# define TRANSMISSION_HPP

# include "front_wheels.hpp"
# include "rear_wheels.hpp"

class Transmission {
    private:
        FrontWheels *front_wheels;
        RearWheels  *rear_wheels;

    private:
        Transmission(const Transmission &other);
        Transmission &operator=(const Transmission &other);

    public:
        Transmission() {}
        ~Transmission() {}

    public:
        void set_wheels(FrontWheels *front_wheels, RearWheels *rear_wheels) {
            this->front_wheels = front_wheels;
            this->rear_wheels = rear_wheels;
        }

    public:
        // activates the mechanical engergy produced by the engine (through the crankshaft)
        void activate(float force) {
            if (front_wheels == NULL || rear_wheels == NULL) {
                std::cout << "Energy dissipated: There must be 4 wheels!" << std::endl;
                return ;
            }

            int count = force > 0 ? force : (-1) * force;
            int speed = force > 0 ? 1 : -1;

            try {
                while (count--) {
                    this->front_wheels->change_speed(speed);
                    this->rear_wheels->change_speed(speed);
                }
            }
            catch (const std::runtime_error &e) {
                std::cout << "ERROR: " << e.what() << std::endl;
            }
        }
};

#endif