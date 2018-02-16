#ifndef GAME_H
#define GAME_H

#define SCORE_LIMIT 10

#include <map>
#include <string>
#include <vector>

using namespace std;

struct xyCoords {
	float x;
	float y;
};

struct player {
	string name;
	float position;
	int score;
};

class game {
public:
	bool running;
	map<int, player> players;
	xyCoords ballPos;
	int ballDirection;
	int lastPlayerHit;
	int maxScore;
	
	game() {
		running = false;
		players = map<int, player>();
		ballPos.x = 250;
		ballPos.y = 250;
		ballDirection = rand() % 360;
		maxScore = SCORE_LIMIT;
	}

	void addPlayer(int id, string _name);
	void removePlayer(int id);
	int getNumOfPlayers();
	void updateBall();
	void resetBall();
	void changeScore(int index, int toAdd);
	void startGame();
	void stopGame();

private:
	xyCoords lastBallPos;

	void flipBallVertical();
	void flipBallHorizontal();
};

#endif