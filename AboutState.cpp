#include "AboutState.h"

void AboutState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("About Developer");

	//title
	if (!_font.loadFromFile(FONT))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_title.setFont(_font);
	_title.setString("ABOUT US");
	_title.setOrigin(_title.getGlobalBounds().width, _title.getGlobalBounds().height / 2);
	_title.setPosition(sf::Vector2f(_window.getSize().x / 2 - 60, 20));
	_title.setCharacterSize(80);
	_title.setFillColor(sf::Color::Black);
	_title.setStyle(sf::Text::Bold);
	
	//back button
	if (!_backTexture.loadFromFile(BACK_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_backButton.setTexture(&_backTexture);
	_backButton.setSize(sf::Vector2f(250, 100));
	_backButton.setPosition(sf::Vector2f(WIDTH - _backButton.getSize().x - 5, HEIGHT - _backButton.getSize().y - 5));

	//background
	if (!_bgTexture.loadFromFile(ABOUT_BG))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_bg.setTexture(&_bgTexture);
	_bg.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

void AboutState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
		{
			_window.close();
		}

		sf::Vector2i MousePos(sf::Mouse::getPosition(_window));
		if (_backButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_backButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Click" << std::endl;
				_state.push_back(new MainMenuState);
				_state.back()->Init(_window);
			}
		}
		else
		{
			_backButton.setFillColor(sf::Color::White);
		}
	}
}

void AboutState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}
void AboutState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_title);
	_window.draw(_backButton);
	_window.display();
}