#include "../../include/Instrucciones/InstructionHALT.h"
#include "../../include/RAMachine.h"

InstructionHALT::InstructionHALT(int line, std::string tag, std::string operation) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
}

void InstructionHALT::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ">\n";
}

int InstructionHALT::execute(RAMachine& ram) {
  ram.halt();
  return ram.getPc();
}