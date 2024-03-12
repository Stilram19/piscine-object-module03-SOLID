#ifndef FRONT_WHEELS_HPP
# define FRONT_WHEELS_HPP

# include "Wheel.hpp"

class FrontWheels {
    private:
        Wheel wheels[2];

    private:
        FrontWheels(const FrontWheels &other) {}
        FrontWheels &operator=(const FrontWheels &other) { return (*this); }

    public:
        FrontWheels() {}
        ~FrontWheels() {}

    public:
        void turn(float angle) {}
        void straighten() {}      
};

#endif