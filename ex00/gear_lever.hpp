#ifndef GEARLEVER_HPP
# define GEARLEVER_HPP

# include <iostream>

enum e_gears {
    REVERSE = -1, NEUTRAL_LEVEL, FIRST_LEVEL, SECOND_LEVEL,
    THIRD_LEVEL, FOURTH_LEVEL, MAX_LEVEL
};

class GearLever {
    private:
        int current_gear;

    // Constructor & Destructor
    private:
        GearLever(const GearLever &other) {}
        GearLever &operator=(const GearLever &other) { return (*this); }

    public:
        GearLever() : current_gear(NEUTRAL_LEVEL) {}
        ~GearLever() {}

    public:
        void switch_up() {
            if (this->current_gear < MAX_LEVEL) {
                this->current_gear++;
                std::cout << "Gear switched up, current level: " << this->current_gear << std::endl;
            }
        }

        void switch_down() {
            if (this->current_gear != NEUTRAL_LEVEL) {
                this->current_gear--;
                std::cout << "Gear switched down, current level: " << this->current_gear << std::endl;
            }
        }

        void reverse() {
            this->current_gear = REVERSE;
        }

        void set_neutral() {
            this->current_gear = NEUTRAL_LEVEL;
        }
};

#endif