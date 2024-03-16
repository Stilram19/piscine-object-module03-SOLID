#ifndef PACKAGE_REDUCTION_DISCOUND_COMMAND_HPP
# define PACKAGE_REDUCTION_DISCOUND_COMMAND_HPP

# include "command.hpp"

class PackageReductionDiscountCommand : public Command {
    private:
        const static int minimum_price = 150;

    private:
        PackageReductionDiscountCommand();
        PackageReductionDiscountCommand(const PackageReductionDiscountCommand &);
        PackageReductionDiscountCommand &operator=(const PackageReductionDiscountCommand &);

    public:
        PackageReductionDiscountCommand(std::string &client, const std::map<int, size_t> &articles) :\
            Command(client, articles) {}
        ~PackageReductionDiscountCommand() {}

    public:
        virtual float get_total_price() const {
            float price = Command::get_total_price();

            if (price >= minimum_price) {
                price -= 10;
            }
            return (price);
        }
};

#endif
