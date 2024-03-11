#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <iostream>

enum e_engine_state {
    ENGINE_ON, ENGINE_OFF
};

// this class will implement the Engine concern. if it happens to have more than one
// concern at some point, as we go deep in the implementation, we should consider
// distributing the new concerns to new classes.

class Engine {
    // Attributes
    private:
        bool status;

    // Constructor & Destructor
    private:
        Engine(const Engine &other) {}
        Engine &operator=(const Engine &other) { return (*this); }

    public:
        Engine() : status(ENGINE_OFF) {}
        ~Engine() {}

    public:
        void start() {
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
};

#endif