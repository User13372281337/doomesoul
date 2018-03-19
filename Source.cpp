#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void OnPlayerPrintText(string printtext) {
	
	if (printtext == "help")
	{
		cout << "If you want to play, write start_game" << endl;
		cout << "Project name - DoomeSoul" << endl;
		cout << "Created by Ryugo" << endl;
		cout << "BETA EDITION" << endl;
	}
	if (printtext == "start_game")
	{
		RenderWindow window(VideoMode(1280, 800), "DoomeSoul");
		CircleShape shape(100.f);
		shape.setFillColor(Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
	}
}
int main(){
	string command;
	cout << "Enter Command" << endl;
	getline(cin, command);
	OnPlayerPrintText(command);
	system("pause");
	return 0;

	
}
