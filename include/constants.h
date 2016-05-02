#pragma once

// NOTE:
// Changing a constant in here requires a clean build because it's a header
// and I don't know how to get Make to pick it up
// 

#include <SFML/System/Vector2.hpp>

#include <cstdint>

// Some ugly constants

static const uint32_t WINDOW_WIDTH = 1280;
static const uint32_t WINDOW_HEIGHT = 720;

static const uint32_t HEX_SIZE = 50;
// Distance in every direction from center, 0,0 grid
static const int32_t MAP_DISTANCE = 3;
static const sf::Vector2f START_PIXEL(0.0f, 0.0f);
static const sf::Vector3i START_CUBE(0, 0, 0);