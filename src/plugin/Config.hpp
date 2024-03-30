#pragma once
// #include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
namespace void_plugin {
namespace config {
namespace v1 {
struct Config {
    int              version    = 1;
    std::vector<int> dimensions = {};
} extern config; // global config
} // namespace v1
} // namespace config
} // namespace void_plugin
