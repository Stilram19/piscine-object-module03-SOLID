#ifndef REAR_WHEEL_HPP
# define REAR_WHEEL_HPP

# include "Wheel.hpp"

class RearWheel : public Wheel {
    private:
        RearWheel(const Wheel &other) {}
        RearWheel &operator=(const Wheel &other) {}
    public:
        RearWheel() {}
        ~RearWheel() {}
};

#endif