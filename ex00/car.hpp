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
        Frame               chassis;
        FrontWheels         *front_wheels;
        RearWheels          *rear_wheels;
        BrakePedal          *brake_pedal;
        Transmission        *current_transmission;
        Crankshaft          *current_crankshaft;
        Engine              *engine;
        GearLever           *gear_lever;
        SteerWheel          *steer_wheel;
        EmergencyBrakes     *emergency_brakes;

    private:
        Car(const Car &other);
        Car &operator=(const Car &other) { return (*this); }

    public:
        Car(int chassis_material) : chassis(chassis_material)
        {
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

        void add_fuel(int amount) {
            if (this->engine) {
                this->engine->add_fuel(amount);
            }
        }

        void accelerate(float speed) {
            if (this->engine) {
                this->engine->burn_and_generate_work(speed);
                return ;
            }
            std::cout << "The car doesn't have an engine!" << std::endl;
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
            if (this->steer_wheel) {
                this->steer_wheel->turn(angle);
                return ;
            }
            std::cout << "The car doesn't have a steering wheel!" << std::endl;
        }

        void straighten_wheels() {
            if (this->steer_wheel) {
                this->steer_wheel->straighten();
                return ;
            }
            std::cout << "The car doesn't have a steering wheel!" << std::endl;
        }

        void apply_force_on_brakes(float force) {
            if (this->brake_pedal) {
                this->brake_pedal->apply_force(force);
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

    private:
        // this function attaches the emergency brakes to the new wheel,
        // resets the speed of the four wheels,
        // and updates the wheels for components that are wheel dependent
        void update_wheels_dependent_components(Wheel *new_wheel) {
            // attaching the emergency_brake
            if (new_wheel == NULL) {
                new_wheel->attach_emergency_brake(this->emergency_brakes);
            }

            if (this->front_wheels) {
                this->front_wheels->reset_wheels();
                this->current_transmission->set_wheels(this->front_wheels, this->rear_wheels);
                this->steer_wheel->set_wheels(this->front_wheels);
                this->brake_pedal->set_wheels(this->front_wheels, this->rear_wheels);
                this->emergency_brakes->set_wheels(this->front_wheels, this->rear_wheels);
            }

            if (this->rear_wheels) {
                this->rear_wheels->reset_wheels();
                this->current_transmission->set_wheels(this->front_wheels, this->rear_wheels);
                this->brake_pedal->set_wheels(this->front_wheels, this->rear_wheels);
                this->emergency_brakes->set_wheels(this->front_wheels, this->rear_wheels);
            }
        }

    public:

        // interface to add, remove or replace car components
        // and still ensures integity and good inter_connection between the components
        // shalow copies are just enough

        void set_front_wheel_holder(FrontWheels *front_wheels) {
            this->front_wheels = front_wheels;
        }

        void set_rear_wheel_holder(RearWheels *rear_wheels) {
            this->rear_wheels = rear_wheels;
        }

        void set_front_left_wheel(FrontWheel *left) {
            if (this->front_wheels) {
                this->front_wheels->set_left_wheel(left);
                this->update_wheels_dependent_components(left);
            }
        }

        void set_front_right_wheel(FrontWheel *right) {
            if (this->front_wheels) {
                this->front_wheels->set_left_wheel(right);
                this->update_wheels_dependent_components(right);
            }
        }

        void set_rear_left_wheel(RearWheel *left) {
            if (this->rear_wheels) {
                this->rear_wheels->add_left_wheel(left);
                this->update_wheels_dependent_components(left);
            }
        }

        void set_rear_right_wheel(RearWheel *right) {
            if (this->rear_wheels) {
                this->rear_wheels->add_left_wheel(right);
                this->update_wheels_dependent_components(right);
            }
        }

        void set_transmission(Transmission *transmission) {
            this->current_transmission = transmission;
            if (this->current_transmission) {
                this->current_transmission->set_wheels(this->front_wheels, this->rear_wheels);
            }
            this->current_crankshaft->set_transmission(this->current_transmission);
        }

        void set_crankshaft(Crankshaft *crankshaft) {
            this->current_crankshaft = crankshaft;
            if (this->current_crankshaft) {
                this->current_crankshaft->set_transmission(this->current_transmission);
            }
        }

        void set_engine(Engine *engine) {
            this->engine = engine;
            
            if (this->engine) {
                this->engine->set_crankshaft(this->current_crankshaft);
            }
        }

        void set_gear_lever(GearLever *gear_lever) {
            this->gear_lever = gear_lever;
        }

        void set_steer_wheel(SteerWheel *steer_wheel) {
            this->steer_wheel = steer_wheel;

            if (this->steer_wheel) {
                this->steer_wheel->set_wheels(this->front_wheels);
            }
        }

        void set_brake_pedal(BrakePedal *brake_pedal) {
            this->brake_pedal = brake_pedal;
            if (this->brake_pedal) {
                this->brake_pedal->set_wheels(this->front_wheels, this->rear_wheels);
            }
        }

        void set_emergency_brakes(EmergencyBrakes *emergency_brakes) {
            this->emergency_brakes = emergency_brakes;
            if (this->emergency_brakes) {
                this->emergency_brakes->set_wheels(this->front_wheels, this->rear_wheels);
            }
        }
};

#endif
