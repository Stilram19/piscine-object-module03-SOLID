#ifndef ANON_HEADER_LOGGER_HPP
# define ANON_HEADER_LOGGER_HPP

# include "ILogger.hpp"

// this class may seem useless, since it doesn't extend the ILogger interface
// but in a dependency injection using a reference with this type, will make sure
// that the object being referred to is a non header logger (FileLogger or StreamLogger)
// it will be implemented by the two low level modules (FileLogger, StreamLogger)
// and will serve as a dependency for the two high level modules in this context (TimeHeader, ConstHeader)
// through the dependency injection technique.

class INonHeaderLogger : public ILogger {
    public:
        virtual ~INonHeaderLogger() {}
};

#endif