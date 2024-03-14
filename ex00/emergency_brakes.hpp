#ifndef EMERGENCY_BRAKES_HPP
# define EMERGENCY_BRAKES_HPP

# include "front_wheels.hpp"
# include "rear_wheels.hpp"

class EmergencyBrakes {
    private:
        bool         status;
        RearWheels  *rear_wheels;

    private:
        enum e_brakes_status {
            RELEASED, APPLIED
        };

    private:
        EmergencyBrakes(const EmergencyBrakes &other);
        EmergencyBrakes &operator=(const EmergencyBrakes &other);

    public:
        EmergencyBrakes() : status(RELEASED) {}
        ~EmergencyBrakes() {}

    public:
        void apply() {
            this->status = APPLIED;

            if (this->rear_wheels == NULL) {
                std::cout << "no wheels attached to the emergency brakes!" << std::endl;
                return ;
            }

            this->rear_wheels->stop_wheels();

            std::cout << "Using Emergency brakes..." << std::endl;
            int speed = this->rear_wheels->get_max_speed(); // the max speed that a wheel can support

            try {
                while (speed--) {
                    this->rear_wheels->change_speed(-1);
                }
            }
            catch (const std::runtime_error &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        void release() {
            this->status = RELEASED;

            if (this->rear_wheels == NULL) {
                std::cout << "No wheels attached to the emergency brakes!" << std::endl;
                return ;
            }

            this->rear_wheels->release_wheels();
        }

        bool is_applied() const {
            return (this->status == APPLIED);
        }

        void set_wheels(RearWheels *rear_wheels) {
            this->rear_wheels = rear_wheels;
        }
};

#endif