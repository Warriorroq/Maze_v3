#pragma once
#include "Scene.h";
#include "Game.h"
Scene::Scene(string name, bool *endGame) {
	p_Objects = new list<GameObject>();
	this->p_Name = &name;
	this->p_EndGame = endGame;
}
Scene::~Scene() {
	
}
void Scene::Draw() {

}
void Scene::Update() {

}