//
// Created by Junius7 on 2023-09-07.
//

#ifndef NAMTARENGINE_LOGGER_H
#define NAMTARENGINE_LOGGER_H

#include <string>
#include <iostream>

namespace ne {
    /**
     * Rudimentary implementation of a logger that allows various parts to send out error messages.
     */
    class Logger {
    public:
        Logger() = default;
        static void LogMessage(std::string sender_class, std::string message) {
            std::cout<<"Warning! "<<sender_class<<" issued the message: "<<message<<std::endl;
        }
    private:
        enum WarningLevel {
            Fatal,
            Error,
            Warning,
            Info,
            Debug
        };
    };

}


#endif //NAMTARENGINE_LOGGER_H
