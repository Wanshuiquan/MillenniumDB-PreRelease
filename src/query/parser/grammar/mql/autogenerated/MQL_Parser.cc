
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
      "root", "matchQuery", "projectSimilarity", "metricType", "describeQuery", 
      "describeFlag", "insertQuery", "insertLabelList", "insertPropertyList", 
      "insertEdgeList", "insertLabelElement", "insertPropertyElement", "insertEdgeElement", 
      "setStatement", "matchStatement", "whereStatement", "groupByStatement", 
      "orderByStatement", "returnStatement", "setItem", "returnItem", "aggregateFunc", 
      "orderByItem", "groupByItem", "graphPattern", "optionalPattern", "similaritySearch", 
      "tensor", "basicPattern", "linearPattern", "path", "pathAlternatives", 
      "pathSequence", "pathAtom", "object", "pathSuffix", "pathType", "node", 
      "fixedNode", "fixedNodeInside", "edge", "edgeInside", "varNode", "properties", 
      "property", "identifier", "boolValue", "numericValue", "datatypeValue", 
      "value", "conditionalOrExpr", "conditionalAndExpr", "comparisonExpr", 
      "additiveExpr", "multiplicativeExpr", "unaryExpr", "atomicExpr", "valueExpr", 
      "exprTypename", "keyword"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "'false'", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'true'", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "'<='", "'>='", "'=='", "'!='", "'<'", "'>'", "'='", "'/'", "'|'", 
      "'^'", "'*'", "'%'", "'\\u003F'", "'+'", "'-'", "'('", "')'", "'{'", 
      "'}'", "'['", "']'", "','", "':'"
    },
    std::vector<std::string>{
      "", "K_ACYCLIC", "K_AND", "K_ANGULAR", "K_ANY", "K_AVG", "K_ALL", 
      "K_ASC", "K_BY", "K_BOOL", "K_COUNT", "K_DESCRIBE", "K_DESC", "K_DISTINCT", 
      "K_EDGE", "K_EUCLIDEAN", "K_INCOMING", "K_INSERT", "K_INTEGER", "K_IS", 
      "K_FALSE", "K_FLOAT", "K_GROUP", "K_LABELS", "K_LABEL", "K_LIMIT", 
      "K_MANHATTAN", "K_MATCH", "K_MAX", "K_MIN", "K_OPTIONAL", "K_ORDER", 
      "K_OR", "K_OUTGOING", "K_PROJECT_SIMILARITY", "K_PROPERTIES", "K_PROPERTY", 
      "K_NOT", "K_NULL", "K_SHORTEST", "K_SIMPLE", "K_RETURN", "K_SET", 
      "K_SIMILARITY_SEARCH", "K_SUM", "K_STRING", "K_TRUE", "K_TRAILS", 
      "K_WALKS", "K_WHERE", "DATA_TEST", "TRUE_PROP", "FALSE_PROP", "ANON_ID", 
      "EDGE_ID", "KEY", "TYPE", "TYPE_VAR", "VARIABLE", "STRING", "UNSIGNED_INTEGER", 
      "UNSIGNED_FLOAT", "UNSIGNED_SCIENTIFIC_NOTATION", "NAME", "LEQ", "GEQ", 
      "EQ", "NEQ", "LT", "GT", "SINGLE_EQ", "PATH_SEQUENCE", "PATH_ALTERNATIVE", 
      "PATH_NEGATION", "STAR", "PERCENT", "QUESTION_MARK", "PLUS", "MINUS", 
      "L_PAR", "R_PAR", "LCURLY_BRACKET", "RCURLY_BRACKET", "LSQUARE_BRACKET", 
      "RSQUARE_BRACKET", "COMMA", "COLON", "WHITE_SPACE", "SINGLE_LINE_COMMENT", 
      "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,89,709,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,1,0,3,0,122,8,0,1,0,1,0,1,0,3,0,127,
  	8,0,1,0,1,0,1,1,1,1,3,1,133,8,1,1,1,3,1,136,8,1,1,1,3,1,139,8,1,1,1,3,
  	1,142,8,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,156,8,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,5,4,166,8,4,10,4,12,4,169,9,4,1,4,1,4,
  	1,5,1,5,1,5,3,5,176,8,5,1,6,1,6,1,6,1,6,3,6,182,8,6,1,7,1,7,1,7,1,7,5,
  	7,188,8,7,10,7,12,7,191,9,7,1,8,1,8,1,8,1,8,5,8,197,8,8,10,8,12,8,200,
  	9,8,1,9,1,9,1,9,1,9,5,9,206,8,9,10,9,12,9,209,9,9,1,10,1,10,1,10,3,10,
  	214,8,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,5,13,240,
  	8,13,10,13,12,13,243,9,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,
  	1,16,1,16,5,16,256,8,16,10,16,12,16,259,9,16,1,17,1,17,1,17,1,17,1,17,
  	5,17,266,8,17,10,17,12,17,269,9,17,1,18,1,18,3,18,273,8,18,1,18,1,18,
  	1,18,5,18,278,8,18,10,18,12,18,281,9,18,1,18,1,18,3,18,285,8,18,1,18,
  	1,18,3,18,289,8,18,1,18,1,18,1,18,3,18,294,8,18,3,18,296,8,18,1,19,1,
  	19,1,19,1,19,1,20,1,20,3,20,304,8,20,1,20,1,20,1,20,1,20,3,20,310,8,20,
  	1,20,1,20,1,20,1,20,1,20,3,20,317,8,20,1,20,1,20,3,20,321,8,20,1,20,3,
  	20,324,8,20,1,20,3,20,327,8,20,1,21,1,21,1,22,1,22,3,22,333,8,22,1,22,
  	3,22,336,8,22,1,22,1,22,1,22,1,22,3,22,342,8,22,1,22,1,22,3,22,346,8,
  	22,1,22,1,22,1,22,3,22,351,8,22,1,22,1,22,3,22,355,8,22,1,22,1,22,3,22,
  	359,8,22,3,22,361,8,22,1,23,1,23,3,23,365,8,23,1,24,1,24,5,24,369,8,24,
  	10,24,12,24,372,9,24,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,3,26,389,8,26,1,26,1,26,3,26,393,8,26,1,26,1,
  	26,1,26,1,27,1,27,1,27,1,27,5,27,402,8,27,10,27,12,27,405,9,27,1,27,1,
  	27,1,28,1,28,1,28,5,28,412,8,28,10,28,12,28,415,9,28,1,29,1,29,1,29,3,
  	29,420,8,29,1,29,1,29,5,29,424,8,29,10,29,12,29,427,9,29,1,29,3,29,430,
  	8,29,1,30,1,30,1,30,3,30,435,8,30,1,30,3,30,438,8,30,1,30,1,30,1,30,1,
  	30,1,30,1,30,1,30,3,30,447,8,30,1,30,3,30,450,8,30,1,30,1,30,1,30,1,30,
  	1,30,3,30,457,8,30,1,31,1,31,1,31,5,31,462,8,31,10,31,12,31,465,9,31,
  	1,32,1,32,1,32,5,32,470,8,32,10,32,12,32,473,9,32,1,33,3,33,476,8,33,
  	1,33,1,33,3,33,480,8,33,1,33,3,33,483,8,33,1,33,1,33,1,33,1,33,3,33,489,
  	8,33,1,33,3,33,492,8,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,500,8,33,3,
  	33,502,8,33,1,34,1,34,3,34,506,8,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,3,35,516,8,35,1,36,1,36,3,36,520,8,36,1,36,3,36,523,8,36,1,36,3,
  	36,526,8,36,1,37,1,37,3,37,530,8,37,1,38,1,38,1,38,1,38,1,39,1,39,1,39,
  	1,39,3,39,540,8,39,1,40,1,40,1,40,3,40,545,8,40,1,40,1,40,1,40,1,40,1,
  	40,3,40,552,8,40,1,40,3,40,555,8,40,1,41,1,41,3,41,559,8,41,1,41,3,41,
  	562,8,41,1,41,3,41,565,8,41,1,41,1,41,1,42,1,42,3,42,571,8,42,1,42,5,
  	42,574,8,42,10,42,12,42,577,9,42,1,42,3,42,580,8,42,1,42,1,42,1,43,1,
  	43,1,43,1,43,5,43,588,8,43,10,43,12,43,591,9,43,1,43,1,43,1,44,1,44,1,
  	44,1,44,1,44,3,44,600,8,44,1,44,1,44,1,44,1,44,1,44,1,44,3,44,608,8,44,
  	1,45,1,45,3,45,612,8,45,1,46,1,46,1,47,3,47,617,8,47,1,47,1,47,1,48,1,
  	48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,3,49,630,8,49,1,50,1,50,1,50,5,
  	50,635,8,50,10,50,12,50,638,9,50,1,51,1,51,1,51,5,51,643,8,51,10,51,12,
  	51,646,9,51,1,52,1,52,1,52,3,52,651,8,52,1,52,1,52,1,52,3,52,656,8,52,
  	1,52,1,52,3,52,660,8,52,1,53,1,53,1,53,5,53,665,8,53,10,53,12,53,668,
  	9,53,1,54,1,54,1,54,5,54,673,8,54,10,54,12,54,676,9,54,1,55,1,55,1,55,
  	1,55,1,55,1,55,1,55,3,55,685,8,55,1,56,1,56,3,56,689,8,56,1,56,1,56,1,
  	56,1,56,1,56,3,56,696,8,56,1,57,1,57,1,57,1,57,1,57,3,57,703,8,57,1,58,
  	1,58,1,59,1,59,1,59,0,0,60,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,
  	78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,
  	118,0,15,3,0,3,3,15,15,26,26,4,0,16,16,23,23,33,33,35,35,3,0,5,5,28,29,
  	44,44,2,0,7,7,12,12,1,0,77,78,2,0,4,4,6,6,3,0,1,1,40,40,47,48,2,0,54,
  	54,58,58,1,0,56,57,2,0,20,20,46,46,1,0,60,62,1,0,64,69,2,0,71,71,74,75,
  	5,0,9,9,18,18,21,21,38,38,45,45,4,0,1,19,21,33,35,45,47,50,759,0,121,
  	1,0,0,0,2,130,1,0,0,0,4,145,1,0,0,0,6,161,1,0,0,0,8,163,1,0,0,0,10,172,
  	1,0,0,0,12,177,1,0,0,0,14,183,1,0,0,0,16,192,1,0,0,0,18,201,1,0,0,0,20,
  	210,1,0,0,0,22,219,1,0,0,0,24,227,1,0,0,0,26,235,1,0,0,0,28,244,1,0,0,
  	0,30,247,1,0,0,0,32,250,1,0,0,0,34,260,1,0,0,0,36,295,1,0,0,0,38,297,
  	1,0,0,0,40,326,1,0,0,0,42,328,1,0,0,0,44,360,1,0,0,0,46,362,1,0,0,0,48,
  	366,1,0,0,0,50,373,1,0,0,0,52,378,1,0,0,0,54,397,1,0,0,0,56,408,1,0,0,
  	0,58,429,1,0,0,0,60,456,1,0,0,0,62,458,1,0,0,0,64,466,1,0,0,0,66,501,
  	1,0,0,0,68,505,1,0,0,0,70,515,1,0,0,0,72,525,1,0,0,0,74,529,1,0,0,0,76,
  	531,1,0,0,0,78,539,1,0,0,0,80,554,1,0,0,0,82,556,1,0,0,0,84,568,1,0,0,
  	0,86,583,1,0,0,0,88,607,1,0,0,0,90,611,1,0,0,0,92,613,1,0,0,0,94,616,
  	1,0,0,0,96,620,1,0,0,0,98,629,1,0,0,0,100,631,1,0,0,0,102,639,1,0,0,0,
  	104,659,1,0,0,0,106,661,1,0,0,0,108,669,1,0,0,0,110,684,1,0,0,0,112,695,
  	1,0,0,0,114,702,1,0,0,0,116,704,1,0,0,0,118,706,1,0,0,0,120,122,3,26,
  	13,0,121,120,1,0,0,0,121,122,1,0,0,0,122,126,1,0,0,0,123,127,3,2,1,0,
  	124,127,3,8,4,0,125,127,3,12,6,0,126,123,1,0,0,0,126,124,1,0,0,0,126,
  	125,1,0,0,0,127,128,1,0,0,0,128,129,5,0,0,1,129,1,1,0,0,0,130,132,3,28,
  	14,0,131,133,3,4,2,0,132,131,1,0,0,0,132,133,1,0,0,0,133,135,1,0,0,0,
  	134,136,3,30,15,0,135,134,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,
  	139,3,32,16,0,138,137,1,0,0,0,138,139,1,0,0,0,139,141,1,0,0,0,140,142,
  	3,34,17,0,141,140,1,0,0,0,141,142,1,0,0,0,142,143,1,0,0,0,143,144,3,36,
  	18,0,144,3,1,0,0,0,145,146,5,34,0,0,146,147,5,79,0,0,147,148,5,58,0,0,
  	148,149,5,85,0,0,149,150,5,58,0,0,150,151,5,85,0,0,151,152,5,59,0,0,152,
  	155,5,85,0,0,153,156,3,78,39,0,154,156,3,54,27,0,155,153,1,0,0,0,155,
  	154,1,0,0,0,156,157,1,0,0,0,157,158,5,85,0,0,158,159,3,6,3,0,159,160,
  	5,80,0,0,160,5,1,0,0,0,161,162,7,0,0,0,162,7,1,0,0,0,163,167,5,11,0,0,
  	164,166,3,10,5,0,165,164,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,
  	168,1,0,0,0,168,170,1,0,0,0,169,167,1,0,0,0,170,171,3,78,39,0,171,9,1,
  	0,0,0,172,175,7,1,0,0,173,174,5,25,0,0,174,176,5,60,0,0,175,173,1,0,0,
  	0,175,176,1,0,0,0,176,11,1,0,0,0,177,181,5,17,0,0,178,182,3,14,7,0,179,
  	182,3,16,8,0,180,182,3,18,9,0,181,178,1,0,0,0,181,179,1,0,0,0,181,180,
  	1,0,0,0,182,13,1,0,0,0,183,184,5,24,0,0,184,189,3,20,10,0,185,186,5,85,
  	0,0,186,188,3,20,10,0,187,185,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,
  	189,190,1,0,0,0,190,15,1,0,0,0,191,189,1,0,0,0,192,193,5,36,0,0,193,198,
  	3,22,11,0,194,195,5,85,0,0,195,197,3,22,11,0,196,194,1,0,0,0,197,200,
  	1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,17,1,0,0,0,200,198,1,0,0,
  	0,201,202,5,14,0,0,202,207,3,24,12,0,203,204,5,85,0,0,204,206,3,24,12,
  	0,205,203,1,0,0,0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,
  	19,1,0,0,0,209,207,1,0,0,0,210,213,5,79,0,0,211,214,3,90,45,0,212,214,
  	5,53,0,0,213,211,1,0,0,0,213,212,1,0,0,0,214,215,1,0,0,0,215,216,5,85,
  	0,0,216,217,5,59,0,0,217,218,5,80,0,0,218,21,1,0,0,0,219,220,5,79,0,0,
  	220,221,3,78,39,0,221,222,5,85,0,0,222,223,5,59,0,0,223,224,5,85,0,0,
  	224,225,3,98,49,0,225,226,5,80,0,0,226,23,1,0,0,0,227,228,5,79,0,0,228,
  	229,3,78,39,0,229,230,5,85,0,0,230,231,3,78,39,0,231,232,5,85,0,0,232,
  	233,3,90,45,0,233,234,5,80,0,0,234,25,1,0,0,0,235,236,5,42,0,0,236,241,
  	3,38,19,0,237,238,5,85,0,0,238,240,3,38,19,0,239,237,1,0,0,0,240,243,
  	1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,27,1,0,0,0,243,241,1,0,0,
  	0,244,245,5,27,0,0,245,246,3,48,24,0,246,29,1,0,0,0,247,248,5,49,0,0,
  	248,249,3,100,50,0,249,31,1,0,0,0,250,251,5,22,0,0,251,252,5,8,0,0,252,
  	257,3,46,23,0,253,254,5,85,0,0,254,256,3,46,23,0,255,253,1,0,0,0,256,
  	259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,33,1,0,0,0,259,257,1,
  	0,0,0,260,261,5,31,0,0,261,262,5,8,0,0,262,267,3,44,22,0,263,264,5,85,
  	0,0,264,266,3,44,22,0,265,263,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,0,
  	267,268,1,0,0,0,268,35,1,0,0,0,269,267,1,0,0,0,270,272,5,41,0,0,271,273,
  	5,13,0,0,272,271,1,0,0,0,272,273,1,0,0,0,273,274,1,0,0,0,274,279,3,40,
  	20,0,275,276,5,85,0,0,276,278,3,40,20,0,277,275,1,0,0,0,278,281,1,0,0,
  	0,279,277,1,0,0,0,279,280,1,0,0,0,280,284,1,0,0,0,281,279,1,0,0,0,282,
  	283,5,25,0,0,283,285,5,60,0,0,284,282,1,0,0,0,284,285,1,0,0,0,285,296,
  	1,0,0,0,286,288,5,41,0,0,287,289,5,13,0,0,288,287,1,0,0,0,288,289,1,0,
  	0,0,289,290,1,0,0,0,290,293,5,74,0,0,291,292,5,25,0,0,292,294,5,60,0,
  	0,293,291,1,0,0,0,293,294,1,0,0,0,294,296,1,0,0,0,295,270,1,0,0,0,295,
  	286,1,0,0,0,296,37,1,0,0,0,297,298,5,58,0,0,298,299,5,70,0,0,299,300,
  	3,78,39,0,300,39,1,0,0,0,301,303,5,58,0,0,302,304,5,55,0,0,303,302,1,
  	0,0,0,303,304,1,0,0,0,304,327,1,0,0,0,305,306,3,42,21,0,306,307,5,79,
  	0,0,307,309,5,58,0,0,308,310,5,55,0,0,309,308,1,0,0,0,309,310,1,0,0,0,
  	310,311,1,0,0,0,311,312,5,80,0,0,312,327,1,0,0,0,313,314,5,10,0,0,314,
  	316,5,79,0,0,315,317,5,13,0,0,316,315,1,0,0,0,316,317,1,0,0,0,317,323,
  	1,0,0,0,318,320,5,58,0,0,319,321,5,55,0,0,320,319,1,0,0,0,320,321,1,0,
  	0,0,321,324,1,0,0,0,322,324,5,74,0,0,323,318,1,0,0,0,323,322,1,0,0,0,
  	324,325,1,0,0,0,325,327,5,80,0,0,326,301,1,0,0,0,326,305,1,0,0,0,326,
  	313,1,0,0,0,327,41,1,0,0,0,328,329,7,2,0,0,329,43,1,0,0,0,330,332,5,58,
  	0,0,331,333,5,55,0,0,332,331,1,0,0,0,332,333,1,0,0,0,333,335,1,0,0,0,
  	334,336,7,3,0,0,335,334,1,0,0,0,335,336,1,0,0,0,336,361,1,0,0,0,337,338,
  	3,42,21,0,338,339,5,79,0,0,339,341,5,58,0,0,340,342,5,55,0,0,341,340,
  	1,0,0,0,341,342,1,0,0,0,342,343,1,0,0,0,343,345,5,80,0,0,344,346,7,3,
  	0,0,345,344,1,0,0,0,345,346,1,0,0,0,346,361,1,0,0,0,347,348,5,10,0,0,
  	348,350,5,79,0,0,349,351,5,13,0,0,350,349,1,0,0,0,350,351,1,0,0,0,351,
  	352,1,0,0,0,352,354,5,58,0,0,353,355,5,55,0,0,354,353,1,0,0,0,354,355,
  	1,0,0,0,355,356,1,0,0,0,356,358,5,80,0,0,357,359,7,3,0,0,358,357,1,0,
  	0,0,358,359,1,0,0,0,359,361,1,0,0,0,360,330,1,0,0,0,360,337,1,0,0,0,360,
  	347,1,0,0,0,361,45,1,0,0,0,362,364,5,58,0,0,363,365,5,55,0,0,364,363,
  	1,0,0,0,364,365,1,0,0,0,365,47,1,0,0,0,366,370,3,56,28,0,367,369,3,50,
  	25,0,368,367,1,0,0,0,369,372,1,0,0,0,370,368,1,0,0,0,370,371,1,0,0,0,
  	371,49,1,0,0,0,372,370,1,0,0,0,373,374,5,30,0,0,374,375,5,81,0,0,375,
  	376,3,48,24,0,376,377,5,82,0,0,377,51,1,0,0,0,378,379,5,43,0,0,379,380,
  	5,79,0,0,380,381,5,58,0,0,381,382,5,85,0,0,382,383,5,58,0,0,383,384,5,
  	85,0,0,384,385,5,59,0,0,385,388,5,85,0,0,386,389,3,78,39,0,387,389,3,
  	54,27,0,388,386,1,0,0,0,388,387,1,0,0,0,389,390,1,0,0,0,390,392,5,85,
  	0,0,391,393,7,4,0,0,392,391,1,0,0,0,392,393,1,0,0,0,393,394,1,0,0,0,394,
  	395,5,60,0,0,395,396,5,80,0,0,396,53,1,0,0,0,397,398,5,83,0,0,398,403,
  	3,94,47,0,399,400,5,85,0,0,400,402,3,94,47,0,401,399,1,0,0,0,402,405,
  	1,0,0,0,403,401,1,0,0,0,403,404,1,0,0,0,404,406,1,0,0,0,405,403,1,0,0,
  	0,406,407,5,84,0,0,407,55,1,0,0,0,408,413,3,58,29,0,409,410,5,85,0,0,
  	410,412,3,58,29,0,411,409,1,0,0,0,412,415,1,0,0,0,413,411,1,0,0,0,413,
  	414,1,0,0,0,414,57,1,0,0,0,415,413,1,0,0,0,416,425,3,74,37,0,417,420,
  	3,80,40,0,418,420,3,60,30,0,419,417,1,0,0,0,419,418,1,0,0,0,420,421,1,
  	0,0,0,421,422,3,74,37,0,422,424,1,0,0,0,423,419,1,0,0,0,424,427,1,0,0,
  	0,425,423,1,0,0,0,425,426,1,0,0,0,426,430,1,0,0,0,427,425,1,0,0,0,428,
  	430,3,52,26,0,429,416,1,0,0,0,429,428,1,0,0,0,430,59,1,0,0,0,431,432,
  	5,64,0,0,432,434,5,83,0,0,433,435,3,72,36,0,434,433,1,0,0,0,434,435,1,
  	0,0,0,435,437,1,0,0,0,436,438,5,58,0,0,437,436,1,0,0,0,437,438,1,0,0,
  	0,438,439,1,0,0,0,439,440,3,62,31,0,440,441,5,84,0,0,441,442,5,70,0,0,
  	442,457,1,0,0,0,443,444,5,70,0,0,444,446,5,83,0,0,445,447,3,72,36,0,446,
  	445,1,0,0,0,446,447,1,0,0,0,447,449,1,0,0,0,448,450,5,58,0,0,449,448,
  	1,0,0,0,449,450,1,0,0,0,450,451,1,0,0,0,451,452,3,62,31,0,452,453,5,84,
  	0,0,453,454,5,70,0,0,454,455,5,69,0,0,455,457,1,0,0,0,456,431,1,0,0,0,
  	456,443,1,0,0,0,457,61,1,0,0,0,458,463,3,64,32,0,459,460,5,72,0,0,460,
  	462,3,64,32,0,461,459,1,0,0,0,462,465,1,0,0,0,463,461,1,0,0,0,463,464,
  	1,0,0,0,464,63,1,0,0,0,465,463,1,0,0,0,466,471,3,66,33,0,467,468,5,71,
  	0,0,468,470,3,66,33,0,469,467,1,0,0,0,470,473,1,0,0,0,471,469,1,0,0,0,
  	471,472,1,0,0,0,472,65,1,0,0,0,473,471,1,0,0,0,474,476,5,73,0,0,475,474,
  	1,0,0,0,475,476,1,0,0,0,476,477,1,0,0,0,477,479,5,56,0,0,478,480,3,70,
  	35,0,479,478,1,0,0,0,479,480,1,0,0,0,480,502,1,0,0,0,481,483,5,73,0,0,
  	482,481,1,0,0,0,482,483,1,0,0,0,483,484,1,0,0,0,484,485,5,79,0,0,485,
  	486,3,62,31,0,486,488,5,80,0,0,487,489,3,70,35,0,488,487,1,0,0,0,488,
  	489,1,0,0,0,489,502,1,0,0,0,490,492,5,73,0,0,491,490,1,0,0,0,491,492,
  	1,0,0,0,492,493,1,0,0,0,493,494,5,79,0,0,494,495,3,68,34,0,495,496,5,
  	85,0,0,496,497,3,102,51,0,497,499,5,80,0,0,498,500,3,70,35,0,499,498,
  	1,0,0,0,499,500,1,0,0,0,500,502,1,0,0,0,501,475,1,0,0,0,501,482,1,0,0,
  	0,501,491,1,0,0,0,502,67,1,0,0,0,503,506,5,56,0,0,504,506,3,74,37,0,505,
  	503,1,0,0,0,505,504,1,0,0,0,506,69,1,0,0,0,507,516,5,74,0,0,508,516,5,
  	77,0,0,509,516,5,76,0,0,510,511,5,81,0,0,511,512,5,60,0,0,512,513,5,85,
  	0,0,513,514,5,60,0,0,514,516,5,82,0,0,515,507,1,0,0,0,515,508,1,0,0,0,
  	515,509,1,0,0,0,515,510,1,0,0,0,516,71,1,0,0,0,517,519,7,5,0,0,518,520,
  	5,39,0,0,519,518,1,0,0,0,519,520,1,0,0,0,520,522,1,0,0,0,521,523,7,6,
  	0,0,522,521,1,0,0,0,522,523,1,0,0,0,523,526,1,0,0,0,524,526,5,50,0,0,
  	525,517,1,0,0,0,525,524,1,0,0,0,526,73,1,0,0,0,527,530,3,76,38,0,528,
  	530,3,84,42,0,529,527,1,0,0,0,529,528,1,0,0,0,530,75,1,0,0,0,531,532,
  	5,79,0,0,532,533,3,78,39,0,533,534,5,80,0,0,534,77,1,0,0,0,535,540,3,
  	90,45,0,536,540,5,53,0,0,537,540,5,54,0,0,538,540,3,98,49,0,539,535,1,
  	0,0,0,539,536,1,0,0,0,539,537,1,0,0,0,539,538,1,0,0,0,540,79,1,0,0,0,
  	541,544,5,68,0,0,542,543,5,78,0,0,543,545,3,82,41,0,544,542,1,0,0,0,544,
  	545,1,0,0,0,545,546,1,0,0,0,546,555,5,78,0,0,547,551,5,78,0,0,548,549,
  	3,82,41,0,549,550,5,78,0,0,550,552,1,0,0,0,551,548,1,0,0,0,551,552,1,
  	0,0,0,552,553,1,0,0,0,553,555,5,69,0,0,554,541,1,0,0,0,554,547,1,0,0,
  	0,555,81,1,0,0,0,556,558,5,83,0,0,557,559,7,7,0,0,558,557,1,0,0,0,558,
  	559,1,0,0,0,559,561,1,0,0,0,560,562,7,8,0,0,561,560,1,0,0,0,561,562,1,
  	0,0,0,562,564,1,0,0,0,563,565,3,86,43,0,564,563,1,0,0,0,564,565,1,0,0,
  	0,565,566,1,0,0,0,566,567,5,84,0,0,567,83,1,0,0,0,568,570,5,79,0,0,569,
  	571,5,58,0,0,570,569,1,0,0,0,570,571,1,0,0,0,571,575,1,0,0,0,572,574,
  	5,56,0,0,573,572,1,0,0,0,574,577,1,0,0,0,575,573,1,0,0,0,575,576,1,0,
  	0,0,576,579,1,0,0,0,577,575,1,0,0,0,578,580,3,86,43,0,579,578,1,0,0,0,
  	579,580,1,0,0,0,580,581,1,0,0,0,581,582,5,80,0,0,582,85,1,0,0,0,583,584,
  	5,81,0,0,584,589,3,88,44,0,585,586,5,85,0,0,586,588,3,88,44,0,587,585,
  	1,0,0,0,588,591,1,0,0,0,589,587,1,0,0,0,589,590,1,0,0,0,590,592,1,0,0,
  	0,591,589,1,0,0,0,592,593,5,82,0,0,593,87,1,0,0,0,594,599,3,90,45,0,595,
  	596,5,86,0,0,596,600,3,98,49,0,597,600,5,51,0,0,598,600,5,52,0,0,599,
  	595,1,0,0,0,599,597,1,0,0,0,599,598,1,0,0,0,600,608,1,0,0,0,601,602,3,
  	90,45,0,602,603,5,56,0,0,603,604,5,79,0,0,604,605,5,59,0,0,605,606,5,
  	80,0,0,606,608,1,0,0,0,607,594,1,0,0,0,607,601,1,0,0,0,608,89,1,0,0,0,
  	609,612,5,63,0,0,610,612,3,118,59,0,611,609,1,0,0,0,611,610,1,0,0,0,612,
  	91,1,0,0,0,613,614,7,9,0,0,614,93,1,0,0,0,615,617,7,4,0,0,616,615,1,0,
  	0,0,616,617,1,0,0,0,617,618,1,0,0,0,618,619,7,10,0,0,619,95,1,0,0,0,620,
  	621,3,90,45,0,621,622,5,79,0,0,622,623,5,59,0,0,623,624,5,80,0,0,624,
  	97,1,0,0,0,625,630,3,94,47,0,626,630,5,59,0,0,627,630,3,92,46,0,628,630,
  	3,96,48,0,629,625,1,0,0,0,629,626,1,0,0,0,629,627,1,0,0,0,629,628,1,0,
  	0,0,630,99,1,0,0,0,631,636,3,102,51,0,632,633,5,32,0,0,633,635,3,102,
  	51,0,634,632,1,0,0,0,635,638,1,0,0,0,636,634,1,0,0,0,636,637,1,0,0,0,
  	637,101,1,0,0,0,638,636,1,0,0,0,639,644,3,104,52,0,640,641,5,2,0,0,641,
  	643,3,104,52,0,642,640,1,0,0,0,643,646,1,0,0,0,644,642,1,0,0,0,644,645,
  	1,0,0,0,645,103,1,0,0,0,646,644,1,0,0,0,647,650,3,106,53,0,648,649,7,
  	11,0,0,649,651,3,106,53,0,650,648,1,0,0,0,650,651,1,0,0,0,651,660,1,0,
  	0,0,652,653,3,106,53,0,653,655,5,19,0,0,654,656,5,37,0,0,655,654,1,0,
  	0,0,655,656,1,0,0,0,656,657,1,0,0,0,657,658,3,116,58,0,658,660,1,0,0,
  	0,659,647,1,0,0,0,659,652,1,0,0,0,660,105,1,0,0,0,661,666,3,108,54,0,
  	662,663,7,4,0,0,663,665,3,108,54,0,664,662,1,0,0,0,665,668,1,0,0,0,666,
  	664,1,0,0,0,666,667,1,0,0,0,667,107,1,0,0,0,668,666,1,0,0,0,669,674,3,
  	110,55,0,670,671,7,12,0,0,671,673,3,110,55,0,672,670,1,0,0,0,673,676,
  	1,0,0,0,674,672,1,0,0,0,674,675,1,0,0,0,675,109,1,0,0,0,676,674,1,0,0,
  	0,677,678,5,37,0,0,678,685,3,110,55,0,679,680,5,77,0,0,680,685,3,110,
  	55,0,681,682,5,78,0,0,682,685,3,110,55,0,683,685,3,112,56,0,684,677,1,
  	0,0,0,684,679,1,0,0,0,684,681,1,0,0,0,684,683,1,0,0,0,685,111,1,0,0,0,
  	686,688,5,58,0,0,687,689,5,55,0,0,688,687,1,0,0,0,688,689,1,0,0,0,689,
  	696,1,0,0,0,690,696,3,114,57,0,691,692,5,79,0,0,692,693,3,100,50,0,693,
  	694,5,80,0,0,694,696,1,0,0,0,695,686,1,0,0,0,695,690,1,0,0,0,695,691,
  	1,0,0,0,696,113,1,0,0,0,697,703,5,60,0,0,698,703,5,61,0,0,699,703,5,59,
  	0,0,700,703,3,92,46,0,701,703,3,96,48,0,702,697,1,0,0,0,702,698,1,0,0,
  	0,702,699,1,0,0,0,702,700,1,0,0,0,702,701,1,0,0,0,703,115,1,0,0,0,704,
  	705,7,13,0,0,705,117,1,0,0,0,706,707,7,14,0,0,707,119,1,0,0,0,93,121,
  	126,132,135,138,141,155,167,175,181,189,198,207,213,241,257,267,272,279,
  	284,288,293,295,303,309,316,320,323,326,332,335,341,345,350,354,358,360,
  	364,370,388,392,403,413,419,425,429,434,437,446,449,456,463,471,475,479,
  	482,488,491,499,501,505,515,519,522,525,529,539,544,551,554,558,561,564,
  	570,575,579,589,599,607,611,616,629,636,644,650,655,659,666,674,684,688,
  	695,702
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

MQL_Parser::MatchQueryContext* MQL_Parser::RootContext::matchQuery() {
  return getRuleContext<MQL_Parser::MatchQueryContext>(0);
}

MQL_Parser::DescribeQueryContext* MQL_Parser::RootContext::describeQuery() {
  return getRuleContext<MQL_Parser::DescribeQueryContext>(0);
}

MQL_Parser::InsertQueryContext* MQL_Parser::RootContext::insertQuery() {
  return getRuleContext<MQL_Parser::InsertQueryContext>(0);
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
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_SET) {
      setState(120);
      setStatement();
    }
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_MATCH: {
        setState(123);
        matchQuery();
        break;
      }

      case MQL_Parser::K_DESCRIBE: {
        setState(124);
        describeQuery();
        break;
      }

      case MQL_Parser::K_INSERT: {
        setState(125);
        insertQuery();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(128);
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
    setState(130);
    matchStatement();
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_PROJECT_SIMILARITY) {
      setState(131);
      projectSimilarity();
    }
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_WHERE) {
      setState(134);
      whereStatement();
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_GROUP) {
      setState(137);
      groupByStatement();
    }
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::K_ORDER) {
      setState(140);
      orderByStatement();
    }
    setState(143);
    returnStatement();
   
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
  enterRule(_localctx, 4, MQL_Parser::RuleProjectSimilarity);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(MQL_Parser::K_PROJECT_SIMILARITY);
    setState(146);
    match(MQL_Parser::L_PAR);
    setState(147);
    match(MQL_Parser::VARIABLE);
    setState(148);
    match(MQL_Parser::COMMA);
    setState(149);
    match(MQL_Parser::VARIABLE);
    setState(150);
    match(MQL_Parser::COMMA);
    setState(151);
    match(MQL_Parser::STRING);
    setState(152);
    match(MQL_Parser::COMMA);
    setState(155);
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
        setState(153);
        fixedNodeInside();
        break;
      }

      case MQL_Parser::LSQUARE_BRACKET: {
        setState(154);
        tensor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(157);
    match(MQL_Parser::COMMA);
    setState(158);
    metricType();
    setState(159);
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
  enterRule(_localctx, 6, MQL_Parser::RuleMetricType);
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
    setState(161);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 67141640) != 0))) {
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
  enterRule(_localctx, 8, MQL_Parser::RuleDescribeQuery);

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
    setState(163);
    match(MQL_Parser::K_DESCRIBE);
    setState(167);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(164);
        describeFlag(); 
      }
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(170);
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
  enterRule(_localctx, 10, MQL_Parser::RuleDescribeFlag);
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
    setState(172);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 42958127104) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(175);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(173);
      match(MQL_Parser::K_LIMIT);
      setState(174);
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

//----------------- InsertQueryContext ------------------------------------------------------------------

MQL_Parser::InsertQueryContext::InsertQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertQueryContext::K_INSERT() {
  return getToken(MQL_Parser::K_INSERT, 0);
}

MQL_Parser::InsertLabelListContext* MQL_Parser::InsertQueryContext::insertLabelList() {
  return getRuleContext<MQL_Parser::InsertLabelListContext>(0);
}

MQL_Parser::InsertPropertyListContext* MQL_Parser::InsertQueryContext::insertPropertyList() {
  return getRuleContext<MQL_Parser::InsertPropertyListContext>(0);
}

MQL_Parser::InsertEdgeListContext* MQL_Parser::InsertQueryContext::insertEdgeList() {
  return getRuleContext<MQL_Parser::InsertEdgeListContext>(0);
}


size_t MQL_Parser::InsertQueryContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertQuery;
}


std::any MQL_Parser::InsertQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertQuery(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertQueryContext* MQL_Parser::insertQuery() {
  InsertQueryContext *_localctx = _tracker.createInstance<InsertQueryContext>(_ctx, getState());
  enterRule(_localctx, 12, MQL_Parser::RuleInsertQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(MQL_Parser::K_INSERT);
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_LABEL: {
        setState(178);
        insertLabelList();
        break;
      }

      case MQL_Parser::K_PROPERTY: {
        setState(179);
        insertPropertyList();
        break;
      }

      case MQL_Parser::K_EDGE: {
        setState(180);
        insertEdgeList();
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

//----------------- InsertLabelListContext ------------------------------------------------------------------

MQL_Parser::InsertLabelListContext::InsertLabelListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertLabelListContext::K_LABEL() {
  return getToken(MQL_Parser::K_LABEL, 0);
}

std::vector<MQL_Parser::InsertLabelElementContext *> MQL_Parser::InsertLabelListContext::insertLabelElement() {
  return getRuleContexts<MQL_Parser::InsertLabelElementContext>();
}

MQL_Parser::InsertLabelElementContext* MQL_Parser::InsertLabelListContext::insertLabelElement(size_t i) {
  return getRuleContext<MQL_Parser::InsertLabelElementContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertLabelListContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertLabelListContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::InsertLabelListContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertLabelList;
}


std::any MQL_Parser::InsertLabelListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertLabelList(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertLabelListContext* MQL_Parser::insertLabelList() {
  InsertLabelListContext *_localctx = _tracker.createInstance<InsertLabelListContext>(_ctx, getState());
  enterRule(_localctx, 14, MQL_Parser::RuleInsertLabelList);
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
    setState(183);
    match(MQL_Parser::K_LABEL);
    setState(184);
    insertLabelElement();
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(185);
      match(MQL_Parser::COMMA);
      setState(186);
      insertLabelElement();
      setState(191);
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

//----------------- InsertPropertyListContext ------------------------------------------------------------------

MQL_Parser::InsertPropertyListContext::InsertPropertyListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertPropertyListContext::K_PROPERTY() {
  return getToken(MQL_Parser::K_PROPERTY, 0);
}

std::vector<MQL_Parser::InsertPropertyElementContext *> MQL_Parser::InsertPropertyListContext::insertPropertyElement() {
  return getRuleContexts<MQL_Parser::InsertPropertyElementContext>();
}

MQL_Parser::InsertPropertyElementContext* MQL_Parser::InsertPropertyListContext::insertPropertyElement(size_t i) {
  return getRuleContext<MQL_Parser::InsertPropertyElementContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertPropertyListContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertPropertyListContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::InsertPropertyListContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPropertyList;
}


std::any MQL_Parser::InsertPropertyListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPropertyList(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPropertyListContext* MQL_Parser::insertPropertyList() {
  InsertPropertyListContext *_localctx = _tracker.createInstance<InsertPropertyListContext>(_ctx, getState());
  enterRule(_localctx, 16, MQL_Parser::RuleInsertPropertyList);
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
    setState(192);
    match(MQL_Parser::K_PROPERTY);
    setState(193);
    insertPropertyElement();
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(194);
      match(MQL_Parser::COMMA);
      setState(195);
      insertPropertyElement();
      setState(200);
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

//----------------- InsertEdgeListContext ------------------------------------------------------------------

MQL_Parser::InsertEdgeListContext::InsertEdgeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertEdgeListContext::K_EDGE() {
  return getToken(MQL_Parser::K_EDGE, 0);
}

std::vector<MQL_Parser::InsertEdgeElementContext *> MQL_Parser::InsertEdgeListContext::insertEdgeElement() {
  return getRuleContexts<MQL_Parser::InsertEdgeElementContext>();
}

MQL_Parser::InsertEdgeElementContext* MQL_Parser::InsertEdgeListContext::insertEdgeElement(size_t i) {
  return getRuleContext<MQL_Parser::InsertEdgeElementContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertEdgeListContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertEdgeListContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}


size_t MQL_Parser::InsertEdgeListContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertEdgeList;
}


std::any MQL_Parser::InsertEdgeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertEdgeList(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertEdgeListContext* MQL_Parser::insertEdgeList() {
  InsertEdgeListContext *_localctx = _tracker.createInstance<InsertEdgeListContext>(_ctx, getState());
  enterRule(_localctx, 18, MQL_Parser::RuleInsertEdgeList);
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
    setState(201);
    match(MQL_Parser::K_EDGE);
    setState(202);
    insertEdgeElement();
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(203);
      match(MQL_Parser::COMMA);
      setState(204);
      insertEdgeElement();
      setState(209);
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

//----------------- InsertLabelElementContext ------------------------------------------------------------------

MQL_Parser::InsertLabelElementContext::InsertLabelElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertLabelElementContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

tree::TerminalNode* MQL_Parser::InsertLabelElementContext::COMMA() {
  return getToken(MQL_Parser::COMMA, 0);
}

tree::TerminalNode* MQL_Parser::InsertLabelElementContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

tree::TerminalNode* MQL_Parser::InsertLabelElementContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}

MQL_Parser::IdentifierContext* MQL_Parser::InsertLabelElementContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::InsertLabelElementContext::ANON_ID() {
  return getToken(MQL_Parser::ANON_ID, 0);
}


size_t MQL_Parser::InsertLabelElementContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertLabelElement;
}


std::any MQL_Parser::InsertLabelElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertLabelElement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertLabelElementContext* MQL_Parser::insertLabelElement() {
  InsertLabelElementContext *_localctx = _tracker.createInstance<InsertLabelElementContext>(_ctx, getState());
  enterRule(_localctx, 20, MQL_Parser::RuleInsertLabelElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(MQL_Parser::L_PAR);
    setState(213);
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
        setState(211);
        identifier();
        break;
      }

      case MQL_Parser::ANON_ID: {
        setState(212);
        match(MQL_Parser::ANON_ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(215);
    match(MQL_Parser::COMMA);
    setState(216);
    match(MQL_Parser::STRING);
    setState(217);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertPropertyElementContext ------------------------------------------------------------------

MQL_Parser::InsertPropertyElementContext::InsertPropertyElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertPropertyElementContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::InsertPropertyElementContext::fixedNodeInside() {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(0);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertPropertyElementContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertPropertyElementContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

tree::TerminalNode* MQL_Parser::InsertPropertyElementContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

MQL_Parser::ValueContext* MQL_Parser::InsertPropertyElementContext::value() {
  return getRuleContext<MQL_Parser::ValueContext>(0);
}

tree::TerminalNode* MQL_Parser::InsertPropertyElementContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}


size_t MQL_Parser::InsertPropertyElementContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertPropertyElement;
}


std::any MQL_Parser::InsertPropertyElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertPropertyElement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertPropertyElementContext* MQL_Parser::insertPropertyElement() {
  InsertPropertyElementContext *_localctx = _tracker.createInstance<InsertPropertyElementContext>(_ctx, getState());
  enterRule(_localctx, 22, MQL_Parser::RuleInsertPropertyElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(MQL_Parser::L_PAR);
    setState(220);
    fixedNodeInside();
    setState(221);
    match(MQL_Parser::COMMA);
    setState(222);
    match(MQL_Parser::STRING);
    setState(223);
    match(MQL_Parser::COMMA);
    setState(224);
    value();
    setState(225);
    match(MQL_Parser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertEdgeElementContext ------------------------------------------------------------------

MQL_Parser::InsertEdgeElementContext::InsertEdgeElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::InsertEdgeElementContext::L_PAR() {
  return getToken(MQL_Parser::L_PAR, 0);
}

std::vector<MQL_Parser::FixedNodeInsideContext *> MQL_Parser::InsertEdgeElementContext::fixedNodeInside() {
  return getRuleContexts<MQL_Parser::FixedNodeInsideContext>();
}

MQL_Parser::FixedNodeInsideContext* MQL_Parser::InsertEdgeElementContext::fixedNodeInside(size_t i) {
  return getRuleContext<MQL_Parser::FixedNodeInsideContext>(i);
}

std::vector<tree::TerminalNode *> MQL_Parser::InsertEdgeElementContext::COMMA() {
  return getTokens(MQL_Parser::COMMA);
}

tree::TerminalNode* MQL_Parser::InsertEdgeElementContext::COMMA(size_t i) {
  return getToken(MQL_Parser::COMMA, i);
}

MQL_Parser::IdentifierContext* MQL_Parser::InsertEdgeElementContext::identifier() {
  return getRuleContext<MQL_Parser::IdentifierContext>(0);
}

tree::TerminalNode* MQL_Parser::InsertEdgeElementContext::R_PAR() {
  return getToken(MQL_Parser::R_PAR, 0);
}


size_t MQL_Parser::InsertEdgeElementContext::getRuleIndex() const {
  return MQL_Parser::RuleInsertEdgeElement;
}


std::any MQL_Parser::InsertEdgeElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitInsertEdgeElement(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::InsertEdgeElementContext* MQL_Parser::insertEdgeElement() {
  InsertEdgeElementContext *_localctx = _tracker.createInstance<InsertEdgeElementContext>(_ctx, getState());
  enterRule(_localctx, 24, MQL_Parser::RuleInsertEdgeElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(MQL_Parser::L_PAR);
    setState(228);
    fixedNodeInside();
    setState(229);
    match(MQL_Parser::COMMA);
    setState(230);
    fixedNodeInside();
    setState(231);
    match(MQL_Parser::COMMA);
    setState(232);
    identifier();
    setState(233);
    match(MQL_Parser::R_PAR);
   
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
  enterRule(_localctx, 26, MQL_Parser::RuleSetStatement);
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
    setState(235);
    match(MQL_Parser::K_SET);
    setState(236);
    setItem();
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(237);
      match(MQL_Parser::COMMA);
      setState(238);
      setItem();
      setState(243);
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
  enterRule(_localctx, 28, MQL_Parser::RuleMatchStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(MQL_Parser::K_MATCH);
    setState(245);
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
  enterRule(_localctx, 30, MQL_Parser::RuleWhereStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(MQL_Parser::K_WHERE);
    setState(248);
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
  enterRule(_localctx, 32, MQL_Parser::RuleGroupByStatement);
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
    setState(250);
    match(MQL_Parser::K_GROUP);
    setState(251);
    match(MQL_Parser::K_BY);
    setState(252);
    groupByItem();
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(253);
      match(MQL_Parser::COMMA);
      setState(254);
      groupByItem();
      setState(259);
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
  enterRule(_localctx, 34, MQL_Parser::RuleOrderByStatement);
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
    setState(260);
    match(MQL_Parser::K_ORDER);
    setState(261);
    match(MQL_Parser::K_BY);
    setState(262);
    orderByItem();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(263);
      match(MQL_Parser::COMMA);
      setState(264);
      orderByItem();
      setState(269);
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

tree::TerminalNode* MQL_Parser::ReturnAllContext::K_LIMIT() {
  return getToken(MQL_Parser::K_LIMIT, 0);
}

tree::TerminalNode* MQL_Parser::ReturnAllContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
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

tree::TerminalNode* MQL_Parser::ReturnListContext::K_LIMIT() {
  return getToken(MQL_Parser::K_LIMIT, 0);
}

tree::TerminalNode* MQL_Parser::ReturnListContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
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
  enterRule(_localctx, 36, MQL_Parser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::ReturnListContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(270);
      match(MQL_Parser::K_RETURN);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_DISTINCT) {
        setState(271);
        match(MQL_Parser::K_DISTINCT);
      }
      setState(274);
      returnItem();
      setState(279);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MQL_Parser::COMMA) {
        setState(275);
        match(MQL_Parser::COMMA);
        setState(276);
        returnItem();
        setState(281);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(284);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_LIMIT) {
        setState(282);
        match(MQL_Parser::K_LIMIT);
        setState(283);
        match(MQL_Parser::UNSIGNED_INTEGER);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::ReturnAllContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(286);
      match(MQL_Parser::K_RETURN);
      setState(288);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_DISTINCT) {
        setState(287);
        match(MQL_Parser::K_DISTINCT);
      }
      setState(290);
      match(MQL_Parser::STAR);
      setState(293);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_LIMIT) {
        setState(291);
        match(MQL_Parser::K_LIMIT);
        setState(292);
        match(MQL_Parser::UNSIGNED_INTEGER);
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
  enterRule(_localctx, 38, MQL_Parser::RuleSetItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(MQL_Parser::VARIABLE);
    setState(298);
    match(MQL_Parser::SINGLE_EQ);
    setState(299);
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
  enterRule(_localctx, 40, MQL_Parser::RuleReturnItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::ReturnItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(301);
        match(MQL_Parser::VARIABLE);
        setState(303);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(302);
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
        setState(305);
        aggregateFunc();
        setState(306);
        match(MQL_Parser::L_PAR);
        setState(307);
        match(MQL_Parser::VARIABLE);
        setState(309);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(308);
          match(MQL_Parser::KEY);
        }
        setState(311);
        match(MQL_Parser::R_PAR);
        break;
      }

      case MQL_Parser::K_COUNT: {
        _localctx = _tracker.createInstance<MQL_Parser::ReturnItemCountContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(313);
        match(MQL_Parser::K_COUNT);
        setState(314);
        match(MQL_Parser::L_PAR);
        setState(316);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_DISTINCT) {
          setState(315);
          match(MQL_Parser::K_DISTINCT);
        }
        setState(323);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MQL_Parser::VARIABLE: {
            setState(318);
            match(MQL_Parser::VARIABLE);
            setState(320);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == MQL_Parser::KEY) {
              setState(319);
              match(MQL_Parser::KEY);
            }
            break;
          }

          case MQL_Parser::STAR: {
            setState(322);
            match(MQL_Parser::STAR);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(325);
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
  enterRule(_localctx, 42, MQL_Parser::RuleAggregateFunc);
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
    setState(328);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17592991350816) != 0))) {
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
  enterRule(_localctx, 44, MQL_Parser::RuleOrderByItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(360);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::OrderByItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(330);
        match(MQL_Parser::VARIABLE);
        setState(332);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(331);
          match(MQL_Parser::KEY);
        }
        setState(335);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(334);
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
        setState(345);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(344);
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
        setState(347);
        match(MQL_Parser::K_COUNT);
        setState(348);
        match(MQL_Parser::L_PAR);
        setState(350);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_DISTINCT) {
          setState(349);
          match(MQL_Parser::K_DISTINCT);
        }
        setState(352);
        match(MQL_Parser::VARIABLE);
        setState(354);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(353);
          match(MQL_Parser::KEY);
        }
        setState(356);
        match(MQL_Parser::R_PAR);
        setState(358);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_ASC

        || _la == MQL_Parser::K_DESC) {
          setState(357);
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
  enterRule(_localctx, 46, MQL_Parser::RuleGroupByItem);
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
    setState(362);
    match(MQL_Parser::VARIABLE);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::KEY) {
      setState(363);
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
  enterRule(_localctx, 48, MQL_Parser::RuleGraphPattern);
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
    setState(366);
    basicPattern();
    setState(370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_OPTIONAL) {
      setState(367);
      optionalPattern();
      setState(372);
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
  enterRule(_localctx, 50, MQL_Parser::RuleOptionalPattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(MQL_Parser::K_OPTIONAL);
    setState(374);
    match(MQL_Parser::LCURLY_BRACKET);
    setState(375);
    graphPattern();
    setState(376);
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

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
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

tree::TerminalNode* MQL_Parser::SimilaritySearchContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
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
  enterRule(_localctx, 52, MQL_Parser::RuleSimilaritySearch);
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
    setState(378);
    match(MQL_Parser::K_SIMILARITY_SEARCH);
    setState(379);
    match(MQL_Parser::L_PAR);
    setState(380);
    match(MQL_Parser::VARIABLE);
    setState(381);
    match(MQL_Parser::COMMA);
    setState(382);
    match(MQL_Parser::VARIABLE);
    setState(383);
    match(MQL_Parser::COMMA);
    setState(384);
    match(MQL_Parser::STRING);
    setState(385);
    match(MQL_Parser::COMMA);
    setState(388);
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
        setState(386);
        fixedNodeInside();
        break;
      }

      case MQL_Parser::LSQUARE_BRACKET: {
        setState(387);
        tensor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(390);
    match(MQL_Parser::COMMA);
    setState(392);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(391);
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
    setState(394);
    match(MQL_Parser::UNSIGNED_INTEGER);
    setState(395);
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
  enterRule(_localctx, 54, MQL_Parser::RuleTensor);
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
    setState(397);
    match(MQL_Parser::LSQUARE_BRACKET);
    setState(398);
    numericValue();
    setState(403);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(399);
      match(MQL_Parser::COMMA);
      setState(400);
      numericValue();
      setState(405);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(406);
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
  enterRule(_localctx, 56, MQL_Parser::RuleBasicPattern);
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
    setState(408);
    linearPattern();
    setState(413);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(409);
      match(MQL_Parser::COMMA);
      setState(410);
      linearPattern();
      setState(415);
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
  enterRule(_localctx, 58, MQL_Parser::RuleLinearPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(429);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::L_PAR: {
        enterOuterAlt(_localctx, 1);
        setState(416);
        node();
        setState(425);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & 16465) != 0)) {
          setState(419);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case MQL_Parser::LT:
            case MQL_Parser::MINUS: {
              setState(417);
              edge();
              break;
            }

            case MQL_Parser::LEQ:
            case MQL_Parser::SINGLE_EQ: {
              setState(418);
              path();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(421);
          node();
          setState(427);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case MQL_Parser::K_SIMILARITY_SEARCH: {
        enterOuterAlt(_localctx, 2);
        setState(428);
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
  enterRule(_localctx, 60, MQL_Parser::RulePath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(456);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::LEQ: {
        enterOuterAlt(_localctx, 1);
        setState(431);
        match(MQL_Parser::LEQ);
        setState(432);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(434);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1125899906842704) != 0)) {
          setState(433);
          pathType();
        }
        setState(437);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::VARIABLE) {
          setState(436);
          match(MQL_Parser::VARIABLE);
        }
        setState(439);
        pathAlternatives();
        setState(440);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(441);
        match(MQL_Parser::SINGLE_EQ);
        break;
      }

      case MQL_Parser::SINGLE_EQ: {
        enterOuterAlt(_localctx, 2);
        setState(443);
        match(MQL_Parser::SINGLE_EQ);
        setState(444);
        match(MQL_Parser::LSQUARE_BRACKET);
        setState(446);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1125899906842704) != 0)) {
          setState(445);
          pathType();
        }
        setState(449);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::VARIABLE) {
          setState(448);
          match(MQL_Parser::VARIABLE);
        }
        setState(451);
        pathAlternatives();
        setState(452);
        match(MQL_Parser::RSQUARE_BRACKET);
        setState(453);
        match(MQL_Parser::SINGLE_EQ);
        setState(454);
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
  enterRule(_localctx, 62, MQL_Parser::RulePathAlternatives);
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
    setState(458);
    pathSequence();
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PATH_ALTERNATIVE) {
      setState(459);
      match(MQL_Parser::PATH_ALTERNATIVE);
      setState(460);
      pathSequence();
      setState(465);
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
  enterRule(_localctx, 64, MQL_Parser::RulePathSequence);
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
    setState(466);
    pathAtom();
    setState(471);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PATH_SEQUENCE) {
      setState(467);
      match(MQL_Parser::PATH_SEQUENCE);
      setState(468);
      pathAtom();
      setState(473);
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

tree::TerminalNode* MQL_Parser::PathAtomSmtContext::COMMA() {
  return getToken(MQL_Parser::COMMA, 0);
}

MQL_Parser::ConditionalAndExprContext* MQL_Parser::PathAtomSmtContext::conditionalAndExpr() {
  return getRuleContext<MQL_Parser::ConditionalAndExprContext>(0);
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
  enterRule(_localctx, 66, MQL_Parser::RulePathAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(501);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(475);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(474);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(477);
      match(MQL_Parser::TYPE);
      setState(479);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 74) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 74)) & 141) != 0)) {
        setState(478);
        pathSuffix();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomAlternativesContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(482);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(481);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(484);
      match(MQL_Parser::L_PAR);
      setState(485);
      pathAlternatives();
      setState(486);
      match(MQL_Parser::R_PAR);
      setState(488);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 74) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 74)) & 141) != 0)) {
        setState(487);
        pathSuffix();
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MQL_Parser::PathAtomSmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(491);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::PATH_NEGATION) {
        setState(490);
        match(MQL_Parser::PATH_NEGATION);
      }
      setState(493);
      match(MQL_Parser::L_PAR);
      setState(494);
      object();
      setState(495);
      match(MQL_Parser::COMMA);
      setState(496);
      conditionalAndExpr();
      setState(497);
      match(MQL_Parser::R_PAR);
      setState(499);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 74) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 74)) & 141) != 0)) {
        setState(498);
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

//----------------- ObjectContext ------------------------------------------------------------------

MQL_Parser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ObjectContext::TYPE() {
  return getToken(MQL_Parser::TYPE, 0);
}

MQL_Parser::NodeContext* MQL_Parser::ObjectContext::node() {
  return getRuleContext<MQL_Parser::NodeContext>(0);
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
  enterRule(_localctx, 68, MQL_Parser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(505);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(503);
        match(MQL_Parser::TYPE);
        break;
      }

      case MQL_Parser::L_PAR: {
        enterOuterAlt(_localctx, 2);
        setState(504);
        node();
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
  enterRule(_localctx, 70, MQL_Parser::RulePathSuffix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(515);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::STAR: {
        enterOuterAlt(_localctx, 1);
        setState(507);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::STAR);
        break;
      }

      case MQL_Parser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(508);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::PLUS);
        break;
      }

      case MQL_Parser::QUESTION_MARK: {
        enterOuterAlt(_localctx, 3);
        setState(509);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MQL_Parser::QUESTION_MARK);
        break;
      }

      case MQL_Parser::LCURLY_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(510);
        match(MQL_Parser::LCURLY_BRACKET);
        setState(511);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->min = match(MQL_Parser::UNSIGNED_INTEGER);
        setState(512);
        match(MQL_Parser::COMMA);
        setState(513);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->max = match(MQL_Parser::UNSIGNED_INTEGER);
        setState(514);
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
  enterRule(_localctx, 72, MQL_Parser::RulePathType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(525);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::K_ANY:
      case MQL_Parser::K_ALL: {
        enterOuterAlt(_localctx, 1);
        setState(517);
        _la = _input->LA(1);
        if (!(_la == MQL_Parser::K_ANY

        || _la == MQL_Parser::K_ALL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(519);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::K_SHORTEST) {
          setState(518);
          match(MQL_Parser::K_SHORTEST);
        }
        setState(522);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 423311976693762) != 0)) {
          setState(521);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 423311976693762) != 0))) {
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
        setState(524);
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
  enterRule(_localctx, 74, MQL_Parser::RuleNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(529);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(527);
      fixedNode();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(528);
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
  enterRule(_localctx, 76, MQL_Parser::RuleFixedNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    match(MQL_Parser::L_PAR);
    setState(532);
    fixedNodeInside();
    setState(533);
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
  enterRule(_localctx, 78, MQL_Parser::RuleFixedNodeInside);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(539);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(535);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(536);
      match(MQL_Parser::ANON_ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(537);
      match(MQL_Parser::EDGE_ID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(538);
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
  enterRule(_localctx, 80, MQL_Parser::RuleEdge);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(554);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(541);
        match(MQL_Parser::LT);
        setState(544);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
        case 1: {
          setState(542);
          match(MQL_Parser::MINUS);
          setState(543);
          edgeInside();
          break;
        }

        default:
          break;
        }
        setState(546);
        match(MQL_Parser::MINUS);
        break;
      }

      case MQL_Parser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(547);
        match(MQL_Parser::MINUS);
        setState(551);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::LSQUARE_BRACKET) {
          setState(548);
          edgeInside();
          setState(549);
          match(MQL_Parser::MINUS);
        }
        setState(553);
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
  enterRule(_localctx, 82, MQL_Parser::RuleEdgeInside);
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
    setState(556);
    match(MQL_Parser::LSQUARE_BRACKET);
    setState(558);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::EDGE_ID

    || _la == MQL_Parser::VARIABLE) {
      setState(557);
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
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::TYPE

    || _la == MQL_Parser::TYPE_VAR) {
      setState(560);
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
    setState(564);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::LCURLY_BRACKET) {
      setState(563);
      properties();
    }
    setState(566);
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
  enterRule(_localctx, 84, MQL_Parser::RuleVarNode);
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
    setState(568);
    match(MQL_Parser::L_PAR);
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::VARIABLE) {
      setState(569);
      match(MQL_Parser::VARIABLE);
    }
    setState(575);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::TYPE) {
      setState(572);
      match(MQL_Parser::TYPE);
      setState(577);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(579);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::LCURLY_BRACKET) {
      setState(578);
      properties();
    }
    setState(581);
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
  enterRule(_localctx, 86, MQL_Parser::RuleProperties);
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
    setState(583);
    match(MQL_Parser::LCURLY_BRACKET);
    setState(584);
    property();
    setState(589);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::COMMA) {
      setState(585);
      match(MQL_Parser::COMMA);
      setState(586);
      property();
      setState(591);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(592);
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
MQL_Parser::PropertyContext* MQL_Parser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 88, MQL_Parser::RuleProperty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(607);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::Property1Context>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(594);
      identifier();
      setState(599);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MQL_Parser::COLON: {
          setState(595);
          match(MQL_Parser::COLON);
          setState(596);
          value();
          break;
        }

        case MQL_Parser::TRUE_PROP: {
          setState(597);
          match(MQL_Parser::TRUE_PROP);
          break;
        }

        case MQL_Parser::FALSE_PROP: {
          setState(598);
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
      setState(601);
      identifier();
      setState(602);
      match(MQL_Parser::TYPE);
      setState(603);
      match(MQL_Parser::L_PAR);
      setState(604);
      match(MQL_Parser::STRING);
      setState(605);
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
  enterRule(_localctx, 90, MQL_Parser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(611);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(609);
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
        setState(610);
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
  enterRule(_localctx, 92, MQL_Parser::RuleBoolValue);
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
    setState(613);
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
  enterRule(_localctx, 94, MQL_Parser::RuleNumericValue);
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
    setState(616);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(615);
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
    setState(618);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8070450532247928832) != 0))) {
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
  enterRule(_localctx, 96, MQL_Parser::RuleDatatypeValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(620);
    identifier();
    setState(621);
    match(MQL_Parser::L_PAR);
    setState(622);
    match(MQL_Parser::STRING);
    setState(623);
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
  enterRule(_localctx, 98, MQL_Parser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::UNSIGNED_INTEGER:
      case MQL_Parser::UNSIGNED_FLOAT:
      case MQL_Parser::UNSIGNED_SCIENTIFIC_NOTATION:
      case MQL_Parser::PLUS:
      case MQL_Parser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(625);
        numericValue();
        break;
      }

      case MQL_Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(626);
        match(MQL_Parser::STRING);
        break;
      }

      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(627);
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
        setState(628);
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
  enterRule(_localctx, 100, MQL_Parser::RuleConditionalOrExpr);
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
    setState(631);
    conditionalAndExpr();
    setState(636);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_OR) {
      setState(632);
      match(MQL_Parser::K_OR);
      setState(633);
      conditionalAndExpr();
      setState(638);
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
  enterRule(_localctx, 102, MQL_Parser::RuleConditionalAndExpr);
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
    setState(639);
    comparisonExpr();
    setState(644);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::K_AND) {
      setState(640);
      match(MQL_Parser::K_AND);
      setState(641);
      comparisonExpr();
      setState(646);
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
  enterRule(_localctx, 104, MQL_Parser::RuleComparisonExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(659);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MQL_Parser::ComparisonExprOpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(647);
      additiveExpr();
      setState(650);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & 63) != 0)) {
        setState(648);
        antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & 63) != 0))) {
          antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(649);
        additiveExpr();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MQL_Parser::ComparisonExprIsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(652);
      additiveExpr();
      setState(653);
      match(MQL_Parser::K_IS);
      setState(655);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MQL_Parser::K_NOT) {
        setState(654);
        match(MQL_Parser::K_NOT);
      }
      setState(657);
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
  enterRule(_localctx, 106, MQL_Parser::RuleAdditiveExpr);
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
    setState(661);
    multiplicativeExpr();
    setState(666);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MQL_Parser::PLUS

    || _la == MQL_Parser::MINUS) {
      setState(662);
      antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1205 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == MQL_Parser::PLUS

      || _la == MQL_Parser::MINUS)) {
        antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1205 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<AdditiveExprContext *>(_localctx)->_tset1205);
      setState(663);
      multiplicativeExpr();
      setState(668);
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
  enterRule(_localctx, 108, MQL_Parser::RuleMultiplicativeExpr);
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
    setState(669);
    unaryExpr();
    setState(674);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 25) != 0)) {
      setState(670);
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1224 = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & 25) != 0))) {
        antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1224 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset1224);
      setState(671);
      unaryExpr();
      setState(676);
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

tree::TerminalNode* MQL_Parser::UnaryExprContext::PLUS() {
  return getToken(MQL_Parser::PLUS, 0);
}

tree::TerminalNode* MQL_Parser::UnaryExprContext::MINUS() {
  return getToken(MQL_Parser::MINUS, 0);
}

MQL_Parser::AtomicExprContext* MQL_Parser::UnaryExprContext::atomicExpr() {
  return getRuleContext<MQL_Parser::AtomicExprContext>(0);
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
  enterRule(_localctx, 110, MQL_Parser::RuleUnaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(684);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(677);
      match(MQL_Parser::K_NOT);
      setState(678);
      unaryExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(679);
      match(MQL_Parser::PLUS);
      setState(680);
      unaryExpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(681);
      match(MQL_Parser::MINUS);
      setState(682);
      unaryExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(683);
      atomicExpr();
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

//----------------- ExprValueExprContext ------------------------------------------------------------------

MQL_Parser::ValueExprContext* MQL_Parser::ExprValueExprContext::valueExpr() {
  return getRuleContext<MQL_Parser::ValueExprContext>(0);
}

MQL_Parser::ExprValueExprContext::ExprValueExprContext(AtomicExprContext *ctx) { copyFrom(ctx); }


std::any MQL_Parser::ExprValueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitExprValueExpr(this);
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
  enterRule(_localctx, 112, MQL_Parser::RuleAtomicExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(695);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::VARIABLE: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(686);
        match(MQL_Parser::VARIABLE);
        setState(688);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MQL_Parser::KEY) {
          setState(687);
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
      case MQL_Parser::NAME: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprValueExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(690);
        valueExpr();
        break;
      }

      case MQL_Parser::L_PAR: {
        _localctx = _tracker.createInstance<MQL_Parser::ExprParenthesisContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(691);
        match(MQL_Parser::L_PAR);
        setState(692);
        conditionalOrExpr();
        setState(693);
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

//----------------- ValueExprContext ------------------------------------------------------------------

MQL_Parser::ValueExprContext::ValueExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MQL_Parser::ValueExprContext::UNSIGNED_INTEGER() {
  return getToken(MQL_Parser::UNSIGNED_INTEGER, 0);
}

tree::TerminalNode* MQL_Parser::ValueExprContext::UNSIGNED_FLOAT() {
  return getToken(MQL_Parser::UNSIGNED_FLOAT, 0);
}

tree::TerminalNode* MQL_Parser::ValueExprContext::STRING() {
  return getToken(MQL_Parser::STRING, 0);
}

MQL_Parser::BoolValueContext* MQL_Parser::ValueExprContext::boolValue() {
  return getRuleContext<MQL_Parser::BoolValueContext>(0);
}

MQL_Parser::DatatypeValueContext* MQL_Parser::ValueExprContext::datatypeValue() {
  return getRuleContext<MQL_Parser::DatatypeValueContext>(0);
}


size_t MQL_Parser::ValueExprContext::getRuleIndex() const {
  return MQL_Parser::RuleValueExpr;
}


std::any MQL_Parser::ValueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MQL_ParserVisitor*>(visitor))
    return parserVisitor->visitValueExpr(this);
  else
    return visitor->visitChildren(this);
}

MQL_Parser::ValueExprContext* MQL_Parser::valueExpr() {
  ValueExprContext *_localctx = _tracker.createInstance<ValueExprContext>(_ctx, getState());
  enterRule(_localctx, 114, MQL_Parser::RuleValueExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(702);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MQL_Parser::UNSIGNED_INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(697);
        match(MQL_Parser::UNSIGNED_INTEGER);
        break;
      }

      case MQL_Parser::UNSIGNED_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(698);
        match(MQL_Parser::UNSIGNED_FLOAT);
        break;
      }

      case MQL_Parser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(699);
        match(MQL_Parser::STRING);
        break;
      }

      case MQL_Parser::K_FALSE:
      case MQL_Parser::K_TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(700);
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
        enterOuterAlt(_localctx, 5);
        setState(701);
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
  enterRule(_localctx, 116, MQL_Parser::RuleExprTypename);
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
    setState(704);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35459252355584) != 0))) {
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
  enterRule(_localctx, 118, MQL_Parser::RuleKeyword);
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
    setState(706);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2181413888589822) != 0))) {
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
