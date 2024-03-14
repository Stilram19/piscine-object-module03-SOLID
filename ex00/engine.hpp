#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <iostream>
# include "crankshaft.hpp"

// using the term engine, which is suggested in the subject, means that we're considering fuel vehicles.
// Motor is used more for electrical vehicles, as it requires a batterie as its energy source.

enum e_engine_state {
    ENGINE_ON, ENGINE_OFF
};

enum e_special_fuel_state {
    OUT_OF_FUEL = 0,  CONSUMPTION_UNIT = 1, START_CONSUMPTION_UNIT = 3, TOPPED_OFF = 1000
};

class Engine {
    // Attributes
    private:
        bool            status;
        unsigned int    fuel_amount;
        Crankshaft      *crankshaft;

    // Constructor & Destructor
    private:
        Engine(const Engine &other);
        Engine &operator=(const Engine &other);

    public:
        Engine() : status(ENGINE_OFF), fuel_amount(OUT_OF_FUEL) {}
        ~Engine() {}

    private:

        // this function is part of the detailed implementation
        // it should be encapsulated
        // it may look simple, but in a serious implementation, it'll be much more
        // complex, maybe even requiring the creation of other classes
        void consume_fuel(unsigned int amount) {
            if (this->fuel_amount <= amount) {
                this->fuel_amount = OUT_OF_FUEL;
                return ;
            }
            this->fuel_amount -= amount;
        }

    public:
        void start() {
            if (this->fuel_amount < START_CONSUMPTION_UNIT) {
                std::cout << "Can't Start! We're out of Fuel!" << std::endl;
                return ;
            }

            this->consume_fuel(START_CONSUMPTION_UNIT);

            if (this->status == ENGINE_OFF) {
                std::cout << "Engine started!" << std::endl;
            }
            this->status = ENGINE_ON;
        }

        void stop() {
            if (this->status == ENGINE_ON) {
                std::cout << "Engine stoped!" << std::endl;
            }
            this->status = ENGINE_OFF;
        }

        void burn_and_generate_work(float speed) {
            if (this->status == ENGINE_OFF) {
                std::cout << "Engine is off! turn it on to accelerate!" << std::endl;
                return ;
            }
            if (this->crankshaft) {
                std::cout << "No crankshaft in engine!" << std::endl;
                return ;
            }
            if (this->fuel_amount < CONSUMPTION_UNIT) {
                std::cout << "Engine can't burn and generate! We're out of fuel!" << std::endl;
                return ;
            }
            this->consume_fuel(CONSUMPTION_UNIT);
            std::cout << "Engine burning fuel..." << std::endl;
            this->crankshaft->receive_force(speed);
        }

        void add_fuel(unsigned int fuel_amount) {

            // check to catch overflows
            if (fuel_amount > TOPPED_OFF) {
                fuel_amount = TOPPED_OFF;
            }

            this->fuel_amount += fuel_amount;

            //ensuring that the fuel amount is within the range
            if (this->fuel_amount > TOPPED_OFF) {
                this->fuel_amount = TOPPED_OFF;
            }

            std::cout << "Fuel added, current fuel amount: " << this->fuel_amount << std::endl;
        }

    public:
        void set_crankshaft(Crankshaft *crankshaft) {
            this->crankshaft = crankshaft;
        }
};

#endif