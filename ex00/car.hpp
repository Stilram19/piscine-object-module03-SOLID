#ifndef CAR_HPP
# define CAR_HPP

# include "header.hpp"

// Since this is a very minimalist implementation, which has design learning purposes
// we can consider all the classes as single responsible, but as the implementation 
// goes deeper in another serious implementation, 
// it might not be the case.

class Car {
    // Attributes
    private:
    // the frame is the only part that's contained (by composition),
    // in my very minimalist car's implementation,
    // I see it like the necessary condition for recognizing a car.
    // all the other components can be replaced. (aggregation)
        Frame           chassis;
        Engine          *engine;
        GearLever       *gear_lever;
        SteerWheel      *steer_wheel;
        BrakePedal      *brakes;
        EmergencyBrakes *emergency_brakes;
        RearWheels      *rear_wheels;
        FrontWheels     *front_wheels;

    private:
        Car(const Car &other);
        Car &operator=(const Car &other) { return (*this); }

    public:
        Car(int chassis_material, Engine *engine = NULL, GearLever *gear_lever = NULL, \
            SteerWheel *steer_wheel = NULL, BrakePedal *brakes = NULL, \
            EmergencyBrakes *emergency_brakes = NULL) : chassis(chassis_material)
        {
                this->engine = engine;
                this->gear_lever = gear_lever;
                this->steer_wheel = steer_wheel;
                this->brakes = brakes;
                this->emergency_brakes = emergency_brakes;
                std::cout << "Car constructed successfully!" << std::endl;
                
        }

        ~Car() {
            std::cout << "Car destroyed successfully!" << std::endl;
        }

    public:
        void start() {
            if (this->engine) {
                this->engine->start();
                return ;
            }
            std::cout << "The car doesn't have an engine!" << std::endl;
        }

        void stop() {
            if (this->engine) {
                this->engine->stop();
                return ;
            }
            std::cout << "The car doesn't have an engine!" << std::endl;
        }

        void accelerate(float speed) {
            
        }

        void shift_gears_up() {
            if (this->gear_lever) {
                this->gear_lever->switch_up();
                return ;
            }
            std::cout << "The car doesn't have a gear_lever!" << std::endl;
        }

        void shift_gears_down() {
            if (this->gear_lever) {
                this->gear_lever->switch_down();
                return ;
            }
            std::cout << "The car doesn't have a gear_lever!" << std::endl;
        }

        // puts the transmission in reverse gear
        void reverse() {
            if (this->gear_lever) {
                this->gear_lever->reverse();
                return ;
            }
            std::cout << "The car doesn't have a gear_lever!" << std::endl;
        }

        void turn_wheel(float angle) {
        }

        void straighten_wheels() {

        }

        void apply_force_on_brakes(float force) {
            if (this->brakes) {
                this->brakes->apply_force(force);
                return ;
            }
            std::cout << "The car doesn't have emergency brakes!" << std::endl;
        }

        void apply_emergency_brakes() {
            if (this->emergency_brakes) {
                this->emergency_brakes->apply();
                return ;
            }
            std::cout << "The car doesn't have emergency brakes!" << std::endl;
        }
};

#endif
