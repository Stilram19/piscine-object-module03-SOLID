#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <iostream>

// using the term engine, which is suggested in the subject, means that we're considering fuel vehicles.
// Motor is used more for electrical vehicles, as it requires a batterie as its energy source.

enum e_engine_state {
    ENGINE_ON, ENGINE_OFF
};

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