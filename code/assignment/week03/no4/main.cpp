#include "Headquarter.cpp"
#include "Warrior.cpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

const string HEADQUARTER_RED = "red";
const string HEADQUARTER_BLUE = "blue";

const string WARRIOR_NAME_DRAGON = "dragon";
const string WARRIOR_NAME_NINJA = "ninja";
const string WARRIOR_NAME_ICEMAN = "iceman";
const string WARRIOR_NAME_LION = "lion";
const string WARRIOR_NAME_WOLF = "wolf";

const string INPUT_ORDER[] = { WARRIOR_NAME_DRAGON, WARRIOR_NAME_NINJA,
		WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION, WARRIOR_NAME_WOLF };
const string RED_ORDER[] = { WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION,
		WARRIOR_NAME_WOLF, WARRIOR_NAME_NINJA, WARRIOR_NAME_DRAGON };
const string BLUE_ORDER[] = { WARRIOR_NAME_LION, WARRIOR_NAME_DRAGON,
		WARRIOR_NAME_NINJA, WARRIOR_NAME_ICEMAN, WARRIOR_NAME_WOLF };

int main() {
	int rounds; // 轮数
	std::cin >> rounds;

	int totalStrength[rounds] = { 0 };       // 每轮各司令部的总生命值
	int allStrengthArray[rounds][5] = { 0 }; // 每轮各种武士的生命值

	for (int i = 0; i < rounds; i++) {
		cin >> totalStrength[i];
		for (int j = 0; j < 5; j++) {
			cin >> allStrengthArray[i][j];
		}
	}

	for (int i = 0; i < rounds; i++) {
		map<string, int> warriorStrengthMap;
		for (int j = 0; j < 5; j++) {
			warriorStrengthMap.insert(
					pair<string, int>(INPUT_ORDER[j], allStrengthArray[i][j]));
		}

		// TODO

		cout << "Case: " << (i + 1) << endl;
	}

	return 0;
}
