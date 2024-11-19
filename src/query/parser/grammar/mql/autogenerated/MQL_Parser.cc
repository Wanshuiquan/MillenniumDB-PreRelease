
// Generated from MQL_Parser.g4 by ANTLR 4.13.2


#include "MQL_ParserVisitor.h"

#include "MQL_Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MQL_ParserStaticData final {
  MQL_ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MQL_ParserStaticData(const MQL_ParserStaticData&) = delete;
  MQL_ParserStaticData(MQL_ParserStaticData&&) = delete;
  MQL_ParserStaticData& operator=(const MQL_ParserStaticData&) = delete;
  MQL_ParserStaticData& operator=(MQL_ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mql_parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MQL_ParserStaticData> mql_parserParserStaticData = nullptr;

void mql_parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mql_parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(mql_parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MQL_ParserStaticData>(
    std::vector<std::string>{
      "root", "matchQuery", "insertPatterns", "insertLinearPattern", "insertPlainNode", 
      "insertPlainNodeInside", "insertPlainEdge", "projectSimilarity", "metricType", 
      "describeQuery", "describeFlag", "setStatement", "matchStatement", 
      "whereStatement", "groupByStatement", "orderByStatement", "returnStatement", 
      "limitOffsetClauses", "limitClause", "offsetClause", "setItem", "returnItem", 
      "aggregateFunc", "orderByItem", "groupByItem", "graphPattern", "optionalPattern", 
      "similaritySearch", "bruteSimilaritySearch", "tensor", "basicPattern", 
      "linearPattern", "path", "pathAlternatives", "pathSequence", "pathAtom", 
      "smtFormula", "smtCompare", "addExpr", "mulExpr", "smtAtomicExpr", 
      "object", "pathSuffix", "pathType", "node", "fixedNode", "fixedNodeInside", 
      "edge", "edgeInside", "varNode", "properties", "property", "conditionalOrType", 
      "identifier", "boolValue", "numericValue", "datatypeValue", "value", 
      "conditionalOrExpr", "conditionalAndExpr", "comparisonExpr", "additiveExpr", 
      "multiplicativeExpr", "unaryExpr", "atomicExpr", "function", "regex", 
      "exprTypename", "keyword"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "'false'", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "'true'", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "'<='", "'>='", "'=='", "'!='", "'<'", "'>'", "'='", 
      "'/'", "'|'", "'^'", "'*'", "'%'", "'\\u003F'", "'+'", "'-'", "'('", 
      "')'", "'{'", "'}'", "'['", "']'", "','", "':'"
    },
    std::vector<std::string>{
      "", "K_ACYCLIC", "K_AND", "K_ANGULAR", "K_ANY", "K_AVG", "K_ALL", 
      "K_ASC", "K_BRUTE_SIMILARITY_SEARCH", "K_BY", "K_BOOL", "K_COUNT", 
      "K_DELETE", "K_DESCRIBE", "K_DESC", "K_DISTINCT", "K_EDGE", "K_EUCLIDEAN", 
      "K_INCOMING", "K_INSERT", "K_INTEGER", "K_IS", "K_FALSE", "K_FLOAT", 
      "K_GROUP", "K_LABELS", "K_LABEL", "K_LIMIT", "K_MANHATTAN", "K_MATCH", 
      "K_MAX", "K_MIN", "K_OFFSET", "K_OPTIONAL", "K_ORDER", "K_OR", "K_OUTGOING", 
      "K_PROJECT_SIMILARITY", "K_PROPERTIES", "K_PROPERTY", "K_NOT", "K_NULL", 
      "K_SHORTEST", "K_SIMPLE", "K_REGEX", "K_RETURN", "K_SET", "K_SIMILARITY_SEARCH", 
      "K_SUM", "K_STRING", "K_TRUE", "K_TRAILS", "K_WALKS", "K_WHERE", "DATA_TEST", 
      "TRUE_PROP", "FALSE_PROP", "ANON_ID", "EDGE_ID", "KEY", "TYPE", "TYPE_VAR", 
      "VARIABLE", "STRING", "UNSIGNED_INTEGER", "UNSIGNED_FLOAT", "UNSIGNED_SCIENTIFIC_NOTATION", 
      "NAME", "LEQ", "GEQ", "EQ", "NEQ", "LT", "GT", "SINGLE_EQ", "PATH_SEQUENCE", 
      "PATH_ALTERNATIVE", "PATH_NEGATION", "STAR", "PERCENT", "QUESTION_MARK", 
      "PLUS", "MINUS", "L_PAR", "R_PAR", "LCURLY_BRACKET", "RCURLY_BRACKET", 
      "LSQUARE_BRACKET", "RSQUARE_BRACKET", "COMMA", "COLON", "WHITE_SPACE", 
      "SINGLE_LINE_COMMENT", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,93,834,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,1,0,3,0,140,8,0,
  	1,0,1,0,3,0,144,8,0,1,0,3,0,147,8,0,1,0,1,0,1,1,1,1,1,1,3,1,154,8,1,1,
  	1,3,1,157,8,1,1,1,3,1,160,8,1,1,1,3,1,163,8,1,1,1,1,1,1,2,1,2,1,2,1,2,
  	5,2,171,8,2,10,2,12,2,174,9,2,1,3,1,3,1,3,1,3,5,3,180,8,3,10,3,12,3,183,
  	9,3,1,4,1,4,3,4,187,8,4,1,4,5,4,190,8,4,10,4,12,4,193,9,4,1,4,3,4,196,
  	8,4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,3,6,207,8,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,3,6,215,8,6,1,6,1,6,1,6,3,6,220,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,3,7,232,8,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,5,9,242,8,9,10,
  	9,12,9,245,9,9,1,9,1,9,1,10,1,10,1,10,3,10,252,8,10,1,11,1,11,1,11,1,
  	11,5,11,258,8,11,10,11,12,11,261,9,11,1,12,1,12,1,12,1,13,1,13,1,13,1,
  	14,1,14,1,14,1,14,1,14,5,14,274,8,14,10,14,12,14,277,9,14,1,15,1,15,1,
  	15,1,15,1,15,5,15,284,8,15,10,15,12,15,287,9,15,1,16,1,16,3,16,291,8,
  	16,1,16,1,16,1,16,5,16,296,8,16,10,16,12,16,299,9,16,1,16,3,16,302,8,
  	16,1,16,1,16,3,16,306,8,16,1,16,1,16,3,16,310,8,16,3,16,312,8,16,1,17,
  	1,17,3,17,316,8,17,1,17,1,17,3,17,320,8,17,3,17,322,8,17,1,18,1,18,1,
  	18,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,3,21,336,8,21,1,21,1,
  	21,1,21,1,21,3,21,342,8,21,1,21,1,21,1,21,1,21,1,21,3,21,349,8,21,1,21,
  	1,21,3,21,353,8,21,1,21,3,21,356,8,21,1,21,3,21,359,8,21,1,22,1,22,1,
  	23,1,23,3,23,365,8,23,1,23,3,23,368,8,23,1,23,1,23,1,23,1,23,3,23,374,
  	8,23,1,23,1,23,3,23,378,8,23,1,23,1,23,1,23,3,23,383,8,23,1,23,1,23,3,
  	23,387,8,23,1,23,1,23,3,23,391,8,23,3,23,393,8,23,1,24,1,24,3,24,397,
  	8,24,1,25,1,25,5,25,401,8,25,10,25,12,25,404,9,25,1,26,1,26,1,26,1,26,
  	1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,421,8,27,
  	1,27,1,27,3,27,425,8,27,1,27,1,27,1,27,3,27,430,8,27,1,27,3,27,433,8,
  	27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,447,
  	8,28,1,28,1,28,1,28,1,28,3,28,453,8,28,1,28,1,28,1,28,1,29,1,29,1,29,
  	1,29,5,29,462,8,29,10,29,12,29,465,9,29,1,29,1,29,1,30,1,30,1,30,5,30,
  	472,8,30,10,30,12,30,475,9,30,1,31,1,31,1,31,3,31,480,8,31,1,31,1,31,
  	5,31,484,8,31,10,31,12,31,487,9,31,1,31,3,31,490,8,31,1,32,1,32,1,32,
  	3,32,495,8,32,1,32,3,32,498,8,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,3,
  	32,507,8,32,1,32,3,32,510,8,32,1,32,1,32,1,32,1,32,1,32,3,32,517,8,32,
  	1,33,1,33,1,33,5,33,522,8,33,10,33,12,33,525,9,33,1,34,1,34,1,34,5,34,
  	530,8,34,10,34,12,34,533,9,34,1,35,3,35,536,8,35,1,35,1,35,3,35,540,8,
  	35,1,35,3,35,543,8,35,1,35,1,35,1,35,1,35,3,35,549,8,35,1,35,3,35,552,
  	8,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,561,8,35,3,35,563,8,35,1,
  	36,1,36,1,36,5,36,568,8,36,10,36,12,36,571,9,36,1,37,1,37,1,37,3,37,576,
  	8,37,1,38,1,38,1,38,5,38,581,8,38,10,38,12,38,584,9,38,1,39,1,39,1,39,
  	5,39,589,8,39,10,39,12,39,592,9,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,
  	3,40,601,8,40,1,41,1,41,3,41,605,8,41,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,3,42,615,8,42,1,43,1,43,3,43,619,8,43,1,43,3,43,622,8,43,1,43,
  	3,43,625,8,43,1,44,1,44,3,44,629,8,44,1,45,1,45,1,45,1,45,1,46,1,46,1,
  	46,1,46,3,46,639,8,46,1,47,1,47,1,47,3,47,644,8,47,1,47,1,47,1,47,1,47,
  	1,47,3,47,651,8,47,1,47,3,47,654,8,47,1,48,1,48,3,48,658,8,48,1,48,3,
  	48,661,8,48,1,48,3,48,664,8,48,1,48,1,48,1,49,1,49,3,49,670,8,49,1,49,
  	5,49,673,8,49,10,49,12,49,676,9,49,1,49,3,49,679,8,49,1,49,1,49,1,50,
  	1,50,1,50,1,50,5,50,687,8,50,10,50,12,50,690,9,50,1,50,1,50,1,51,1,51,
  	1,51,1,51,1,51,3,51,699,8,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,
  	1,51,3,51,710,8,51,1,51,1,51,5,51,714,8,51,10,51,12,51,717,9,51,1,51,
  	1,51,1,51,1,51,3,51,723,8,51,1,52,1,52,1,52,1,53,1,53,3,53,730,8,53,1,
  	54,1,54,1,55,3,55,735,8,55,1,55,1,55,1,56,1,56,1,56,1,56,1,56,1,57,1,
  	57,1,57,1,57,3,57,748,8,57,1,58,1,58,1,58,5,58,753,8,58,10,58,12,58,756,
  	9,58,1,59,1,59,1,59,5,59,761,8,59,10,59,12,59,764,9,59,1,60,1,60,1,60,
  	3,60,769,8,60,1,60,1,60,1,60,3,60,774,8,60,1,60,1,60,3,60,778,8,60,1,
  	61,1,61,1,61,5,61,783,8,61,10,61,12,61,786,9,61,1,62,1,62,1,62,5,62,791,
  	8,62,10,62,12,62,794,9,62,1,63,1,63,1,63,1,63,1,63,1,63,1,63,3,63,803,
  	8,63,1,64,1,64,3,64,807,8,64,1,64,1,64,1,64,1,64,1,64,1,64,3,64,815,8,
  	64,1,65,1,65,1,66,1,66,1,66,1,66,1,66,1,66,1,66,3,66,826,8,66,1,66,1,
  	66,1,67,1,67,1,68,1,68,1,68,0,0,69,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,
  	72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,
  	114,116,118,120,122,124,126,128,130,132,134,136,0,15,3,0,3,3,17,17,28,
  	28,4,0,18,18,25,25,36,36,38,38,3,0,5,5,30,31,48,48,2,0,7,7,14,14,1,0,
  	81,82,1,0,68,73,2,0,4,4,6,6,3,0,1,1,43,43,51,52,2,0,58,58,62,62,1,0,60,
  	61,2,0,22,22,50,50,1,0,64,66,2,0,75,75,78,79,5,0,10,10,20,20,23,23,41,
  	41,49,49,6,0,1,7,9,21,23,36,38,43,45,49,51,54,894,0,146,1,0,0,0,2,150,
  	1,0,0,0,4,166,1,0,0,0,6,175,1,0,0,0,8,184,1,0,0,0,10,199,1,0,0,0,12,219,
  	1,0,0,0,14,221,1,0,0,0,16,237,1,0,0,0,18,239,1,0,0,0,20,248,1,0,0,0,22,
  	253,1,0,0,0,24,262,1,0,0,0,26,265,1,0,0,0,28,268,1,0,0,0,30,278,1,0,0,
  	0,32,311,1,0,0,0,34,321,1,0,0,0,36,323,1,0,0,0,38,326,1,0,0,0,40,329,
  	1,0,0,0,42,358,1,0,0,0,44,360,1,0,0,0,46,392,1,0,0,0,48,394,1,0,0,0,50,
  	398,1,0,0,0,52,405,1,0,0,0,54,410,1,0,0,0,56,436,1,0,0,0,58,457,1,0,0,
  	0,60,468,1,0,0,0,62,489,1,0,0,0,64,516,1,0,0,0,66,518,1,0,0,0,68,526,
  	1,0,0,0,70,562,1,0,0,0,72,564,1,0,0,0,74,572,1,0,0,0,76,577,1,0,0,0,78,
  	585,1,0,0,0,80,600,1,0,0,0,82,604,1,0,0,0,84,614,1,0,0,0,86,624,1,0,0,
  	0,88,628,1,0,0,0,90,630,1,0,0,0,92,638,1,0,0,0,94,653,1,0,0,0,96,655,
  	1,0,0,0,98,667,1,0,0,0,100,682,1,0,0,0,102,722,1,0,0,0,104,724,1,0,0,
  	0,106,729,1,0,0,0,108,731,1,0,0,0,110,734,1,0,0,0,112,738,1,0,0,0,114,
  	747,1,0,0,0,116,749,1,0,0,0,118,757,1,0,0,0,120,777,1,0,0,0,122,779,1,
  	0,0,0,124,787,1,0,0,0,126,802,1,0,0,0,128,814,1,0,0,0,130,816,1,0,0,0,
  	132,818,1,0,0,0,134,829,1,0,0,0,136,831,1,0,0,0,138,140,3,22,11,0,139,
  	138,1,0,0,0,139,140,1,0,0,0,140,141,1,0,0,0,141,144,3,2,1,0,142,144,3,
  	18,9,0,143,139,1,0,0,0,143,142,1,0,0,0,144,147,1,0,0,0,145,147,3,4,2,
  	0,146,143,1,0,0,0,146,145,1,0,0,0,147,148,1,0,0,0,148,149,5,0,0,1,149,
  	1,1,0,0,0,150,153,3,24,12,0,151,154,3,14,7,0,152,154,3,56,28,0,153,151,
  	1,0,0,0,153,152,1,0,0,0,153,154,1,0,0,0,154,156,1,0,0,0,155,157,3,26,
  	13,0,156,155,1,0,0,0,156,157,1,0,0,0,157,159,1,0,0,0,158,160,3,28,14,
  	0,159,158,1,0,0,0,159,160,1,0,0,0,160,162,1,0,0,0,161,163,3,30,15,0,162,
  	161,1,0,0,0,162,163,1,0,0,0,163,164,1,0,0,0,164,165,3,32,16,0,165,3,1,
  	0,0,0,166,167,5,19,0,0,167,172,3,6,3,0,168,169,5,89,0,0,169,171,3,6,3,
  	0,170,168,1,0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,172,173,1,0,0,0,173,
  	5,1,0,0,0,174,172,1,0,0,0,175,181,3,8,4,0,176,177,3,12,6,0,177,178,3,
  	8,4,0,178,180,1,0,0,0,179,176,1,0,0,0,180,183,1,0,0,0,181,179,1,0,0,0,
  	181,182,1,0,0,0,182,7,1,0,0,0,183,181,1,0,0,0,184,186,5,83,0,0,185,187,
  	3,10,5,0,186,185,1,0,0,0,186,187,1,0,0,0,187,191,1,0,0,0,188,190,5,60,
  	0,0,189,188,1,0,0,0,190,193,1,0,0,0,191,189,1,0,0,0,191,192,1,0,0,0,192,
  	195,1,0,0,0,193,191,1,0,0,0,194,196,3,100,50,0,195,194,1,0,0,0,195,196,
  	1,0,0,0,196,197,1,0,0,0,197,198,5,84,0,0,198,9,1,0,0,0,199,200,3,106,
  	53,0,200,11,1,0,0,0,201,202,5,72,0,0,202,203,5,82,0,0,203,204,5,87,0,
  	0,204,206,5,60,0,0,205,207,3,100,50,0,206,205,1,0,0,0,206,207,1,0,0,0,
  	207,208,1,0,0,0,208,209,5,88,0,0,209,220,5,82,0,0,210,211,5,82,0,0,211,
  	212,5,87,0,0,212,214,5,60,0,0,213,215,3,100,50,0,214,213,1,0,0,0,214,
  	215,1,0,0,0,215,216,1,0,0,0,216,217,5,88,0,0,217,218,5,82,0,0,218,220,
  	5,73,0,0,219,201,1,0,0,0,219,210,1,0,0,0,220,13,1,0,0,0,221,222,5,37,
  	0,0,222,223,5,83,0,0,223,224,5,62,0,0,224,225,5,89,0,0,225,226,5,62,0,
  	0,226,227,5,89,0,0,227,228,5,63,0,0,228,231,5,89,0,0,229,232,3,92,46,
  	0,230,232,3,58,29,0,231,229,1,0,0,0,231,230,1,0,0,0,232,233,1,0,0,0,233,
  	234,5,89,0,0,234,235,3,16,8,0,235,236,5,84,0,0,236,15,1,0,0,0,237,238,
  	7,0,0,0,238,17,1,0,0,0,239,243,5,13,0,0,240,242,3,20,10,0,241,240,1,0,
  	0,0,242,245,1,0,0,0,243,241,1,0,0,0,243,244,1,0,0,0,244,246,1,0,0,0,245,
  	243,1,0,0,0,246,247,3,92,46,0,247,19,1,0,0,0,248,251,7,1,0,0,249,250,
  	5,27,0,0,250,252,5,64,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,21,1,0,
  	0,0,253,254,5,46,0,0,254,259,3,40,20,0,255,256,5,89,0,0,256,258,3,40,
  	20,0,257,255,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,260,1,0,0,0,
  	260,23,1,0,0,0,261,259,1,0,0,0,262,263,5,29,0,0,263,264,3,50,25,0,264,
  	25,1,0,0,0,265,266,5,53,0,0,266,267,3,116,58,0,267,27,1,0,0,0,268,269,
  	5,24,0,0,269,270,5,9,0,0,270,275,3,48,24,0,271,272,5,89,0,0,272,274,3,
  	48,24,0,273,271,1,0,0,0,274,277,1,0,0,0,275,273,1,0,0,0,275,276,1,0,0,
  	0,276,29,1,0,0,0,277,275,1,0,0,0,278,279,5,34,0,0,279,280,5,9,0,0,280,
  	285,3,46,23,0,281,282,5,89,0,0,282,284,3,46,23,0,283,281,1,0,0,0,284,
  	287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,31,1,0,0,0,287,285,1,
  	0,0,0,288,290,5,45,0,0,289,291,5,15,0,0,290,289,1,0,0,0,290,291,1,0,0,
  	0,291,292,1,0,0,0,292,297,3,42,21,0,293,294,5,89,0,0,294,296,3,42,21,
  	0,295,293,1,0,0,0,296,299,1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,
  	301,1,0,0,0,299,297,1,0,0,0,300,302,3,34,17,0,301,300,1,0,0,0,301,302,
  	1,0,0,0,302,312,1,0,0,0,303,305,5,45,0,0,304,306,5,15,0,0,305,304,1,0,
  	0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,309,5,78,0,0,308,310,3,34,17,
  	0,309,308,1,0,0,0,309,310,1,0,0,0,310,312,1,0,0,0,311,288,1,0,0,0,311,
  	303,1,0,0,0,312,33,1,0,0,0,313,315,3,36,18,0,314,316,3,38,19,0,315,314,
  	1,0,0,0,315,316,1,0,0,0,316,322,1,0,0,0,317,319,3,38,19,0,318,320,3,36,
  	18,0,319,318,1,0,0,0,319,320,1,0,0,0,320,322,1,0,0,0,321,313,1,0,0,0,
  	321,317,1,0,0,0,322,35,1,0,0,0,323,324,5,27,0,0,324,325,5,64,0,0,325,
  	37,1,0,0,0,326,327,5,32,0,0,327,328,5,64,0,0,328,39,1,0,0,0,329,330,5,
  	62,0,0,330,331,5,74,0,0,331,332,3,92,46,0,332,41,1,0,0,0,333,335,5,62,
  	0,0,334,336,5,59,0,0,335,334,1,0,0,0,335,336,1,0,0,0,336,359,1,0,0,0,
  	337,338,3,44,22,0,338,339,5,83,0,0,339,341,5,62,0,0,340,342,5,59,0,0,
  	341,340,1,0,0,0,341,342,1,0,0,0,342,343,1,0,0,0,343,344,5,84,0,0,344,
  	359,1,0,0,0,345,346,5,11,0,0,346,348,5,83,0,0,347,349,5,15,0,0,348,347,
  	1,0,0,0,348,349,1,0,0,0,349,355,1,0,0,0,350,352,5,62,0,0,351,353,5,59,
  	0,0,352,351,1,0,0,0,352,353,1,0,0,0,353,356,1,0,0,0,354,356,5,78,0,0,
  	355,350,1,0,0,0,355,354,1,0,0,0,356,357,1,0,0,0,357,359,5,84,0,0,358,
  	333,1,0,0,0,358,337,1,0,0,0,358,345,1,0,0,0,359,43,1,0,0,0,360,361,7,
  	2,0,0,361,45,1,0,0,0,362,364,5,62,0,0,363,365,5,59,0,0,364,363,1,0,0,
  	0,364,365,1,0,0,0,365,367,1,0,0,0,366,368,7,3,0,0,367,366,1,0,0,0,367,
  	368,1,0,0,0,368,393,1,0,0,0,369,370,3,44,22,0,370,371,5,83,0,0,371,373,
  	5,62,0,0,372,374,5,59,0,0,373,372,1,0,0,0,373,374,1,0,0,0,374,375,1,0,
  	0,0,375,377,5,84,0,0,376,378,7,3,0,0,377,376,1,0,0,0,377,378,1,0,0,0,
  	378,393,1,0,0,0,379,380,5,11,0,0,380,382,5,83,0,0,381,383,5,15,0,0,382,
  	381,1,0,0,0,382,383,1,0,0,0,383,384,1,0,0,0,384,386,5,62,0,0,385,387,
  	5,59,0,0,386,385,1,0,0,0,386,387,1,0,0,0,387,388,1,0,0,0,388,390,5,84,
  	0,0,389,391,7,3,0,0,390,389,1,0,0,0,390,391,1,0,0,0,391,393,1,0,0,0,392,
  	362,1,0,0,0,392,369,1,0,0,0,392,379,1,0,0,0,393,47,1,0,0,0,394,396,5,
  	62,0,0,395,397,5,59,0,0,396,395,1,0,0,0,396,397,1,0,0,0,397,49,1,0,0,
  	0,398,402,3,60,30,0,399,401,3,52,26,0,400,399,1,0,0,0,401,404,1,0,0,0,
  	402,400,1,0,0,0,402,403,1,0,0,0,403,51,1,0,0,0,404,402,1,0,0,0,405,406,
  	5,33,0,0,406,407,5,85,0,0,407,408,3,50,25,0,408,409,5,86,0,0,409,53,1,
  	0,0,0,410,411,5,47,0,0,411,412,5,83,0,0,412,413,5,62,0,0,413,414,5,89,
  	0,0,414,415,5,62,0,0,415,416,5,89,0,0,416,417,5,63,0,0,417,420,5,89,0,
  	0,418,421,3,92,46,0,419,421,3,58,29,0,420,418,1,0,0,0,420,419,1,0,0,0,
  	421,422,1,0,0,0,422,424,5,89,0,0,423,425,7,4,0,0,424,423,1,0,0,0,424,
  	425,1,0,0,0,425,426,1,0,0,0,426,432,5,64,0,0,427,429,5,89,0,0,428,430,
  	5,81,0,0,429,428,1,0,0,0,429,430,1,0,0,0,430,431,1,0,0,0,431,433,5,64,
  	0,0,432,427,1,0,0,0,432,433,1,0,0,0,433,434,1,0,0,0,434,435,5,84,0,0,
  	435,55,1,0,0,0,436,437,5,8,0,0,437,438,5,83,0,0,438,439,5,62,0,0,439,
  	440,5,89,0,0,440,441,5,62,0,0,441,442,5,89,0,0,442,443,5,63,0,0,443,446,
  	5,89,0,0,444,447,3,92,46,0,445,447,3,58,29,0,446,444,1,0,0,0,446,445,
  	1,0,0,0,447,448,1,0,0,0,448,449,5,89,0,0,449,450,3,16,8,0,450,452,5,89,
  	0,0,451,453,5,81,0,0,452,451,1,0,0,0,452,453,1,0,0,0,453,454,1,0,0,0,
  	454,455,5,64,0,0,455,456,5,84,0,0,456,57,1,0,0,0,457,458,5,87,0,0,458,
  	463,3,110,55,0,459,460,5,89,0,0,460,462,3,110,55,0,461,459,1,0,0,0,462,
  	465,1,0,0,0,463,461,1,0,0,0,463,464,1,0,0,0,464,466,1,0,0,0,465,463,1,
  	0,0,0,466,467,5,88,0,0,467,59,1,0,0,0,468,473,3,62,31,0,469,470,5,89,
  	0,0,470,472,3,62,31,0,471,469,1,0,0,0,472,475,1,0,0,0,473,471,1,0,0,0,
  	473,474,1,0,0,0,474,61,1,0,0,0,475,473,1,0,0,0,476,485,3,88,44,0,477,
  	480,3,94,47,0,478,480,3,64,32,0,479,477,1,0,0,0,479,478,1,0,0,0,480,481,
  	1,0,0,0,481,482,3,88,44,0,482,484,1,0,0,0,483,479,1,0,0,0,484,487,1,0,
  	0,0,485,483,1,0,0,0,485,486,1,0,0,0,486,490,1,0,0,0,487,485,1,0,0,0,488,
  	490,3,54,27,0,489,476,1,0,0,0,489,488,1,0,0,0,490,63,1,0,0,0,491,492,
  	5,68,0,0,492,494,5,87,0,0,493,495,3,86,43,0,494,493,1,0,0,0,494,495,1,
  	0,0,0,495,497,1,0,0,0,496,498,5,62,0,0,497,496,1,0,0,0,497,498,1,0,0,
  	0,498,499,1,0,0,0,499,500,3,66,33,0,500,501,5,88,0,0,501,502,5,74,0,0,
  	502,517,1,0,0,0,503,504,5,74,0,0,504,506,5,87,0,0,505,507,3,86,43,0,506,
  	505,1,0,0,0,506,507,1,0,0,0,507,509,1,0,0,0,508,510,5,62,0,0,509,508,
  	1,0,0,0,509,510,1,0,0,0,510,511,1,0,0,0,511,512,3,66,33,0,512,513,5,88,
  	0,0,513,514,5,74,0,0,514,515,5,73,0,0,515,517,1,0,0,0,516,491,1,0,0,0,
  	516,503,1,0,0,0,517,65,1,0,0,0,518,523,3,68,34,0,519,520,5,76,0,0,520,
  	522,3,68,34,0,521,519,1,0,0,0,522,525,1,0,0,0,523,521,1,0,0,0,523,524,
  	1,0,0,0,524,67,1,0,0,0,525,523,1,0,0,0,526,531,3,70,35,0,527,528,5,75,
  	0,0,528,530,3,70,35,0,529,527,1,0,0,0,530,533,1,0,0,0,531,529,1,0,0,0,
  	531,532,1,0,0,0,532,69,1,0,0,0,533,531,1,0,0,0,534,536,5,77,0,0,535,534,
  	1,0,0,0,535,536,1,0,0,0,536,537,1,0,0,0,537,539,5,60,0,0,538,540,3,84,
  	42,0,539,538,1,0,0,0,539,540,1,0,0,0,540,563,1,0,0,0,541,543,5,77,0,0,
  	542,541,1,0,0,0,542,543,1,0,0,0,543,544,1,0,0,0,544,545,5,83,0,0,545,
  	546,3,66,33,0,546,548,5,84,0,0,547,549,3,84,42,0,548,547,1,0,0,0,548,
  	549,1,0,0,0,549,563,1,0,0,0,550,552,5,77,0,0,551,550,1,0,0,0,551,552,
  	1,0,0,0,552,553,1,0,0,0,553,554,5,83,0,0,554,555,3,82,41,0,555,556,5,
  	85,0,0,556,557,3,72,36,0,557,558,5,86,0,0,558,560,5,84,0,0,559,561,3,
  	84,42,0,560,559,1,0,0,0,560,561,1,0,0,0,561,563,1,0,0,0,562,535,1,0,0,
  	0,562,542,1,0,0,0,562,551,1,0,0,0,563,71,1,0,0,0,564,569,3,74,37,0,565,
  	566,5,2,0,0,566,568,3,74,37,0,567,565,1,0,0,0,568,571,1,0,0,0,569,567,
  	1,0,0,0,569,570,1,0,0,0,570,73,1,0,0,0,571,569,1,0,0,0,572,575,3,76,38,
  	0,573,574,7,5,0,0,574,576,3,76,38,0,575,573,1,0,0,0,575,576,1,0,0,0,576,
  	75,1,0,0,0,577,582,3,78,39,0,578,579,7,4,0,0,579,581,3,78,39,0,580,578,
  	1,0,0,0,581,584,1,0,0,0,582,580,1,0,0,0,582,583,1,0,0,0,583,77,1,0,0,
  	0,584,582,1,0,0,0,585,590,3,80,40,0,586,587,5,78,0,0,587,589,3,80,40,
  	0,588,586,1,0,0,0,589,592,1,0,0,0,590,588,1,0,0,0,590,591,1,0,0,0,591,
  	79,1,0,0,0,592,590,1,0,0,0,593,601,5,62,0,0,594,601,3,106,53,0,595,601,
  	3,114,57,0,596,597,5,83,0,0,597,598,3,76,38,0,598,599,5,84,0,0,599,601,
  	1,0,0,0,600,593,1,0,0,0,600,594,1,0,0,0,600,595,1,0,0,0,600,596,1,0,0,
  	0,601,81,1,0,0,0,602,605,5,60,0,0,603,605,3,106,53,0,604,602,1,0,0,0,
  	604,603,1,0,0,0,605,83,1,0,0,0,606,615,5,78,0,0,607,615,5,81,0,0,608,
  	615,5,80,0,0,609,610,5,85,0,0,610,611,5,64,0,0,611,612,5,89,0,0,612,613,
  	5,64,0,0,613,615,5,86,0,0,614,606,1,0,0,0,614,607,1,0,0,0,614,608,1,0,
  	0,0,614,609,1,0,0,0,615,85,1,0,0,0,616,618,7,6,0,0,617,619,5,42,0,0,618,
  	617,1,0,0,0,618,619,1,0,0,0,619,621,1,0,0,0,620,622,7,7,0,0,621,620,1,
  	0,0,0,621,622,1,0,0,0,622,625,1,0,0,0,623,625,5,54,0,0,624,616,1,0,0,
  	0,624,623,1,0,0,0,625,87,1,0,0,0,626,629,3,90,45,0,627,629,3,98,49,0,
  	628,626,1,0,0,0,628,627,1,0,0,0,629,89,1,0,0,0,630,631,5,83,0,0,631,632,
  	3,92,46,0,632,633,5,84,0,0,633,91,1,0,0,0,634,639,3,106,53,0,635,639,
  	5,57,0,0,636,639,5,58,0,0,637,639,3,114,57,0,638,634,1,0,0,0,638,635,
  	1,0,0,0,638,636,1,0,0,0,638,637,1,0,0,0,639,93,1,0,0,0,640,643,5,72,0,
  	0,641,642,5,82,0,0,642,644,3,96,48,0,643,641,1,0,0,0,643,644,1,0,0,0,
  	644,645,1,0,0,0,645,654,5,82,0,0,646,650,5,82,0,0,647,648,3,96,48,0,648,
  	649,5,82,0,0,649,651,1,0,0,0,650,647,1,0,0,0,650,651,1,0,0,0,651,652,
  	1,0,0,0,652,654,5,73,0,0,653,640,1,0,0,0,653,646,1,0,0,0,654,95,1,0,0,
  	0,655,657,5,87,0,0,656,658,7,8,0,0,657,656,1,0,0,0,657,658,1,0,0,0,658,
  	660,1,0,0,0,659,661,7,9,0,0,660,659,1,0,0,0,660,661,1,0,0,0,661,663,1,
  	0,0,0,662,664,3,100,50,0,663,662,1,0,0,0,663,664,1,0,0,0,664,665,1,0,
  	0,0,665,666,5,88,0,0,666,97,1,0,0,0,667,669,5,83,0,0,668,670,5,62,0,0,
  	669,668,1,0,0,0,669,670,1,0,0,0,670,674,1,0,0,0,671,673,5,60,0,0,672,
  	671,1,0,0,0,673,676,1,0,0,0,674,672,1,0,0,0,674,675,1,0,0,0,675,678,1,
  	0,0,0,676,674,1,0,0,0,677,679,3,100,50,0,678,677,1,0,0,0,678,679,1,0,
  	0,0,679,680,1,0,0,0,680,681,5,84,0,0,681,99,1,0,0,0,682,683,5,85,0,0,
  	683,688,3,102,51,0,684,685,5,89,0,0,685,687,3,102,51,0,686,684,1,0,0,
  	0,687,690,1,0,0,0,688,686,1,0,0,0,688,689,1,0,0,0,689,691,1,0,0,0,690,
  	688,1,0,0,0,691,692,5,86,0,0,692,101,1,0,0,0,693,698,3,106,53,0,694,695,
  	5,90,0,0,695,699,3,114,57,0,696,699,5,55,0,0,697,699,5,56,0,0,698,694,
  	1,0,0,0,698,696,1,0,0,0,698,697,1,0,0,0,699,723,1,0,0,0,700,701,3,106,
  	53,0,701,702,5,60,0,0,702,703,5,83,0,0,703,704,5,63,0,0,704,705,5,84,
  	0,0,705,723,1,0,0,0,706,707,3,106,53,0,707,709,5,21,0,0,708,710,5,40,
  	0,0,709,708,1,0,0,0,709,710,1,0,0,0,710,711,1,0,0,0,711,715,3,134,67,
  	0,712,714,3,104,52,0,713,712,1,0,0,0,714,717,1,0,0,0,715,713,1,0,0,0,
  	715,716,1,0,0,0,716,723,1,0,0,0,717,715,1,0,0,0,718,719,3,106,53,0,719,
  	720,7,5,0,0,720,721,3,114,57,0,721,723,1,0,0,0,722,693,1,0,0,0,722,700,
  	1,0,0,0,722,706,1,0,0,0,722,718,1,0,0,0,723,103,1,0,0,0,724,725,5,35,
  	0,0,725,726,3,134,67,0,726,105,1,0,0,0,727,730,5,67,0,0,728,730,3,136,
  	68,0,729,727,1,0,0,0,729,728,1,0,0,0,730,107,1,0,0,0,731,732,7,10,0,0,
  	732,109,1,0,0,0,733,735,7,4,0,0,734,733,1,0,0,0,734,735,1,0,0,0,735,736,
  	1,0,0,0,736,737,7,11,0,0,737,111,1,0,0,0,738,739,3,106,53,0,739,740,5,
  	83,0,0,740,741,5,63,0,0,741,742,5,84,0,0,742,113,1,0,0,0,743,748,3,110,
  	55,0,744,748,5,63,0,0,745,748,3,108,54,0,746,748,3,112,56,0,747,743,1,
  	0,0,0,747,744,1,0,0,0,747,745,1,0,0,0,747,746,1,0,0,0,748,115,1,0,0,0,
  	749,754,3,118,59,0,750,751,5,35,0,0,751,753,3,118,59,0,752,750,1,0,0,
  	0,753,756,1,0,0,0,754,752,1,0,0,0,754,755,1,0,0,0,755,117,1,0,0,0,756,
  	754,1,0,0,0,757,762,3,120,60,0,758,759,5,2,0,0,759,761,3,120,60,0,760,
  	758,1,0,0,0,761,764,1,0,0,0,762,760,1,0,0,0,762,763,1,0,0,0,763,119,1,
  	0,0,0,764,762,1,0,0,0,765,768,3,122,61,0,766,767,7,5,0,0,767,769,3,122,
  	61,0,768,766,1,0,0,0,768,769,1,0,0,0,769,778,1,0,0,0,770,771,3,122,61,
  	0,771,773,5,21,0,0,772,774,5,40,0,0,773,772,1,0,0,0,773,774,1,0,0,0,774,
  	775,1,0,0,0,775,776,3,134,67,0,776,778,1,0,0,0,777,765,1,0,0,0,777,770,
  	1,0,0,0,778,121,1,0,0,0,779,784,3,124,62,0,780,781,7,4,0,0,781,783,3,
  	124,62,0,782,780,1,0,0,0,783,786,1,0,0,0,784,782,1,0,0,0,784,785,1,0,
  	0,0,785,123,1,0,0,0,786,784,1,0,0,0,787,792,3,126,63,0,788,789,7,12,0,
  	0,789,791,3,126,63,0,790,788,1,0,0,0,791,794,1,0,0,0,792,790,1,0,0,0,
  	792,793,1,0,0,0,793,125,1,0,0,0,794,792,1,0,0,0,795,796,5,40,0,0,796,
  	803,3,126,63,0,797,803,3,128,64,0,798,799,5,81,0,0,799,803,3,126,63,0,
  	800,801,5,82,0,0,801,803,3,126,63,0,802,795,1,0,0,0,802,797,1,0,0,0,802,
  	798,1,0,0,0,802,800,1,0,0,0,803,127,1,0,0,0,804,806,5,62,0,0,805,807,
  	5,59,0,0,806,805,1,0,0,0,806,807,1,0,0,0,807,815,1,0,0,0,808,815,3,114,
  	57,0,809,810,5,83,0,0,810,811,3,116,58,0,811,812,5,84,0,0,812,815,1,0,
  	0,0,813,815,3,130,65,0,814,804,1,0,0,0,814,808,1,0,0,0,814,809,1,0,0,
  	0,814,813,1,0,0,0,815,129,1,0,0,0,816,817,3,132,66,0,817,131,1,0,0,0,
  	818,819,5,44,0,0,819,820,5,83,0,0,820,821,3,116,58,0,821,822,5,89,0,0,
  	822,825,3,116,58,0,823,824,5,89,0,0,824,826,3,116,58,0,825,823,1,0,0,
  	0,825,826,1,0,0,0,826,827,1,0,0,0,827,828,5,84,0,0,828,133,1,0,0,0,829,
  	830,7,13,0,0,830,135,1,0,0,0,831,832,7,14,0,0,832,137,1,0,0,0,111,139,
  	143,146,153,156,159,162,172,181,186,191,195,206,214,219,231,243,251,259,
  	275,285,290,297,301,305,309,311,315,319,321,335,341,348,352,355,358,364,
  	367,373,377,382,386,390,392,396,402,420,424,429,432,446,452,463,473,479,
  	485,489,494,497,506,509,516,523,531,535,539,542,548,551,560,562,569,575,
  	582,590,600,604,614,618,621,624,628,638,643,650,653,657,660,663,669,674,
  	678,688,698,709,715,722,729,734,747,754,762,768,773,777,784,792,802,806,
  	814,825
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mql_parserParserStaticData = std::move(staticData);
}

}

MQL_Parser::MQL_Parser(TokenStream *input) : MQL_Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MQL_Parser::MQL_Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MQL_Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mql_parserParserStaticData->atn, mql_parserParserStaticData->decisionToDFA, mql_parserParserStaticData->sharedContextCache, options);
}

MQL_Parser::~MQL_Parser() {
  delete _interpreter;
}

const atn::ATN& MQL_Parser::getATN() const {
  return *mql_parserParserStaticData->atn;
}

std::string MQL_Parser::getGrammarFileName() const {
  return "MQL_Parser.g4";
}

const std::vector<std::string>& MQL_Parser::getRuleNames() const {
  return mql_parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& MQL_Parser::getVocabulary() const {
  return mql_parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MQL_Parser::getSerializedATN() const {
  return mql_parserParserStaticData->serializedATN;
}


//----------------- RootContext ------------------------------------------------------------------

MQL_Parser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::RootContext::EOF() {
  return getToken(MQL_Parser::EOF, 0);
}

MQL_Parser::InsertPatternsContext* MQL_Parser::RootContext::insertPatterns() {
  return getRuleContext<MQL_Parser::InsertPatternsContext>(0);
}

MQL_Parser::MatchQueryContext* MQL_Parser::RootContext::matchQuery() {
  return getRuleContext<MQL_Parser::MatchQueryContext>(0);
}

MQL_Parser::DescribeQueryContext* MQL_Parser::RootContext::describeQuery() {
  return getRuleContext<MQL_Parser::DescribeQueryContext>(0);
}

MQL_Parser::SetStatementContext* MQL_Parser::RootContext::setStatement() {
  return getRuleContext<MQL_Parser::SetStatementContext>(0);
}


size_t MQL_Parser::RootContext::getRuleIndex() const {
  return MQL_Parser::RuleRoot;
}


std::any MQL_Parser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::RootContext* MQL_Parser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, MQL_Parser::RuleRoot);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_SET: {
        setState(143);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MQL_Parser::K_MATCH:
          case MQL_Parser::K_SET: {
            setState(139);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == MQL_Parser::K_SET) {
              setState(138);
              setStatement();
            }
            setState(141);
            matchQuery();
            break;
          }

          case MQL_Parser::K_DESCRIBE: {
            setState(142);
            describeQuery();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case MQL_Parser::K_INSERT: {
        setState(145);
        insertPatterns();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(148);
    match(MQL_Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchQueryContext ------------------------------------------------------------------

MQL_Parser::MatchQueryContext::MatchQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::MatchStatementContext* MQL_Parser::MatchQueryContext::matchStatement() {
  return getRuleContext<MQL_Parser::MatchStatementContext>(0);
}

MQL_Parser::ReturnStatementContext* MQL_Parser::MatchQueryContext::returnStatement() {
  return getRuleContext<MQL_Parser::ReturnStatementContext>(0);
}

MQL_Parser::ProjectSimilarityContext* MQL_Parser::MatchQueryContext::projectSimilarity() {
  return getRuleContext<MQL_Parser::ProjectSimilarityContext>(0);
}

MQL_Parser::BruteSimilaritySearchContext* MQL_Parser::MatchQueryContext::bruteSimilaritySearch() {
  return getRuleContext<MQL_Parser::BruteSimilaritySearchContext>(0);
}

MQL_Parser::WhereStatementContext* MQL_Parser::MatchQueryContext::whereStatement() {
  return getRuleContext<MQL_Parser::WhereStatementContext>(0);
}

MQL_Parser::GroupByStatementContext* MQL_Parser::MatchQueryContext::groupByStatement() {
  return getRuleContext<MQL_Parser::GroupByStatementContext>(0);
}

MQL_Parser::OrderByStatementContext* MQL_Parser::MatchQueryContext::orderByStatement() {
  return getRuleContext<MQL_Parser::OrderByStatementContext>(0);
}


size_t MQL_Parser::MatchQueryContext::getRuleIndex() const {
  return MQL_Parser::RuleMatchQuery;
}


std::any MQL_Parser::MatchQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitMatchQuery(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::MatchQueryContext* MQL_Parser::matchQuery() {
  MatchQueryContext *_localctx = _tracker.createInstance<MatchQueryContext>(_ctx, getState());
  enterRule(_localctx, 2, MQL_Parser::RuleMatchQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    matchStatement();
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_PROJECT_SIMILARITY: {
        setState(151);
        projectSimilarity();
        break;
      }

      case MQL_Parser::K_BRUTE_SIMILARITY_SEARCH: {
        setState(152);
        bruteSimilaritySearch();
        break;
      }

      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_WHERE: {
        break;
      }

    default:
      break;
    }
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_WHERE) {
      setState(155);
      whereStatement();
    }
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_GROUP) {
      setState(158);
      groupByStatement();
    }
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_ORDER) {
      setState(161);
      orderByStatement();
    }
    setState(164);
    returnStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertPatternsContext ------------------------------------------------------------------

MQL_Parser::InsertPatternsContext::InsertPatternsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertPatternsContext::K_INSERT() {
  return getToken(MQL_Parser::K_INSERT, 0);
}

std::vector<MQL_Parser::InsertLinearPatternContext *> MQL_Parser::InsertPatternsContext::insertLinearPattern() {
  return getRuleContexts<MQL_Parser::InsertLinearPatternContext>();
}

MQL_Parser::InsertLinearPatternContext* MQL_Parser::InsertPatternsContext::insertLinearPattern(size_t i) {
  return getRuleContext<MQL_Parser::InsertLinearPatternContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertPatternsContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertPatternsContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::InsertPatternsContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPatterns;
}


std::any MQL_Parser::InsertPatternsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPatterns(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPatternsContext* MQL_Parser::insertPatterns() {
  InsertPatternsContext *_localctx = _tracker.createInstance<InsertPatternsContext>(_ctx, getState());
  enterRule(_localctx, 4, MQL_Parser::RuleInsertPatterns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(MQL_Parser::K_INSERT);
    setState(167);
    insertLinearPattern();
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(168);
      match(MQL_Parser::COMMA);
      setState(169);
      insertLinearPattern();
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertLinearPatternContext ------------------------------------------------------------------

MQL_Parser::InsertLinearPatternContext::InsertLinearPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::InsertPlainNodeContext *> MQL_Parser::InsertLinearPatternContext::insertPlainNode() {
  return getRuleContexts<MQL_Parser::InsertPlainNodeContext>();
}

MQL_Parser::InsertPlainNodeContext* MQL_Parser::InsertLinearPatternContext::insertPlainNode(size_t i) {
  return getRuleContext<MQL_Parser::InsertPlainNodeContext>(i);
}

std::vector<MQL_Parser::InsertPlainEdgeContext *> MQL_Parser::InsertLinearPatternContext::insertPlainEdge() {
  return getRuleContexts<MQL_Parser::InsertPlainEdgeContext>();
}

MQL_Parser::InsertPlainEdgeContext* MQL_Parser::InsertLinearPatternContext::insertPlainEdge(size_t i) {
  return getRuleContext<MQL_Parser::InsertPlainEdgeContext>(i);
}


size_t MQL_Parser::InsertLinearPatternContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertLinearPattern;
}


std::any MQL_Parser::InsertLinearPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertLinearPattern(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertLinearPatternContext* MQL_Parser::insertLinearPattern() {
  InsertLinearPatternContext *_localctx = _tracker.createInstance<InsertLinearPatternContext>(_ctx, getState());
  enterRule(_localctx, 6, MQL_Parser::RuleInsertLinearPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    insertPlainNode();
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::LT

    || _la == MQL_Parser::MINUS) {
      setState(176);
      insertPlainEdge();
      setState(177);
      insertPlainNode();
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertPlainNodeContext ------------------------------------------------------------------

MQL_Parser::InsertPlainNodeContext::InsertPlainNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertPlainNodeContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::InsertPlainNodeContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::InsertPlainNodeInsideContext* MQL_Parser::InsertPlainNodeContext::insertPlainNodeInside() {
  return getRuleContext<MQL_Parser::InsertPlainNodeInsideContext>(0);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertPlainNodeContext::TYPE() {
  return getTokens(MQL_Parser::TYPE);
}

tree::TerminalNode* MQL_Parser::InsertPlainNodeContext::TYPE(size_t i) {
  return getToken(MQL_Parser::TYPE, i);
}

MQL_Parser::PropertiesContext* MQL_Parser::InsertPlainNodeContext::properties() {
  return getRuleContext<MQL_Parser::PropertiesContext>(0);
}


size_t MQL_Parser::InsertPlainNodeContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPlainNode;
}


std::any MQL_Parser::InsertPlainNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPlainNode(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPlainNodeContext* MQL_Parser::insertPlainNode() {
  InsertPlainNodeContext *_localctx = _tracker.createInstance<InsertPlainNodeContext>(_ctx, getState());
  enterRule(_localctx, 8, MQL_Parser::RuleInsertPlainNode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(MQL_Parser::L_PAR);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34885167482928894) != 0) || _la == MQL_Parser::NAME) {
      setState(185);
      insertPlainNodeInside();
    }
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::TYPE) {
      setState(188);
      match(MQL_Parser::TYPE);
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::LCURLY_BRACKET) {
      setState(194);
      properties();
    }
    setState(197);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertPlainNodeInsideContext ------------------------------------------------------------------

MQL_Parser::InsertPlainNodeInsideContext::InsertPlainNodeInsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::IdentifierContext* MQL_Parser::InsertPlainNodeInsideContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}


size_t MQL_Parser::InsertPlainNodeInsideContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPlainNodeInside;
}


std::any MQL_Parser::InsertPlainNodeInsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPlainNodeInside(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPlainNodeInsideContext* MQL_Parser::insertPlainNodeInside() {
  InsertPlainNodeInsideContext *_localctx = _tracker.createInstance<InsertPlainNodeInsideContext>(_ctx, getState());
  enterRule(_localctx, 10, MQL_Parser::RuleInsertPlainNodeInside);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertPlainEdgeContext ------------------------------------------------------------------

MQL_Parser::InsertPlainEdgeContext::InsertPlainEdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::LT() {
  return getToken(MQL_Parser::LT, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertPlainEdgeContext::MINUS() {
  return getTokens(MQL_Parser::MINUS);
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::MINUS(size_t i) {
  return getToken(MQL_Parser::MINUS, i);
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::LSQUARE_BRACKET() {
  return getToken(MQL_Parser::LSQUARE_BRACKET, 0);
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::RSQUARE_BRACKET() {
  return getToken(MQL_Parser::RSQUARE_BRACKET, 0);
}

MQL_Parser::PropertiesContext* MQL_Parser::InsertPlainEdgeContext::properties() {
  return getRuleContext<MQL_Parser::PropertiesContext>(0);
}

tree::TerminalNode* MQL_Parser::InsertPlainEdgeContext::GT() {
  return getToken(MQL_Parser::GT, 0);
}


size_t MQL_Parser::InsertPlainEdgeContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPlainEdge;
}


std::any MQL_Parser::InsertPlainEdgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPlainEdge(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPlainEdgeContext* MQL_Parser::insertPlainEdge() {
  InsertPlainEdgeContext *_localctx = _tracker.createInstance<InsertPlainEdgeContext>(_ctx, getState());
  enterRule(_localctx, 12, MQL_Parser::RuleInsertPlainEdge);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(201);
        match(MQL_Parser::LT);
        setState(202);
        match(MQL_Parser::MINUS);
        setState(203);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(204);
        match(MQL_Parser::TYPE);
        setState(206);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::LCURLY_BRACKET) {
          setState(205);
          properties();
        }
        setState(208);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(209);
        match(MQL_Parser::MINUS);
        break;
      }

      case MQL_Parser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(210);
        match(MQL_Parser::MINUS);
        setState(211);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(212);
        match(MQL_Parser::TYPE);
        setState(214);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::LCURLY_BRACKET) {
          setState(213);
          properties();
        }
        setState(216);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(217);
        match(MQL_Parser::MINUS);
        setState(218);
        match(MQL_Parser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProjectSimilarityContext ------------------------------------------------------------------

MQL_Parser::ProjectSimilarityContext::ProjectSimilarityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::K_PROJECT_SIMILARITY() {
  return getToken(MQL_Parser::K_PROJECT_SIMILARITY, 0);
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::ProjectSimilarityContext::VARIABLE() {
  return getTokens(MQL_Parser::VARIABLE);
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::VARIABLE(size_t i) {
  return getToken(MQL_Parser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::ProjectSimilarityContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

MQL_Parser::MetricTypeContext* MQL_Parser::ProjectSimilarityContext::metricType() {
  return getRuleContext<MQL_Parser::MetricTypeContext>(0);
}

tree::TerminalNode* MQL_Parser::ProjectSimilarityContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::ProjectSimilarityContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

MQL_Parser::TensorContext* MQL_Parser::ProjectSimilarityContext::tensor() {
  return getRuleContext<MQL_Parser::TensorContext>(0);
}


size_t MQL_Parser::ProjectSimilarityContext::getRuleIndex() const {
  return MQL_Parser::RuleProjectSimilarity;
}


std::any MQL_Parser::ProjectSimilarityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProjectSimilarity(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ProjectSimilarityContext* MQL_Parser::projectSimilarity() {
  ProjectSimilarityContext *_localctx = _tracker.createInstance<ProjectSimilarityContext>(_ctx, getState());
  enterRule(_localctx, 14, MQL_Parser::RuleProjectSimilarity);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(MQL_Parser::K_PROJECT_SIMILARITY);
    setState(222);
    match(MQL_Parser::L_PAR);
    setState(223);
    match(MQL_Parser::VARIABLE);
    setState(224);
    match(MQL_Parser::COMMA);
    setState(225);
    match(MQL_Parser::VARIABLE);
    setState(226);
    match(MQL_Parser::COMMA);
    setState(227);
    match(MQL_Parser::STRING);
    setState(228);
    match(MQL_Parser::COMMA);
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRUE:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::ANON_ID:
      case MQL_Parser::EDGE_ID:
      case MQL_Parser::STRING:
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::NAME:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        setState(229);
        fixedNodeInside();
        break;
      }

      case MQL_Parser::LSQUARE_BRACKET: {
        setState(230);
        tensor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(233);
    match(MQL_Parser::COMMA);
    setState(234);
    metricType();
    setState(235);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetricTypeContext ------------------------------------------------------------------

MQL_Parser::MetricTypeContext::MetricTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::MetricTypeContext::K_ANGULAR() {
  return getToken(MQL_Parser::K_ANGULAR, 0);
}

tree::TerminalNode* MQL_Parser::MetricTypeContext::K_EUCLIDEAN() {
  return getToken(MQL_Parser::K_EUCLIDEAN, 0);
}

tree::TerminalNode* MQL_Parser::MetricTypeContext::K_MANHATTAN() {
  return getToken(MQL_Parser::K_MANHATTAN, 0);
}


size_t MQL_Parser::MetricTypeContext::getRuleIndex() const {
  return MQL_Parser::RuleMetricType;
}


std::any MQL_Parser::MetricTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitMetricType(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::MetricTypeContext* MQL_Parser::metricType() {
  MetricTypeContext *_localctx = _tracker.createInstance<MetricTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MQL_Parser::RuleMetricType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 268566536) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescribeQueryContext ------------------------------------------------------------------

MQL_Parser::DescribeQueryContext::DescribeQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::DescribeQueryContext::K_DESCRIBE() {
  return getToken(MQL_Parser::K_DESCRIBE, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::DescribeQueryContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

std::vector<MQL_Parser::DescribeFlagContext *> MQL_Parser::DescribeQueryContext::describeFlag() {
  return getRuleContexts<MQL_Parser::DescribeFlagContext>();
}

MQL_Parser::DescribeFlagContext* MQL_Parser::DescribeQueryContext::describeFlag(size_t i) {
  return getRuleContext<MQL_Parser::DescribeFlagContext>(i);
}


size_t MQL_Parser::DescribeQueryContext::getRuleIndex() const {
  return MQL_Parser::RuleDescribeQuery;
}


std::any MQL_Parser::DescribeQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitDescribeQuery(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::DescribeQueryContext* MQL_Parser::describeQuery() {
  DescribeQueryContext *_localctx = _tracker.createInstance<DescribeQueryContext>(_ctx, getState());
  enterRule(_localctx, 18, MQL_Parser::RuleDescribeQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(MQL_Parser::K_DESCRIBE);
    setState(243);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(240);
        describeFlag(); 
      }
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(246);
    fixedNodeInside();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescribeFlagContext ------------------------------------------------------------------

MQL_Parser::DescribeFlagContext::DescribeFlagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::K_LABELS() {
  return getToken(MQL_Parser::K_LABELS, 0);
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::K_PROPERTIES() {
  return getToken(MQL_Parser::K_PROPERTIES, 0);
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::K_OUTGOING() {
  return getToken(MQL_Parser::K_OUTGOING, 0);
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::K_INCOMING() {
  return getToken(MQL_Parser::K_INCOMING, 0);
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::K_LIMIT() {
  return getToken(MQL_Parser::K_LIMIT, 0);
}

tree::TerminalNode* MQL_Parser::DescribeFlagContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}


size_t MQL_Parser::DescribeFlagContext::getRuleIndex() const {
  return MQL_Parser::RuleDescribeFlag;
}


std::any MQL_Parser::DescribeFlagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitDescribeFlag(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::DescribeFlagContext* MQL_Parser::describeFlag() {
  DescribeFlagContext *_localctx = _tracker.createInstance<DescribeFlagContext>(_ctx, getState());
  enterRule(_localctx, 20, MQL_Parser::RuleDescribeFlag);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 343631200256) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(251);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(249);
      match(MQL_Parser::K_LIMIT);
      setState(250);
      match(MQL_Parser::UNSIGNED_INTEGER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetStatementContext ------------------------------------------------------------------

MQL_Parser::SetStatementContext::SetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::SetStatementContext::K_SET() {
  return getToken(MQL_Parser::K_SET, 0);
}

std::vector<MQL_Parser::SetItemContext *> MQL_Parser::SetStatementContext::setItem() {
  return getRuleContexts<MQL_Parser::SetItemContext>();
}

MQL_Parser::SetItemContext* MQL_Parser::SetStatementContext::setItem(size_t i) {
  return getRuleContext<MQL_Parser::SetItemContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::SetStatementContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::SetStatementContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::SetStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleSetStatement;
}


std::any MQL_Parser::SetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSetStatement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::SetStatementContext* MQL_Parser::setStatement() {
  SetStatementContext *_localctx = _tracker.createInstance<SetStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, MQL_Parser::RuleSetStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(MQL_Parser::K_SET);
    setState(254);
    setItem();
    setState(259);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(255);
      match(MQL_Parser::COMMA);
      setState(256);
      setItem();
      setState(261);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchStatementContext ------------------------------------------------------------------

MQL_Parser::MatchStatementContext::MatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::MatchStatementContext::K_MATCH() {
  return getToken(MQL_Parser::K_MATCH, 0);
}

MQL_Parser::GraphPatternContext* MQL_Parser::MatchStatementContext::graphPattern() {
  return getRuleContext<MQL_Parser::GraphPatternContext>(0);
}


size_t MQL_Parser::MatchStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleMatchStatement;
}


std::any MQL_Parser::MatchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitMatchStatement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::MatchStatementContext* MQL_Parser::matchStatement() {
  MatchStatementContext *_localctx = _tracker.createInstance<MatchStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, MQL_Parser::RuleMatchStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(MQL_Parser::K_MATCH);
    setState(263);
    graphPattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereStatementContext ------------------------------------------------------------------

MQL_Parser::WhereStatementContext::WhereStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::WhereStatementContext::K_WHERE() {
  return getToken(MQL_Parser::K_WHERE, 0);
}

MQL_Parser::ConditionalOrExprContext* MQL_Parser::WhereStatementContext::conditionalOrExpr() {
  return getRuleContext<MQL_Parser::ConditionalOrExprContext>(0);
}


size_t MQL_Parser::WhereStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleWhereStatement;
}


std::any MQL_Parser::WhereStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitWhereStatement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::WhereStatementContext* MQL_Parser::whereStatement() {
  WhereStatementContext *_localctx = _tracker.createInstance<WhereStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, MQL_Parser::RuleWhereStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(MQL_Parser::K_WHERE);
    setState(266);
    conditionalOrExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupByStatementContext ------------------------------------------------------------------

MQL_Parser::GroupByStatementContext::GroupByStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::GroupByStatementContext::K_GROUP() {
  return getToken(MQL_Parser::K_GROUP, 0);
}

tree::TerminalNode* MQL_Parser::GroupByStatementContext::K_BY() {
  return getToken(MQL_Parser::K_BY, 0);
}

std::vector<MQL_Parser::GroupByItemContext *> MQL_Parser::GroupByStatementContext::groupByItem() {
  return getRuleContexts<MQL_Parser::GroupByItemContext>();
}

MQL_Parser::GroupByItemContext* MQL_Parser::GroupByStatementContext::groupByItem(size_t i) {
  return getRuleContext<MQL_Parser::GroupByItemContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::GroupByStatementContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::GroupByStatementContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::GroupByStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleGroupByStatement;
}


std::any MQL_Parser::GroupByStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitGroupByStatement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::GroupByStatementContext* MQL_Parser::groupByStatement() {
  GroupByStatementContext *_localctx = _tracker.createInstance<GroupByStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, MQL_Parser::RuleGroupByStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(MQL_Parser::K_GROUP);
    setState(269);
    match(MQL_Parser::K_BY);
    setState(270);
    groupByItem();
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(271);
      match(MQL_Parser::COMMA);
      setState(272);
      groupByItem();
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderByStatementContext ------------------------------------------------------------------

MQL_Parser::OrderByStatementContext::OrderByStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::OrderByStatementContext::K_ORDER() {
  return getToken(MQL_Parser::K_ORDER, 0);
}

tree::TerminalNode* MQL_Parser::OrderByStatementContext::K_BY() {
  return getToken(MQL_Parser::K_BY, 0);
}

std::vector<MQL_Parser::OrderByItemContext *> MQL_Parser::OrderByStatementContext::orderByItem() {
  return getRuleContexts<MQL_Parser::OrderByItemContext>();
}

MQL_Parser::OrderByItemContext* MQL_Parser::OrderByStatementContext::orderByItem(size_t i) {
  return getRuleContext<MQL_Parser::OrderByItemContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::OrderByStatementContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::OrderByStatementContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::OrderByStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleOrderByStatement;
}


std::any MQL_Parser::OrderByStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOrderByStatement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::OrderByStatementContext* MQL_Parser::orderByStatement() {
  OrderByStatementContext *_localctx = _tracker.createInstance<OrderByStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, MQL_Parser::RuleOrderByStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(MQL_Parser::K_ORDER);
    setState(279);
    match(MQL_Parser::K_BY);
    setState(280);
    orderByItem();
    setState(285);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(281);
      match(MQL_Parser::COMMA);
      setState(282);
      orderByItem();
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

MQL_Parser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::ReturnStatementContext::getRuleIndex() const {
  return MQL_Parser::RuleReturnStatement;
}

void MQL_Parser::ReturnStatementContext::copyFrom(ReturnStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnAllContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ReturnAllContext::K_RETURN() {
  return getToken(MQL_Parser::K_RETURN, 0);
}

tree::TerminalNode* MQL_Parser::ReturnAllContext::STAR() {
  return getToken(MQL_Parser::STAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnAllContext::K_DISTINCT() {
  return getToken(MQL_Parser::K_DISTINCT, 0);
}

MQL_Parser::LimitOffsetClausesContext* MQL_Parser::ReturnAllContext::limitOffsetClauses() {
  return getRuleContext<MQL_Parser::LimitOffsetClausesContext>(0);
}

MQL_Parser::ReturnAllContext::ReturnAllContext(ReturnStatementContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ReturnAllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitReturnAll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnListContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ReturnListContext::K_RETURN() {
  return getToken(MQL_Parser::K_RETURN, 0);
}

std::vector<MQL_Parser::ReturnItemContext *> MQL_Parser::ReturnListContext::returnItem() {
  return getRuleContexts<MQL_Parser::ReturnItemContext>();
}

MQL_Parser::ReturnItemContext* MQL_Parser::ReturnListContext::returnItem(size_t i) {
  return getRuleContext<MQL_Parser::ReturnItemContext>(i);
}

tree::TerminalNode* MQL_Parser::ReturnListContext::K_DISTINCT() {
  return getToken(MQL_Parser::K_DISTINCT, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::ReturnListContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::ReturnListContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

MQL_Parser::LimitOffsetClausesContext* MQL_Parser::ReturnListContext::limitOffsetClauses() {
  return getRuleContext<MQL_Parser::LimitOffsetClausesContext>(0);
}

MQL_Parser::ReturnListContext::ReturnListContext(ReturnStatementContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ReturnListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitReturnList(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::ReturnStatementContext* MQL_Parser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, MQL_Parser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::ReturnListContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(288);
      match(MQL_Parser::K_RETURN);
      setState(290);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_DISTINCT) {
        setState(289);
        match(MQL_Parser::K_DISTINCT);
      }
      setState(292);
      returnItem();
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MQL_Parser::COMMA) {
        setState(293);
        match(MQL_Parser::COMMA);
        setState(294);
        returnItem();
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(301);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_LIMIT

      || _la == MQL_Parser::K_OFFSET) {
        setState(300);
        limitOffsetClauses();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::ReturnAllContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(303);
      match(MQL_Parser::K_RETURN);
      setState(305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_DISTINCT) {
        setState(304);
        match(MQL_Parser::K_DISTINCT);
      }
      setState(307);
      match(MQL_Parser::STAR);
      setState(309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_LIMIT

      || _la == MQL_Parser::K_OFFSET) {
        setState(308);
        limitOffsetClauses();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LimitOffsetClausesContext ------------------------------------------------------------------

MQL_Parser::LimitOffsetClausesContext::LimitOffsetClausesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::LimitClauseContext* MQL_Parser::LimitOffsetClausesContext::limitClause() {
  return getRuleContext<MQL_Parser::LimitClauseContext>(0);
}

MQL_Parser::OffsetClauseContext* MQL_Parser::LimitOffsetClausesContext::offsetClause() {
  return getRuleContext<MQL_Parser::OffsetClauseContext>(0);
}


size_t MQL_Parser::LimitOffsetClausesContext::getRuleIndex() const {
  return MQL_Parser::RuleLimitOffsetClauses;
}


std::any MQL_Parser::LimitOffsetClausesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitLimitOffsetClauses(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::LimitOffsetClausesContext* MQL_Parser::limitOffsetClauses() {
  LimitOffsetClausesContext *_localctx = _tracker.createInstance<LimitOffsetClausesContext>(_ctx, getState());
  enterRule(_localctx, 34, MQL_Parser::RuleLimitOffsetClauses);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_LIMIT: {
        enterOuterAlt(_localctx, 1);
        setState(313);
        limitClause();
        setState(315);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_OFFSET) {
          setState(314);
          offsetClause();
        }
        break;
      }

      case MQL_Parser::K_OFFSET: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        offsetClause();
        setState(319);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_LIMIT) {
          setState(318);
          limitClause();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LimitClauseContext ------------------------------------------------------------------

MQL_Parser::LimitClauseContext::LimitClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::LimitClauseContext::K_LIMIT() {
  return getToken(MQL_Parser::K_LIMIT, 0);
}

tree::TerminalNode* MQL_Parser::LimitClauseContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}


size_t MQL_Parser::LimitClauseContext::getRuleIndex() const {
  return MQL_Parser::RuleLimitClause;
}


std::any MQL_Parser::LimitClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitLimitClause(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::LimitClauseContext* MQL_Parser::limitClause() {
  LimitClauseContext *_localctx = _tracker.createInstance<LimitClauseContext>(_ctx, getState());
  enterRule(_localctx, 36, MQL_Parser::RuleLimitClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(MQL_Parser::K_LIMIT);
    setState(324);
    match(MQL_Parser::UNSIGNED_INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OffsetClauseContext ------------------------------------------------------------------

MQL_Parser::OffsetClauseContext::OffsetClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::OffsetClauseContext::K_OFFSET() {
  return getToken(MQL_Parser::K_OFFSET, 0);
}

tree::TerminalNode* MQL_Parser::OffsetClauseContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}


size_t MQL_Parser::OffsetClauseContext::getRuleIndex() const {
  return MQL_Parser::RuleOffsetClause;
}


std::any MQL_Parser::OffsetClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOffsetClause(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::OffsetClauseContext* MQL_Parser::offsetClause() {
  OffsetClauseContext *_localctx = _tracker.createInstance<OffsetClauseContext>(_ctx, getState());
  enterRule(_localctx, 38, MQL_Parser::RuleOffsetClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(MQL_Parser::K_OFFSET);
    setState(327);
    match(MQL_Parser::UNSIGNED_INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetItemContext ------------------------------------------------------------------

MQL_Parser::SetItemContext::SetItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::SetItemContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::SetItemContext::SINGLE_EQ() {
  return getToken(MQL_Parser::SINGLE_EQ, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::SetItemContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}


size_t MQL_Parser::SetItemContext::getRuleIndex() const {
  return MQL_Parser::RuleSetItem;
}


std::any MQL_Parser::SetItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSetItem(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::SetItemContext* MQL_Parser::setItem() {
  SetItemContext *_localctx = _tracker.createInstance<SetItemContext>(_ctx, getState());
  enterRule(_localctx, 40, MQL_Parser::RuleSetItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(MQL_Parser::VARIABLE);
    setState(330);
    match(MQL_Parser::SINGLE_EQ);
    setState(331);
    fixedNodeInside();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemContext ------------------------------------------------------------------

MQL_Parser::ReturnItemContext::ReturnItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::ReturnItemContext::getRuleIndex() const {
  return MQL_Parser::RuleReturnItem;
}

void MQL_Parser::ReturnItemContext::copyFrom(ReturnItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnItemVarContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ReturnItemVarContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemVarContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

MQL_Parser::ReturnItemVarContext::ReturnItemVarContext(ReturnItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ReturnItemVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnItemAggContext ------------------------------------------------------------------

MQL_Parser::AggregateFuncContext* MQL_Parser::ReturnItemAggContext::aggregateFunc() {
  return getRuleContext<MQL_Parser::AggregateFuncContext>(0);
}

tree::TerminalNode* MQL_Parser::ReturnItemAggContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemAggContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemAggContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemAggContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

MQL_Parser::ReturnItemAggContext::ReturnItemAggContext(ReturnItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ReturnItemAggContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemAgg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnItemCountContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::K_COUNT() {
  return getToken(MQL_Parser::K_COUNT, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::STAR() {
  return getToken(MQL_Parser::STAR, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::K_DISTINCT() {
  return getToken(MQL_Parser::K_DISTINCT, 0);
}

tree::TerminalNode* MQL_Parser::ReturnItemCountContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

MQL_Parser::ReturnItemCountContext::ReturnItemCountContext(ReturnItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ReturnItemCountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemCount(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::ReturnItemContext* MQL_Parser::returnItem() {
  ReturnItemContext *_localctx = _tracker.createInstance<ReturnItemContext>(_ctx, getState());
  enterRule(_localctx, 42, MQL_Parser::RuleReturnItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(358);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::ReturnItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(333);
        match(MQL_Parser::VARIABLE);
        setState(335);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(334);
          match(MQL_Parser::KEY);
        }
        break;
      }

      case MQL_Parser::K_AVG:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_SUM: {
        _localctx = _tracker.createInstance<MQL_Parser::ReturnItemAggContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(337);
        aggregateFunc();
        setState(338);
        match(MQL_Parser::L_PAR);
        setState(339);
        match(MQL_Parser::VARIABLE);
        setState(341);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(340);
          match(MQL_Parser::KEY);
        }
        setState(343);
        match(MQL_Parser::R_PAR);
        break;
      }

      case MQL_Parser::K_COUNT: {
        _localctx = _tracker.createInstance<MQL_Parser::ReturnItemCountContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(345);
        match(MQL_Parser::K_COUNT);
        setState(346);
        match(MQL_Parser::L_PAR);
        setState(348);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_DISTINCT) {
          setState(347);
          match(MQL_Parser::K_DISTINCT);
        }
        setState(355);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MQL_Parser::VARIABLE: {
            setState(350);
            match(MQL_Parser::VARIABLE);
            setState(352);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == MQL_Parser::KEY) {
              setState(351);
              match(MQL_Parser::KEY);
            }
            break;
          }

          case MQL_Parser::STAR: {
            setState(354);
            match(MQL_Parser::STAR);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(357);
        match(MQL_Parser::R_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregateFuncContext ------------------------------------------------------------------

MQL_Parser::AggregateFuncContext::AggregateFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::AggregateFuncContext::K_SUM() {
  return getToken(MQL_Parser::K_SUM, 0);
}

tree::TerminalNode* MQL_Parser::AggregateFuncContext::K_MAX() {
  return getToken(MQL_Parser::K_MAX, 0);
}

tree::TerminalNode* MQL_Parser::AggregateFuncContext::K_MIN() {
  return getToken(MQL_Parser::K_MIN, 0);
}

tree::TerminalNode* MQL_Parser::AggregateFuncContext::K_AVG() {
  return getToken(MQL_Parser::K_AVG, 0);
}


size_t MQL_Parser::AggregateFuncContext::getRuleIndex() const {
  return MQL_Parser::RuleAggregateFunc;
}


std::any MQL_Parser::AggregateFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitAggregateFunc(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::AggregateFuncContext* MQL_Parser::aggregateFunc() {
  AggregateFuncContext *_localctx = _tracker.createInstance<AggregateFuncContext>(_ctx, getState());
  enterRule(_localctx, 44, MQL_Parser::RuleAggregateFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 281478197936160) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderByItemContext ------------------------------------------------------------------

MQL_Parser::OrderByItemContext::OrderByItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::OrderByItemContext::getRuleIndex() const {
  return MQL_Parser::RuleOrderByItem;
}

void MQL_Parser::OrderByItemContext::copyFrom(OrderByItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OrderByItemCountContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::K_COUNT() {
  return getToken(MQL_Parser::K_COUNT, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::K_DISTINCT() {
  return getToken(MQL_Parser::K_DISTINCT, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::K_ASC() {
  return getToken(MQL_Parser::K_ASC, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemCountContext::K_DESC() {
  return getToken(MQL_Parser::K_DESC, 0);
}

MQL_Parser::OrderByItemCountContext::OrderByItemCountContext(OrderByItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::OrderByItemCountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemCount(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrderByItemVarContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::OrderByItemVarContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemVarContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemVarContext::K_ASC() {
  return getToken(MQL_Parser::K_ASC, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemVarContext::K_DESC() {
  return getToken(MQL_Parser::K_DESC, 0);
}

MQL_Parser::OrderByItemVarContext::OrderByItemVarContext(OrderByItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::OrderByItemVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrderByItemAggContext ------------------------------------------------------------------

MQL_Parser::AggregateFuncContext* MQL_Parser::OrderByItemAggContext::aggregateFunc() {
  return getRuleContext<MQL_Parser::AggregateFuncContext>(0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::K_ASC() {
  return getToken(MQL_Parser::K_ASC, 0);
}

tree::TerminalNode* MQL_Parser::OrderByItemAggContext::K_DESC() {
  return getToken(MQL_Parser::K_DESC, 0);
}

MQL_Parser::OrderByItemAggContext::OrderByItemAggContext(OrderByItemContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::OrderByItemAggContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemAgg(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::OrderByItemContext* MQL_Parser::orderByItem() {
  OrderByItemContext *_localctx = _tracker.createInstance<OrderByItemContext>(_ctx, getState());
  enterRule(_localctx, 46, MQL_Parser::RuleOrderByItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(392);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::OrderByItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(362);
        match(MQL_Parser::VARIABLE);
        setState(364);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(363);
          match(MQL_Parser::KEY);
        }
        setState(367);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(366);
          _la = _input->LA(1);
          if (!(_la == MQL_Parser::K_ASC

          || _la == MQL_Parser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case MQL_Parser::K_AVG:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_SUM: {
        _localctx = _tracker.createInstance<MQL_Parser::OrderByItemAggContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(369);
        aggregateFunc();
        setState(370);
        match(MQL_Parser::L_PAR);
        setState(371);
        match(MQL_Parser::VARIABLE);
        setState(373);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(372);
          match(MQL_Parser::KEY);
        }
        setState(375);
        match(MQL_Parser::R_PAR);
        setState(377);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(376);
          _la = _input->LA(1);
          if (!(_la == MQL_Parser::K_ASC

          || _la == MQL_Parser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case MQL_Parser::K_COUNT: {
        _localctx = _tracker.createInstance<MQL_Parser::OrderByItemCountContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(379);
        match(MQL_Parser::K_COUNT);
        setState(380);
        match(MQL_Parser::L_PAR);
        setState(382);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_DISTINCT) {
          setState(381);
          match(MQL_Parser::K_DISTINCT);
        }
        setState(384);
        match(MQL_Parser::VARIABLE);
        setState(386);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(385);
          match(MQL_Parser::KEY);
        }
        setState(388);
        match(MQL_Parser::R_PAR);
        setState(390);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(389);
          _la = _input->LA(1);
          if (!(_la == MQL_Parser::K_ASC

          || _la == MQL_Parser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupByItemContext ------------------------------------------------------------------

MQL_Parser::GroupByItemContext::GroupByItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::GroupByItemContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::GroupByItemContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}


size_t MQL_Parser::GroupByItemContext::getRuleIndex() const {
  return MQL_Parser::RuleGroupByItem;
}


std::any MQL_Parser::GroupByItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitGroupByItem(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::GroupByItemContext* MQL_Parser::groupByItem() {
  GroupByItemContext *_localctx = _tracker.createInstance<GroupByItemContext>(_ctx, getState());
  enterRule(_localctx, 48, MQL_Parser::RuleGroupByItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(MQL_Parser::VARIABLE);
    setState(396);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::KEY) {
      setState(395);
      match(MQL_Parser::KEY);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphPatternContext ------------------------------------------------------------------

MQL_Parser::GraphPatternContext::GraphPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::BasicPatternContext* MQL_Parser::GraphPatternContext::basicPattern() {
  return getRuleContext<MQL_Parser::BasicPatternContext>(0);
}

std::vector<MQL_Parser::OptionalPatternContext *> MQL_Parser::GraphPatternContext::optionalPattern() {
  return getRuleContexts<MQL_Parser::OptionalPatternContext>();
}

MQL_Parser::OptionalPatternContext* MQL_Parser::GraphPatternContext::optionalPattern(size_t i) {
  return getRuleContext<MQL_Parser::OptionalPatternContext>(i);
}


size_t MQL_Parser::GraphPatternContext::getRuleIndex() const {
  return MQL_Parser::RuleGraphPattern;
}


std::any MQL_Parser::GraphPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitGraphPattern(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::GraphPatternContext* MQL_Parser::graphPattern() {
  GraphPatternContext *_localctx = _tracker.createInstance<GraphPatternContext>(_ctx, getState());
  enterRule(_localctx, 50, MQL_Parser::RuleGraphPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    basicPattern();
    setState(402);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_OPTIONAL) {
      setState(399);
      optionalPattern();
      setState(404);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalPatternContext ------------------------------------------------------------------

MQL_Parser::OptionalPatternContext::OptionalPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::OptionalPatternContext::K_OPTIONAL() {
  return getToken(MQL_Parser::K_OPTIONAL, 0);
}

tree::TerminalNode* MQL_Parser::OptionalPatternContext::LCURLY_BRACKET() {
  return getToken(MQL_Parser::LCURLY_BRACKET, 0);
}

MQL_Parser::GraphPatternContext* MQL_Parser::OptionalPatternContext::graphPattern() {
  return getRuleContext<MQL_Parser::GraphPatternContext>(0);
}

tree::TerminalNode* MQL_Parser::OptionalPatternContext::RCURLY_BRACKET() {
  return getToken(MQL_Parser::RCURLY_BRACKET, 0);
}


size_t MQL_Parser::OptionalPatternContext::getRuleIndex() const {
  return MQL_Parser::RuleOptionalPattern;
}


std::any MQL_Parser::OptionalPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitOptionalPattern(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::OptionalPatternContext* MQL_Parser::optionalPattern() {
  OptionalPatternContext *_localctx = _tracker.createInstance<OptionalPatternContext>(_ctx, getState());
  enterRule(_localctx, 52, MQL_Parser::RuleOptionalPattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(MQL_Parser::K_OPTIONAL);
    setState(406);
    match(MQL_Parser::LCURLY_BRACKET);
    setState(407);
    graphPattern();
    setState(408);
    match(MQL_Parser::RCURLY_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimilaritySearchContext ------------------------------------------------------------------

MQL_Parser::SimilaritySearchContext::SimilaritySearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::K_SIMILARITY_SEARCH() {
  return getToken(MQL_Parser::K_SIMILARITY_SEARCH, 0);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::SimilaritySearchContext::VARIABLE() {
  return getTokens(MQL_Parser::VARIABLE);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::VARIABLE(size_t i) {
  return getToken(MQL_Parser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::SimilaritySearchContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::SimilaritySearchContext::UNSIGNED_INTEGER() {
  return getTokens(MQL_Parser::UNSIGNED_INTEGER);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::UNSIGNED_INTEGER(size_t i) {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, i);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::SimilaritySearchContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

MQL_Parser::TensorContext* MQL_Parser::SimilaritySearchContext::tensor() {
  return getRuleContext<MQL_Parser::TensorContext>(0);
}

std::vector<tree::TerminalNode *> MQL_Parser::SimilaritySearchContext::PLUS() {
  return getTokens(MQL_Parser::PLUS);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::PLUS(size_t i) {
  return getToken(MQL_Parser::PLUS, i);
}

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::MINUS() {
  return getToken(MQL_Parser::MINUS, 0);
}


size_t MQL_Parser::SimilaritySearchContext::getRuleIndex() const {
  return MQL_Parser::RuleSimilaritySearch;
}


std::any MQL_Parser::SimilaritySearchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSimilaritySearch(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::SimilaritySearchContext* MQL_Parser::similaritySearch() {
  SimilaritySearchContext *_localctx = _tracker.createInstance<SimilaritySearchContext>(_ctx, getState());
  enterRule(_localctx, 54, MQL_Parser::RuleSimilaritySearch);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    match(MQL_Parser::K_SIMILARITY_SEARCH);
    setState(411);
    match(MQL_Parser::L_PAR);
    setState(412);
    match(MQL_Parser::VARIABLE);
    setState(413);
    match(MQL_Parser::COMMA);
    setState(414);
    match(MQL_Parser::VARIABLE);
    setState(415);
    match(MQL_Parser::COMMA);
    setState(416);
    match(MQL_Parser::STRING);
    setState(417);
    match(MQL_Parser::COMMA);
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRUE:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::ANON_ID:
      case MQL_Parser::EDGE_ID:
      case MQL_Parser::STRING:
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::NAME:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        setState(418);
        fixedNodeInside();
        break;
      }

      case MQL_Parser::LSQUARE_BRACKET: {
        setState(419);
        tensor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(422);
    match(MQL_Parser::COMMA);
    setState(424);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(423);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::PLUS

      || _la == MQL_Parser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(426);
    match(MQL_Parser::UNSIGNED_INTEGER);
    setState(432);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::COMMA) {
      setState(427);
      match(MQL_Parser::COMMA);
      setState(429);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PLUS) {
        setState(428);
        match(MQL_Parser::PLUS);
      }
      setState(431);
      match(MQL_Parser::UNSIGNED_INTEGER);
    }
    setState(434);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BruteSimilaritySearchContext ------------------------------------------------------------------

MQL_Parser::BruteSimilaritySearchContext::BruteSimilaritySearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::K_BRUTE_SIMILARITY_SEARCH() {
  return getToken(MQL_Parser::K_BRUTE_SIMILARITY_SEARCH, 0);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::BruteSimilaritySearchContext::VARIABLE() {
  return getTokens(MQL_Parser::VARIABLE);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::VARIABLE(size_t i) {
  return getToken(MQL_Parser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::BruteSimilaritySearchContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

MQL_Parser::MetricTypeContext* MQL_Parser::BruteSimilaritySearchContext::metricType() {
  return getRuleContext<MQL_Parser::MetricTypeContext>(0);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::BruteSimilaritySearchContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

MQL_Parser::TensorContext* MQL_Parser::BruteSimilaritySearchContext::tensor() {
  return getRuleContext<MQL_Parser::TensorContext>(0);
}

tree::TerminalNode* MQL_Parser::BruteSimilaritySearchContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
}


size_t MQL_Parser::BruteSimilaritySearchContext::getRuleIndex() const {
  return MQL_Parser::RuleBruteSimilaritySearch;
}


std::any MQL_Parser::BruteSimilaritySearchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitBruteSimilaritySearch(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::BruteSimilaritySearchContext* MQL_Parser::bruteSimilaritySearch() {
  BruteSimilaritySearchContext *_localctx = _tracker.createInstance<BruteSimilaritySearchContext>(_ctx, getState());
  enterRule(_localctx, 56, MQL_Parser::RuleBruteSimilaritySearch);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    match(MQL_Parser::K_BRUTE_SIMILARITY_SEARCH);
    setState(437);
    match(MQL_Parser::L_PAR);
    setState(438);
    match(MQL_Parser::VARIABLE);
    setState(439);
    match(MQL_Parser::COMMA);
    setState(440);
    match(MQL_Parser::VARIABLE);
    setState(441);
    match(MQL_Parser::COMMA);
    setState(442);
    match(MQL_Parser::STRING);
    setState(443);
    match(MQL_Parser::COMMA);
    setState(446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRUE:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::ANON_ID:
      case MQL_Parser::EDGE_ID:
      case MQL_Parser::STRING:
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::NAME:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        setState(444);
        fixedNodeInside();
        break;
      }

      case MQL_Parser::LSQUARE_BRACKET: {
        setState(445);
        tensor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(448);
    match(MQL_Parser::COMMA);
    setState(449);
    metricType();
    setState(450);
    match(MQL_Parser::COMMA);
    setState(452);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::PLUS) {
      setState(451);
      match(MQL_Parser::PLUS);
    }
    setState(454);
    match(MQL_Parser::UNSIGNED_INTEGER);
    setState(455);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TensorContext ------------------------------------------------------------------

MQL_Parser::TensorContext::TensorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::TensorContext::LSQUARE_BRACKET() {
  return getToken(MQL_Parser::LSQUARE_BRACKET, 0);
}

std::vector<MQL_Parser::NumericValueContext *> MQL_Parser::TensorContext::numericValue() {
  return getRuleContexts<MQL_Parser::NumericValueContext>();
}

MQL_Parser::NumericValueContext* MQL_Parser::TensorContext::numericValue(size_t i) {
  return getRuleContext<MQL_Parser::NumericValueContext>(i);
}

tree::TerminalNode* MQL_Parser::TensorContext::RSQUARE_BRACKET() {
  return getToken(MQL_Parser::RSQUARE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::TensorContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::TensorContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::TensorContext::getRuleIndex() const {
  return MQL_Parser::RuleTensor;
}


std::any MQL_Parser::TensorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitTensor(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::TensorContext* MQL_Parser::tensor() {
  TensorContext *_localctx = _tracker.createInstance<TensorContext>(_ctx, getState());
  enterRule(_localctx, 58, MQL_Parser::RuleTensor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    match(MQL_Parser::LSQUARE_BRACKET);
    setState(458);
    numericValue();
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(459);
      match(MQL_Parser::COMMA);
      setState(460);
      numericValue();
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(466);
    match(MQL_Parser::RSQUARE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicPatternContext ------------------------------------------------------------------

MQL_Parser::BasicPatternContext::BasicPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::LinearPatternContext *> MQL_Parser::BasicPatternContext::linearPattern() {
  return getRuleContexts<MQL_Parser::LinearPatternContext>();
}

MQL_Parser::LinearPatternContext* MQL_Parser::BasicPatternContext::linearPattern(size_t i) {
  return getRuleContext<MQL_Parser::LinearPatternContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::BasicPatternContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::BasicPatternContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::BasicPatternContext::getRuleIndex() const {
  return MQL_Parser::RuleBasicPattern;
}


std::any MQL_Parser::BasicPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitBasicPattern(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::BasicPatternContext* MQL_Parser::basicPattern() {
  BasicPatternContext *_localctx = _tracker.createInstance<BasicPatternContext>(_ctx, getState());
  enterRule(_localctx, 60, MQL_Parser::RuleBasicPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    linearPattern();
    setState(473);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(469);
      match(MQL_Parser::COMMA);
      setState(470);
      linearPattern();
      setState(475);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LinearPatternContext ------------------------------------------------------------------

MQL_Parser::LinearPatternContext::LinearPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::NodeContext *> MQL_Parser::LinearPatternContext::node() {
  return getRuleContexts<MQL_Parser::NodeContext>();
}

MQL_Parser::NodeContext* MQL_Parser::LinearPatternContext::node(size_t i) {
  return getRuleContext<MQL_Parser::NodeContext>(i);
}

std::vector<MQL_Parser::EdgeContext *> MQL_Parser::LinearPatternContext::edge() {
  return getRuleContexts<MQL_Parser::EdgeContext>();
}

MQL_Parser::EdgeContext* MQL_Parser::LinearPatternContext::edge(size_t i) {
  return getRuleContext<MQL_Parser::EdgeContext>(i);
}

std::vector<MQL_Parser::PathContext *> MQL_Parser::LinearPatternContext::path() {
  return getRuleContexts<MQL_Parser::PathContext>();
}

MQL_Parser::PathContext* MQL_Parser::LinearPatternContext::path(size_t i) {
  return getRuleContext<MQL_Parser::PathContext>(i);
}

MQL_Parser::SimilaritySearchContext* MQL_Parser::LinearPatternContext::similaritySearch() {
  return getRuleContext<MQL_Parser::SimilaritySearchContext>(0);
}


size_t MQL_Parser::LinearPatternContext::getRuleIndex() const {
  return MQL_Parser::RuleLinearPattern;
}


std::any MQL_Parser::LinearPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitLinearPattern(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::LinearPatternContext* MQL_Parser::linearPattern() {
  LinearPatternContext *_localctx = _tracker.createInstance<LinearPatternContext>(_ctx, getState());
  enterRule(_localctx, 62, MQL_Parser::RuleLinearPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(489);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::L_PAR: {
        enterOuterAlt(_localctx, 1);
        setState(476);
        node();
        setState(485);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 68) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 68)) & 16465) != 0)) {
          setState(479);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case MQL_Parser::LT:
            case MQL_Parser::MINUS: {
              setState(477);
              edge();
              break;
            }

            case MQL_Parser::LEQ:
            case MQL_Parser::SINGLE_EQ: {
              setState(478);
              path();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(481);
          node();
          setState(487);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case MQL_Parser::K_SIMILARITY_SEARCH: {
        enterOuterAlt(_localctx, 2);
        setState(488);
        similaritySearch();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

MQL_Parser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::PathContext::LEQ() {
  return getToken(MQL_Parser::LEQ, 0);
}

tree::TerminalNode* MQL_Parser::PathContext::LSQUARE_BRACKET() {
  return getToken(MQL_Parser::LSQUARE_BRACKET, 0);
}

MQL_Parser::PathAlternativesContext* MQL_Parser::PathContext::pathAlternatives() {
  return getRuleContext<MQL_Parser::PathAlternativesContext>(0);
}

tree::TerminalNode* MQL_Parser::PathContext::RSQUARE_BRACKET() {
  return getToken(MQL_Parser::RSQUARE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::PathContext::SINGLE_EQ() {
  return getTokens(MQL_Parser::SINGLE_EQ);
}

tree::TerminalNode* MQL_Parser::PathContext::SINGLE_EQ(size_t i) {
  return getToken(MQL_Parser::SINGLE_EQ, i);
}

MQL_Parser::PathTypeContext* MQL_Parser::PathContext::pathType() {
  return getRuleContext<MQL_Parser::PathTypeContext>(0);
}

tree::TerminalNode* MQL_Parser::PathContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::PathContext::GT() {
  return getToken(MQL_Parser::GT, 0);
}


size_t MQL_Parser::PathContext::getRuleIndex() const {
  return MQL_Parser::RulePath;
}


std::any MQL_Parser::PathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPath(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PathContext* MQL_Parser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 64, MQL_Parser::RulePath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(516);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::LEQ: {
        enterOuterAlt(_localctx, 1);
        setState(491);
        match(MQL_Parser::LEQ);
        setState(492);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(494);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 18014398509482064) != 0)) {
          setState(493);
          pathType();
        }
        setState(497);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::VARIABLE) {
          setState(496);
          match(MQL_Parser::VARIABLE);
        }
        setState(499);
        pathAlternatives();
        setState(500);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(501);
        match(MQL_Parser::SINGLE_EQ);
        break;
      }

      case MQL_Parser::SINGLE_EQ: {
        enterOuterAlt(_localctx, 2);
        setState(503);
        match(MQL_Parser::SINGLE_EQ);
        setState(504);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(506);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 18014398509482064) != 0)) {
          setState(505);
          pathType();
        }
        setState(509);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::VARIABLE) {
          setState(508);
          match(MQL_Parser::VARIABLE);
        }
        setState(511);
        pathAlternatives();
        setState(512);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(513);
        match(MQL_Parser::SINGLE_EQ);
        setState(514);
        match(MQL_Parser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathAlternativesContext ------------------------------------------------------------------

MQL_Parser::PathAlternativesContext::PathAlternativesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::PathSequenceContext *> MQL_Parser::PathAlternativesContext::pathSequence() {
  return getRuleContexts<MQL_Parser::PathSequenceContext>();
}

MQL_Parser::PathSequenceContext* MQL_Parser::PathAlternativesContext::pathSequence(size_t i) {
  return getRuleContext<MQL_Parser::PathSequenceContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::PathAlternativesContext::PATH_ALTERNATIVE() {
  return getTokens(MQL_Parser::PATH_ALTERNATIVE);
}

tree::TerminalNode* MQL_Parser::PathAlternativesContext::PATH_ALTERNATIVE(size_t i) {
  return getToken(MQL_Parser::PATH_ALTERNATIVE, i);
}


size_t MQL_Parser::PathAlternativesContext::getRuleIndex() const {
  return MQL_Parser::RulePathAlternatives;
}


std::any MQL_Parser::PathAlternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathAlternatives(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PathAlternativesContext* MQL_Parser::pathAlternatives() {
  PathAlternativesContext *_localctx = _tracker.createInstance<PathAlternativesContext>(_ctx, getState());
  enterRule(_localctx, 66, MQL_Parser::RulePathAlternatives);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(518);
    pathSequence();
    setState(523);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PATH_ALTERNATIVE) {
      setState(519);
      match(MQL_Parser::PATH_ALTERNATIVE);
      setState(520);
      pathSequence();
      setState(525);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathSequenceContext ------------------------------------------------------------------

MQL_Parser::PathSequenceContext::PathSequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::PathAtomContext *> MQL_Parser::PathSequenceContext::pathAtom() {
  return getRuleContexts<MQL_Parser::PathAtomContext>();
}

MQL_Parser::PathAtomContext* MQL_Parser::PathSequenceContext::pathAtom(size_t i) {
  return getRuleContext<MQL_Parser::PathAtomContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::PathSequenceContext::PATH_SEQUENCE() {
  return getTokens(MQL_Parser::PATH_SEQUENCE);
}

tree::TerminalNode* MQL_Parser::PathSequenceContext::PATH_SEQUENCE(size_t i) {
  return getToken(MQL_Parser::PATH_SEQUENCE, i);
}


size_t MQL_Parser::PathSequenceContext::getRuleIndex() const {
  return MQL_Parser::RulePathSequence;
}


std::any MQL_Parser::PathSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathSequence(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PathSequenceContext* MQL_Parser::pathSequence() {
  PathSequenceContext *_localctx = _tracker.createInstance<PathSequenceContext>(_ctx, getState());
  enterRule(_localctx, 68, MQL_Parser::RulePathSequence);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    pathAtom();
    setState(531);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PATH_SEQUENCE) {
      setState(527);
      match(MQL_Parser::PATH_SEQUENCE);
      setState(528);
      pathAtom();
      setState(533);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathAtomContext ------------------------------------------------------------------

MQL_Parser::PathAtomContext::PathAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::PathAtomContext::getRuleIndex() const {
  return MQL_Parser::RulePathAtom;
}

void MQL_Parser::PathAtomContext::copyFrom(PathAtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PathAtomSmtContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::ObjectContext* MQL_Parser::PathAtomSmtContext::object() {
  return getRuleContext<MQL_Parser::ObjectContext>(0);
}

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::LCURLY_BRACKET() {
  return getToken(MQL_Parser::LCURLY_BRACKET, 0);
}

MQL_Parser::SmtFormulaContext* MQL_Parser::PathAtomSmtContext::smtFormula() {
  return getRuleContext<MQL_Parser::SmtFormulaContext>(0);
}

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::RCURLY_BRACKET() {
  return getToken(MQL_Parser::RCURLY_BRACKET, 0);
}

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::PATH_NEGATION() {
  return getToken(MQL_Parser::PATH_NEGATION, 0);
}

MQL_Parser::PathSuffixContext* MQL_Parser::PathAtomSmtContext::pathSuffix() {
  return getRuleContext<MQL_Parser::PathSuffixContext>(0);
}

MQL_Parser::PathAtomSmtContext::PathAtomSmtContext(PathAtomContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::PathAtomSmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathAtomSmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathAtomAlternativesContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::PathAtomAlternativesContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::PathAlternativesContext* MQL_Parser::PathAtomAlternativesContext::pathAlternatives() {
  return getRuleContext<MQL_Parser::PathAlternativesContext>(0);
}

tree::TerminalNode* MQL_Parser::PathAtomAlternativesContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::PathAtomAlternativesContext::PATH_NEGATION() {
  return getToken(MQL_Parser::PATH_NEGATION, 0);
}

MQL_Parser::PathSuffixContext* MQL_Parser::PathAtomAlternativesContext::pathSuffix() {
  return getRuleContext<MQL_Parser::PathSuffixContext>(0);
}

MQL_Parser::PathAtomAlternativesContext::PathAtomAlternativesContext(PathAtomContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::PathAtomAlternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathAtomAlternatives(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathAtomSimpleContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::PathAtomSimpleContext::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

tree::TerminalNode* MQL_Parser::PathAtomSimpleContext::PATH_NEGATION() {
  return getToken(MQL_Parser::PATH_NEGATION, 0);
}

MQL_Parser::PathSuffixContext* MQL_Parser::PathAtomSimpleContext::pathSuffix() {
  return getRuleContext<MQL_Parser::PathSuffixContext>(0);
}

MQL_Parser::PathAtomSimpleContext::PathAtomSimpleContext(PathAtomContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::PathAtomSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathAtomSimple(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::PathAtomContext* MQL_Parser::pathAtom() {
  PathAtomContext *_localctx = _tracker.createInstance<PathAtomContext>(_ctx, getState());
  enterRule(_localctx, 70, MQL_Parser::RulePathAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(535);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(534);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(537);
      match(MQL_Parser::TYPE);
      setState(539);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & 141) != 0)) {
        setState(538);
        pathSuffix();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomAlternativesContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(542);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(541);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(544);
      match(MQL_Parser::L_PAR);
      setState(545);
      pathAlternatives();
      setState(546);
      match(MQL_Parser::R_PAR);
      setState(548);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & 141) != 0)) {
        setState(547);
        pathSuffix();
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomSmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(551);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(550);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(553);
      match(MQL_Parser::L_PAR);
      setState(554);
      object();
      setState(555);
      match(MQL_Parser::LCURLY_BRACKET);
      setState(556);
      smtFormula();
      setState(557);
      match(MQL_Parser::RCURLY_BRACKET);
      setState(558);
      match(MQL_Parser::R_PAR);
      setState(560);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & 141) != 0)) {
        setState(559);
        pathSuffix();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmtFormulaContext ------------------------------------------------------------------

MQL_Parser::SmtFormulaContext::SmtFormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::SmtCompareContext *> MQL_Parser::SmtFormulaContext::smtCompare() {
  return getRuleContexts<MQL_Parser::SmtCompareContext>();
}

MQL_Parser::SmtCompareContext* MQL_Parser::SmtFormulaContext::smtCompare(size_t i) {
  return getRuleContext<MQL_Parser::SmtCompareContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::SmtFormulaContext::K_AND() {
  return getTokens(MQL_Parser::K_AND);
}

tree::TerminalNode* MQL_Parser::SmtFormulaContext::K_AND(size_t i) {
  return getToken(MQL_Parser::K_AND, i);
}


size_t MQL_Parser::SmtFormulaContext::getRuleIndex() const {
  return MQL_Parser::RuleSmtFormula;
}


std::any MQL_Parser::SmtFormulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtFormula(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::SmtFormulaContext* MQL_Parser::smtFormula() {
  SmtFormulaContext *_localctx = _tracker.createInstance<SmtFormulaContext>(_ctx, getState());
  enterRule(_localctx, 72, MQL_Parser::RuleSmtFormula);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    smtCompare();
    setState(569);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_AND) {
      setState(565);
      match(MQL_Parser::K_AND);
      setState(566);
      smtCompare();
      setState(571);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmtCompareContext ------------------------------------------------------------------

MQL_Parser::SmtCompareContext::SmtCompareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::AddExprContext *> MQL_Parser::SmtCompareContext::addExpr() {
  return getRuleContexts<MQL_Parser::AddExprContext>();
}

MQL_Parser::AddExprContext* MQL_Parser::SmtCompareContext::addExpr(size_t i) {
  return getRuleContext<MQL_Parser::AddExprContext>(i);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::EQ() {
  return getToken(MQL_Parser::EQ, 0);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::NEQ() {
  return getToken(MQL_Parser::NEQ, 0);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::LT() {
  return getToken(MQL_Parser::LT, 0);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::GT() {
  return getToken(MQL_Parser::GT, 0);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::LEQ() {
  return getToken(MQL_Parser::LEQ, 0);
}

tree::TerminalNode* MQL_Parser::SmtCompareContext::GEQ() {
  return getToken(MQL_Parser::GEQ, 0);
}


size_t MQL_Parser::SmtCompareContext::getRuleIndex() const {
  return MQL_Parser::RuleSmtCompare;
}


std::any MQL_Parser::SmtCompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtCompare(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::SmtCompareContext* MQL_Parser::smtCompare() {
  SmtCompareContext *_localctx = _tracker.createInstance<SmtCompareContext>(_ctx, getState());
  enterRule(_localctx, 74, MQL_Parser::RuleSmtCompare);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    addExpr();
    setState(575);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 63) != 0)) {
      setState(573);
      antlrcpp::downCast<SmtCompareContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 63) != 0))) {
        antlrcpp::downCast<SmtCompareContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(574);
      addExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExprContext ------------------------------------------------------------------

MQL_Parser::AddExprContext::AddExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::MulExprContext *> MQL_Parser::AddExprContext::mulExpr() {
  return getRuleContexts<MQL_Parser::MulExprContext>();
}

MQL_Parser::MulExprContext* MQL_Parser::AddExprContext::mulExpr(size_t i) {
  return getRuleContext<MQL_Parser::MulExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::AddExprContext::PLUS() {
  return getTokens(MQL_Parser::PLUS);
}

tree::TerminalNode* MQL_Parser::AddExprContext::PLUS(size_t i) {
  return getToken(MQL_Parser::PLUS, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::AddExprContext::MINUS() {
  return getTokens(MQL_Parser::MINUS);
}

tree::TerminalNode* MQL_Parser::AddExprContext::MINUS(size_t i) {
  return getToken(MQL_Parser::MINUS, i);
}


size_t MQL_Parser::AddExprContext::getRuleIndex() const {
  return MQL_Parser::RuleAddExpr;
}


std::any MQL_Parser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::AddExprContext* MQL_Parser::addExpr() {
  AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, getState());
  enterRule(_localctx, 76, MQL_Parser::RuleAddExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    mulExpr();
    setState(582);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(578);
      antlrcpp::downCast<AddExprContext *>(_localctx)->_tset961 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::PLUS

      || _la == MQL_Parser::MINUS)) {
        antlrcpp::downCast<AddExprContext *>(_localctx)->_tset961 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<AddExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<AddExprContext *>(_localctx)->_tset961);
      setState(579);
      mulExpr();
      setState(584);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExprContext ------------------------------------------------------------------

MQL_Parser::MulExprContext::MulExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::SmtAtomicExprContext *> MQL_Parser::MulExprContext::smtAtomicExpr() {
  return getRuleContexts<MQL_Parser::SmtAtomicExprContext>();
}

MQL_Parser::SmtAtomicExprContext* MQL_Parser::MulExprContext::smtAtomicExpr(size_t i) {
  return getRuleContext<MQL_Parser::SmtAtomicExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::MulExprContext::STAR() {
  return getTokens(MQL_Parser::STAR);
}

tree::TerminalNode* MQL_Parser::MulExprContext::STAR(size_t i) {
  return getToken(MQL_Parser::STAR, i);
}


size_t MQL_Parser::MulExprContext::getRuleIndex() const {
  return MQL_Parser::RuleMulExpr;
}


std::any MQL_Parser::MulExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitMulExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::MulExprContext* MQL_Parser::mulExpr() {
  MulExprContext *_localctx = _tracker.createInstance<MulExprContext>(_ctx, getState());
  enterRule(_localctx, 78, MQL_Parser::RuleMulExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    smtAtomicExpr();
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::STAR) {
      setState(586);
      match(MQL_Parser::STAR);
      setState(587);
      smtAtomicExpr();
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmtAtomicExprContext ------------------------------------------------------------------

MQL_Parser::SmtAtomicExprContext::SmtAtomicExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::SmtAtomicExprContext::getRuleIndex() const {
  return MQL_Parser::RuleSmtAtomicExpr;
}

void MQL_Parser::SmtAtomicExprContext::copyFrom(SmtAtomicExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SmtParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::SmtParenthesisContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::AddExprContext* MQL_Parser::SmtParenthesisContext::addExpr() {
  return getRuleContext<MQL_Parser::AddExprContext>(0);
}

tree::TerminalNode* MQL_Parser::SmtParenthesisContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::SmtParenthesisContext::SmtParenthesisContext(SmtAtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::SmtParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SmtValContext ------------------------------------------------------------------

MQL_Parser::ValueContext* MQL_Parser::SmtValContext::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}

MQL_Parser::SmtValContext::SmtValContext(SmtAtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::SmtValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SmtAttrContext ------------------------------------------------------------------

MQL_Parser::IdentifierContext* MQL_Parser::SmtAttrContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

MQL_Parser::SmtAttrContext::SmtAttrContext(SmtAtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::SmtAttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtAttr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SmtVarContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::SmtVarContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

MQL_Parser::SmtVarContext::SmtVarContext(SmtAtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::SmtVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitSmtVar(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::SmtAtomicExprContext* MQL_Parser::smtAtomicExpr() {
  SmtAtomicExprContext *_localctx = _tracker.createInstance<SmtAtomicExprContext>(_ctx, getState());
  enterRule(_localctx, 80, MQL_Parser::RuleSmtAtomicExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(600);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::SmtVarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(593);
      match(MQL_Parser::VARIABLE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::SmtAttrContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(594);
      identifier();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MQL_Parser::SmtValContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(595);
      value();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MQL_Parser::SmtParenthesisContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(596);
      match(MQL_Parser::L_PAR);
      setState(597);
      addExpr();
      setState(598);
      match(MQL_Parser::R_PAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

MQL_Parser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ObjectContext::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

MQL_Parser::IdentifierContext* MQL_Parser::ObjectContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}


size_t MQL_Parser::ObjectContext::getRuleIndex() const {
  return MQL_Parser::RuleObject;
}


std::any MQL_Parser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ObjectContext* MQL_Parser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 82, MQL_Parser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(604);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(602);
        match(MQL_Parser::TYPE);
        break;
      }

      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(603);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathSuffixContext ------------------------------------------------------------------

MQL_Parser::PathSuffixContext::PathSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::STAR() {
  return getToken(MQL_Parser::STAR, 0);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::QUESTION_MARK() {
  return getToken(MQL_Parser::QUESTION_MARK, 0);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::LCURLY_BRACKET() {
  return getToken(MQL_Parser::LCURLY_BRACKET, 0);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::COMMA() {
  return getToken(MQL_Parser::COMMA, 0);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::RCURLY_BRACKET() {
  return getToken(MQL_Parser::RCURLY_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::PathSuffixContext::UNSIGNED_INTEGER() {
  return getTokens(MQL_Parser::UNSIGNED_INTEGER);
}

tree::TerminalNode* MQL_Parser::PathSuffixContext::UNSIGNED_INTEGER(size_t i) {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, i);
}


size_t MQL_Parser::PathSuffixContext::getRuleIndex() const {
  return MQL_Parser::RulePathSuffix;
}


std::any MQL_Parser::PathSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathSuffix(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PathSuffixContext* MQL_Parser::pathSuffix() {
  PathSuffixContext *_localctx = _tracker.createInstance<PathSuffixContext>(_ctx, getState());
  enterRule(_localctx, 84, MQL_Parser::RulePathSuffix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(614);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::STAR: {
        enterOuterAlt(_localctx, 1);
        setState(606);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::STAR);
        break;
      }

      case MQL_Parser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(607);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::PLUS);
        break;
      }

      case MQL_Parser::QUESTION_MARK: {
        enterOuterAlt(_localctx, 3);
        setState(608);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::QUESTION_MARK);
        break;
      }

      case MQL_Parser::LCURLY_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(609);
        match(MQL_Parser::LCURLY_BRACKET);
        setState(610);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->min = match(MQL_Parser::UNSIGNED_INTEGER);
        setState(611);
        match(MQL_Parser::COMMA);
        setState(612);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->max = match(MQL_Parser::UNSIGNED_INTEGER);
        setState(613);
        match(MQL_Parser::RCURLY_BRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathTypeContext ------------------------------------------------------------------

MQL_Parser::PathTypeContext::PathTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_ANY() {
  return getToken(MQL_Parser::K_ANY, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_ALL() {
  return getToken(MQL_Parser::K_ALL, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_SHORTEST() {
  return getToken(MQL_Parser::K_SHORTEST, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_WALKS() {
  return getToken(MQL_Parser::K_WALKS, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_SIMPLE() {
  return getToken(MQL_Parser::K_SIMPLE, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_ACYCLIC() {
  return getToken(MQL_Parser::K_ACYCLIC, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::K_TRAILS() {
  return getToken(MQL_Parser::K_TRAILS, 0);
}

tree::TerminalNode* MQL_Parser::PathTypeContext::DATA_TEST() {
  return getToken(MQL_Parser::DATA_TEST, 0);
}


size_t MQL_Parser::PathTypeContext::getRuleIndex() const {
  return MQL_Parser::RulePathType;
}


std::any MQL_Parser::PathTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitPathType(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PathTypeContext* MQL_Parser::pathType() {
  PathTypeContext *_localctx = _tracker.createInstance<PathTypeContext>(_ctx, getState());
  enterRule(_localctx, 86, MQL_Parser::RulePathType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(624);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_ALL: {
        enterOuterAlt(_localctx, 1);
        setState(616);
        _la = _input->LA(1);
        if (!(_la == MQL_Parser::K_ANY

        || _la == MQL_Parser::K_ALL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(618);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_SHORTEST) {
          setState(617);
          match(MQL_Parser::K_SHORTEST);
        }
        setState(621);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 6764195534077954) != 0)) {
          setState(620);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 6764195534077954) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case MQL_Parser::DATA_TEST: {
        enterOuterAlt(_localctx, 2);
        setState(623);
        match(MQL_Parser::DATA_TEST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

MQL_Parser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::FixedNodeContext* MQL_Parser::NodeContext::fixedNode() {
  return getRuleContext<MQL_Parser::FixedNodeContext>(0);
}

MQL_Parser::VarNodeContext* MQL_Parser::NodeContext::varNode() {
  return getRuleContext<MQL_Parser::VarNodeContext>(0);
}


size_t MQL_Parser::NodeContext::getRuleIndex() const {
  return MQL_Parser::RuleNode;
}


std::any MQL_Parser::NodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitNode(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::NodeContext* MQL_Parser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 88, MQL_Parser::RuleNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(628);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(626);
      fixedNode();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(627);
      varNode();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FixedNodeContext ------------------------------------------------------------------

MQL_Parser::FixedNodeContext::FixedNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::FixedNodeContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::FixedNodeContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

tree::TerminalNode* MQL_Parser::FixedNodeContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}


size_t MQL_Parser::FixedNodeContext::getRuleIndex() const {
  return MQL_Parser::RuleFixedNode;
}


std::any MQL_Parser::FixedNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitFixedNode(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::FixedNodeContext* MQL_Parser::fixedNode() {
  FixedNodeContext *_localctx = _tracker.createInstance<FixedNodeContext>(_ctx, getState());
  enterRule(_localctx, 90, MQL_Parser::RuleFixedNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(630);
    match(MQL_Parser::L_PAR);
    setState(631);
    fixedNodeInside();
    setState(632);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FixedNodeInsideContext ------------------------------------------------------------------

MQL_Parser::FixedNodeInsideContext::FixedNodeInsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::IdentifierContext* MQL_Parser::FixedNodeInsideContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::FixedNodeInsideContext::ANON_ID() {
  return getToken(MQL_Parser::ANON_ID, 0);
}

tree::TerminalNode* MQL_Parser::FixedNodeInsideContext::EDGE_ID() {
  return getToken(MQL_Parser::EDGE_ID, 0);
}

MQL_Parser::ValueContext* MQL_Parser::FixedNodeInsideContext::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}


size_t MQL_Parser::FixedNodeInsideContext::getRuleIndex() const {
  return MQL_Parser::RuleFixedNodeInside;
}


std::any MQL_Parser::FixedNodeInsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitFixedNodeInside(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::fixedNodeInside() {
  FixedNodeInsideContext *_localctx = _tracker.createInstance<FixedNodeInsideContext>(_ctx, getState());
  enterRule(_localctx, 92, MQL_Parser::RuleFixedNodeInside);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(638);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(634);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(635);
      match(MQL_Parser::ANON_ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(636);
      match(MQL_Parser::EDGE_ID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(637);
      value();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeContext ------------------------------------------------------------------

MQL_Parser::EdgeContext::EdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::EdgeContext::LT() {
  return getToken(MQL_Parser::LT, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::EdgeContext::MINUS() {
  return getTokens(MQL_Parser::MINUS);
}

tree::TerminalNode* MQL_Parser::EdgeContext::MINUS(size_t i) {
  return getToken(MQL_Parser::MINUS, i);
}

MQL_Parser::EdgeInsideContext* MQL_Parser::EdgeContext::edgeInside() {
  return getRuleContext<MQL_Parser::EdgeInsideContext>(0);
}

tree::TerminalNode* MQL_Parser::EdgeContext::GT() {
  return getToken(MQL_Parser::GT, 0);
}


size_t MQL_Parser::EdgeContext::getRuleIndex() const {
  return MQL_Parser::RuleEdge;
}


std::any MQL_Parser::EdgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitEdge(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::EdgeContext* MQL_Parser::edge() {
  EdgeContext *_localctx = _tracker.createInstance<EdgeContext>(_ctx, getState());
  enterRule(_localctx, 94, MQL_Parser::RuleEdge);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(653);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(640);
        match(MQL_Parser::LT);
        setState(643);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
        case 1: {
          setState(641);
          match(MQL_Parser::MINUS);
          setState(642);
          edgeInside();
          break;
        }

        default:
          break;
        }
        setState(645);
        match(MQL_Parser::MINUS);
        break;
      }

      case MQL_Parser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(646);
        match(MQL_Parser::MINUS);
        setState(650);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::LSQUARE_BRACKET) {
          setState(647);
          edgeInside();
          setState(648);
          match(MQL_Parser::MINUS);
        }
        setState(652);
        match(MQL_Parser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeInsideContext ------------------------------------------------------------------

MQL_Parser::EdgeInsideContext::EdgeInsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::LSQUARE_BRACKET() {
  return getToken(MQL_Parser::LSQUARE_BRACKET, 0);
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::RSQUARE_BRACKET() {
  return getToken(MQL_Parser::RSQUARE_BRACKET, 0);
}

MQL_Parser::PropertiesContext* MQL_Parser::EdgeInsideContext::properties() {
  return getRuleContext<MQL_Parser::PropertiesContext>(0);
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::EDGE_ID() {
  return getToken(MQL_Parser::EDGE_ID, 0);
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

tree::TerminalNode* MQL_Parser::EdgeInsideContext::TYPE_VAR() {
  return getToken(MQL_Parser::TYPE_VAR, 0);
}


size_t MQL_Parser::EdgeInsideContext::getRuleIndex() const {
  return MQL_Parser::RuleEdgeInside;
}


std::any MQL_Parser::EdgeInsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitEdgeInside(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::EdgeInsideContext* MQL_Parser::edgeInside() {
  EdgeInsideContext *_localctx = _tracker.createInstance<EdgeInsideContext>(_ctx, getState());
  enterRule(_localctx, 96, MQL_Parser::RuleEdgeInside);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(655);
    match(MQL_Parser::LSQUARE_BRACKET);
    setState(657);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::EDGE_ID

    || _la == MQL_Parser::VARIABLE) {
      setState(656);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::EDGE_ID

      || _la == MQL_Parser::VARIABLE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(660);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::TYPE

    || _la == MQL_Parser::TYPE_VAR) {
      setState(659);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::TYPE

      || _la == MQL_Parser::TYPE_VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(663);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::LCURLY_BRACKET) {
      setState(662);
      properties();
    }
    setState(665);
    match(MQL_Parser::RSQUARE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNodeContext ------------------------------------------------------------------

MQL_Parser::VarNodeContext::VarNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::VarNodeContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::VarNodeContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

tree::TerminalNode* MQL_Parser::VarNodeContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::VarNodeContext::TYPE() {
  return getTokens(MQL_Parser::TYPE);
}

tree::TerminalNode* MQL_Parser::VarNodeContext::TYPE(size_t i) {
  return getToken(MQL_Parser::TYPE, i);
}

MQL_Parser::PropertiesContext* MQL_Parser::VarNodeContext::properties() {
  return getRuleContext<MQL_Parser::PropertiesContext>(0);
}


size_t MQL_Parser::VarNodeContext::getRuleIndex() const {
  return MQL_Parser::RuleVarNode;
}


std::any MQL_Parser::VarNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitVarNode(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::VarNodeContext* MQL_Parser::varNode() {
  VarNodeContext *_localctx = _tracker.createInstance<VarNodeContext>(_ctx, getState());
  enterRule(_localctx, 98, MQL_Parser::RuleVarNode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    match(MQL_Parser::L_PAR);
    setState(669);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::VARIABLE) {
      setState(668);
      match(MQL_Parser::VARIABLE);
    }
    setState(674);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::TYPE) {
      setState(671);
      match(MQL_Parser::TYPE);
      setState(676);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(678);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::LCURLY_BRACKET) {
      setState(677);
      properties();
    }
    setState(680);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

MQL_Parser::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::PropertiesContext::LCURLY_BRACKET() {
  return getToken(MQL_Parser::LCURLY_BRACKET, 0);
}

std::vector<MQL_Parser::PropertyContext *> MQL_Parser::PropertiesContext::property() {
  return getRuleContexts<MQL_Parser::PropertyContext>();
}

MQL_Parser::PropertyContext* MQL_Parser::PropertiesContext::property(size_t i) {
  return getRuleContext<MQL_Parser::PropertyContext>(i);
}

tree::TerminalNode* MQL_Parser::PropertiesContext::RCURLY_BRACKET() {
  return getToken(MQL_Parser::RCURLY_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MQL_Parser::PropertiesContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::PropertiesContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::PropertiesContext::getRuleIndex() const {
  return MQL_Parser::RuleProperties;
}


std::any MQL_Parser::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::PropertiesContext* MQL_Parser::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 100, MQL_Parser::RuleProperties);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(682);
    match(MQL_Parser::LCURLY_BRACKET);
    setState(683);
    property();
    setState(688);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(684);
      match(MQL_Parser::COMMA);
      setState(685);
      property();
      setState(690);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(691);
    match(MQL_Parser::RCURLY_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

MQL_Parser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::PropertyContext::getRuleIndex() const {
  return MQL_Parser::RuleProperty;
}

void MQL_Parser::PropertyContext::copyFrom(PropertyContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Property2Context ------------------------------------------------------------------

MQL_Parser::IdentifierContext* MQL_Parser::Property2Context::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::Property2Context::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

tree::TerminalNode* MQL_Parser::Property2Context::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::Property2Context::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

tree::TerminalNode* MQL_Parser::Property2Context::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::Property2Context::Property2Context(PropertyContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::Property2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProperty2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Property1Context ------------------------------------------------------------------

MQL_Parser::IdentifierContext* MQL_Parser::Property1Context::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::Property1Context::COLON() {
  return getToken(MQL_Parser::COLON, 0);
}

MQL_Parser::ValueContext* MQL_Parser::Property1Context::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}

tree::TerminalNode* MQL_Parser::Property1Context::TRUE_PROP() {
  return getToken(MQL_Parser::TRUE_PROP, 0);
}

tree::TerminalNode* MQL_Parser::Property1Context::FALSE_PROP() {
  return getToken(MQL_Parser::FALSE_PROP, 0);
}

MQL_Parser::Property1Context::Property1Context(PropertyContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::Property1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProperty1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Property4Context ------------------------------------------------------------------

MQL_Parser::IdentifierContext* MQL_Parser::Property4Context::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

MQL_Parser::ValueContext* MQL_Parser::Property4Context::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}

tree::TerminalNode* MQL_Parser::Property4Context::EQ() {
  return getToken(MQL_Parser::EQ, 0);
}

tree::TerminalNode* MQL_Parser::Property4Context::NEQ() {
  return getToken(MQL_Parser::NEQ, 0);
}

tree::TerminalNode* MQL_Parser::Property4Context::LT() {
  return getToken(MQL_Parser::LT, 0);
}

tree::TerminalNode* MQL_Parser::Property4Context::GT() {
  return getToken(MQL_Parser::GT, 0);
}

tree::TerminalNode* MQL_Parser::Property4Context::LEQ() {
  return getToken(MQL_Parser::LEQ, 0);
}

tree::TerminalNode* MQL_Parser::Property4Context::GEQ() {
  return getToken(MQL_Parser::GEQ, 0);
}

MQL_Parser::Property4Context::Property4Context(PropertyContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::Property4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProperty4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Property3Context ------------------------------------------------------------------

MQL_Parser::IdentifierContext* MQL_Parser::Property3Context::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::Property3Context::K_IS() {
  return getToken(MQL_Parser::K_IS, 0);
}

MQL_Parser::ExprTypenameContext* MQL_Parser::Property3Context::exprTypename() {
  return getRuleContext<MQL_Parser::ExprTypenameContext>(0);
}

tree::TerminalNode* MQL_Parser::Property3Context::K_NOT() {
  return getToken(MQL_Parser::K_NOT, 0);
}

std::vector<MQL_Parser::ConditionalOrTypeContext *> MQL_Parser::Property3Context::conditionalOrType() {
  return getRuleContexts<MQL_Parser::ConditionalOrTypeContext>();
}

MQL_Parser::ConditionalOrTypeContext* MQL_Parser::Property3Context::conditionalOrType(size_t i) {
  return getRuleContext<MQL_Parser::ConditionalOrTypeContext>(i);
}

MQL_Parser::Property3Context::Property3Context(PropertyContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::Property3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitProperty3(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::PropertyContext* MQL_Parser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 102, MQL_Parser::RuleProperty);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(722);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::Property1Context>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(693);
      identifier();
      setState(698);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MQL_Parser::COLON: {
          setState(694);
          match(MQL_Parser::COLON);
          setState(695);
          value();
          break;
        }

        case MQL_Parser::TRUE_PROP: {
          setState(696);
          match(MQL_Parser::TRUE_PROP);
          break;
        }

        case MQL_Parser::FALSE_PROP: {
          setState(697);
          match(MQL_Parser::FALSE_PROP);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::Property2Context>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(700);
      identifier();
      setState(701);
      match(MQL_Parser::TYPE);
      setState(702);
      match(MQL_Parser::L_PAR);
      setState(703);
      match(MQL_Parser::STRING);
      setState(704);
      match(MQL_Parser::R_PAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MQL_Parser::Property3Context>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(706);
      identifier();
      setState(707);
      match(MQL_Parser::K_IS);
      setState(709);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_NOT) {
        setState(708);
        match(MQL_Parser::K_NOT);
      }
      setState(711);
      exprTypename();
      setState(715);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MQL_Parser::K_OR) {
        setState(712);
        conditionalOrType();
        setState(717);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MQL_Parser::Property4Context>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(718);
      identifier();

      setState(719);
      antlrcpp::downCast<Property4Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 63) != 0))) {
        antlrcpp::downCast<Property4Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(720);
      value();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalOrTypeContext ------------------------------------------------------------------

MQL_Parser::ConditionalOrTypeContext::ConditionalOrTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ConditionalOrTypeContext::K_OR() {
  return getToken(MQL_Parser::K_OR, 0);
}

MQL_Parser::ExprTypenameContext* MQL_Parser::ConditionalOrTypeContext::exprTypename() {
  return getRuleContext<MQL_Parser::ExprTypenameContext>(0);
}


size_t MQL_Parser::ConditionalOrTypeContext::getRuleIndex() const {
  return MQL_Parser::RuleConditionalOrType;
}


std::any MQL_Parser::ConditionalOrTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitConditionalOrType(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ConditionalOrTypeContext* MQL_Parser::conditionalOrType() {
  ConditionalOrTypeContext *_localctx = _tracker.createInstance<ConditionalOrTypeContext>(_ctx, getState());
  enterRule(_localctx, 104, MQL_Parser::RuleConditionalOrType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    match(MQL_Parser::K_OR);
    setState(725);
    exprTypename();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MQL_Parser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::IdentifierContext::NAME() {
  return getToken(MQL_Parser::NAME, 0);
}

MQL_Parser::KeywordContext* MQL_Parser::IdentifierContext::keyword() {
  return getRuleContext<MQL_Parser::KeywordContext>(0);
}


size_t MQL_Parser::IdentifierContext::getRuleIndex() const {
  return MQL_Parser::RuleIdentifier;
}


std::any MQL_Parser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::IdentifierContext* MQL_Parser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 106, MQL_Parser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(729);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(727);
        match(MQL_Parser::NAME);
        break;
      }

      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST: {
        enterOuterAlt(_localctx, 2);
        setState(728);
        keyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolValueContext ------------------------------------------------------------------

MQL_Parser::BoolValueContext::BoolValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::BoolValueContext::K_TRUE() {
  return getToken(MQL_Parser::K_TRUE, 0);
}

tree::TerminalNode* MQL_Parser::BoolValueContext::K_FALSE() {
  return getToken(MQL_Parser::K_FALSE, 0);
}


size_t MQL_Parser::BoolValueContext::getRuleIndex() const {
  return MQL_Parser::RuleBoolValue;
}


std::any MQL_Parser::BoolValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitBoolValue(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::BoolValueContext* MQL_Parser::boolValue() {
  BoolValueContext *_localctx = _tracker.createInstance<BoolValueContext>(_ctx, getState());
  enterRule(_localctx, 108, MQL_Parser::RuleBoolValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(731);
    _la = _input->LA(1);
    if (!(_la == MQL_Parser::K_FALSE

    || _la == MQL_Parser::K_TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericValueContext ------------------------------------------------------------------

MQL_Parser::NumericValueContext::NumericValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::NumericValueContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}

tree::TerminalNode* MQL_Parser::NumericValueContext::UNSIGNED_FLOAT() {
  return getToken(MQL_Parser::UNSIGNED_FLOAT, 0);
}

tree::TerminalNode* MQL_Parser::NumericValueContext::UNSIGNED_SCIENTIFIC_NOTATION() {
  return getToken(MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION, 0);
}

tree::TerminalNode* MQL_Parser::NumericValueContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
}

tree::TerminalNode* MQL_Parser::NumericValueContext::MINUS() {
  return getToken(MQL_Parser::MINUS, 0);
}


size_t MQL_Parser::NumericValueContext::getRuleIndex() const {
  return MQL_Parser::RuleNumericValue;
}


std::any MQL_Parser::NumericValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitNumericValue(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::NumericValueContext* MQL_Parser::numericValue() {
  NumericValueContext *_localctx = _tracker.createInstance<NumericValueContext>(_ctx, getState());
  enterRule(_localctx, 110, MQL_Parser::RuleNumericValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(734);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(733);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::PLUS

      || _la == MQL_Parser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(736);
    _la = _input->LA(1);
    if (!(((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 7) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DatatypeValueContext ------------------------------------------------------------------

MQL_Parser::DatatypeValueContext::DatatypeValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::IdentifierContext* MQL_Parser::DatatypeValueContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::DatatypeValueContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::DatatypeValueContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

tree::TerminalNode* MQL_Parser::DatatypeValueContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}


size_t MQL_Parser::DatatypeValueContext::getRuleIndex() const {
  return MQL_Parser::RuleDatatypeValue;
}


std::any MQL_Parser::DatatypeValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitDatatypeValue(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::DatatypeValueContext* MQL_Parser::datatypeValue() {
  DatatypeValueContext *_localctx = _tracker.createInstance<DatatypeValueContext>(_ctx, getState());
  enterRule(_localctx, 112, MQL_Parser::RuleDatatypeValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(738);
    identifier();
    setState(739);
    match(MQL_Parser::L_PAR);
    setState(740);
    match(MQL_Parser::STRING);
    setState(741);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

MQL_Parser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::NumericValueContext* MQL_Parser::ValueContext::numericValue() {
  return getRuleContext<MQL_Parser::NumericValueContext>(0);
}

tree::TerminalNode* MQL_Parser::ValueContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

MQL_Parser::BoolValueContext* MQL_Parser::ValueContext::boolValue() {
  return getRuleContext<MQL_Parser::BoolValueContext>(0);
}

MQL_Parser::DatatypeValueContext* MQL_Parser::ValueContext::datatypeValue() {
  return getRuleContext<MQL_Parser::DatatypeValueContext>(0);
}


size_t MQL_Parser::ValueContext::getRuleIndex() const {
  return MQL_Parser::RuleValue;
}


std::any MQL_Parser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ValueContext* MQL_Parser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 114, MQL_Parser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(747);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(743);
        numericValue();
        break;
      }

      case MQL_Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(744);
        match(MQL_Parser::STRING);
        break;
      }

      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(745);
        boolValue();
        break;
      }

      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::NAME: {
        enterOuterAlt(_localctx, 4);
        setState(746);
        datatypeValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalOrExprContext ------------------------------------------------------------------

MQL_Parser::ConditionalOrExprContext::ConditionalOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::ConditionalAndExprContext *> MQL_Parser::ConditionalOrExprContext::conditionalAndExpr() {
  return getRuleContexts<MQL_Parser::ConditionalAndExprContext>();
}

MQL_Parser::ConditionalAndExprContext* MQL_Parser::ConditionalOrExprContext::conditionalAndExpr(size_t i) {
  return getRuleContext<MQL_Parser::ConditionalAndExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::ConditionalOrExprContext::K_OR() {
  return getTokens(MQL_Parser::K_OR);
}

tree::TerminalNode* MQL_Parser::ConditionalOrExprContext::K_OR(size_t i) {
  return getToken(MQL_Parser::K_OR, i);
}


size_t MQL_Parser::ConditionalOrExprContext::getRuleIndex() const {
  return MQL_Parser::RuleConditionalOrExpr;
}


std::any MQL_Parser::ConditionalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitConditionalOrExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ConditionalOrExprContext* MQL_Parser::conditionalOrExpr() {
  ConditionalOrExprContext *_localctx = _tracker.createInstance<ConditionalOrExprContext>(_ctx, getState());
  enterRule(_localctx, 116, MQL_Parser::RuleConditionalOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(749);
    conditionalAndExpr();
    setState(754);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_OR) {
      setState(750);
      match(MQL_Parser::K_OR);
      setState(751);
      conditionalAndExpr();
      setState(756);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalAndExprContext ------------------------------------------------------------------

MQL_Parser::ConditionalAndExprContext::ConditionalAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::ComparisonExprContext *> MQL_Parser::ConditionalAndExprContext::comparisonExpr() {
  return getRuleContexts<MQL_Parser::ComparisonExprContext>();
}

MQL_Parser::ComparisonExprContext* MQL_Parser::ConditionalAndExprContext::comparisonExpr(size_t i) {
  return getRuleContext<MQL_Parser::ComparisonExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::ConditionalAndExprContext::K_AND() {
  return getTokens(MQL_Parser::K_AND);
}

tree::TerminalNode* MQL_Parser::ConditionalAndExprContext::K_AND(size_t i) {
  return getToken(MQL_Parser::K_AND, i);
}


size_t MQL_Parser::ConditionalAndExprContext::getRuleIndex() const {
  return MQL_Parser::RuleConditionalAndExpr;
}


std::any MQL_Parser::ConditionalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitConditionalAndExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ConditionalAndExprContext* MQL_Parser::conditionalAndExpr() {
  ConditionalAndExprContext *_localctx = _tracker.createInstance<ConditionalAndExprContext>(_ctx, getState());
  enterRule(_localctx, 118, MQL_Parser::RuleConditionalAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(757);
    comparisonExpr();
    setState(762);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_AND) {
      setState(758);
      match(MQL_Parser::K_AND);
      setState(759);
      comparisonExpr();
      setState(764);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonExprContext ------------------------------------------------------------------

MQL_Parser::ComparisonExprContext::ComparisonExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::ComparisonExprContext::getRuleIndex() const {
  return MQL_Parser::RuleComparisonExpr;
}

void MQL_Parser::ComparisonExprContext::copyFrom(ComparisonExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ComparisonExprIsContext ------------------------------------------------------------------

MQL_Parser::AdditiveExprContext* MQL_Parser::ComparisonExprIsContext::additiveExpr() {
  return getRuleContext<MQL_Parser::AdditiveExprContext>(0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprIsContext::K_IS() {
  return getToken(MQL_Parser::K_IS, 0);
}

MQL_Parser::ExprTypenameContext* MQL_Parser::ComparisonExprIsContext::exprTypename() {
  return getRuleContext<MQL_Parser::ExprTypenameContext>(0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprIsContext::K_NOT() {
  return getToken(MQL_Parser::K_NOT, 0);
}

MQL_Parser::ComparisonExprIsContext::ComparisonExprIsContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ComparisonExprIsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExprIs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonExprOpContext ------------------------------------------------------------------

std::vector<MQL_Parser::AdditiveExprContext *> MQL_Parser::ComparisonExprOpContext::additiveExpr() {
  return getRuleContexts<MQL_Parser::AdditiveExprContext>();
}

MQL_Parser::AdditiveExprContext* MQL_Parser::ComparisonExprOpContext::additiveExpr(size_t i) {
  return getRuleContext<MQL_Parser::AdditiveExprContext>(i);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::EQ() {
  return getToken(MQL_Parser::EQ, 0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::NEQ() {
  return getToken(MQL_Parser::NEQ, 0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::LT() {
  return getToken(MQL_Parser::LT, 0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::GT() {
  return getToken(MQL_Parser::GT, 0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::LEQ() {
  return getToken(MQL_Parser::LEQ, 0);
}

tree::TerminalNode* MQL_Parser::ComparisonExprOpContext::GEQ() {
  return getToken(MQL_Parser::GEQ, 0);
}

MQL_Parser::ComparisonExprOpContext::ComparisonExprOpContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ComparisonExprOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExprOp(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::ComparisonExprContext* MQL_Parser::comparisonExpr() {
  ComparisonExprContext *_localctx = _tracker.createInstance<ComparisonExprContext>(_ctx, getState());
  enterRule(_localctx, 120, MQL_Parser::RuleComparisonExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(777);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::ComparisonExprOpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(765);
      additiveExpr();
      setState(768);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 63) != 0)) {
        setState(766);
        antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 68)) & 63) != 0))) {
          antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(767);
        additiveExpr();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::ComparisonExprIsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(770);
      additiveExpr();
      setState(771);
      match(MQL_Parser::K_IS);
      setState(773);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_NOT) {
        setState(772);
        match(MQL_Parser::K_NOT);
      }
      setState(775);
      exprTypename();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveExprContext ------------------------------------------------------------------

MQL_Parser::AdditiveExprContext::AdditiveExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::MultiplicativeExprContext *> MQL_Parser::AdditiveExprContext::multiplicativeExpr() {
  return getRuleContexts<MQL_Parser::MultiplicativeExprContext>();
}

MQL_Parser::MultiplicativeExprContext* MQL_Parser::AdditiveExprContext::multiplicativeExpr(size_t i) {
  return getRuleContext<MQL_Parser::MultiplicativeExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::AdditiveExprContext::PLUS() {
  return getTokens(MQL_Parser::PLUS);
}

tree::TerminalNode* MQL_Parser::AdditiveExprContext::PLUS(size_t i) {
  return getToken(MQL_Parser::PLUS, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::AdditiveExprContext::MINUS() {
  return getTokens(MQL_Parser::MINUS);
}

tree::TerminalNode* MQL_Parser::AdditiveExprContext::MINUS(size_t i) {
  return getToken(MQL_Parser::MINUS, i);
}


size_t MQL_Parser::AdditiveExprContext::getRuleIndex() const {
  return MQL_Parser::RuleAdditiveExpr;
}


std::any MQL_Parser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::AdditiveExprContext* MQL_Parser::additiveExpr() {
  AdditiveExprContext *_localctx = _tracker.createInstance<AdditiveExprContext>(_ctx, getState());
  enterRule(_localctx, 122, MQL_Parser::RuleAdditiveExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(779);
    multiplicativeExpr();
    setState(784);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(780);
      antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1491 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::PLUS

      || _la == MQL_Parser::MINUS)) {
        antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1491 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1491);
      setState(781);
      multiplicativeExpr();
      setState(786);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExprContext ------------------------------------------------------------------

MQL_Parser::MultiplicativeExprContext::MultiplicativeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MQL_Parser::UnaryExprContext *> MQL_Parser::MultiplicativeExprContext::unaryExpr() {
  return getRuleContexts<MQL_Parser::UnaryExprContext>();
}

MQL_Parser::UnaryExprContext* MQL_Parser::MultiplicativeExprContext::unaryExpr(size_t i) {
  return getRuleContext<MQL_Parser::UnaryExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::MultiplicativeExprContext::STAR() {
  return getTokens(MQL_Parser::STAR);
}

tree::TerminalNode* MQL_Parser::MultiplicativeExprContext::STAR(size_t i) {
  return getToken(MQL_Parser::STAR, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::MultiplicativeExprContext::PATH_SEQUENCE() {
  return getTokens(MQL_Parser::PATH_SEQUENCE);
}

tree::TerminalNode* MQL_Parser::MultiplicativeExprContext::PATH_SEQUENCE(size_t i) {
  return getToken(MQL_Parser::PATH_SEQUENCE, i);
}

std::vector<tree::TerminalNode *> MQL_Parser::MultiplicativeExprContext::PERCENT() {
  return getTokens(MQL_Parser::PERCENT);
}

tree::TerminalNode* MQL_Parser::MultiplicativeExprContext::PERCENT(size_t i) {
  return getToken(MQL_Parser::PERCENT, i);
}


size_t MQL_Parser::MultiplicativeExprContext::getRuleIndex() const {
  return MQL_Parser::RuleMultiplicativeExpr;
}


std::any MQL_Parser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::MultiplicativeExprContext* MQL_Parser::multiplicativeExpr() {
  MultiplicativeExprContext *_localctx = _tracker.createInstance<MultiplicativeExprContext>(_ctx, getState());
  enterRule(_localctx, 124, MQL_Parser::RuleMultiplicativeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(787);
    unaryExpr();
    setState(792);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & 25) != 0)) {
      setState(788);
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1510 = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & 25) != 0))) {
        antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1510 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1510);
      setState(789);
      unaryExpr();
      setState(794);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

MQL_Parser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::UnaryExprContext::K_NOT() {
  return getToken(MQL_Parser::K_NOT, 0);
}

MQL_Parser::UnaryExprContext* MQL_Parser::UnaryExprContext::unaryExpr() {
  return getRuleContext<MQL_Parser::UnaryExprContext>(0);
}

MQL_Parser::AtomicExprContext* MQL_Parser::UnaryExprContext::atomicExpr() {
  return getRuleContext<MQL_Parser::AtomicExprContext>(0);
}

tree::TerminalNode* MQL_Parser::UnaryExprContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
}

tree::TerminalNode* MQL_Parser::UnaryExprContext::MINUS() {
  return getToken(MQL_Parser::MINUS, 0);
}


size_t MQL_Parser::UnaryExprContext::getRuleIndex() const {
  return MQL_Parser::RuleUnaryExpr;
}


std::any MQL_Parser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::UnaryExprContext* MQL_Parser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 126, MQL_Parser::RuleUnaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(802);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(795);
      match(MQL_Parser::K_NOT);
      setState(796);
      unaryExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(797);
      atomicExpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(798);
      match(MQL_Parser::PLUS);
      setState(799);
      unaryExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(800);
      match(MQL_Parser::MINUS);
      setState(801);
      unaryExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicExprContext ------------------------------------------------------------------

MQL_Parser::AtomicExprContext::AtomicExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MQL_Parser::AtomicExprContext::getRuleIndex() const {
  return MQL_Parser::RuleAtomicExpr;
}

void MQL_Parser::AtomicExprContext::copyFrom(AtomicExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprFunctionContext ------------------------------------------------------------------

MQL_Parser::FunctionContext* MQL_Parser::ExprFunctionContext::function() {
  return getRuleContext<MQL_Parser::FunctionContext>(0);
}

MQL_Parser::ExprFunctionContext::ExprFunctionContext(AtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ExprFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprFunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprValueContext ------------------------------------------------------------------

MQL_Parser::ValueContext* MQL_Parser::ExprValueContext::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}

MQL_Parser::ExprValueContext::ExprValueContext(AtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ExprValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ExprVarContext::VARIABLE() {
  return getToken(MQL_Parser::VARIABLE, 0);
}

tree::TerminalNode* MQL_Parser::ExprVarContext::KEY() {
  return getToken(MQL_Parser::KEY, 0);
}

MQL_Parser::ExprVarContext::ExprVarContext(AtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* MQL_Parser::ExprParenthesisContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::ConditionalOrExprContext* MQL_Parser::ExprParenthesisContext::conditionalOrExpr() {
  return getRuleContext<MQL_Parser::ConditionalOrExprContext>(0);
}

tree::TerminalNode* MQL_Parser::ExprParenthesisContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::ExprParenthesisContext::ExprParenthesisContext(AtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
MQL_Parser::AtomicExprContext* MQL_Parser::atomicExpr() {
  AtomicExprContext *_localctx = _tracker.createInstance<AtomicExprContext>(_ctx, getState());
  enterRule(_localctx, 128, MQL_Parser::RuleAtomicExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(814);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(804);
        match(MQL_Parser::VARIABLE);
        setState(806);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(805);
          match(MQL_Parser::KEY);
        }
        break;
      }

      case MQL_Parser::K_ACYCLIC:
      case MQL_Parser::K_AND:
      case MQL_Parser::K_ANGULAR:
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_AVG:
      case MQL_Parser::K_ALL:
      case MQL_Parser::K_ASC:
      case MQL_Parser::K_BY:
      case MQL_Parser::K_BOOL:
      case MQL_Parser::K_COUNT:
      case MQL_Parser::K_DELETE:
      case MQL_Parser::K_DESCRIBE:
      case MQL_Parser::K_DESC:
      case MQL_Parser::K_DISTINCT:
      case MQL_Parser::K_EDGE:
      case MQL_Parser::K_EUCLIDEAN:
      case MQL_Parser::K_INCOMING:
      case MQL_Parser::K_INSERT:
      case MQL_Parser::K_INTEGER:
      case MQL_Parser::K_IS:
      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_FLOAT:
      case MQL_Parser::K_GROUP:
      case MQL_Parser::K_LABELS:
      case MQL_Parser::K_LABEL:
      case MQL_Parser::K_LIMIT:
      case MQL_Parser::K_MANHATTAN:
      case MQL_Parser::K_MATCH:
      case MQL_Parser::K_MAX:
      case MQL_Parser::K_MIN:
      case MQL_Parser::K_OFFSET:
      case MQL_Parser::K_OPTIONAL:
      case MQL_Parser::K_ORDER:
      case MQL_Parser::K_OR:
      case MQL_Parser::K_OUTGOING:
      case MQL_Parser::K_PROPERTIES:
      case MQL_Parser::K_PROPERTY:
      case MQL_Parser::K_NOT:
      case MQL_Parser::K_NULL:
      case MQL_Parser::K_SHORTEST:
      case MQL_Parser::K_SIMPLE:
      case MQL_Parser::K_RETURN:
      case MQL_Parser::K_SET:
      case MQL_Parser::K_SIMILARITY_SEARCH:
      case MQL_Parser::K_SUM:
      case MQL_Parser::K_STRING:
      case MQL_Parser::K_TRUE:
      case MQL_Parser::K_TRAILS:
      case MQL_Parser::K_WALKS:
      case MQL_Parser::K_WHERE:
      case MQL_Parser::DATA_TEST:
      case MQL_Parser::STRING:
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::NAME:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprValueContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(808);
        value();
        break;
      }

      case MQL_Parser::L_PAR: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprParenthesisContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(809);
        match(MQL_Parser::L_PAR);
        setState(810);
        conditionalOrExpr();
        setState(811);
        match(MQL_Parser::R_PAR);
        break;
      }

      case MQL_Parser::K_REGEX: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprFunctionContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(813);
        function();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

MQL_Parser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MQL_Parser::RegexContext* MQL_Parser::FunctionContext::regex() {
  return getRuleContext<MQL_Parser::RegexContext>(0);
}


size_t MQL_Parser::FunctionContext::getRuleIndex() const {
  return MQL_Parser::RuleFunction;
}


std::any MQL_Parser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::FunctionContext* MQL_Parser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 130, MQL_Parser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(816);
    regex();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegexContext ------------------------------------------------------------------

MQL_Parser::RegexContext::RegexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::RegexContext::K_REGEX() {
  return getToken(MQL_Parser::K_REGEX, 0);
}

tree::TerminalNode* MQL_Parser::RegexContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

std::vector<MQL_Parser::ConditionalOrExprContext *> MQL_Parser::RegexContext::conditionalOrExpr() {
  return getRuleContexts<MQL_Parser::ConditionalOrExprContext>();
}

MQL_Parser::ConditionalOrExprContext* MQL_Parser::RegexContext::conditionalOrExpr(size_t i) {
  return getRuleContext<MQL_Parser::ConditionalOrExprContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::RegexContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::RegexContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

tree::TerminalNode* MQL_Parser::RegexContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}


size_t MQL_Parser::RegexContext::getRuleIndex() const {
  return MQL_Parser::RuleRegex;
}


std::any MQL_Parser::RegexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitRegex(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::RegexContext* MQL_Parser::regex() {
  RegexContext *_localctx = _tracker.createInstance<RegexContext>(_ctx, getState());
  enterRule(_localctx, 132, MQL_Parser::RuleRegex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(818);
    match(MQL_Parser::K_REGEX);
    setState(819);
    match(MQL_Parser::L_PAR);
    setState(820);
    conditionalOrExpr();
    setState(821);
    match(MQL_Parser::COMMA);
    setState(822);
    conditionalOrExpr();
    setState(825);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::COMMA) {
      setState(823);
      match(MQL_Parser::COMMA);
      setState(824);
      conditionalOrExpr();
    }
    setState(827);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprTypenameContext ------------------------------------------------------------------

MQL_Parser::ExprTypenameContext::ExprTypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ExprTypenameContext::K_NULL() {
  return getToken(MQL_Parser::K_NULL, 0);
}

tree::TerminalNode* MQL_Parser::ExprTypenameContext::K_STRING() {
  return getToken(MQL_Parser::K_STRING, 0);
}

tree::TerminalNode* MQL_Parser::ExprTypenameContext::K_BOOL() {
  return getToken(MQL_Parser::K_BOOL, 0);
}

tree::TerminalNode* MQL_Parser::ExprTypenameContext::K_INTEGER() {
  return getToken(MQL_Parser::K_INTEGER, 0);
}

tree::TerminalNode* MQL_Parser::ExprTypenameContext::K_FLOAT() {
  return getToken(MQL_Parser::K_FLOAT, 0);
}


size_t MQL_Parser::ExprTypenameContext::getRuleIndex() const {
  return MQL_Parser::RuleExprTypename;
}


std::any MQL_Parser::ExprTypenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprTypename(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ExprTypenameContext* MQL_Parser::exprTypename() {
  ExprTypenameContext *_localctx = _tracker.createInstance<ExprTypenameContext>(_ctx, getState());
  enterRule(_localctx, 134, MQL_Parser::RuleExprTypename);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(829);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 565148986115072) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

MQL_Parser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ACYCLIC() {
  return getToken(MQL_Parser::K_ACYCLIC, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_AND() {
  return getToken(MQL_Parser::K_AND, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ANGULAR() {
  return getToken(MQL_Parser::K_ANGULAR, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ANY() {
  return getToken(MQL_Parser::K_ANY, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ALL() {
  return getToken(MQL_Parser::K_ALL, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_AVG() {
  return getToken(MQL_Parser::K_AVG, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ASC() {
  return getToken(MQL_Parser::K_ASC, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_BY() {
  return getToken(MQL_Parser::K_BY, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_BOOL() {
  return getToken(MQL_Parser::K_BOOL, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_COUNT() {
  return getToken(MQL_Parser::K_COUNT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_DELETE() {
  return getToken(MQL_Parser::K_DELETE, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_DESCRIBE() {
  return getToken(MQL_Parser::K_DESCRIBE, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_DESC() {
  return getToken(MQL_Parser::K_DESC, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_DISTINCT() {
  return getToken(MQL_Parser::K_DISTINCT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_EDGE() {
  return getToken(MQL_Parser::K_EDGE, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_EUCLIDEAN() {
  return getToken(MQL_Parser::K_EUCLIDEAN, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_INCOMING() {
  return getToken(MQL_Parser::K_INCOMING, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_INSERT() {
  return getToken(MQL_Parser::K_INSERT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_INTEGER() {
  return getToken(MQL_Parser::K_INTEGER, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_IS() {
  return getToken(MQL_Parser::K_IS, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_FLOAT() {
  return getToken(MQL_Parser::K_FLOAT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_GROUP() {
  return getToken(MQL_Parser::K_GROUP, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_LABELS() {
  return getToken(MQL_Parser::K_LABELS, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_LABEL() {
  return getToken(MQL_Parser::K_LABEL, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_LIMIT() {
  return getToken(MQL_Parser::K_LIMIT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_MANHATTAN() {
  return getToken(MQL_Parser::K_MANHATTAN, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_MATCH() {
  return getToken(MQL_Parser::K_MATCH, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_MAX() {
  return getToken(MQL_Parser::K_MAX, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_MIN() {
  return getToken(MQL_Parser::K_MIN, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_OFFSET() {
  return getToken(MQL_Parser::K_OFFSET, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_OPTIONAL() {
  return getToken(MQL_Parser::K_OPTIONAL, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_ORDER() {
  return getToken(MQL_Parser::K_ORDER, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_OR() {
  return getToken(MQL_Parser::K_OR, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_OUTGOING() {
  return getToken(MQL_Parser::K_OUTGOING, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_PROPERTIES() {
  return getToken(MQL_Parser::K_PROPERTIES, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_PROPERTY() {
  return getToken(MQL_Parser::K_PROPERTY, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_NOT() {
  return getToken(MQL_Parser::K_NOT, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_NULL() {
  return getToken(MQL_Parser::K_NULL, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_SHORTEST() {
  return getToken(MQL_Parser::K_SHORTEST, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_SIMPLE() {
  return getToken(MQL_Parser::K_SIMPLE, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_RETURN() {
  return getToken(MQL_Parser::K_RETURN, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_SET() {
  return getToken(MQL_Parser::K_SET, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_SIMILARITY_SEARCH() {
  return getToken(MQL_Parser::K_SIMILARITY_SEARCH, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_SUM() {
  return getToken(MQL_Parser::K_SUM, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_STRING() {
  return getToken(MQL_Parser::K_STRING, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_TRAILS() {
  return getToken(MQL_Parser::K_TRAILS, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_WALKS() {
  return getToken(MQL_Parser::K_WALKS, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::K_WHERE() {
  return getToken(MQL_Parser::K_WHERE, 0);
}

tree::TerminalNode* MQL_Parser::KeywordContext::DATA_TEST() {
  return getToken(MQL_Parser::DATA_TEST, 0);
}


size_t MQL_Parser::KeywordContext::getRuleIndex() const {
  return MQL_Parser::RuleKeyword;
}


std::any MQL_Parser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::KeywordContext* MQL_Parser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 136, MQL_Parser::RuleKeyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(831);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34885167482928894) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MQL_Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mql_parserParserInitialize();
#else
  ::antlr4::internal::call_once(mql_parserParserOnceFlag, mql_parserParserInitialize);
#endif
}
