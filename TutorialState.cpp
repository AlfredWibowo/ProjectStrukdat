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
	_backButton.setOrigin(_backButton.getGlobalBounds().width, _backButton.getGlobalBounds().height / 2);
	_backButton.setPosition(sf::Vector2f(WIDTH / 2 + _backButton.getSize().x / 2, HEIGHT - _backButton.getSize().y / 2 - 5));

	if (!_nextTexture.loadFromFile(NEXT_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_nextButton.setTexture(&_nextTexture);
	_nextButton.setSize(sf::Vector2f(250, 100));
	_nextButton.setPosition(sf::Vector2f(WIDTH - _nextButton.getSize().x - 5, HEIGHT -_nextButton.getSize().y - 5));

	if (!_prevTexture.loadFromFile(PREV_BUTTON))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_prevButton.setTexture(&_prevTexture);
	_prevButton.setSize(sf::Vector2f(250, 100));
	_prevButton.setPosition(sf::Vector2f(5, HEIGHT - _nextButton.getSize().y - 5));

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
	_bg.setSize(sf::Vector2f(WIDTH, HEIGHT));
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
		switch (page)
		{
		case 1:
			if (_nextButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_nextButton.setFillColor(sf::Color::Yellow);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Click" << std::endl;
					_bg.setTexture(&_bg2Texture);
					page = 2;
				}
			}
			else
			{
				_nextButton.setFillColor(sf::Color::White);
			}

		case 2:
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

			if (_prevButton.getGlobalBounds().contains(static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)))
			{
				_prevButton.setFillColor(sf::Color::Yellow);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Click" << std::endl;
					_bg.setTexture(&_bg1Texture);
					page = 1;
				}
			}
			else
			{
				_prevButton.setFillColor(sf::Color::White);
			}
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
	if (page == 1)
	{
		_window.draw(_nextButton);
	}
	else if (page == 2)
	{
		_window.draw(_backButton);
		_window.draw(_prevButton);
	}
	
	_window.display();
}