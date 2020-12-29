#include "State.h"
#include "MainMenuState.h"
#include <iostream>

void MainMenuState::Init(sf::RenderWindow& _window)
{

	//bg
	if (!_bgTexture.loadFromFile(MAP_BG))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_bg.setTexture(&_bgTexture);
	_bg.setSize(sf::Vector2f(WIDTH, HEIGHT));

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
	_title.setFillColor(sf::Color::Black);
	_title.setStyle(sf::Text::Bold);

	//button
	sf::Vector2f buttonSize(450, 125);
	_playButton.setSize(buttonSize);
	_playButton.setOrigin(_playButton.getGlobalBounds().width, _playButton.getGlobalBounds().height / 2);
	_aboutButton.setSize(buttonSize);
	_aboutButton.setOrigin(_aboutButton.getGlobalBounds().width, _aboutButton.getGlobalBounds().height / 2);
	_tutorialButton.setSize(buttonSize);
	_tutorialButton.setOrigin(_tutorialButton.getGlobalBounds().width, _tutorialButton.getGlobalBounds().height / 2);
	_quitButton.setSize(buttonSize);
	_quitButton.setOrigin(_quitButton.getGlobalBounds().width, _quitButton.getGlobalBounds().height / 2);

	//position button
	_playButton.setPosition(sf::Vector2f(WIDTH / 2 + _playButton.getSize().x / 2, HEIGHT / 2 - _playButton.getSize().y));
	_tutorialButton.setPosition(sf::Vector2f((WIDTH + _tutorialButton.getSize().x) / 2, _playButton.getPosition().y + _tutorialButton.getSize().y + 10));
	_aboutButton.setPosition(sf::Vector2f((WIDTH + _aboutButton.getSize().x) / 2, _tutorialButton.getPosition().y + _aboutButton.getSize().y + 10));
	_quitButton.setPosition(sf::Vector2f((WIDTH + _quitButton.getSize().x) / 2, _aboutButton.getPosition().y + _quitButton.getSize().y + 10));



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

	if (!_quitTexture.loadFromFile(QUIT_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_quitButton.setTexture(&_quitTexture);

	

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

		if (_quitButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_quitButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_window.close();
			}
		}
		else
		{
			_quitButton.setFillColor(sf::Color::White);
		}
	}
}
void MainMenuState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}

void MainMenuState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_title);
	_window.draw(_playButton);
	_window.draw(_tutorialButton);
	_window.draw(_aboutButton);
	_window.draw(_quitButton);
	_window.display();
}