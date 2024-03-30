#include "Config.hpp"
#include "FileLogger.hpp"
#include "VoidPlugin.h"
#include <ll/api/Config.h>

FILE_LOGGER;

namespace void_plugin {
namespace config {
namespace v1 {
Config config;
namespace details {
auto initConfig = []() -> void {
    // config.dimensions.resize(1024);
    if (!std::filesystem::exists(::void_plugin::VoidPlugin::getInstance()->getSelf().getConfigDir() / u8"config.json")) {
        ::ll::config::saveConfig(config, ::void_plugin::VoidPlugin::getInstance()->getSelf().getConfigDir() / u8"config.json");
    }
    ::ll::config::loadConfig(config, ::void_plugin::VoidPlugin::getInstance()->getSelf().getConfigDir() / u8"config.json");
    // logger.info("loadconfig");
    // for (auto v : ::void_plugin::config::v1::config.dimensions) {
    //     logger.info("{}", v);
    // }
    // constexpr auto res = ll::concepts::ArrayLike<std::vector<int>>;
};
auto _ = []() -> int {
    ::void_plugin::VoidPlugin::addInitFunction(initConfig);
    return 0;
}();
} // namespace details
} // namespace v1
} // namespace config
} // namespace void_plugin