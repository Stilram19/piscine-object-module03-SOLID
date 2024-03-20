#ifndef ASTREAM_LOGGER_HPP
# define ASTREAM_LOGGER_HPP

# include "ILogger.hpp"

class AStreamLogger : public ILogger {
    protected:
        std::ostream &os;

    private:
        AStreamLogger();
        AStreamLogger(const AStreamLogger &);
        AStreamLogger &operator=(const AStreamLogger &);

    public:
        AStreamLogger(std::ostream &os) : os(os) {}
        virtual ~AStreamLogger() {}
};

#endif