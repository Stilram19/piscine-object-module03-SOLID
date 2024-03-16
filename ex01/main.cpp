# include "packageReductionDiscount.hpp"
# include "thuesdayDiscount.hpp"

// testing the Command class
void test1() {

    std::cout << Command::get_article_price(Command::YOGURT) << std::endl;
    std::cout << Command::get_article_price(Command::JUICE) << std::endl;
    std::cout << Command::get_article_price(Command::MEAL) << std::endl;
    std::cout << Command::get_article_price(Command::SNACK) << std::endl;
    std::cout << Command::get_article_price(123) << std::endl;

    std::string name = "OMAR";
    std::map<int, size_t> articles;

    articles[Command::YOGURT] = 10;
    articles[Command::MEAL] = 20;
    articles[Command::JUICE] = 10;
    articles[Command::SNACK] = 10;
    articles[123] = 10;

    Command command(name, articles);
    float price = command.get_total_price();

    std::cout << "Total price is: " <<  price << std::endl;
}

// testing the package Reduction Discount feature
void test2() {
    std::string name = "OMAR";
    std::map<int, size_t> articles;

    articles[Command::YOGURT] = 10;
    articles[Command::MEAL] = 20;
    articles[Command::JUICE] = 10;
    articles[Command::SNACK] = 10;
    articles[123] = 10;

    PackageReductionDiscountCommand command(name, articles);
    float price = command.get_total_price();

    std::cout << "Total price is: " <<  price << std::endl;
}

// testing the Tuesday Discount feature
void test3() {
    std::string name = "OMAR";
    std::map<int, size_t> articles;

    articles[Command::YOGURT] = 10;
    articles[Command::MEAL] = 20;
    articles[Command::JUICE] = 10;
    articles[Command::SNACK] = 10;
    articles[123] = 10;

    ThuesdayDiscountCommand command(name, articles);
    float price = command.get_total_price();

    std::cout << "Total price is: " <<  price << std::endl;
}

int main() {
    try {
        // test1();
        // test2();
        // test3();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
