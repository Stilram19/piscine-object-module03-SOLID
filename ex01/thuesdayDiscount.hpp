#ifndef THUESDAY_DISCOUNT_COMMAND_HPP
# define THUESDAY_DISCOUNT_COMMAND_HPP

# include "command.hpp"

// Thuesday is not a day name, but that's how the subject name it.

class ThuesdayDiscountCommand : public Command {
    private:
        ThuesdayDiscountCommand();
        ThuesdayDiscountCommand(const ThuesdayDiscountCommand &);
        ThuesdayDiscountCommand &operator=(const ThuesdayDiscountCommand &);

    public:
        ThuesdayDiscountCommand(std::string &client, const std::map<int, size_t> &articles) :\
            Command(client, articles) {}
        ~ThuesdayDiscountCommand() {}

    private:
        bool is_tuesday() const {
            std::string day = this->date.substr(0, 3);

            // return (day == "Tue");
            return (true);
        }

    public:
        virtual float get_total_price() const {
            float price = Command::get_total_price();

            if (this->is_tuesday() == true) {
                price -= price * 0.1;
            }
            return (price);
        }
};


#endif