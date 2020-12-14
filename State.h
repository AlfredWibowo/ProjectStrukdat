#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class State
{
public:
	virtual void Init(sf::RenderWindow& _window) = 0;
	virtual void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state) = 0;
	virtual void Update(sf::RenderWindow& _window, std::vector<State*>& _state) = 0;
	virtual void Draw(sf::RenderWindow& _window) = 0;
};