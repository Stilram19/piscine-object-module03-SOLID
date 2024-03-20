#ifndef NON_HEADER_STREAM_LOGGER_HPP
# define NON_HEADER_STREAM_LOGGER_HPP

# include "AStreamLogger.hpp"

class NonHeaderStreamLogger : public AStreamLogger {
    private:
        NonHeaderStreamLogger();
        NonHeaderStreamLogger(const NonHeaderStreamLogger &);
        NonHeaderStreamLogger &operator=(const NonHeaderStreamLogger &);

    public:
        NonHeaderStreamLogger(std::ostream &os) : AStreamLogger(os) {}
        ~NonHeaderStreamLogger() {}

    public:
        virtual void write(std::string &str) {
            if (str.empty() == false) {
                this->os << str;
            }
        }
};

#endif