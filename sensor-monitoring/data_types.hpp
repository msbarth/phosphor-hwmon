#pragma once

#include <functional>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/message.hpp>

namespace phosphor
{
namespace sensor
{
namespace monitoring
{

class Monitor;

using GroupVariantType = sdbusplus::message::variant<uint32_t>;

using Group = std::vector<std::tuple<std::string, GroupVariantType>>;

using Condition = std::function<bool (sdbusplus::bus::bus&,
                                      sdbusplus::message::message&,
                                      Monitor&)>;

} // namespace monitoring
} // namespace sensor
} // namespace phosphor
