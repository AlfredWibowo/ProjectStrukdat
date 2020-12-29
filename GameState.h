#pragma once
#include "MainMenuState.h"
#include "LDL.h"
#include <Windows.h>s

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
	sf::Music _music;

	LDL _mapLuar;
	LDL _mapWarna[4];

	Node* _specialSkill[4];
	sf::Text _nameSkill[4];

	bool _onSpecialSpot = false;

	Node* _pion[4][4];
	Node* _entry[4];
	Node* _exit[4];
	int _giliran = 0;
	int _move;
	int mode = 0;

	int _skill;


	bool diMarkas[4][4];
	bool pionfinish[4][4];
	//pionfinish[0][0,1,2,3] -> true ijo menang

	int _finish[4];
	std::vector<int> _rank;

public://fungsi
	void setNext(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4]);

	void setBack(Node* pos[4][4], int _warna, int _pionKe, bool markas[4][4]);

	void setdiMarkas(bool n, int i, int j);

	int jumlah_pion_yg_diluar(bool pion[4][4], int giliran);

	int pion_yg_diluar(bool pion[4][4], int giliran);

	void collision(int giliran, int pion_ke);

	bool cek_di_mapWarna(Node* pos[4][4], int _warna, int pion_ke);

	int jumlah_langkah_keTail(Node* pos[4][4], int _warna, int _pionKe);

	void add_finish(int giliran, int pionke);

	bool udh_finish_semua();

	bool diSpecialSkill(Node* pos[4][4], int _warna, int pion_ke);
};