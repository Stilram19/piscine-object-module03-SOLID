#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <map>

// (*) In a serious implementation this class can't stay single responsible without the help
// of other classes.

# define MAX_TOTAL_ARTICLES 3

class Command {
    public:
        enum e_articles {
            YOGORT, JUICE, MEAL, SNACK
        };

    private:
        enum e_articles_prices {
            NO_PRICE = -1, YOGORT_PRICE = 1, JUICE_PRICE = 2, MEAL_PRICE = 5, SNACK_PRICE = 4
        };

    private:
        static int id;
        // time
        std::string client;
        std::map<int, size_t> articles;
        static std::map<int, int> article_price;// available articles and their prices

    private:
        Command();
        Command(const Command &);
        Command &operator=(const Command &);

    public:
        // @parameter client Client's name
        // @parameter articles map of article and the quantity
        Command(std::string &client, const std::map<std::string, size_t> &articles) {}
        ~Command() {}

    private:
        static std::map<int, int> init_article_price() {
            std::map<int, int> a;

            a[YOGORT] = YOGORT_PRICE;       
            a[JUICE] = JUICE_PRICE;            
            a[MEAL] = MEAL_PRICE;            
            a[SNACK] = SNACK_PRICE;

            return (a);
        }

    private:
        size_t get_article_price(int article) const {
            for (std::map<int, int>::const_iterator it = this->article_price.begin(); it != this->article_price.end(); it++) {
                if (article == it->first) {
                    return (it->second);
                }
            }
            return (NO_PRICE);
        }

    public:
        float get_total_price() const {
            int price = 0;
            int total_articles_count = 0;

            for (std::map<int, std::string>::const_iterator it = this->articles.begin(); it != this->articles.end(); it++) {
                int item_price = this->get_article_price(it->first);

                if (item_price == NO_PRICE) {
                    std::cout << "Item " << it->first << ", not found!" << std::endl;
                    continue ;
                }

                total_articles_count += it->second;

                if (total_articles_count > MAX_TOTAL_ARTICLES) {
                    throw std::runtime_error("Get the extra articles back!");
                }

                price += item_price * it->second;
            }
        }
};

std::map<int, int> Command::article_price = Command::init_article_price();

#endif