#include <sstream>
#include <queue>
#include <string>
#include <cctype>
#include "util.hpp"

#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level
{
public:
	static int level_order;
	std::queue<std::string> lv;

	Level();  // constructor
	~Level(); // destructor

	void newLevel();
	void spawnEnemyPer(const int &);

	// utils
	std::string processStr(const std::string &); // a member function
};

extern Level *level;
extern std::queue<std::queue<std::string>> lvs;

#endif // LEVEL_HPP