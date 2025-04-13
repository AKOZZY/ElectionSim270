#pragma once
#include "raylib.h"
#include "iostream"

class Button
{
public:
	Button(std::string text, int fontSize, int width, int height, Vector2 position);
	~Button();
	void DrawTexture();
	void Draw();
	void MouseHover(Vector2 mousePosition);
	bool isMouseOverButton{};
private:
	std::string text{};
	int fontSize{};
	int width{};
	int height{};
	Vector2 position{};
	Color color{ WHITE };
	Color selectedColor{ BLACK };
	Texture2D buttonSprite{};
};