#ifndef EMERGENCY_BRAKES_HPP
# define EMERGENCY_BRAKES_HPP

# include "Wheel.hpp"

enum e_brakes_status {
    NOT_APPLIED, APPLIED
};

class EmergencyBrakes {
    private:
        bool status;

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
        }
};

#endif