#include "engine.hpp"
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

class PlayerScore {
  int score = 0;

public:
  PlayerScore(char game) {
    switch (static_cast<PlayerGame>(game)) {
    case PlayerGame::rock:
      score = ROCK;
      break;
    case PlayerGame::paper:
      score = PAPER;
      break;
    case PlayerGame::scissor:
      score = SCISSOR;
      break;
    }
  }

  operator int() const { return score; }
};

enum class Game { rock, paper, scissor };

template <typename T> Game ToGame(T game);
Game ToGame(PlayerGame game) {
  switch (game) {

  case PlayerGame::rock:
    return Game::rock;
  case PlayerGame::paper:
    return Game::paper;
  case PlayerGame::scissor:
    return Game::scissor;
  }

  throw "Cannot convert to Game";
}
Game ToGame(ElfGame game) {
  switch (game) {

  case ElfGame::rock:
    return Game::rock;
  case ElfGame::paper:
    return Game::paper;
  case ElfGame::scissor:
    return Game::scissor;
  }

  throw "Cannot convert to Game";
}

class Manche {
  Game game;

public:
  friend std::ostream &operator<<(std::ostream &sout, Manche manche) {
    switch (manche.game) {
    case Game::rock:
      sout << "rock";
      break;
    case Game::paper:
      sout << "paper";
      break;
    case Game::scissor:
      sout << "scissor";
      break;
    }

    return sout;
  }

  Manche(const Game game) { this->game = game; }

  EndGame isBitten(Manche *oppositor) {
    if (this->game == oppositor->game) {
      return EndGame::draw;
    }

    if ((this->game == Game::rock && oppositor->game == Game::paper) ||
        (this->game == Game::paper && oppositor->game == Game::scissor) ||
        (this->game == Game::scissor && oppositor->game == Game::rock)) {
      return EndGame::elf;
    }

    return EndGame::player;
  }
};

EndGame Engine::winner(ElfGame elf, PlayerGame player) {
  std::tuple<ElfGame, PlayerGame> rock_beaten = {ElfGame::rock,
                                                 PlayerGame::paper};
  Manche elfManche = Manche(ToGame(elf));
  Manche playerManche = Manche(ToGame(player));

  return playerManche.isBitten(&elfManche);
}

Score Engine::match(char elf, char player) {
  ElfGame e = static_cast<ElfGame>(elf);
  PlayerGame p = static_cast<PlayerGame>(player);
  // implement operators and remove the cast to int
  int winnerScore = (int)Engine::winner(e, p);

  PlayerScore playerScore = PlayerScore(player);

  return playerScore + winnerScore;
}
