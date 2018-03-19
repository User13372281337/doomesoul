#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <conio.h>

//Defines only!!!!!!
#define SFML_STATIC

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
		
		Texture player2texture;
		player2texture.loadFromFile("player/player2.png");

		Sprite player2;
		player2.setTexture(player2texture);
		player2.setPosition(100, 100);

		Texture player1texture;
		player1texture.loadFromFile("player/player1.png");

		Sprite player1;
		player1.setTexture(player1texture);
		player1.setPosition(101, 101);
		
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			
				if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code) {
					case sf::Keyboard::Escape:  // обработка нажатия Escape
						window.close();
						break;
					}
				}if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code) {
					case sf::Keyboard::D:  // обработка нажатия Escape
						window.draw(player1);
						break;
					}
				}
			
			
			
			}

			window.clear();
			window.draw(player2);
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
