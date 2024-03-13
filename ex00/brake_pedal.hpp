#ifndef BRAKEPEDAL_HPP
# define BRAKEPEDAL_HPP

# include <iostream>
# include "front_wheels.hpp"
# include "rear_wheels.hpp"

class BrakePedal {
    private:
        FrontWheels *front_wheels;
        RearWheels *rear_wheels;

    private:
        BrakePedal(const BrakePedal &other) {}
        BrakePedal &operator=(const BrakePedal &other) { return (*this); }

    public:
        BrakePedal(FrontWheels *front_wheels, RearWheels *rear_wheels) :\
         front_wheels(front_wheels), rear_wheels(rear_wheels) {}
        ~BrakePedal() {}

    public:
        void apply_force(float force) {
            
        }
};

#endif