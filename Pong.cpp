#include "Score.h" 
#include "Player.h" 
#include <iostream> 
#include <thread> 
#include <stdlib.h> 
#include <time.h> 
#include <random> 
#include <mutex> 
 
using namespace std;

Score score(0, 0);

mutex m;

void RandomPlayerHits(Player* player, bool* isOver) 
{
	m.lock();
	int* i = new int;
	srand((int)i);
	delete i;
	player->SetHits(rand() % 101);
	m.unlock();
	//tampilan
	cout << "Hits : " << player->GetHits();
	if (player->GetPlayers() == 0) {
		cout << " Player X ";
	}
	else {
		cout << " Player Y ";
	}

	if (player->GetHits() <= 50) 
	{
		if (player->GetPlayers() == 0) 
		{
			score.AddScoreY();
		}
		else 
		{
			score.AddScoreX();
		}
		cout << "Miss" << endl;

		*isOver = true;
	}
	else 
	{
		cout << "Hit" << endl;
	}

	this_thread::sleep_for(chrono::seconds(1));
}

void randomFirstTurn(int* player) {
	int* i = new int;
	srand((int)i);
	delete i;
	*player = rand() % 2;
}

int main()
{
	srand(time(0));

	Player playerX(0);

	Player playerY = playerX;

	int RoundStart = 1;
	while (score.XScore() < 10 && score.YScore() < 10)
	{
		int RandomStart;
		thread RandomFirst(randomFirstTurn, &RandomStart);
		RandomFirst.join();
		bool roundIsOver = false;

		cout << "---Round " << RoundStart << "---" << endl;
		while (roundIsOver == false) {
			if (RandomStart == 0) 
			{ 
				cout << "Player X Take First" << endl;

				thread playerXThread(RandomPlayerHits, &playerX, &roundIsOver);
				playerXThread.join();

				if (roundIsOver == true) {
					RoundStart++;
					break;
				}

				thread playerYThread(RandomPlayerHits, &playerY, &roundIsOver);
				playerYThread.join();

				if (roundIsOver == true) {
					RoundStart++;
					break;
				}
			}
			else if (RandomStart == 1)
			{ 
				cout << "Player Y Take First" << endl;

				thread playerYThread(RandomPlayerHits, &playerY, &roundIsOver);
				playerYThread.join();

				if (roundIsOver == true) 
				{
					RoundStart++;
					break;
				}

				thread playerXThread(RandomPlayerHits, &playerX, &roundIsOver);
				playerXThread.join();

				if (roundIsOver == true) {
					RoundStart++;
					break;
				}
			}
		}
	}

	cout << "\nFinal Result" << endl;
	if (score.XScore() >= 10) {
		cout << "Player X WIN with Score :  " << score.XScore() << "-" << score.YScore() << endl;
	}
	else {
		cout << "Player Y WIN with Score :  " << score.YScore() << "-" << score.XScore() << endl;
	}

	return 0;
}