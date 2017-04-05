#pragma once

#include "data_types.hpp"

namespace phosphor
{
namespace sensor
{
namespace monitoring
{

class Event : public std::vector<Condition>
{
    public:
        enum class Trigger
        {
            UNKNOWN,
            START
        };

        Event() = delete;
        Event(const Event&) = delete;
        Event(Event&&) = delete;
        Event& operator=(const Event&) = delete;
        Event& operator=(Event&&) = delete;
        virtual ~Event() = default;

        Event(const std::vector<Condition>& conditions,
              Trigger t = Trigger::UNKNOWN) :
                  std::vector<Condition>(conditions),
                  trigger(t)
        {
            // Nothing to do here
        }

        Trigger trigger;
};

class StartEvent : public Event
{
    public:
        StartEvent() = delete;
        StartEvent(const StartEvent&) = delete;
        StartEvent(StartEvent&&) = delete;
        StartEvent& operator=(const StartEvent&) = delete;
        StartEvent& operator=(StartEvent&&) = delete;
        ~StartEvent() = default;

        StartEvent(Group sensors, const std::vector<Condition>& conditions) :
            Event(conditions, Trigger::START),
            sensors(sensors)
        {
            // Nothing to do here
        }

        Group sensors;
};

} // namespace monitoring
} // namespace sensor
} // namespace phosphor
