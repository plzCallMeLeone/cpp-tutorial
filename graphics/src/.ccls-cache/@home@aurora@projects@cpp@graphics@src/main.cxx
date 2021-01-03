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
        if(level == 0) { return; }
        for(size_t i = 1; i < level; i*=2) {
            for(size_t j = 0; j < i; ++j) {
                sf::CircleShape circle{node_radius};
                circle.setPosition(root_pos.x - node_radius - chunk*(i-j) ,
				   root_pos.y - node_radius + j*chunk);
                nodes.push_back(sf::CircleShape(node_radius));
                
            }
        }
    }

    size_t get_level() { return level; }
private:
    float static constexpr node_radius = 15;
    float static constexpr chunk      = 40;

    size_t level;
    Point root_pos;
    std::vector<sf::CircleShape> nodes;

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

    sf::Font font;

    constexpr float node_radius   = 15;
    constexpr float screen_width  = 800;
    constexpr float screen_height = 600;

    Point root_pos{screen_width/2 - node_radius, node_radius};

    sf::CircleShape circle{node_radius};
    circle.setPosition(root_pos.x - node_radius, root_pos.y - node_radius);

    sf::RectangleShape line1{Size{1, 90}};

    BinaryTree bin{3};
    line1.rotate(60);

    
    line1.setPosition(root_pos.x, root_pos.y);

    sf::RectangleShape line2{Size{1, 90}};
    line2.rotate(300);

    line2.setPosition(root_pos.x, root_pos.y);


    std::vector<sf::CircleShape> nodes;
    for(size_t i = 1; i < 3; i*=2) {
        for(size_t j = 0; j < i; ++j) {
            sf::CircleShape circle{node_radius};
            std::cout << root_pos.x - node_radius - 20*(i-j) << ' ' << root_pos.y - node_radius + j*20 << '\n';
            circle.setPosition(root_pos.x - node_radius - 20*(i-j) , root_pos.y - node_radius + j*20);
            nodes.push_back(sf::CircleShape(node_radius));
        }
    }
    
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
