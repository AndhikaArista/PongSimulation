class Player {
private:
	enum Players { playerX, playerY } player;
	float Hits;
public:
	Player(int i);

	Player(Player& i);

	void SetHits(float t);

	float GetHits();

	Players GetPlayers()
	{
		return player;
	}
};

Player::Player(int i)
{
	if (i == 0)
	{
		player = Players::playerX;
	}
	else
	{
		player = Players::playerY;
	}
	Hits = 0;
}

Player::Player(Player& i)
{
	if (i.player == Players::playerX)
	{
		player = Players::playerY;
	}
	else
	{
		player = Players::playerX;
	}
	Hits = i.Hits;
}

void Player::SetHits(float t)
{
	Hits = t;
}

float Player::GetHits()
{
	return Hits;
}