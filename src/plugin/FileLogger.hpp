#pragma once
#include <ll/api/Logger.h>
#include <ll/api/base/FixedString.h>

template <ll::FixedString>
class FileLogger : public ll::Logger {
    using ::ll::Logger::Logger;
};

#define FILE_LOGGER FileLogger<__FILE__> logger(__FILE__)