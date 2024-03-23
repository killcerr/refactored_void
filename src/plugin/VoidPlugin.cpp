#include "plugin/VoidPlugin.h"

#include <memory>

#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"

namespace void_plugin {
namespace details {
std::vector<std::function<void()>> init_functions;
} // namespace details

void void_plugin::VoidPlugin::addInitFunction(std::function<void()> f) { details::init_functions.push_back(f); }

std::unique_ptr<VoidPlugin>& VoidPlugin::getInstance() {
    static std::unique_ptr<VoidPlugin> instance;
    return instance;
}

bool VoidPlugin::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the plugin goes here.
    return true;
}

bool VoidPlugin::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the plugin goes here.
    for (auto f : details::init_functions) {
        f();
    }
    return true;
}

bool VoidPlugin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace void_plugin

LL_REGISTER_PLUGIN(void_plugin::VoidPlugin, void_plugin::VoidPlugin::getInstance());
