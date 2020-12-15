#include "GameState.h"

void GameState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Ludo Game");
	_window.setFramerateLimit(240);

	//roll button
	if (!_rollTexture.loadFromFile(ROLL_BUTTON))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_rollButton.setTexture(&_rollTexture);
	_rollButton.setSize(sf::Vector2f(250, 100));
	_rollButton.setPosition(sf::Vector2f(1000 - _rollButton.getSize().x - 50, 600 - _rollButton.getSize().y));

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
		if (_rollButton.getGlobalBounds().contains((float)MousePos.x, (float)MousePos.y))
		{
			_rollButton.setFillColor(sf::Color::Yellow);
		/*	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Click" << std::endl;
				_state.push_back(new MainMenuState);
				_state.back()->Init(_window);
			}*/
		}
		else
		{
			_rollButton.setFillColor(sf::Color::White);
		}

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
	_window.draw(_rollButton);
	_window.draw(Dice);
	_window.display();
}