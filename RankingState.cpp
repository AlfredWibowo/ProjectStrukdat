#include "RankingState.h"
#include "GameState.h"

void RankingState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Ranking");

	//title
	if (!_font.loadFromFile(FONT))
	{
		std::cout << "Failed to Open File" << std::endl;
	}

	_title.setFont(_font);
	_title.setString("RANKING");
	_title.setOrigin(_title.getGlobalBounds().width, _title.getGlobalBounds().height / 2);
	_title.setPosition(sf::Vector2f(_window.getSize().x / 2 - 60, 20));
	_title.setCharacterSize(80);
	_title.setFillColor(sf::Color::Black);
	_title.setStyle(sf::Text::Bold);

	if (!_font2.loadFromFile(FONT2))
	{
		std::cout << "Failed to Open File" << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		_ranking[i].setFont(_font2);
		_ranking[i].setOrigin(_title.getGlobalBounds().width, _title.getGlobalBounds().height / 2);
		_ranking[i].setCharacterSize(60);
	}

	_ranking[0].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2 -_ranking[0].getCharacterSize()));
	_ranking[1].setPosition(sf::Vector2f(WIDTH / 2, _ranking[0].getPosition().y + _ranking[0].getCharacterSize()));
	_ranking[2].setPosition(sf::Vector2f(WIDTH / 2, _ranking[1].getPosition().y + _ranking[2].getCharacterSize()));
	_ranking[3].setPosition(sf::Vector2f(WIDTH / 2, _ranking[2].getPosition().y + _ranking[3].getCharacterSize()));

	winText[0] = "GREEN";
	winText[1] = "YELLOW";
	winText[2] = "BLUE";
	winText[3] = "RED";

	std::fstream _file;

	_file.open("Ranking.txt", std::ios::in);
	if (_file.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			_file >> rank[i];
		}
	}
	_file.close();

	_ranking[0].setString("1st: \t" + winText[rank[0]]);
	_ranking[1].setString("2nd: \t" + winText[rank[1]]);
	_ranking[2].setString("3rd: \t" + winText[rank[2]]);
	_ranking[3].setString("4th: \t" + winText[rank[3]]);

	//back button
	if (!_backTexture.loadFromFile(BACK_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_backButton.setTexture(&_backTexture);
	_backButton.setSize(sf::Vector2f(250, 100));
	_backButton.setPosition(sf::Vector2f(WIDTH - _backButton.getSize().x - 5, HEIGHT - _backButton.getSize().y - 5));

}
void RankingState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
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
void RankingState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}
void RankingState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_title);
	for (int i = 0; i < 4; i++)
	{
		_window.draw(_ranking[i]);
	}
	_window.draw(_backButton);
	_window.display();
}