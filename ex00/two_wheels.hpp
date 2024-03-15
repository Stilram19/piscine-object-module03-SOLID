#ifndef TWO_WHEELS
# define TWO_WHEELS

# include <iostream>

// base class for front and rear wheels
// it's created to prevent reptition of common features of Front&Rear Wheels
// and to use it in classes that may not need to know about the details of
// the two child classes
// T is Wheel, FrontWheel or RearWheel

template <class T>
class TwoWheels {
    protected:
        T *left_wheel;
        T *right_wheel;

    private:
        TwoWheels(const TwoWheels &other);
        TwoWheels &operator=(const TwoWheels &other);

    public:
        TwoWheels() : left_wheel(NULL), right_wheel(NULL) {}
        TwoWheels(T *left_wheel, T *right_wheel) : left_wheel(left_wheel), right_wheel(right_wheel) {}
        virtual ~TwoWheels() {}

    public:

        void change_speed(float speed) {
            if (this->left_wheel == NULL || this->right_wheel == NULL) {
                throw std::runtime_error("To change wheels speed, all wheels must exist");
            }

            this->left_wheel->change_speed(speed);
            this->right_wheel->change_speed(speed);
        }

        void set_left_wheel(T *left_wheel) {
            this->left_wheel = left_wheel;

            // ensuring that both wheels have the same speed
            if (this->left_wheel) {
                this->left_wheel->reset_speed();
            }

            if (this->right_wheel) {
                this->right_wheel->reset_speed();
            }
        }

        void set_right_wheel(T *right_wheel) {
            this->right_wheel = right_wheel;

            // ensuring that both wheels have the same speed
            if (this->left_wheel) {
                this->left_wheel->reset_speed();
            }

            if (this->right_wheel) {
                this->right_wheel->reset_speed();
            }
        }

        void reset_wheels() {
            if (this->left_wheel) {
                this->left_wheel->reset_speed();
            }
            if (this->right_wheel) {
                this->right_wheel->reset_speed();
            }
        }

    public:
        int get_current_speed() const {
            if (this->left_wheel && this->right_wheel) {
                return (this->left_wheel->get_current_speed());
            }
            return (0);
        }
};

#endif