#include "GameState.h"

void GameState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Ludo Game");
	_window.setFramerateLimit(240);
	/*if (!_font.loadfromfile(font))
	{
		std::cout << "failed to open file" << std::endl;
	}*/
	Dice.setSize(sf::Vector2f(300, 300));
	Dice.setPosition(_window.getSize().x / 2 - 300, _window.getSize().y / 2 - 300);
	Dicehead[0].loadFromFile(DICE_ONE);
	Dicehead[1].loadFromFile(DICE_TWO);
	Dicehead[2].loadFromFile(DICE_THREE);
	Dicehead[3].loadFromFile(DICE_FOUR);
	Dicehead[4].loadFromFile(DICE_FIVE);
	Dicehead[5].loadFromFile(DICE_SIX);
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
	//dice animation
	int random = rand() % 5;
	Dice.setTexture(&Dicehead[random]);
}
void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(Dice);
	_window.display();
}