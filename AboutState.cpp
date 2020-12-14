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
	_title.setPosition(sf::Vector2f((1000 - _title.getGlobalBounds().width) / 2, 20));
	_title.setCharacterSize(80);
	
	//isi about
	_info.setString("Nama - NRP \n\nAnderson - c14190014 \n\nAlfred - c14190016 \n\nFebri - c14190039");
	_info.setFont(_font);
	_info.setPosition(sf::Vector2f(1000 / 2 - 200, 200));
	_info.setFillColor(sf::Color::Red);

	//back button
	if (!_backTexture.loadFromFile(BACK_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_backButton.setTexture(&_backTexture);
	_backButton.setSize(sf::Vector2f(250, 100));
	_backButton.setPosition(sf::Vector2f(1000 - _backButton.getSize().x, 600 - _backButton.getSize().y));
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
	_window.draw(_title);
	_window.draw(_info);
	_window.draw(_backButton);
	_window.display();
}