// Assignment 4
// Zinadine M.

#include <iostream>
#include <vector>
#include <string>
#include "TextureManager.h"
#include "Texture.h"
#include "Entity.h"
#include <Global.h>
int main()
{
	std::vector<a4::Entity> myEntities;
	a4::Entity p1;
	p1.initialize("player_texture_1");
	a4::Entity p2;
	p2.initialize("player_texture_2");

	myEntities.push_back(p1);
	myEntities.push_back(p2);


	for (int i = 0; i < 20; i++)
	{
		a4::Entity enemy;
		enemy.initialize("enemy_texture");
		myEntities.push_back(enemy);
	}

	for (a4::Entity e : myEntities)
	{
		e.update();
	}

	Global::BubbleSort(myEntities, [](const a4::Entity& a, a4::Entity& b) {
		return a.getPosition().Magnitude() < b.getPosition().Magnitude();
		});

	for (a4::Entity e : myEntities)
	{
		e.render();
	}

	for (a4::Entity e : myEntities)
	{
		e.update();
	}

	Global::BubbleSort(myEntities, [](const a4::Entity& a, a4::Entity& b) {
		return a.getPosition().Magnitude() < b.getPosition().Magnitude();
		});

	for (a4::Entity e : myEntities)
	{
		e.render();
	}

	for (a4::Entity e : myEntities)
	{
		e.update();
	}

	Global::BubbleSort(myEntities, [](const a4::Entity& a, a4::Entity& b) {
		return a.getPosition().Magnitude() < b.getPosition().Magnitude();
		});

	for (a4::Entity e : myEntities)
	{
		e.render();
	}

	for (a4::Entity e : myEntities)
	{
		e.update();
	}

	Global::BubbleSort(myEntities, [](const a4::Entity& a, a4::Entity& b) {
		return a.getPosition().Magnitude() < b.getPosition().Magnitude();
		});

	for (a4::Entity e : myEntities)
	{
		e.render();
	}
}