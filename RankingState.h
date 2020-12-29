#pragma once
#include "State.h"


class RankingState :public State
{
public:
	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);

private:
	sf::Font _font, _font2;
	sf::Text _title;
	sf::Text _ranking[4];
	std::string winText[4];

	sf::Texture _backTexture;
	sf::RectangleShape _backButton;

	sf::RectangleShape _bg;
	sf::Texture _bgTexture;

	int rank[4];
};

