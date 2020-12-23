#include <SFML/Graphics.hpp>
#include "State.h"
#include "MainMenuState.h"
#include <vector>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	sf::RenderWindow _window(sf::VideoMode(1000, 600), "Ludo Menu", sf::Style::Close);
	std::vector<State*> _state;
	_state.push_back(new MainMenuState);
	_state.back()->Init(_window);

	while (_window.isOpen())
	{
		sf::Event _event;
		_state.back()->Input(_window, _event, _state);
		_state.back()->Update(_window, _state);
		_state.back()->Draw(_window);

		if (_state.size() > 3)
		{
			delete _state[0];
			_state.erase(_state.begin());
		}
	}
	for (int i = 0; i < _state.size(); i++)
	{
		delete _state[i];
	}

	return 0;
}