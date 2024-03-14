#ifndef FRAME_HPP
# define FRAME_HPP

# include <iostream>

class Frame {
    private:
        int material;

    private:
        Frame() {}
        Frame(const Frame &other);
        Frame &operator=(const Frame &other);

    public:
        enum e_material {
            STEEL, ALUMINUM, COMPOSITE_MATERIALS
        };

    public:
        Frame(int material) : material(material) {
            std::cout << "Frame constructed!" << std::endl;
        }
        ~Frame() {
            std::cout << "Frame destroyed!" << std::endl;
        }

    public:
        int getMaterial() {
            return (this->material);
        }
};

#endif