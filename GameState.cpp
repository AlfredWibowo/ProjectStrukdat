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

	_dice.setPosition(sf::Vector2f(1000 - 215, 600 - _rollButton.getSize().y - _dice.getSize().y - 50));
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
	_turn[2].setString("BLUE TURN");
	_turn[3].setString("RED TURN");

	_turn[0].setFillColor(sf::Color::Green);
	_turn[1].setFillColor(sf::Color::Yellow);
	_turn[2].setFillColor(sf::Color::Blue);
	_turn[3].setFillColor(sf::Color::Red);

	_turnFix = _turn[0];

	//background
	_bg.setFillColor(sf::Color::Cyan);
	_bg.setSize(sf::Vector2f(1000, 600));

	//LDL
	//map luar (kiri -> kanan)

	//pintu masuk hijau
	_mapLuar.add(56, 245);
	_entry[0] = _mapLuar.getTail();
	_pion[0][0] = _mapLuar.getTail();
	//daerah putih
	_mapLuar.add(94, 245);

	_mapLuar.add(132, 245);
	_mapLuar.add(169, 245);
	_mapLuar.add(207, 245);
	_mapLuar.add(245, 207);
	_mapLuar.add(245, 169);
	_mapLuar.add(245, 131);
	_mapLuar.add(245, 94);
	_mapLuar.add(245, 57);
	_mapLuar.add(245, 19);

	//pintu keluar merah
	_mapLuar.add(282, 19);
	_exit[3] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(320, 19);

	//pintu masuk merah
	_mapLuar.add(320, 57);
	_entry[3] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(320, 94);
	_mapLuar.add(320, 131);
	_mapLuar.add(320, 169);
	_mapLuar.add(320, 207);
	_mapLuar.add(357, 245);
	_mapLuar.add(395, 245);
	_mapLuar.add(433, 245);
	_mapLuar.add(470, 245);
	_mapLuar.add(508, 245);
	_mapLuar.add(545, 245);

	//pintu keluar biru
	_mapLuar.add(545, 282);
	_exit[2] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(545, 320);

	//pintu masuk biru
	_mapLuar.add(508, 320);
	_entry[2] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(470, 320);
	_mapLuar.add(433, 320);
	_mapLuar.add(395, 320);
	_mapLuar.add(357, 320);
	_mapLuar.add(320, 358);
	_mapLuar.add(320, 395);
	_mapLuar.add(320, 433);
	_mapLuar.add(320, 470);
	_mapLuar.add(320, 508);
	_mapLuar.add(320, 545);

	//pintu keluar kuning
	_mapLuar.add(282, 545);
	_exit[1] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(245, 545);

	//pintu masuk kuning
	_mapLuar.add(245, 508);
	_entry[1] = _mapLuar.getTail();

	//daerah putih
	_mapLuar.add(245, 470);
	_mapLuar.add(245, 433);
	_mapLuar.add(245, 395);
	_mapLuar.add(245, 358);
	_mapLuar.add(207, 320);
	_mapLuar.add(169, 320);
	_mapLuar.add(132, 320);
	_mapLuar.add(94, 320);
	_mapLuar.add(56, 320);
	_mapLuar.add(19, 320);

	//pintu keluar hijau
	_mapLuar.add(19, 282);
	_exit[0] = _mapLuar.getTail();

	//daerah putih	
	_mapLuar.add(19, 245);

	//map hijau
	_mapWarna[0].add(56, 282);
	_mapWarna[0].add(94, 282);
	_mapWarna[0].add(132, 282);
	_mapWarna[0].add(169, 282);
	_mapWarna[0].add(207, 282);
	_mapWarna[0].add(245, 282);

	//map kuning
	_mapWarna[1].add(282, 508);
	_mapWarna[1].add(282, 470);
	_mapWarna[1].add(282, 433);
	_mapWarna[1].add(282, 395);
	_mapWarna[1].add(282, 358);
	_mapWarna[1].add(282, 320);

	//map biru
	_mapWarna[2].add(508, 282);
	_mapWarna[2].add(470, 282);
	_mapWarna[2].add(433, 282);
	_mapWarna[2].add(395, 282);
	_mapWarna[2].add(357, 282);
	_mapWarna[2].add(320, 282);

	//map merah
	_mapWarna[3].add(282, 57);
	_mapWarna[3].add(282, 94);
	_mapWarna[3].add(282, 131);
	_mapWarna[3].add(282, 169);
	_mapWarna[3].add(282, 207);
	_mapWarna[3].add(282, 245);

	_turnFix = _turn[_giliran];

	//pion dimarkas semua
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			diMarkas[i][j] = true;
		}
	}
	_giliran = 0;
}

void GameState::setNext(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4])
{
	/*if (_pion[0][0] == _exit[0])
	{
		_pion[0][0] = _mapWarna[0].getHead();
		break;0
	}*/
	if (markas[_warna][_pionKe] == false)
	{
		if (pos[_warna][_pionKe] == _exit[_warna])
		{
			pos[_warna][_pionKe] = _mapWarna[_warna].getHead();
		}
		else
		{
			pos[_warna][_pionKe] = pos[_warna][_pionKe]->next;
		}
		_pionSprite[_warna][_pionKe].setPosition(sf::Vector2f(pos[_warna][_pionKe]->_posX, pos[_warna][_pionKe]->_posY));


	}
	else
	{
		pos[_warna][_pionKe] = _entry[_warna];
		_pionSprite[_warna][_pionKe].setPosition(sf::Vector2f(pos[_warna][_pionKe]->_posX, pos[_warna][_pionKe]->_posY));
		setdiMarkas(false, _warna, _pionKe);
	}
}

void GameState::setdiMarkas(bool n, int i, int j)
{
	diMarkas[i][j] = n;
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
		/*for (int a = 0; a < 4; a++)
		{
			if (_pionSprite[0][a].getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_pionSprite[0][a].setColor(sf::Color::Red);
			}
			else
			{
				_pionSprite[0][a].setColor(sf::Color::White);
			}
		}*/
		if (mode == 0)
		{
			if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_rollButton.setFillColor(sf::Color::Yellow);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					_move = rand() % 6 + 1;
					_move = 6;
					_dice.setTexture(&_diceHead[_move - 1]);
					_rollButton.setFillColor(sf::Color::White);
					mode = 1;
					/*if (_giliran == 0)
					{
						if (_pion[0][0]->getmarkas())
						{
							for (int a = 0; a < _move; a++)
							{
								_pionSprite[0][0].setPosition(sf::Vector2f(_pion[0][0]->_posX, _pion[0][0]->_posY));
								_pion[0][0] = _pion[0][0]->next;
							}
							_pion[0][0]->_markas = false;
						}
						else
						{
							for (int a = 0; a < 1 && _pion[0][0]->_finish == false; a++)
							{
								if (_pion[0][0] == _mapWarna[0].getTail())
								{
									_pion[0][0]->_finish == true;
									break;
								}
								if (!(_pion[0][0]->_finish))
								{
									_pionSprite[0][0].setPosition(sf::Vector2f(_pion[0][0]->_posX, _pion[0][0]->_posY));
									if (_pion[0][0] == _exit[0])
									{
										_pion[0][0] = _mapWarna[0].getHead();
										break;
									}
									if (_pion[0][0] == _mapWarna[0].getTail())
									{
										_pion[0][0]->_finish == true;
										break;
									}
									_pion[0][0] = _pion[0][0]->next;

								}
							}
							_pion[0][0]->_markas = false;
						}
					}*/

					//if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)) && mode)
					//{
					//	_rollButton.setFillColor(sf::Color::Yellow);
					//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					//	{
					//		_move = rand() % 6 + 1;
					//		_dice.setTexture(&_diceHead[_move - 1]);

					//		if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
					//		{
					//			setNext(_pion, _giliran, 0, diMarkas);
					//		}
					//		_giliran++;

					//		if (_giliran > 3)
					//		{
					//			_giliran = 0;
					//		}
					//		std::cout << _giliran << std::endl;

					//		_turnFix = _turn[_giliran];

					//		/*if (_move != 6)
					//		{
					//			_giliran++;
					//		}*/
					//	}
				}
			}
			else
			{
				_rollButton.setFillColor(sf::Color::White);
			}
		}

		if (mode == 1)
		{
			bool isout;
			for (int a = 0; a < 4; a++)
			{
				if (_pionSprite[_giliran][a].getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
				{
					_pionSprite[_giliran][a].setColor(sf::Color::Magenta);
					if (_move != 6)
					{
						for (int b = 0; b < 4; b++)
						{
							if (diMarkas[_giliran][b])
							{
								isout = true;
							}
						}
					}
					if (_move == 6)
					{
						isout = true;
					}
					if (isout)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (_move != 6)
							{
								if (isout && !(diMarkas[_giliran][a]))
								{
									for (int b = 0; b < _move; b++)
									{
										std::cout << "Klik" << std::endl;
										setNext(_pion, _giliran, a, diMarkas);
										Draw(_window);
										Sleep(300);
										_pionSprite[_giliran][a].setColor(sf::Color::White);
									}
								}
							}
							else
							{
								for (int b = 0; b < _move; b++)
								{
									std::cout << "Klik" << std::endl;
									setNext(_pion, _giliran, a, diMarkas);
									Draw(_window);
									Sleep(300);
									_pionSprite[_giliran][a].setColor(sf::Color::White);
								}
							}

							if (_move != 6)
							{
								_giliran++;
							}
							if (_giliran > 3)
							{
								_giliran = 0;
							}

							_turnFix = _turn[_giliran];
							mode = 0;
						}
					}
				}
				else
				{
					_pionSprite[_giliran][a].setColor(sf::Color::White);
				}
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::cout << "ESC" << std::endl;
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
	_window.clear();
};

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

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
	_window.draw(_turnFix);
	_window.draw(_dice);
	_window.display();

}