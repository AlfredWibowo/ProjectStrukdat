#include "GameState.h"
#include "RankingState.h"

void GameState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Ludo Game");
	_window.setFramerateLimit(240);

	//music
	if (!_music.openFromFile(MUSIC))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_music.setLoop(true);
	_music.play();
	_music.setVolume(0);

	//roll button
	if (!_rollTexture.loadFromFile(ROLL_BUTTON))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_rollButton.setTexture(&_rollTexture);
	_rollButton.setSize(sf::Vector2f(250, 100));
	_rollButton.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT - _rollButton.getSize().y - 20));


	//dice
	_dice.setSize(sf::Vector2f(80, 80));
	_dice.setPosition(_window.getSize().x / 2 - 300, _window.getSize().y / 2 - 300);
	_diceHead[0].loadFromFile(DICE_ONE);
	_diceHead[1].loadFromFile(DICE_TWO);
	_diceHead[2].loadFromFile(DICE_THREE);
	_diceHead[3].loadFromFile(DICE_FOUR);
	_diceHead[4].loadFromFile(DICE_FIVE);
	_diceHead[5].loadFromFile(DICE_SIX);

	_dice.setPosition(sf::Vector2f(WIDTH / 4 + _dice.getSize().x * 2, HEIGHT - _dice.getSize().y - 50));
	_dice.setTexture(&_diceHead[5]);

	//map
	if (!_mapTexture.loadFromFile(MAP))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_mapSprite.setTexture(_mapTexture);

	//pion
	_pionTexture[0].loadFromFile(PION_HIJAU);
	_pionTexture[1].loadFromFile(PION_KUNING);
	_pionTexture[2].loadFromFile(PION_BIRU);
	_pionTexture[3].loadFromFile(PION_MERAH);

	//pionShield
	_pionShieldTexture[0].loadFromFile(PION_HIJAU_SHIELD);
	_pionShieldTexture[1].loadFromFile(PION_KUNING_SHIELD);
	_pionShieldTexture[2].loadFromFile(PION_BIRU_SHIELD);
	_pionShieldTexture[3].loadFromFile(PION_MERAH_SHIELD);

	//posisi awal hijau
	_pionSprite[0][0].setPosition(sf::Vector2f(113, 75));
	_pionSprite[0][1].setPosition(sf::Vector2f(75, 113));
	_pionSprite[0][2].setPosition(sf::Vector2f(113, 151));
	_pionSprite[0][3].setPosition(sf::Vector2f(151, 113));
	for (int i = 0, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}

	//posisi awal kuning
	_pionSprite[1][0].setPosition(sf::Vector2f(113, 414));
	_pionSprite[1][1].setPosition(sf::Vector2f(75, 452));
	_pionSprite[1][2].setPosition(sf::Vector2f(113, 490));
	_pionSprite[1][3].setPosition(sf::Vector2f(151, 452));
	for (int i = 1, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}

	//posisi awal biru
	_pionSprite[2][0].setPosition(sf::Vector2f(452, 414));
	_pionSprite[2][1].setPosition(sf::Vector2f(414, 452));
	_pionSprite[2][2].setPosition(sf::Vector2f(452, 490));
	_pionSprite[2][3].setPosition(sf::Vector2f(490, 452));
	for (int i = 2, j = 0; j < 4; j++)
	{
		_pionSprite[i][j].setTexture(_pionTexture[i]);
	}

	//posisi awal merah
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
		_turn[i].setCharacterSize(60);
		_turn[i].setPosition(sf::Vector2f(_dice.getPosition().x + WIDTH / 4, 1 / 4 * HEIGHT + 60));
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

	//bg
	if (!_bgTexture.loadFromFile(GAME_BG))
	{
		std::cout << "failed to open file" << std::endl;
	}
	_bg.setTexture(&_bgTexture);
	_bg.setSize(sf::Vector2f(WIDTH, HEIGHT));

	//CDL
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
	_specialSkill[0] = _mapLuar.getTail();

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
	_specialSkill[1] = _mapLuar.getTail();

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
	_specialSkill[2] = _mapLuar.getTail();

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
	_specialSkill[3] = _mapLuar.getTail();

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
			pionfinish[i][j] = false;
		}
	}

	_nameSkill[0].setString("MAJU");
	_nameSkill[1].setString("MUNDUR");
	_nameSkill[2].setString("SHIELD");

	for (int i = 0; i < 3; i++)
	{
		_nameSkill[i].setFillColor(sf::Color::Black);
		_nameSkill[i].setFont(_font);
		_nameSkill[i].setCharacterSize(60);
		_nameSkill[i].setPosition(sf::Vector2f(_turn[i].getPosition().x, _turn[i].getPosition().y * 2 + 60));
	}

	_skillFix = _nameSkill[0];
	_giliran = 0;

	//cek brp finsih
	for (int i = 0; i < 4; i++)
	{
		_finish[i] = 0;
	}

	std::cout << "Map Size: " << _mapLuar.getSize() << std::endl;
}

bool GameState::cek_di_mapWarna(Node* pos[4][4], int _warna, int pion_ke)
{
	Node* iterator = _mapWarna[_warna].getHead();

	while (iterator != _mapWarna[_warna].getTail())
	{
		if (pos[_warna][pion_ke] == iterator)
		{
			return true;
		}
		iterator = iterator->next;
	}
	if (pos[_warna][pion_ke] == iterator)
	{
		return true;
	}
	return false;
}

bool GameState::diSpecialSkill(Node* pos[4][4], int _warna, int pion_ke)
{
	for (int i = 0; i < 4; i++)
	{
		if (pos[_warna][pion_ke] == _specialSkill[i])
		{
			return true;
		}
	}
	return false;
}

int GameState::jumlah_langkah_keTail(Node* pos[4][4], int _warna, int pion_ke)
{
	int langkah = 0;
	Node* iterator = _mapWarna[_warna].getHead();

	while (iterator != _mapWarna[_warna].getTail())
	{
		langkah++;
		iterator = iterator->next;
	}
	langkah++;
	return langkah;
}

void GameState::setNext(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4])
{
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

void GameState::setBack(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4])
{
	if (markas[_warna][_pionKe] == false)
	{
		if (pos[_warna][_pionKe] != _entry[_warna])
		{
			if (pos[_warna][_pionKe] == _mapWarna[_warna].getHead())
			{
				pos[_warna][_pionKe] = _exit[_warna];
			}
			else
			{
				pos[_warna][_pionKe] = pos[_warna][_pionKe]->prev;
			}
			_pionSprite[_warna][_pionKe].setPosition(sf::Vector2f(pos[_warna][_pionKe]->_posX, pos[_warna][_pionKe]->_posY));
		}
		else
		{
			setdiMarkas(true, _warna, _pionKe);
			if (_giliran == 0)
			{
				if (_pionKe == 0)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(113, 75));

				}
				else if (_pionKe == 1)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(75, 113));
				}
				else if (_pionKe == 2)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(113, 151));
				}
				else if (_pionKe == 3)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(151, 113));
				}
			}
			//kuning
			else if (_giliran == 1)
			{
				if (_pionKe == 0)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(113, 414));
				}
				else if (_pionKe == 1)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(75, 452));
				}
				else if (_pionKe == 2)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(113, 490));
				}
				else if (_pionKe == 3)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(151, 452));
				}
			}
			//biru
			else if (_giliran == 2)
			{
				if (_pionKe == 0)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(452, 414));
				}
				else if (_pionKe == 1)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(414, 452));
				}
				else if (_pionKe == 2)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(452, 490));

				}
				else if (_pionKe == 3)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(490, 452));
				}
			}
			//merah
			else if (_giliran == 3)
			{
				if (_pionKe == 0)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(452, 75));

				}
				else if (_pionKe == 1)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(414, 113));
				}
				else if (_pionKe == 2)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(452, 151));
				}
				else if (_pionKe == 3)
				{
					_pionSprite[_giliran][_pionKe].setPosition(sf::Vector2f(490, 113));
				}
			}

		}
	}
}

void GameState::setdiMarkas(bool n, int i, int j)
{
	diMarkas[i][j] = n;
}

int GameState::jumlah_pion_yg_diluar(bool pion[4][4], int giliran)
{
	int jumlah_pion_diluar = 0;
	for (int i = 0; i < 4; i++)
	{
		if (pion[giliran][i] == false && !pionfinish[giliran][i])
		{
			jumlah_pion_diluar++;
		}
	}
	return jumlah_pion_diluar;
}

int GameState::pion_yg_diluar(bool pion[4][4], int giliran)
{
	for (int i = 0; i < 4; i++)
	{
		if (pion[giliran][i] == false && !pionfinish[giliran][i])
		{
			return i;
		}
	}
	return -1;
}

void GameState::collision(int giliran, int pion_ke)
{
	for (int b = 0; b < 4; b++)
	{
		if (b != giliran)
		{
			for (int c = 0; c < 4; c++)
			{
				//cek posisi semua pion _giliran ada yg sama sama _giliran lain
				if (_pion[giliran][pion_ke] == _pion[b][c]) //b = selain _giliran
				{
					//setdiMarkas(true, _giliran, c);
					//set posisi pion di tempat awal
					if (!diMarkas[b][c])
					{
						std::cout << "ada yg posisi sama dengan pion giliran " << _giliran << " pion " << c << std::endl;
						if (shieldpion[b][c])
						{
							std::cout << "pion ada shield" << std::endl;
							setNext(_pion, giliran, pion_ke, diMarkas);
							shieldpion[b][c] = false;
							_pionSprite[b][c].setTexture(_pionTexture[b]);
						}
						else
						{
							/*diMarkas[_giliran][a] == true;*/
							setdiMarkas(true, b, c);
							//hijau
							if (b == 0)
							{
								if (c == 0)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(113, 75));

								}
								else if (c == 1)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(75, 113));
								}
								else if (c == 2)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(113, 151));
								}
								else if (c == 3)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(151, 113));
								}
							}
							//kuning
							else if (b == 1)
							{
								if (c == 0)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(113, 414));
								}
								else if (c == 1)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(75, 452));
								}
								else if (c == 2)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(113, 490));
								}
								else if (c == 3)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(151, 452));
								}
							}
							//biru
							else if (b == 2)
							{
								if (c == 0)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(452, 414));
								}
								else if (c == 1)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(414, 452));
								}
								else if (c == 2)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(452, 490));

								}
								else if (c == 3)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(490, 452));
								}
							}
							//merah
							else if (b == 3)
							{
								if (c == 0)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(452, 75));

								}
								else if (c == 1)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(414, 113));
								}
								else if (c == 2)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(452, 151));
								}
								else if (c == 3)
								{
									_pionSprite[b][c].setPosition(sf::Vector2f(490, 113));
								}
							}
						}
					}
				}
			}
		}
	}
}

void GameState::add_finish(int giliran, int pionke)
{
	if (_pion[giliran][pionke] == _mapWarna[giliran].getTail())
	{
		_finish[giliran]++;
		pionfinish[_giliran][pionke] = true;
	}
}

bool GameState::udh_finish_semua()
{
	for (int i = 0; i < 4; i++)
	{
		if (_finish[i] != 4)
		{
			return false;
		}
	}
	return true;
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

		if (mode == 0)
		{
			if (_rank.size() == 3)
			{
				_music.stop();
				_rank.push_back(_giliran);

				for (int a = 0; a < _rank.size(); a++)
				{
					std::cout << _rank[a] << std::endl;
				}

				std::fstream _file;

				_file.open("Ranking.txt", std::ios::out);
				if (_file.is_open())
				{
					for (int i = 0; i < _rank.size(); i++)
					{
						_file << _rank[i] << std::endl;
					}
				}
				_file.close();

				_state.push_back(new RankingState);
				_state.back()->Init(_window);


			}

			if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_rollButton.setFillColor(sf::Color::Yellow);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "move: "; std::cin >> _move;
					//_move = rand() % 6 + 1;
					_dice.setTexture(&_diceHead[_move - 1]);
					_rollButton.setFillColor(sf::Color::White);
					std::cout << "giliran = " << _giliran << std::endl;
					mode = 1;
				}
			}
			else
			{
				_rollButton.setFillColor(sf::Color::White);
			}
		}

		else if (mode == 1)
		{
			if (_move != 6)
			{
				if (jumlah_pion_yg_diluar(diMarkas, _giliran) == 1)
				{
					int pion_ke = pion_yg_diluar(diMarkas, _giliran);

					_lastPos = pion_ke; //buat special skill shield

					bool goback = false; //jika sampai finish maka true -> move dengan setback
					//klo di map warna

					if (cek_di_mapWarna(_pion, _giliran, pion_ke) == true)
					{
						for (int a = 0; a < _move; a++)
						{
							if (goback)
							{
								setBack(_pion, _giliran, pion_ke, diMarkas);
								Draw(_window);
								Sleep(300);
							}
							else
							{
								setNext(_pion, _giliran, pion_ke, diMarkas);
								Draw(_window);
								Sleep(300);
								if (_pion[_giliran][pion_ke] == _mapWarna[_giliran].getTail())
								{
									goback = true;
								}
							}
						}

						_pionSprite[_giliran][pion_ke].setColor(sf::Color::White);

					}
					//klo ga
					else
					{
						for (int i = 0; i < _move; i++)
						{
							setNext(_pion, _giliran, pion_ke, diMarkas);
							//mapnya didelete klo dpt dadu 3
							if (_move == 3)
							{
								bool del = true;
								for (int z = 0; z < 4; z++)//_giliran
								{
									for (int p = 0; p < 4; p++) //pion ke
									{
										if (_pion[_giliran][pion_ke]->prev == _entry[z] || _pion[_giliran][pion_ke]->prev == _exit[z] || _pion[_giliran][pion_ke]->prev == _pion[z][p])
										{
											if (_giliran != z)
												del = false;
										}
									}
								}
								if (del)
								{
									disabled.push_back(_pion[_giliran][pion_ke]->prev);
									disabledshape.push_back(sf::RectangleShape());
									disabledshape.back().setPosition(disabled.back()->_posX, disabled.back()->_posY);

									_mapLuar.deleteNode(_pion[_giliran][pion_ke]->prev);
									std::cout << "Map Size: " << _mapLuar.getSize() << std::endl;
								}
							}
							Draw(_window);
							Sleep(300);
						}
						_pionSprite[_giliran][pion_ke].setColor(sf::Color::White);
					}

					//tabrakan
					collision(_giliran, pion_ke);

					add_finish(_giliran, pion_ke);

					if (_finish[_giliran] == 4)
					{
						std::cout << "Masuk ke vector rank" << std::endl;
						_rank.push_back(_giliran);
					}

					//klo dispecial skill
					if (diSpecialSkill(_pion, _giliran, pion_ke))
					{
						std::cout << "masuk special skill bang " << std::endl;
						mode = 2;
					}
					else
					{
						if (_move != 6)
						{
							_giliran++;
						}

						for (int c = 0; c < _rank.size(); c++)
						{
							if (_giliran == _rank[c])
							{
								_giliran++;
							}
						}
						if (_giliran > 3)
						{
							_giliran = 0;
						}
						_turnFix = _turn[_giliran];
						mode = 0;
					}
				}
				else if (jumlah_pion_yg_diluar(diMarkas, _giliran) == 0)//klo ga ad yg diluar markas langsung ganti turn
				{
					if (_move != 6)
					{
						_giliran++;
					}


					if (_giliran > 3)
					{
						_giliran = 0;
					}

					for (int c = 0; c < _rank.size(); c++)
					{
						if (_giliran == _rank[c])
						{
							_giliran++;
							if (_giliran > 3)
							{
								_giliran = 0;
							}
						}
					}
					_turnFix = _turn[_giliran];
					mode = 0;
				}
				else if (jumlah_pion_yg_diluar(diMarkas, _giliran) > 1)
				{
					for (int a = 0; a < 4; a++)
					{
						if (_pionSprite[_giliran][a].getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)) && !pionfinish[_giliran][a] && !diMarkas[_giliran][a])
						{
							_pionSprite[_giliran][a].setColor(sf::Color::Magenta);

							//action klo pion udah keluar
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								_lastPos = a; //buat special skill shield
								if (_move != 6)
								{
									if (!(diMarkas[_giliran][a]))
									{

										//klo di map warna
										//sg baru
										bool goback = false;
										if (cek_di_mapWarna(_pion, _giliran, a) == true)
										{
											for (int i = 0; i < _move; i++)
											{
												if (goback)
												{
													setBack(_pion, _giliran, a, diMarkas);
													Draw(_window);
													Sleep(300);
												}
												else
												{
													setNext(_pion, _giliran, a, diMarkas);
													Draw(_window);
													Sleep(300);
													if (_pion[_giliran][a] == _mapWarna[_giliran].getTail())
													{
														goback = true;
													}
												}
											}
											_pionSprite[_giliran][a].setColor(sf::Color::White);

										}
										//klo ga
										else
										{
											for (int i = 0; i < _move; i++)
											{
												setNext(_pion, _giliran, a, diMarkas);
												if (_move == 3)
												{
													_mapLuar.deleteNode(_pion[_giliran][a]->prev);
													std::cout << "Map Size: " << _mapLuar.getSize() << std::endl;
												}
												Draw(_window);
												Sleep(300);
											}
											_pionSprite[_giliran][a].setColor(sf::Color::White);

										}

									}
								}
								else
								{
									bool goback = false; //klo nyampek finish jdi true
									for (int i = 0; i < _move; i++)
									{
										if (goback)
										{
											setBack(_pion, _giliran, a, diMarkas);
											Draw(_window);
											Sleep(300);
										}
										else
										{
											setNext(_pion, _giliran, a, diMarkas);
											if (_move == 3)
											{
												_mapLuar.deleteNode(_pion[_giliran][a]->prev);
												std::cout << "Map Size: " << _mapLuar.getSize() << std::endl;
											}
											Draw(_window);
											Sleep(300);
											if (_pion[_giliran][a] == _mapWarna[_giliran].getTail())
											{
												goback = true;
											}
										}
									}


									_pionSprite[_giliran][a].setColor(sf::Color::White);
								}

								//tabrakan
								collision(_giliran, a);

								//klo ad yg finish finish[i]++
								add_finish(_giliran, a);


								//klo udh difinish semua
								if (_finish[_giliran] == 4)
								{
									std::cout << "Masuk ke vector rank" << std::endl;
									_rank.push_back(_giliran);
								}


								//klo dispecial skill
								if (diSpecialSkill(_pion, _giliran, a))
								{
									std::cout << "masuk special skill bang " << std::endl;
									mode = 2;
								}
								else
								{
									if (_move != 6)
									{
										_giliran++;
									}

									for (int c = 0; c < _rank.size(); c++)
									{
										if (_giliran == _rank[c])
										{
											_giliran++;
										}
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

			}

			else
			{
				for (int a = 0; a < 4; a++)
				{
					if (_pionSprite[_giliran][a].getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)) && !pionfinish[_giliran][a])
					{
						_pionSprite[_giliran][a].setColor(sf::Color::Magenta);

						//action klo pion udah keluar
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							_lastPos = a; //buat special skill shield
							
							bool goback = false; //klo nyampek finish jdi true
							for (int i = 0; i < _move; i++)
							{
								if (goback)
								{
									setBack(_pion, _giliran, a, diMarkas);
									Draw(_window);
									Sleep(300);
								}
								else
								{
									setNext(_pion, _giliran, a, diMarkas);
									Draw(_window);
									Sleep(300);
									if (_pion[_giliran][a] == _mapWarna[_giliran].getTail())
									{
										goback = true;
									}
								}
							}

							_pionSprite[_giliran][a].setColor(sf::Color::White);

							//tabrakan
							collision(_giliran, a);

							//klo ad yg finish finish[i]++
							add_finish(_giliran, a);


							//klo udh difinish semua
							if (_finish[_giliran] == 4)
							{
								std::cout << "Masuk ke vector rank" << std::endl;
								_rank.push_back(_giliran);
							}


							//klo dispecial skill
							if (diSpecialSkill(_pion, _giliran, a))
							{
								std::cout << "masuk special skill bang " << std::endl;
								mode = 2;
							}
							else
							{
								if (_move != 6)
								{
									_giliran++;
								}

								for (int c = 0; c < _rank.size(); c++)
								{
									if (_giliran == _rank[c])
									{
										_giliran++;
									}
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
		}

		//roll klo dispecial skill
		else if (mode == 2)
		{
			if (_rollButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_rollButton.setFillColor(sf::Color::Yellow);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					_skill = rand() % 3 + 1;
					std::cout << "skill-ke: "; std::cin >> _skill;
					_dice.setTexture(&_diceHead[_skill - 1]);
					_rollButton.setFillColor(sf::Color::White);
					std::cout << _giliran << std::endl;

					if (_skill == 3)
					{
						mode = 4;
					}
					else
					{
						mode = 3;
					}
					_skillFix = _nameSkill[_skill - 1];
				}
			}
			else
			{
				_rollButton.setFillColor(sf::Color::White);
			}
			Draw(_window);
		}

		//action dari special skill maju atau mundur
		else if (mode == 3)
		{
			for (int b = 0; b < 4; b++)
			{
				for (int a = 0; a < 4; a++)
				{
					if (_pionSprite[b][a].getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)) && !pionfinish[_giliran][a] && !diMarkas[b][a])
					{
						_pionSprite[b][a].setColor(sf::Color::Magenta);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							std::cout << "Special skill jalan ke pion yg ditekan " << std::endl;

							switch (_skill)
							{
							case 1://maju

								_rollButton.setFillColor(sf::Color::Yellow);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									//std::cout << "move: "; std::cin >> _move;
									_move = rand() % 5 + 1;
									_dice.setTexture(&_diceHead[_move - 1]);
									_rollButton.setFillColor(sf::Color::White);

									bool goback = false; //klo nyampek finish jdi true
									for (int i = 0; i < _move; i++)
									{
										if (goback)
										{
											setBack(_pion, b, a, diMarkas);
											Draw(_window);
											Sleep(300);
										}
										else
										{
											setNext(_pion, b, a, diMarkas);
											Draw(_window);
											Sleep(300);
											if (_pion[b][a] == _mapWarna[b].getTail())
											{
												goback = true;
											}
										}
									}
									_pionSprite[b][a].setColor(sf::Color::White);

									collision(b, a);

									//klo dispecial skill
									if (diSpecialSkill(_pion, _giliran, a))
									{
										std::cout << "masuk special skill bang " << std::endl;
										mode = 2;
									}
									else
									{
										if (_move != 6)
										{
											_giliran++;
										}
										bool finished = false;
										for (int c = 0; c < _rank.size(); c++)
										{
											if (_giliran == _rank[c])
											{
												_giliran++;
											}
										}
										if (_giliran > 3)
										{
											_giliran = 0;
										}
										_turnFix = _turn[_giliran];

									}
								}
								break;



							case 2://mundur
								_rollButton.setFillColor(sf::Color::Yellow);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									//std::cout << "move: "; std::cin >> _move;
									_move = rand() % 5 + 1;
									_dice.setTexture(&_diceHead[_move - 1]);
									_rollButton.setFillColor(sf::Color::White);

									for (int i = 0; i < _move; i++)
									{
										setBack(_pion, b, a, diMarkas);
										Draw(_window);
										Sleep(300);
									}
									_pionSprite[b][a].setColor(sf::Color::White);

									collision(b, a);

									//klo dispecial skill
									if (diSpecialSkill(_pion, _giliran, a))
									{
										std::cout << "masuk special skill bang " << std::endl;
										mode = 2;
									}
									else
									{
										if (_move != 6)
										{
											_giliran++;
										}
										bool finished = false;
										for (int c = 0; c < _rank.size(); c++)
										{
											if (_giliran == _rank[c])
											{
												_giliran++;
											}
										}
										if (_giliran > 3)
										{
											_giliran = 0;
										}
										_turnFix = _turn[_giliran];

									}
								}
								break;
							}
							mode = 0;
						}
					}
					else
					{
						_pionSprite[b][a].setColor(sf::Color::White);
					}


				}
			}
		}

		//action dari special skill shield
		else if (mode == 4)
		{
			_pionSprite[_giliran][_lastPos].setColor(sf::Color::White);
			_pionSprite[_giliran][_lastPos].setTexture(_pionShieldTexture[_giliran]);
			shieldpion[_giliran][_lastPos] = true;
			std::cout << "pion " << _giliran << " " << _lastPos << " dpt shield" << std::endl;
			if (_move != 6)
			{
				_giliran++;
			}
			bool finished = false;
			for (int c = 0; c < _rank.size(); c++)
			{
				if (_giliran == _rank[c])
				{
					_giliran++;
				}
			}
			if (_giliran > 3)
			{
				_giliran = 0;
			}
			_turnFix = _turn[_giliran];

			mode = 0;
		}

		//klo dr game cuma bisa back pakek esc
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::cout << "ESC" << std::endl;
			_music.stop();
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);

		}
		_window.clear();
	}

}

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
	for (int a = 0; a < disabledshape.size(); a++)
	{
		disabledshape[a].setSize(sf::Vector2f(36, 36));
		disabledshape[a].setFillColor(sf::Color(248, 24, 148));
		_window.draw(disabledshape[a]);
	}
	if (mode > 2)
	{
		_window.draw(_skillFix);
	}
	_window.draw(_turnFix);
	_window.draw(_rollButton);
	_window.draw(_dice);
	_window.display();
}