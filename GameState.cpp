#include "GameState.h"

void GameState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Ludo Game");
	/*if (!_font.loadfromfile(font))
	{
		std::cout << "failed to open file" << std::endl;
	}*/
}	

void GameState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
		{
			_window.close();
		}

		sf::Vector2i MousePos(sf::Mouse::getPosition(_window));
		/*if (_backButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
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
		}*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::cout << "ESC" << std::endl;
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
}

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}
void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.display();
}