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


class BinaryTree : public sf::Drawable 
{
public:

    BinaryTree(size_t level)
    : level{level}, root_pos{400.f, 7.5f}
    { 
        sf::CircleShape tmp{node_radius};
        tmp.setPosition(400 - 3*node_radius, 0);
        nodes.push_back(tmp);
        for(size_t i = 0; i < level; ++i) {
            for(size_t j = 0; j < 2<<i; ++j) {
                sf::CircleShape tmp{node_radius};
                tmp.setPosition(400 - node_radius - (2<<i)*30 + j*60,
                                60*(i+1) - node_radius);
                nodes.push_back(tmp);
                std::cout << j << ' ';
            }
            std::cout << '\n';
        }

    }

    size_t get_level() { return level; }
private:
    float static constexpr node_radius = 15;

    size_t level;
    Point root_pos;
    std::vector<sf::CircleShape> nodes;
    Lines lines;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
        if(level == 0) { return; }
        for(auto&& tmp : nodes) {
            target.draw(tmp);
        }
    }
    
};

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode{800,600}, "Window", sf::Style::Default, settings);



    BinaryTree bin{3};
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }
        
        window.clear(sf::Color{128, 128, 128});

        window.draw(bin);
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
