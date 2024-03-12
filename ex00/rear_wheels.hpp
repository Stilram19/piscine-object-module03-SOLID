#ifndef REAR_WHEELS_HPP
# define REAR_WHEELS_HPP

# include "Wheel.hpp"

class RearWheels {
    private:
        Wheel wheels[2];

    private:
        RearWheels(const RearWheels &other) {}
        RearWheels &operator=(const RearWheels &other) { return (*this); }

    public:
        
};

#endif
