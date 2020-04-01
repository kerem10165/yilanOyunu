#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

enum class Yon { SAG, SOL, YUKARÝ, ASAGÝ };

class info
{
public:
	float x, y;
};



class Yem
{
public:
	float x, y;
};

info a[2000];
Yem yem;


void konum(int yon, uniform_int_distribution<int>& dagilim, mt19937& motor);


int number = 40;

float x = 15.0f;
float y = 15.0f;

float w = x * 40;
float h = y * 40;


int main()
{

	int yon=0;
	random_device rd;
	uniform_int_distribution<int> dagilim(0, 39);
	mt19937 motor(rd());
	yem.x = dagilim(motor)*15;
	yem.y = dagilim(motor)*15;


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

	sf::RectangleShape yemm;
	yemm.setSize(sf::Vector2f(x, y));
	yemm.setFillColor(sf::Color::Green);

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

		if (clock.getElapsedTime().asMilliseconds() > 120)

		{
			konum(yon,dagilim,motor);
			clock.restart();
		}

		//draw

		pencere.clear();

		for (size_t i = 0; i < number; i++)
		{
			yilan.setPosition(a[i].x, a[i].y);
			pencere.draw(yilan);
		}


		yemm.setPosition(yem.x, yem.y);
		pencere.draw(yemm);

		
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

void konum(int yon,uniform_int_distribution<int>&dagilim,mt19937 &motor)
{
	static int sayac = 0;

	if (sayac >= 40)
	{
		for (int i = 1; i < number; i++)
		{
			if (a[0].x == a[i].x && a[0].y == a[i].y)
			{
				sayac = 0;
				a[0].x = 0;
				a[0].y = 0;
				number = 40;
			}
		}
	}

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

	


	cout << sayac << "x: " << a[0].x << " y: " << a[0].y << endl;
	
	
	if (a[0].x < 0)
	{
		a[0].x = 585;
	}
	else if (a[0].x > 585)
	{
		a[0].x = 0;
	}
	else if (a[0].y > 585)
	{
		a[0].y = 0;
	}
	else if (a[0].y < 0)
	{
		a[0].y = 585;
	}

	if (a[0].x == yem.x && a[0].y == yem.y)
	{
		number++;
		yem.x = dagilim(motor)*15;
		yem.y = dagilim(motor)*15;
	}

	sayac++;
}
