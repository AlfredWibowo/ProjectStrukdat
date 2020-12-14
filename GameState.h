#pragma once
#include "MainMenuState.h"

class GameState :public State
{
public:
	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
};

