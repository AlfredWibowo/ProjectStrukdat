#include "State.h"
#include "MainMenuState.h"
#include <iostream>

void MainMenuState::Init(sf::RenderWindow& _window)
{
	//title
	if (!_font.loadFromFile(FONT))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_title.setFont(_font);
	_title.setString("RACING TOKEN");
	_title.setOrigin(_title.getGlobalBounds().width, _title.getGlobalBounds().height / 2);
	_title.setPosition(sf::Vector2f(_window.getSize().x / 2 - 60 , 20));
	_title.setCharacterSize(80);


	//button
	sf::Vector2f buttonSize(400, 100);
	_playButton.setSize(buttonSize);
	_playButton.setOrigin(_playButton.getGlobalBounds().width / 2, _playButton.getGlobalBounds().height / 2);
	_aboutButton.setSize(buttonSize);
	_aboutButton.setOrigin(_aboutButton.getGlobalBounds().width / 2, _aboutButton.getGlobalBounds().height / 2);
	_tutorialButton.setSize(buttonSize);
	_tutorialButton.setOrigin(_tutorialButton.getGlobalBounds().width / 2, _tutorialButton.getGlobalBounds().height / 2);


	//texture
	if (!_playTexture.loadFromFile(PLAY_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_playButton.setTexture(&_playTexture);

	if (!_tutorialTexture.loadFromFile(TUTORIAL_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_tutorialButton.setTexture(&_tutorialTexture);

	if (!_aboutTexture.loadFromFile(ABOUT_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_aboutButton.setTexture(&_aboutTexture);

	//position button

	_playButton.setPosition(sf::Vector2f(_window.getSize().x/2, 600/3));
	_tutorialButton.setPosition(sf::Vector2f(_window.getSize().x / 2, 600/3 + buttonSize.y + 20));
	_aboutButton.setPosition(sf::Vector2f(_window.getSize().x / 2, 600 / 3 + (2 * buttonSize.y) + 50));

}
void MainMenuState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
		{
			_window.close();
		}

		sf::Vector2i MousePos(sf::Mouse::getPosition(_window));
		if (_playButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_playButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_state.push_back(new GameState);
				_state.back()->Init(_window);
			}
		}
		else
		{
			_playButton.setFillColor(sf::Color::White);
		}

		if (_tutorialButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_tutorialButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_state.push_back(new TutorialState);
				_state.back()->Init(_window);
			}
		}
		else
		{
			_tutorialButton.setFillColor(sf::Color::White);
		}

		if (_aboutButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_aboutButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_state.push_back(new AboutState);
				_state.back()->Init(_window);
			}
		}
		else
		{
			_aboutButton.setFillColor(sf::Color::White);
		}
	}
}
void MainMenuState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}

void MainMenuState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_title);
	_window.draw(_playButton);
	_window.draw(_tutorialButton);
	_window.draw(_aboutButton);
	_window.display();
}