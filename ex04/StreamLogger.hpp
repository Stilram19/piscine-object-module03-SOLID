#ifndef STREAM_LOGGER_HPP
# define STREAM_LOGGER_HPP

# include "INonHeaderLogger.hpp"

// This is a low level module depending on the INonHeaderLogger abstraction

class StreamLogger : public INonHeaderLogger {
    protected:
        std::ostream &os;

    private:
        StreamLogger();
        StreamLogger(const StreamLogger &);
        StreamLogger &operator=(const StreamLogger &);

    public:
        StreamLogger(std::ostream &os) : os(os) {}
        virtual ~StreamLogger() {}

    public:
        virtual void write(std::string &str) {
            if (str.empty() == false) {
                this->os << str;
            }
        }
};

#endif