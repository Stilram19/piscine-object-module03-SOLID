# include "car.hpp"

// this exercise is about designing the Car class respecting
// the Single Responsibility principle, every class should be single responsible.
// For instance, the responsibility of the Car class is to ensure the interconnection,
// synchronization of its components, and this is the only reason it could be changed for.


// a car with no components
void test1() {
    Car car(Frame::ALUMINUM);

    car.start();
    car.stop();
    car.apply_emergency_brakes();
    car.accelerate(5);
    car.add_fuel(12);
    car.reverse();
    car.shift_gears_up();
    car.shift_gears_down();
    car.apply_force_on_brakes(12);
    car.turn_wheel(12);
    car.straighten_wheels();
}

void test2() {
    float force = 10;
    FrontWheel front_left;
    FrontWheel front_right;
    RearWheel rear_left;
    RearWheel rear_right;
    BrakePedal pedal;
    Transmission transmission;
    Crankshaft  crankshaft;
    Engine      engine;
    Car car(Frame::STEEL);

    car.set_brake_pedal(&pedal);
    car.set_crankshaft(&crankshaft);
    car.set_transmission(&transmission);
    car.set_engine(&engine);
    car.set_front_left_wheel(&front_left);

}

int main() {
    try {
        // test1();
        test2();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
