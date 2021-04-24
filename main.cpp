#include <iostream>
#include "homeAutomationConfig.h"
#include "libs/cxxopts/include/cxxopts.hpp"
#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>

int main (int arc, char **argv)
{
   
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);


    cxxopts::Options options("Home automation","home automation application");
    PLOG_DEBUG<<"version minor: "<<homeAutomation_VERSION_MINOR;
    PLOG_DEBUG<<"version major: "<<homeAutomation_VERSION_MAJOR;
    options.add_options()
    ("l, level","debug level")
    ("d, debug","enable debugging");
    auto parsed_options = options.parse(arc,argv);

    return 0;
}