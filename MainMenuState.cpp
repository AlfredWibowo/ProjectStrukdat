#include "State.h"
#include "MainMenuState.h"
#include <iostream>

void MainMenuState::Init(sf::RenderWindow& _window)
{
	//button
	sf::Vector2f buttonSize(500, 200);
	_playButton.setSize(buttonSize);
	_aboutButton.setSize(buttonSize);

	//texture
	if (!_playTexture.loadFromFile(PLAY_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_playButton.setTexture(&_playTexture);

	if (!_aboutTexture.loadFromFile(ABOUT_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_aboutButton.setTexture(&_aboutTexture);

	//position button
	_playButton.setPosition(sf::Vector2f(1000 / 2 - 200, 56));
	_aboutButton.setPosition(sf::Vector2f(1000 / 2 - 200, 356));

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
				std::cout << "Click" << std::endl;
				_state.push_back(new GameState);
				_state.back()->Init(_window);
			}
		}
		else
		{
			_playButton.setFillColor(sf::Color::White);
		}

		if (_aboutButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_aboutButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Click" << std::endl;
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
	_window.draw(_playButton);
	_window.draw(_aboutButton);
	_window.display();
}