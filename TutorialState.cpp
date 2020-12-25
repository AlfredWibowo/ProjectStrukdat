#include "TutorialState.h"

void TutorialState::Init(sf::RenderWindow& _window)
{
	_window.setTitle("Game Tutorial");

	//title
	if (!_font.loadFromFile(FONT))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_title.setFont(_font);
	_title.setString("TUTORIAL");
	_title.setOrigin(_title.getGlobalBounds().width, _title.getGlobalBounds().height / 2);
	_title.setPosition(sf::Vector2f(_window.getSize().x / 2 - 60, 20));
	_title.setCharacterSize(80);

	//back button
	if (!_backTexture.loadFromFile(BACK_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_backButton.setTexture(&_backTexture);
	_backButton.setSize(sf::Vector2f(250, 100));
	_backButton.setPosition(sf::Vector2f(1000 - _backButton.getSize().x, 600 - _backButton.getSize().y));

	if (!_nextTexture.loadFromFile(NEXT_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_nextButton.setTexture(&_nextTexture);
	_nextButton.setSize(sf::Vector2f(250, 100));
	_nextButton.setPosition(sf::Vector2f(1000 - _backButton.getSize().x, 600 - _backButton.getSize().y));

	//bg
	if (!_bg1Texture.loadFromFile(TUTORIAL1_BG))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	if (!_bg2Texture.loadFromFile(TUTORIAL2_BG))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_bg.setTexture(&_bg1Texture);
	_bg.setSize(sf::Vector2f(1000, 600));
}
void TutorialState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
		{
			_window.close();
		}

		sf::Vector2i MousePos(sf::Mouse::getPosition(_window));
		if (_nextButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
		{
			_nextButton.setFillColor(sf::Color::Yellow);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Click" << std::endl;
				_bg.setTexture(&_bg2Texture);
			}
		}

		else
		{
			_nextButton.setFillColor(sf::Color::White);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::cout << "ESC" << std::endl;
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
}
void TutorialState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}
void TutorialState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_title);
	_window.draw(_nextButton);
	//_window.draw(_backButton);
	_window.display();
}