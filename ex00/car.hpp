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
        FrontWheels         *front_wheel_holder;
        RearWheels          *rear_wheel_holder;
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

        void accelerate(float speed) {
            this->engine->burn_and_generate_work(speed);
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
            this->front_wheel_holder->turn(angle);
        }

        void straighten_wheels() {
            this->front_wheel_holder->straighten();
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

    public:

        // interface to add, remove or replace car components
        // and still ensures integity and good inter_connection between the components
        // shalow copies are just enough

        void set_front_wheel_holder(FrontWheels *front_wheel_holder) {
            this->front_wheel_holder = front_wheel_holder;
        }

        void set_rear_wheel_holder(RearWheels *rear_wheel_holder) {
            this->rear_wheel_holder = rear_wheel_holder;
        }

        void set_front_left_wheel(FrontWheel *left) {
            if (this->front_wheel_holder) {
                this->front_wheel_holder->set_left_wheel(left);
                this->current_transmission->set_front_wheels(this->front_wheel_holder);
            }
        }

        void set_front_right_wheel(FrontWheel *right) {
            if (this->front_wheel_holder) {
                this->front_wheel_holder->set_left_wheel(right);
                this->current_transmission->set_front_wheels(this->front_wheel_holder);
            }
        }

        void set_rear_left_wheel(RearWheel *left) {
            if (this->rear_wheel_holder) {
                this->rear_wheel_holder->add_left_wheel(left);
                this->current_transmission->set_rear_wheels(this->rear_wheel_holder);
            }
        }

        void add_rear_right_wheel(RearWheel *right) {
            if (this->rear_wheel_holder) {
                this->rear_wheel_holder->add_left_wheel(right);
                this->current_transmission->set_rear_wheels(this->rear_wheel_holder);

            }
        }

        void set_transmission(Transmission *transmission) {
            this->current_transmission = transmission;
            if (this->current_transmission) {
                this->current_transmission->set_front_wheels(this->front_wheel_holder);
                this->current_transmission->set_rear_wheels(this->rear_wheel_holder);
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
        }

        void set_brake_pedal(BrakePedal *brake_pedal) {
            this->brake_pedal = brake_pedal;
        }

        void set_emergency_brakes(EmergencyBrakes *emergency_brakes) {
            this->emergency_brakes = emergency_brakes;
        }
};

#endif
