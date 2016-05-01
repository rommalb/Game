#include <SFML/Graphics.hpp>

#include "format.h"
#include "hex.h"
#include "hexagon_shape.h"

#include <iostream>
#include <sstream>

int main() {
  
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Foobar");

  sf::Vector2i hex(0, 0);

  HexagonShape hexagon_shape(50, hex::axial_to_pixel(hex, 50));

  while (window.isOpen()) {
    sf::Event event;
    
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(hexagon_shape.get_drawable());
    window.display();
  }

  return 0;
}