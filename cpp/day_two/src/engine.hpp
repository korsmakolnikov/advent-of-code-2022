using Score = int;

enum class EndGame { player = 6, elf = 0, draw = 3 };
enum class ElfGame : char { rock = 'A', paper = 'B', scissor = 'C' };
enum class PlayerGame : char { rock = 'X', paper = 'Y', scissor = 'Z' };

class Engine {
  static EndGame winner(ElfGame elf, PlayerGame player);

public:
  static Score match(char elf, char player);
};
