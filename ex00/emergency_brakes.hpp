#ifndef EMERGENCY_BRAKES_HPP
# define EMERGENCY_BRAKES_HPP

# include "front_wheels.hpp"
# include "rear_wheels.hpp"

class EmergencyBrakes {
    private:
        bool         status;
        RearWheels  *rear_wheels;
        FrontWheels *front_wheels;

    private:
        enum e_brakes_status {
            RELEASED, APPLIED
        };

    private:
        EmergencyBrakes(const EmergencyBrakes &other);
        EmergencyBrakes &operator=(const EmergencyBrakes &other);

    public:
        EmergencyBrakes() : status(RELEASED), rear_wheels(NULL), front_wheels(NULL) {}
        ~EmergencyBrakes() {}

    public:
        void apply() {
            if (this->status == APPLIED) {
                return ;
            }

            if (this->rear_wheels == NULL || this->front_wheels == NULL) {
                std::cout << "no wheels attached to the emergency brakes!" << std::endl;
                return ;
            }

            this->status = APPLIED;

            std::cout << "Using Emergency brakes..." << std::endl;


            try {
                while (this->rear_wheels->get_current_speed() != 0) {
                    this->rear_wheels->change_speed(-1);
                    this->front_wheels->change_speed(-1);
                }
                this->rear_wheels->stop_wheels();
            }
            catch (const std::runtime_error &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        void release() {
            if (this->status == RELEASED) {
                return ;
            }

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

        void set_wheels(RearWheels *rear_wheels, FrontWheels *front_wheels) {
            this->front_wheels = front_wheels;
            this->rear_wheels = rear_wheels;
        }
};

#endif