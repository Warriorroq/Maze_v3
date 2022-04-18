#pragma once
#include "Scene.h";
Scene::Scene(string name) {
	objects = new list<GameObject>();
	this->name = &name;
}
Scene::~Scene() {
	
}
void Scene::Draw() {

}
void Scene::Update() {

}