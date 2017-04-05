#include "data_types.hpp"
#include "functor.hpp"
#include "monitor.hpp"

namespace phosphor
{
namespace sensor
{
namespace monitoring
{

// Example vector of sensors constructing a group
static Group core_temp_group = {
    std::make_tuple(
        "/xyz/openbmc_project/sensors/temperature/core0",0
    ),
    std::make_tuple(
        "/xyz/openbmc_project/sensors/temperature/core1",0
    ),
    std::make_tuple(
        "/xyz/openbmc_project/sensors/temperature/core2",0
    ),
    std::make_tuple(
        "/xyz/openbmc_project/sensors/temperature/core3",0
    )
};

const std::vector<std::tuple<std::vector<std::shared_ptr<Event>>>>
    Monitor::events
{ // Example vector of Event with START trigger
    {std::make_tuple(std::vector<std::shared_ptr<Event>>(
        { //Example vector of StartEvent
            std::make_shared<StartEvent>(
                core_temp_group,
//                "interface='org.freedesktop.DBus.Properties',"
//                "member='Get',",
//                "type='signal'",
                std::vector<Condition>(
                    { // Example vector of StartEvent conditions
                        make_condition(countAtOrAbove(
                            core_temp_group,
                            "/xyz/openbmc_project/sensors/temperature/core0",
                            "xyz.openbmc_project.Sensor.Value",
                            "Value",
                            3,
                            static_cast<uint32_t>(115ll)
                        )),
                        make_condition(countAtOrAbove(
                            core_temp_group,
                            "/xyz/openbmc_project/sensors/temperature/core1",
                            "xyz.openbmc_project.Sensor.Value",
                            "Value",
                            3,
                            static_cast<uint32_t>(115ll)
                        )),
                        make_condition(countAtOrAbove(
                            core_temp_group,
                            "/xyz/openbmc_project/sensors/temperature/core2",
                            "xyz.openbmc_project.Sensor.Value",
                            "Value",
                            3,
                            static_cast<uint32_t>(115ll)
                        )),
                        make_condition(countAtOrAbove(
                            core_temp_group,
                            "/xyz/openbmc_project/sensors/temperature/core3",
                            "xyz.openbmc_project.Sensor.Value",
                            "Value",
                            3,
                            static_cast<uint32_t>(115ll)
                        ))
                    }
                )
            )
        })
//        std::vector<Action>(
//        {
//            make_action(
//                functor::log_error(
//                )
//            )
//            make_action(
//                functor::shutdown(
//                )
//            )
//        })
    )}
};

} // namespace monitoring
} // namespace sensor
} // namespace phosphor
