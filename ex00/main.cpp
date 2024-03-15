# include "car.hpp"

// this exercise is about designing the Car class respecting
// the Single Responsibility principle, every class should be single responsible.
// For instance, the responsibility of the Car class is to ensure the interconnection,
// synchronization of its components, and this is the only reason it could be changed for.


// a car with no components
// void test1() {
//     Car car(Frame::ALUMINUM);

//     car.start();
//     car.stop();
//     car.apply_emergency_brakes();
//     car.accelerate(5);
//     car.add_fuel(12);
//     car.reverse();
//     car.shift_gears_up();
//     car.shift_gears_down();
//     car.apply_force_on_brakes(12);
//     car.turn_wheel(12);
//     car.straighten_wheels();
// }

// void test2() {
//     float force = 10;
//     FrontWheel front_left;
//     FrontWheel front_right;
//     RearWheel rear_left;
//     RearWheel rear_right;
//     FrontWheels front_wheels;
//     RearWheels rear_wheels;
//     BrakePedal pedal;
//     Transmission transmission;
//     Crankshaft  crankshaft;
//     Engine      engine;
//     Car car(Frame::STEEL);

//     car.set_brake_pedal(&pedal);
//     car.set_crankshaft(&crankshaft);
//     car.set_transmission(&transmission);
//     car.set_engine(&engine);

//     car.set_front_wheel_holder(&front_wheels);
//     car.set_rear_wheel_holder(&rear_wheels);

//     car.set_front_left_wheel(&front_left);
//     car.set_front_right_wheel(&front_right);
//     car.set_rear_left_wheel(&rear_left);
//     car.set_rear_right_wheel(&rear_right);

//     car.accelerate(force);
//     car.start();
//     car.add_fuel(300);
//     car.start();
//     car.accelerate(force);
//     car.accelerate(-11);

//     car.accelerate(10);
//     car.apply_force_on_brakes(force);

//     car.accelerate(20);

//     EmergencyBrakes e;

//     car.set_emergency_brakes(&e);
//     car.apply_emergency_brakes();

//     car.accelerate(10);

//     car.release_emergency_brakes();
//     car.accelerate(10);

//     GearLever g;

//     car.set_gear_lever(&g);
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_up();
//     car.shift_gears_down();

//     SteerWheel s;

//     car.set_steer_wheel(&s);
//     car.turn_wheel(100);
//     car.turn_wheel(-100);
// }

int main() {
    try {
        // test1();
        // test2();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
