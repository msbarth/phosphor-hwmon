#include "monitor.hpp"

namespace phosphor
{
namespace sensor
{
namespace monitoring
{

Monitor::Monitor(sdbusplus::bus::bus& bus) :
    bus(bus)
{
    // TODO Process thru given events that are type 'dbus'
}

void Monitor::run() noexcept
{
    sdbusplus::message::message nullMsg{nullptr};

    // Process thru given events that are type 'start'
    for (auto& event : events)
    {
        for (auto pEvent : std::get<std::vector<std::shared_ptr<Event>>>(event))
        {
            if (pEvent->trigger == Event::Trigger::START)
            {
                handleEvent(nullMsg, *pEvent, event);
            }
        }
    }

    // Keep application running to process dbus events
    while (true)
    {
        bus.process_discard();
        bus.wait();
    }
}

void Monitor::handleEvent(sdbusplus::message::message& msg,
                          const Event& event,
                          const std::tuple<std::vector<
                             std::shared_ptr<Event>>>& eventDef)
{
    // Iterate over conditions
    for (auto& cond : event)
    {
        if (!cond(bus, msg, *this))
        {
            return;
        }
    }
    // TODO Perform defined 'Actions'
}

} // namespace monitoring
} // namespace sensor
} // namespace phosphor
