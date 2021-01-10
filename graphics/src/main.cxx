#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "includes/Lines.hpp"
#include <iostream>


class Image : public sf::Drawable
{
public:
  Image(const std::string& path, Point pos, Size size);
  Image(const std::string& path, Point pos);
  void setSize(Size size);
  void setPos(Point pos);
  class ImageOpenException { };
private:
  sf::Texture texture;
  sf::Sprite sprite;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
  }
};



int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode{800,600}, "Window", sf::Style::Default, settings);


  while (window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) { window.close(); }
    }
	
    window.clear(sf::Color{128, 128, 128});
    window.display();
  }
  return 0;
}

Image::Image(const std::string& path, Point pos, Size size) 
{
  if(!texture.loadFromFile(path.c_str())) { throw ImageOpenException{ }; }
    
  sprite.setTexture(texture);     
  setSize(size);
  setPos(pos);
}
Image::Image(const std::string& path, Point pos)
{
  texture.loadFromFile(path.c_str());
  sprite.setTexture(texture);     
  sprite.setPosition(pos.x, pos.y);
}
void Image::setSize(Size size)
{
  sprite.setScale(size.x / sprite.getLocalBounds().width,
		  size.y / sprite.getLocalBounds().height);
}
void Image::setPos(Point pos)
{
  sprite.setPosition(pos.x, pos.y);
}
