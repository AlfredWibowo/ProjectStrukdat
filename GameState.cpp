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


	//dice
	_dice.setSize(sf::Vector2f(80, 80));
	_dice.setPosition(_window.getSize().x / 2 - 300, _window.getSize().y / 2 - 300);
	_diceHead[0].loadFromFile(DICE_ONE);
	_diceHead[1].loadFromFile(DICE_TWO);
	_diceHead[2].loadFromFile(DICE_THREE);
	_diceHead[3].loadFromFile(DICE_FOUR);
	_diceHead[4].loadFromFile(DICE_FIVE);
	_diceHead[5].loadFromFile(DICE_SIX);
	
	_dice.setPosition(sf::Vector2f(1000 - 215, 600 -_rollButton.getSize().y - _dice.getSize().y - 50));
	_dice.setTexture(&_diceHead[5]);

	//map
	if (!_mapTexture.loadFromFile(MAP_BG))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_mapSprite.setTexture(_mapTexture);

	//pion
	_pionTexture[0].loadFromFile(PION_HIJAU);
	_pionTexture[1].loadFromFile(PION_KUNING);
	_pionTexture[2].loadFromFile(PION_BIRU);
	_pionTexture[3].loadFromFile(PION_MERAH);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_pionSprite[i][j].setTexture(_pionTexture[i]);
		}
	}

	//pion position
	_pionSprite[0][0].setPosition(sf::Vector2f(113, 75));
	_pionSprite[0][1].setPosition(sf::Vector2f(75, 113));
	_pionSprite[0][2].setPosition(sf::Vector2f(113, 151));
	_pionSprite[0][3].setPosition(sf::Vector2f(151, 113));
	for (int i = 0, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}
												 

	_pionSprite[1][0].setPosition(sf::Vector2f(113, 414));
	_pionSprite[1][1].setPosition(sf::Vector2f(75, 452));
	_pionSprite[1][2].setPosition(sf::Vector2f(113, 490));
	_pionSprite[1][3].setPosition(sf::Vector2f(151, 452));
	for (int i = 1, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}
												
	_pionSprite[2][0].setPosition(sf::Vector2f(452, 414));
	_pionSprite[2][1].setPosition(sf::Vector2f(414, 452));
	_pionSprite[2][2].setPosition(sf::Vector2f(452, 490));
	_pionSprite[2][3].setPosition(sf::Vector2f(490, 452));
	for (int i = 2, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}

	_pionSprite[3][0].setPosition(sf::Vector2f(452, 75));
	_pionSprite[3][1].setPosition(sf::Vector2f(414, 113));
	_pionSprite[3][2].setPosition(sf::Vector2f(452, 151));
	_pionSprite[3][3].setPosition(sf::Vector2f(490, 113));
	for (int i = 3, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}

	//turn
	if (!_font.loadFromFile(FONT))
	{
		std::cout << "failed to open file" << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		_turn[i].setFont(_font);
		_turn[i].setCharacterSize(50);
		_turn[i].setPosition(sf::Vector2f(650, 25));
	}
	
	_turn[0].setString("GREEN TURN");
	_turn[1].setString("YELLOW TURN");
	_turn[2].setString("RED TURN");
	_turn[3].setString("BLUE TURN");

	_turn[0].setFillColor(sf::Color::Green);
	_turn[1].setFillColor(sf::Color::Yellow);
	_turn[2].setFillColor(sf::Color::Red);
	_turn[3].setFillColor(sf::Color::Blue);

	//background
	_bg.setFillColor(sf::Color::Cyan);
	_bg.setSize(sf::Vector2f(1000, 600));

	//LDL

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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << MousePos.x <<","<< MousePos.y << std::endl;
		}

		if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_rollButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Click" << std::endl;
				int random = rand() % 6 + 1;
				std::cout << random << std::endl;
				_dice.setTexture(&_diceHead[random - 1]);
			}
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
	//_dice animation
	
}
void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_mapSprite);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_window.draw(_pionSprite[i][j]);
		}
	}
	_window.draw(_turnFix);
	_window.draw(_rollButton);
	_window.draw(_dice);
	_window.display();
}