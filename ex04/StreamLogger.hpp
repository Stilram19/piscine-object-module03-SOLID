#ifndef ASTREAM_LOGGER_HPP
# define ASTREAM_LOGGER_HPP

# include <ostream>
# include "ILogger.hpp"

class AStreamLogger : public ILogger {
    protected:
        std::ostream os;
};

#endif