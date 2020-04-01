#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

enum class Yon { SAG, SOL, YUKARÝ, ASAGÝ };

class info
{
public:
	float x, y;
};

info a[100];

void konum(int yon);

float yilan_x = 60.0f;
float yilan_y = 60.0f;

int number = 4;

float x = 15.0f;
float y = 15.0f;

float w = x * 40;
float h = y * 40;


int main()
{

	int yon=0;

	sf::RenderWindow pencere(sf::VideoMode(w+1, h+1), "YilanOyunu");
	pencere.setFramerateLimit(60);

	sf::RectangleShape yatay_cizgi;
	yatay_cizgi.setSize(sf::Vector2f(w,0.6));
	yatay_cizgi.setFillColor(sf::Color(200, 200, 200));

	sf::RectangleShape dikey_cizgi;
	dikey_cizgi.setSize(sf::Vector2f(0.6f, h));
	dikey_cizgi.setFillColor(sf::Color(200,200,200));

	sf::RectangleShape yilan;
	yilan.setSize(sf::Vector2f(x,y));
	yilan.setFillColor(sf::Color::Red);
	yilan.setPosition(30, 30);

	sf::Clock clock;
	float timer = 0, delay = 0.1;
	

	while (pencere.isOpen())
	{

		sf::Event olay;

		while (pencere.pollEvent(olay))
		{
			if (olay.type == sf::Event::Closed)
			{
				pencere.close();
			}
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			yon = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			yon = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			yon = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			yon = 3;
		}

		if (clock.getElapsedTime().asMilliseconds() > 20)

		{
			konum(yon);
			clock.restart();
		}


		pencere.clear();

		for (size_t i = 0; i < number; i++)
		{
			yilan.setPosition(a[i].x, a[i].y);
			pencere.draw(yilan);
		}

		
		for (int i = 0,j=0; i < 41; i++ , j+=15)
		{
			yatay_cizgi.setPosition(0, j);
			pencere.draw(yatay_cizgi);
		}
		
		for (int i = 0, j = 0; i < 41; i++, j += 15)
		{
				dikey_cizgi.setPosition(j, 0);
				pencere.draw(dikey_cizgi);
		}

		


		pencere.display();
	}


	return 0;
}

void konum(int yon)
{
	for (int i = number; i > 0; --i)
	{
		a[i].x = a[i - 1].x;
		a[i].y = a[i - 1].y;
	}

	if (yon==0)
	{
		a[0].x += 15;
	}
	else if (yon == 1)
	{
		a[0].x -= 15;
	}
	else if (yon == 2)
	{
		a[0].y -= 15;
	}
	else if (yon == 3)
	{
		a[0].y += 15;
	}


}
