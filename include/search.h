#pragma once

#include <SFML/System/Vector3.hpp>

#include <cstdint>
#include <vector>

namespace search {
  void range(sf::Vector3i start, int32_t distance, std::vector<sf::Vector3i>& coords);
}