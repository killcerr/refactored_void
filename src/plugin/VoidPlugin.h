#pragma once

#include "ll/api/plugin/NativePlugin.h"

namespace void_plugin {


class VoidPlugin {

public:
    static void addInitFunction(std::function<void()>);
    /// @return The instanace of this plugin
    static std::unique_ptr<VoidPlugin>& getInstance();

    VoidPlugin(ll::plugin::NativePlugin& self) : mSelf(self) {}

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const { return mSelf; }

    /// @return True if the plugin is loaded successfully.
    bool load();

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

    // TODO: Implement this method if you need to unload the plugin.
    // /// @return True if the plugin is unloaded successfully.
    // bool unload();

private:
    ll::plugin::NativePlugin& mSelf;
};

} // namespace void_plugin
