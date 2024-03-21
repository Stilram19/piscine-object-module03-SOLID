#ifndef CONST_LOGGER_HPP
# define CONST_LOGGER_HPP

# include "AHeaderLogger.hpp"

// (*) this is a high level module in the context where the abstraction is INonHeaderLogger
// which is hiding the low level modules implementation (FileHeader, StreamHeader)
// (*) this is a low level module in the context where the abstraction is ILogger
// which is hiding this low level module's concrete implementation.

class ConstLogger : public AHeaderLogger {
    private:
        std::string constant_header;

    private:
        ConstLogger();
        ConstLogger(const ConstLogger &);
        ConstLogger &operator=(const ConstLogger &);

    public:
        ConstLogger(INonHeaderLogger &nonHeaderLogger, const std::string &constant_header) : \
            AHeaderLogger(nonHeaderLogger), constant_header(constant_header) {}
        ~ConstLogger() {}

    private:
        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += this->constant_header;
        }
};

#endif