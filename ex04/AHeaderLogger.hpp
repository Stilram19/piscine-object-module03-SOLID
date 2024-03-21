#ifndef AHEADER_LOGGER_HPP
# define AHEADER_LOGGER_HPP

# include "ILogger.hpp"
# include "INonHeaderLogger.hpp"

class AHeaderLogger : public ILogger {
    protected:
        INonHeaderLogger &nonHeaderLogger;

    private:
        AHeaderLogger();
        AHeaderLogger(const AHeaderLogger &);
        AHeaderLogger &operator=(const AHeaderLogger &);

    public:
        AHeaderLogger(INonHeaderLogger &nonHeaderLogger) : nonHeaderLogger(nonHeaderLogger) {}
        ~AHeaderLogger() {}

    protected:
        // appends the header in front of the input string
        virtual void put_header_in_front_of_str(std::string &str) = 0;

    public:
        virtual void write(std::string &str) {
            this->put_header_in_front_of_str(str);
            this->nonHeaderLogger.write(str);
        }
};

#endif