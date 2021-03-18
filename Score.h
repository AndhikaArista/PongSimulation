class Score {
private:
	int PlayerXScore;
	int PlayerYScore;
public:
	Score(int x, int y);

	int XScore();

	int YScore();

	void SetScore(int x, int y);

	void AddScoreX();

	void AddScoreY();
};

Score::Score(int x, int y)
{
	PlayerXScore = x;
	PlayerYScore = y;
}

int Score::XScore()
{
	return PlayerXScore;
}

int Score::YScore()
{
	return PlayerYScore;
}

void Score::SetScore(int x, int y)
{
	PlayerXScore = x;
	PlayerYScore = y;
}

void Score::AddScoreX()
{
	PlayerXScore++;
}

void Score::AddScoreY()
{
	PlayerYScore++;
}