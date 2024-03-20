#ifndef AHEADER_STREAM_LOGGER_HPP
# define AHEADER_STREAM_LOGGER_HPP

# include "AStreamLogger.hpp"

class AHeaderStreamLogger : public AStreamLogger {
    private:
        AHeaderStreamLogger();
        AHeaderStreamLogger(const AHeaderStreamLogger &);
        AHeaderStreamLogger &operator=(const AHeaderStreamLogger &);

    public:
        AHeaderStreamLogger(std::ostream &os) : AStreamLogger(os) {}
        ~AHeaderStreamLogger() {}

    protected:
        // appends the header in front of the input string
        virtual void put_header_in_front_of_str(std::string &str) = 0;
    
    public:
        virtual void write(std::string &str) {

            if (str.empty() == false) {
                this->put_header_in_front_of_str(str);

                this->os << str;
            }
        }
};

#endif