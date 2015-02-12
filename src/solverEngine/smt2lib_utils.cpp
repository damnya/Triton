
#include "smt2lib_utils.h"



/* Returns the 'bv' syntax based on a value and a size.
 * Mainly used for the SMT translation */
std::string smt2lib::bv(uint64_t value, uint64_t size)
{
  std::stringstream stream;

  switch(size){
    case 1:
      stream << "(_ bv" << std::dec << value << " 8)";
      break;
    case 2:
      stream << "(_ bv" << std::dec << value << " 16)";
      break;
    case 4:
      stream << "(_ bv" << std::dec << value << " 32)";
      break;
    case 8:
      stream << "(_ bv" << std::dec << value << " 64)";
      break;
  }

  return stream.str();
}


/* Returns the 'extract' syntax based on a value and a size.
 * Mainly used for the SMT translation */
std::string smt2lib::extract(uint64_t regSize)
{
  std::stringstream stream;

  switch(regSize){
    case 1:
      stream << "(_ extract 7 0)";
      break;
    case 2:
      stream << "(_ extract 15 0)";
      break;
    case 4:
      stream << "(_ extract 31 0)";
      break;
    case 8:
      stream << "(_ extract 63 0)";
      break;
  }

  return stream.str();
}


/* Returns the 'declare' syntax based on a value and a size.
 * Mainly used for the SMT translation */
std::string smt2lib::declare(uint64_t idSymVar, uint64_t BitVecSize)
{
  std::stringstream stream;

  switch(BitVecSize){
    case 1:
      stream << "(declare-fun SymVar_" << idSymVar << " () (_ BitVec 8))";
      break;
    case 2:
      stream << "(declare-fun SymVar_" << idSymVar << " () (_ BitVec 16))";
      break;
    case 4:
      stream << "(declare-fun SymVar_" << idSymVar << " () (_ BitVec 32))";
      break;
    case 8:
      stream << "(declare-fun SymVar_" << idSymVar << " () (_ BitVec 64))";
      break;
  }

  return stream.str();
}

