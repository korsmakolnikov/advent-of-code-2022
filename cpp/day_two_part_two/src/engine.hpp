#include <optional>
using Score = int;

enum class BaseScore { win = 6, lose = 0, draw = 3 };
enum class Game { rock = 'A', paper = 'B', scissor = 'C' };
enum class PlayerStrategy : char { lose = 'X', draw = 'Y', win = 'Z' };

class Move {

protected:
  const Score score;
  const Game defeated;
  const Game defeat;

public:
  explicit Move(Score score, Game defeat, Game defeated)
      : score(score), defeat(defeat), defeated(defeated) {}
  Game getDefeat() { return this->defeat; }
  Game getDefeated() { return this->defeated; }
  Score operator+(BaseScore &a) { return this->score + (int)a; }
};

class Engine {
  Game elfGame;
  PlayerStrategy playerStrategy;

public:
  Engine(char elf, char player);
  Score match();
};
