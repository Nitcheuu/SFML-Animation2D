#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
/// <summary>
/// Classe animation 2D
/// </summary>
class Animation2D
{
#pragma region Attributs
private:
	/// <summary>
	/// Chemin d'accès au fichier
	/// </summary>
	std::string chemin;
	/// <summary>
	/// Texture
	/// </summary>
	sf::Texture texture;
	/// <summary>
	/// "Cadre" qui ne sélectionne qu'une partie du
	/// sprite sheet
	/// </summary>
	sf::IntRect rectangle;
	/// <summary>
	/// L'image courante
	/// </summary>
	sf::Sprite sprite;
	/// <summary>
	/// Horloge
	/// </summary>
	sf::Clock clock;
	/// <summary>
	/// Hauteur d'une frame
	/// </summary>
	int hauteur;
	/// <summary>
	/// Largeur d'une frame
	/// </summary>
	int largeur;
	/// <summary>
	/// Nombre de frames
	/// </summary>
	int frames;
	/// <summary>
	/// Delai entre chaque frame
	/// </summary>
	float delai;
	/// <summary>
	/// Position en x de l'animation
	/// </summary>
	float pos_x;
	/// <summary>
	/// Position en y de l'animation
	/// </summary>
	float pos_y;
#pragma endregion
#pragma region Constructeurs
public:
	/// <summary>
	/// Constructeur avec le délai par défaut
	/// </summary>
	Animation2D(std::string c, int h, int l, int f) {
		chemin = c;
		hauteur = h;
		largeur = l;
		frames = f;
		delai = 1;
		texture.loadFromFile(chemin);
		rectangle = sf::IntRect(0, 0, largeur, hauteur);
		sprite = sf::Sprite(texture, rectangle);
		pos_y = 0;
		pos_x = 0;
	}
	/// <summary>
	/// Constructeur avec le choix du délai
	/// </summary>
	Animation2D(std::string c, int h, int l, int f, float d) {
		chemin = c;
		hauteur = h;
		largeur = l;
		frames = f;
		delai = d;
		texture.loadFromFile(chemin);
		rectangle = sf::IntRect(0, 0, largeur, hauteur);
		sprite = sf::Sprite(texture, rectangle);
		pos_y = 0;
		pos_x = 0;
	}
#pragma endregion
#pragma region Méthodes
	/// <summary>
	/// Retourne le sprite courant
	/// </summary>
	sf::Sprite Me() {
		return sprite;
	}
	/// <summary>
	/// Met à jour la position de l'animation + l'animation
	/// </summary>
	void Update() {
		sprite.setPosition(pos_x, pos_y);
		if (clock.getElapsedTime().asSeconds() > delai) {
			if (rectangle.left == largeur * frames - largeur) {
				rectangle.left -= largeur * frames - largeur;
			}
			else {
				rectangle.left += largeur;
			}
			std::cout << rectangle.left;
			sprite.setTextureRect(rectangle);
			clock.restart();
		}
	}
	/// <summary>
	/// Permet d'aggrandir ou de rétrécir l'animation
	/// </summary>
	void setZoom(int zoom) {
		if (zoom > 0) {
			sprite.setScale(sf::Vector2f(zoom, zoom));
		}
		else {
			std::cout << "Impossible de zoomer : valeur nulle ou négative" << std::endl;
		}
	}
	/// <summary>
	/// Change la position de l'animation
	/// </summary>
	void setPosition(float x, float y) {
		pos_x = x;
		pos_y = y;
	}
	/// <summary>
	/// Change le délai entre chaque frame
	/// </summary>
	void setDelai(float d) {
		delai = d;
	}
#pragma endregion 
};

