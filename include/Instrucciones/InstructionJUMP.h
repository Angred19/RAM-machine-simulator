#include "../Instruction.h"

class InstructionJUMP: public Instruction {
  private:
    std::string operand_;
  public:
    InstructionJUMP(int line, std::string tag, std::string operation, std::string operand);

    void show();
};