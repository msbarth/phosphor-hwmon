#pragma once

#include <sdbusplus/bus.hpp>
#include "events.hpp"

namespace phosphor
{
namespace sensor
{
namespace monitoring
{

class Monitor
{
    public:
        Monitor() = delete;
        Monitor(const Monitor&) = delete;
        Monitor(Monitor&&) = default;
        Monitor& operator=(const Monitor&) = delete;
        Monitor& operator=(Monitor&&) = delete;
        ~Monitor() = default;

        Monitor(sdbusplus::bus::bus& bus);

        void run() noexcept;

        void handleEvent(sdbusplus::message::message& msg,
                         const Event& event,
                         const std::tuple<std::vector<
                            std::shared_ptr<Event>>>& eventDef);

    private:
        sdbusplus::bus::bus& bus;

        // TODO Add vector of 'Actions' to events vector
        static const std::vector<
            std::tuple<std::vector<std::shared_ptr<Event>>>> events;

};

} // namespace monitoring
} // namespace sensor
} // namespace phosphor
