#ifndef EMERGENCY_BRAKES_HPP
# define EMERGENCY_BRAKES_HPP

# include "front_wheels.hpp"
# include "rear_wheels.hpp"

enum e_brakes_status {
    NOT_APPLIED, APPLIED
};

class EmergencyBrakes {
    private:
        bool         status;
        FrontWheels *front_wheels;
        RearWheels  *rear_wheels;

    private:
        EmergencyBrakes(const EmergencyBrakes &other) {}
        EmergencyBrakes &operator=(const EmergencyBrakes &other) { return (*this); }

    public:
        EmergencyBrakes() : status(NOT_APPLIED) {}
        ~EmergencyBrakes() {}
        
    public:
        void apply() {
            if (status == NOT_APPLIED) {
                this->status = APPLIED;
                std::cout << "Brakes applied" << std::endl;
            }

            std::cout << "Using Emergency brakes..." << std::endl;
            int speed = this->front_wheels->get_max_speed(); // the max speed that a wheel can support

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

        bool is_applied() const {
            return (this->status == APPLIED);
        }

        void set_wheels(FrontWheels *front_wheels, RearWheels *rear_wheels) {
            this->front_wheels = front_wheels;
            this->rear_wheels = rear_wheels;
        }
};

#endif