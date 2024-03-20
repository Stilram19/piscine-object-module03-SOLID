# include "ILogger.hpp"
# include <vector>

// this test, depends only on abstraction (the ILogger interface)
// it can be put in a seprate high level module
// of course the vector header file doesn't count, as it is not a concrete implementation
// of the abstraction (ILogger in our case).

void high_level_test(const std::vector<ILogger *> &loggers) {
    for (std::vector<ILogger *>::const_iterator logger = loggers.begin(); logger != loggers.end(); logger++) {
        std::string str("Hello, World!");
        (*logger)->write(str);
    }
}

# include "NonHeaderFileLogger.hpp"
# include "NonHeaderStreamLogger.hpp"
# include "ConstantHeaderFileLogger.hpp"
# include "ConstantHeaderStreamLogger.hpp"
# include "TimeHeaderFileLogger.hpp"
# include "TimeHeaderStreamLogger.hpp"
# include <fstream>

// the subject & main functions do not respecting DIP, they cannot because it's a test
// that requires testing all the concrete implementations of the abstraction

void subject_test() {
    std::ofstream s1("file1.txt");
    std::ofstream s2("file2.txt");
    std::ofstream s3("file3.txt");

    NonHeaderFileLogger logger1("file4.txt");
    NonHeaderStreamLogger logger2(s1);
    ConstantHeaderFileLogger logger3("file5.txt", "FILE_CONSTANT");
    ConstantHeaderStreamLogger logger4(s2, "STREAM_CONSTANT");
    TimeHeaderFileLogger    logger5("file6.txt");
    TimeHeaderStreamLogger  logger6(s3);

    std::vector<ILogger *> loggers;

    loggers.push_back(&logger1);
    loggers.push_back(&logger2);
    loggers.push_back(&logger3);
    loggers.push_back(&logger4);
    loggers.push_back(&logger5);
    loggers.push_back(&logger6);

    // calling the high level test
    high_level_test(loggers);

    // closing the ofstreams
    s1.close();
    s2.close();
    s3.close();
}

int main() {
    try {
        subject_test();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
