
// Generated from MQL_Lexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MQL_Lexer : public antlr4::Lexer {
public:
  enum {
    K_ACYCLIC = 1, K_AND = 2, K_ANGULAR = 3, K_ANY = 4, K_AVG = 5, K_ALL = 6, 
    K_ASC = 7, K_BY = 8, K_BOOL = 9, K_COUNT = 10, K_DESCRIBE = 11, K_DESC = 12, 
    K_DISTINCT = 13, K_EDGE = 14, K_EUCLIDEAN = 15, K_INCOMING = 16, K_INSERT = 17, 
    K_INTEGER = 18, K_IS = 19, K_FALSE = 20, K_FLOAT = 21, K_GROUP = 22, 
    K_LABELS = 23, K_LABEL = 24, K_LIMIT = 25, K_MANHATTAN = 26, K_MATCH = 27, 
    K_MAX = 28, K_MIN = 29, K_OPTIONAL = 30, K_ORDER = 31, K_OR = 32, K_OUTGOING = 33, 
    K_PROJECT_SIMILARITY = 34, K_PROPERTIES = 35, K_PROPERTY = 36, K_NOT = 37, 
    K_NULL = 38, K_SHORTEST = 39, K_SIMPLE = 40, K_RETURN = 41, K_SET = 42, 
    K_SIMILARITY_SEARCH = 43, K_SUM = 44, K_STRING = 45, K_TRUE = 46, K_TRAILS = 47, 
    K_WALKS = 48, K_WHERE = 49, TRUE_PROP = 50, FALSE_PROP = 51, ANON_ID = 52, 
    EDGE_ID = 53, KEY = 54, TYPE = 55, TYPE_VAR = 56, VARIABLE = 57, STRING = 58, 
    UNSIGNED_INTEGER = 59, UNSIGNED_FLOAT = 60, UNSIGNED_SCIENTIFIC_NOTATION = 61, 
    NAME = 62, LEQ = 63, GEQ = 64, EQ = 65, NEQ = 66, LT = 67, GT = 68, 
    SINGLE_EQ = 69, PATH_SEQUENCE = 70, PATH_ALTERNATIVE = 71, PATH_NEGATION = 72, 
    STAR = 73, PERCENT = 74, QUESTION_MARK = 75, PLUS = 76, MINUS = 77, 
    L_PAR = 78, R_PAR = 79, LCURLY_BRACKET = 80, RCURLY_BRACKET = 81, LSQUARE_BRACKET = 82, 
    RSQUARE_BRACKET = 83, COMMA = 84, COLON = 85, WHITE_SPACE = 86, SINGLE_LINE_COMMENT = 87, 
    UNRECOGNIZED = 88
  };

  enum {
    WS_CHANNEL = 2
  };

  explicit MQL_Lexer(antlr4::CharStream *input);

  ~MQL_Lexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

