
// Generated from MQL_Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  MQL_Lexer : public antlr4::Lexer {
public:
  enum {
    K_ACYCLIC = 1, K_AND = 2, K_ANGULAR = 3, K_ANY = 4, K_AVG = 5, K_ALL = 6, 
    K_ASC = 7, K_BRUTE_SIMILARITY_SEARCH = 8, K_BY = 9, K_BOOL = 10, K_COUNT = 11, 
    K_DELETE = 12, K_DESCRIBE = 13, K_DESC = 14, K_DISTINCT = 15, K_EDGE = 16, 
    K_EUCLIDEAN = 17, K_INCOMING = 18, K_INSERT = 19, K_INTEGER = 20, K_IS = 21, 
    K_FALSE = 22, K_FLOAT = 23, K_GROUP = 24, K_LABELS = 25, K_LABEL = 26, 
    K_LIMIT = 27, K_MANHATTAN = 28, K_MATCH = 29, K_MAX = 30, K_MIN = 31, 
    K_OFFSET = 32, K_OPTIONAL = 33, K_ORDER = 34, K_OR = 35, K_OUTGOING = 36, 
    K_PROJECT_SIMILARITY = 37, K_PROPERTIES = 38, K_PROPERTY = 39, K_NOT = 40, 
    K_NULL = 41, K_SHORTEST = 42, K_SIMPLE = 43, K_REGEX = 44, K_RETURN = 45, 
    K_SET = 46, K_SIMILARITY_SEARCH = 47, K_SUM = 48, K_STRING = 49, K_TRUE = 50, 
    K_TRAILS = 51, K_WALKS = 52, K_WHERE = 53, DATA_TEST = 54, TRUE_PROP = 55, 
    FALSE_PROP = 56, ANON_ID = 57, EDGE_ID = 58, KEY = 59, TYPE = 60, TYPE_VAR = 61, 
    VARIABLE = 62, STRING = 63, UNSIGNED_INTEGER = 64, UNSIGNED_FLOAT = 65, 
    UNSIGNED_SCIENTIFIC_NOTATION = 66, NAME = 67, LEQ = 68, GEQ = 69, EQ = 70, 
    NEQ = 71, LT = 72, GT = 73, SINGLE_EQ = 74, PATH_SEQUENCE = 75, PATH_ALTERNATIVE = 76, 
    PATH_NEGATION = 77, STAR = 78, PERCENT = 79, QUESTION_MARK = 80, PLUS = 81, 
    MINUS = 82, L_PAR = 83, R_PAR = 84, LCURLY_BRACKET = 85, RCURLY_BRACKET = 86, 
    LSQUARE_BRACKET = 87, RSQUARE_BRACKET = 88, COMMA = 89, COLON = 90, 
    WHITE_SPACE = 91, SINGLE_LINE_COMMENT = 92, UNRECOGNIZED = 93
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

