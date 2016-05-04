#pragma once

// Map will be stored in axial coordinates

#include <cstdint>
#include <functional>
#include <SFML/System/Vector3.hpp>
#include <vector>

#include "camera.h"

namespace map {
  void build(const sf::Vector3i start, int32_t distance);
  void for_each_tile(std::function<void(const sf::Vector3i& coord)> operation);
  void update(const Camera& camera);
}