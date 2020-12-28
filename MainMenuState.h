#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "AboutState.h"
#include "GameState.h"
#include "TutorialState.h"

class MainMenuState :public State
{
public:
	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _playTexture, _aboutTexture, _tutorialTexture, _quitTexture;
	sf::Font _font;
	sf::Text _title;
	sf::RectangleShape _playButton, _aboutButton, _tutorialButton, _quitButton;
};

