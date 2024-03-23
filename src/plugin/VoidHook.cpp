#include "Config.hpp"
#include "FileLogger.hpp"
#include "VoidPlugin.h"
#include "utils.hpp"


#include <mc/entity/systems/common/BiomeDecorationSystem.h>
#include <mc/world/level/ChunkBlockPos.h>
#include <mc/world/level/block/Block.h>
#include <mc/world/level/block/BlockVolume.h>
#include <mc/world/level/chunk/LevelChunk.h>
#include <mc/world/level/dimension/Dimension.h>


#include <ll/api/memory/Hook.h>

FILE_LOGGER;

LL_STATIC_HOOK(DecorateHook, HookPriority::Normal, "?decorate@BiomeDecorationSystem@@YAXAEAVLevelChunk@@AEAVBlockSource@@AEAVRandom@@AEAV?$vector@PEBVBiome@@V?$allocator@PEBVBiome@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@6@AEBVIPreliminarySurfaceProvider@@@Z", void, class LevelChunk& lc, class BlockSource& source, class Random& random, std::vector<class Biome const*>& biomes, std::string const& pass, class IPreliminarySurfaceProvider const& provider) {
    // origin(lc, source, random, biomes, pass, provider);
    logger.info("{}", tools::in(lc.getDimension().getDimensionId(), void_plugin::config::v1::config.dimensions));
    if (tools::in(lc.getDimension().getDimensionId(), void_plugin::config::v1::config.dimensions) && pass == "first_pass") {
        for (short x = 0; x < 16; x++)
            for (short y = lc.getMinY(); y < lc.getMaxY(); y++)
                for (short z = 0; z < 16; z++) lc.setBlockSimple({x, y, z}, Block::tryGetFromRegistry("minecraft:air"));
        // origin(lc, source, random, biomes, pass, provider);
    } else {
        origin(lc, source, random, biomes, pass, provider);
    }
}
namespace void_plugin {
namespace void_hook {
void disableHook() { DecorateHook::unhook(); }
void enableHook() { DecorateHook::hook(); }
} // namespace void_hook
} // namespace void_plugin

auto _ = []() -> int {
    void_plugin::VoidPlugin::addInitFunction(void_plugin::void_hook::enableHook);
    return 0;
}();