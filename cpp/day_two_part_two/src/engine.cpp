#include "engine.hpp"
#include <optional>

Move ToMove(Game game) {
  switch (game) {

  case Game::rock:
    return Move(1, Game::scissor, Game::paper);
  case Game::paper:
    return Move(2, Game::rock, Game::scissor);
  case Game::scissor:
    return Move(3, Game::paper, Game::rock);
  }
  throw "Something unexpected happened while casting char to Move";
}

Engine::Engine(char elfGame, char player) {
  this->elfGame = static_cast<Game>(elfGame);
  this->playerStrategy = static_cast<PlayerStrategy>(player);
}

Score Engine::match() {
  auto elfGame = ToMove(this->elfGame);

  std::optional<Game> playerGame;
  std::optional<BaseScore> baseScore;

  switch (this->playerStrategy) {
  case PlayerStrategy::lose:
    playerGame = elfGame.getDefeat();
    baseScore = BaseScore::lose;
    break;

  case PlayerStrategy::draw:
    playerGame = this->elfGame;
    baseScore = BaseScore::draw;
    break;
  case PlayerStrategy::win:
    playerGame = elfGame.getDefeated();
    baseScore = BaseScore::win;
    break;
  }

  if (!playerGame || !baseScore)
    throw "Something unexpected happened while casting player strategy";

  auto playerMove = ToMove(playerGame.value());

  return playerMove + baseScore.value();
}
