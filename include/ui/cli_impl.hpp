#pragma once

#include "event/event.hpp"
#include <string_view>

namespace cli_details {
event::event_t to_event(std::string_view input);
} // namespace cli_details
