#pragma once
#include "MainMenuState.h"
#include "LDL.h"
#include <Windows.h>

class GameState :public State
{
public:
	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::RectangleShape _dice, _rollButton;
	sf::Texture _diceHead[6];
	sf::Texture _rollTexture;
	sf::Texture _mapTexture;
	sf::Sprite _mapSprite;
	sf::Sprite _pionSprite[4][4];
	sf::Texture _pionTexture[4];
	sf::Font _font;
	sf::Text _turn[4];
	sf::Text _turnFix;
	sf::RectangleShape _bg;
	LDL _mapLuar;
	LDL _mapWarna[4];

	Node* _pion[4][4];
	Node* _entry[4];
	Node* _exit[4];
	int _giliran = 0;
	int _move;
	int mode = 0;

	bool diMarkas[4][4];

public://fungsi
	void setNext(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4]);

	void setdiMarkas(bool n, int i, int j);
};

