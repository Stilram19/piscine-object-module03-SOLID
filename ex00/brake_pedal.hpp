#ifndef BRAKEPEDAL_HPP
# define BRAKEPEDAL_HPP

# include <iostream>
# include "Wheel.hpp"

class BrakePedal {
    private:
        Wheel *wheel;

    private:
        BrakePedal() {}
        

    public:
        BrakePedal(Wheel *wheel = NULL) {}

};

#endif