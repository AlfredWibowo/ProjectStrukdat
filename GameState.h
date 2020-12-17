#pragma once
#include "MainMenuState.h"
#include "CDL.h"

class GameState :public State
{
public:
	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::RectangleShape _dice, _rollButton;
	sf::Texture _diceHead[6];
	sf::Texture _rollTexture;
	sf::Texture _mapTexture;
	sf::Sprite _mapSprite;
	sf::Sprite _pionSprite[4][4];
	sf::Texture _pionTexture[4];
	sf::Font _font;
	sf::Text _turn;
};

