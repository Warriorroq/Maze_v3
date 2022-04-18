#pragma once
#include "GameObject.h";
#include <string>
using namespace std;
void GameObject::Draw() {};
void GameObject::Update() {};
string* GameObject::ToString() {
	return new string("Game Object");
};