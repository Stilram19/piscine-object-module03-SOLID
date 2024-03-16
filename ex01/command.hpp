#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <ctime>
# include <map>

// (*) In a serious implementation this class can't stay single responsible without the help
// of other classes.

# define MAX_TOTAL_ARTICLES 1000

class Command {
    public:
        enum e_articles {
            YOGURT, JUICE, MEAL, SNACK
        };

    private:
        enum e_articles_prices {
            NO_PRICE = -1, YOGURT_PRICE = 1, JUICE_PRICE = 2, MEAL_PRICE = 5, SNACK_PRICE = 4
        };

    protected:
        static int id;
        std::string date;
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
        Command(std::string &client, const std::map<int, size_t> &articles) {
            id++;
            this->date = Command::get_date();
            this->client = client;
            this->articles = articles;
        }
        virtual ~Command() {}

    private:
        static std::map<int, int> init_article_price() {
            std::map<int, int> a;

            a[YOGURT] = YOGURT_PRICE;       
            a[JUICE] = JUICE_PRICE;            
            a[MEAL] = MEAL_PRICE;            
            a[SNACK] = SNACK_PRICE;

            return (a);
        }

        static std::string get_date() {
            std::time_t current_time = std::time(NULL);

            std::string timeString = std::ctime(&current_time);

            return (timeString);
        }

    public:
        static int get_article_price(int article) {
            for (std::map<int, int>::const_iterator it = Command::article_price.begin(); it != Command::article_price.end(); it++) {
                if (article == it->first) {
                    return (it->second);
                }
            }
            return (NO_PRICE);
        }

    public:
        virtual float get_total_price() const {
            float price = 0;
            int total_articles_count = 0;

            for (std::map<int, size_t>::const_iterator it = this->articles.begin(); it != this->articles.end(); it++) {
                int item_price = Command::get_article_price(it->first);

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

            return (price);
        }
};

int Command::id = 0;
std::map<int, int> Command::article_price = Command::init_article_price();

#endif