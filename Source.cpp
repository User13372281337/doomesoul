#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <ctime>

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
		cout << "If you want to see dialog, watch at the console!" << endl;
	}
	if (printtext == "start_game")
	{
		RenderWindow window(VideoMode(1280, 800), "DoomeSoul");

		cout << "Hello, Johnson!" << endl;
		cout << "You are here to save the world!" << endl;
		cout << "Please, find the thief of The Laser Stone!" << endl;
			cout << "Take this stick" << endl;
			cout << "If you touch him by this stick, you wil steal his soul!" << endl;
			cout << "Your turn!" << endl;
		
		
		//анимации
		float CurrentFrame = 0;


		Texture player1texture;
		player1texture.loadFromFile("player/player1.png");

		Sprite player1;
		player1.setTexture(player1texture);
		player1.setPosition(101, 101);

		player1.setTextureRect(IntRect(96 * int(CurrentFrame) + 96, 96, -96, 96));

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code) {
					case sf::Keyboard::Escape: 
						window.close();
						break;
					}
				}if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
					player1.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); 
					player1.move(0.5, 0);
					
				}if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
					player1.setTextureRect(IntRect(-96 * int(CurrentFrame), 96, 96, 96));
					player1.move(-0.5, 0);
				}if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
					player1.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
					player1.move(0, 0.5);
				}if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
					player1.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
					player1.move(0, -0.5);
				}



			}

			window.clear();
			window.draw(player1);
			window.display();
		}
	}
}
int main() {
	string command;
	cout << "Enter Command" << endl;
	getline(cin, command);
	OnPlayerPrintText(command);
	system("pause");
	return 0;


}