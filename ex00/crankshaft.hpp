#ifndef CRANKSHAFT
# define CRANKSHAFT

# include "transmission.hpp"

class Crankshaft {
    private:
        Transmission *transmission;

    private:
        Crankshaft(const Transmission &other);
        Crankshaft &operator=(const Crankshaft &other);

    public:
        Crankshaft() {}
        ~Crankshaft() {}

    public:
        void receive_force(float force) {
            std::cout << "Crankshaft received the output mechanical energy!" << std::endl;

            if (this->transmission == NULL) {
                std::cout << "Energy is dissipated, there's no transmission!" << std::endl;
                return ;
            }
            this->transmission->activate(force);
        }

    public:
        void set_transmission(Transmission *transmission) {
            this->transmission = transmission;
        }
};

#endif