#include "../../include/Instrucciones/InstructionLOAD.h"
#include "../../include/RAMachine.h"

InstructionLOAD::InstructionLOAD(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionLOAD::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

int InstructionLOAD::execute(RAMachine& ram) {
  int value;
  int position;
  switch(opType_) {
    case 'd':
      value = ram.readMemory(operand_);
      ram.writeMemory(0, value);
      break;
    case '*':
      position = ram.readMemory(operand_);
      value = ram.readMemory(position);
      ram.writeMemory(0, value);
      break;
    case '=':
      value = operand_;
      ram.writeMemory(0, value);
      break;
      
  }
  return ram.getPc() + 1;
}
