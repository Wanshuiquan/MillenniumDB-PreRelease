#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <stack>
#include <vector>

#include "query/id.h"
#include "query/parser/grammar/sparql/query_autogenerated/SparqlQueryParserBaseVisitor.h"
#include "query/parser/grammar/sparql/id_or_path.h"
#include "query/parser/op/sparql/op_path.h"
#include "query/parser/op/sparql/op_triple.h"
#include "query/parser/paths/regular_path_expr.h"
#include "query/query_context.h"

#include "antlr4-runtime.h"

class Expr;

using SparqlParser = SparqlQueryParser;

namespace SPARQL {

class QueryVisitor : public SparqlQueryParserBaseVisitor {
public:

// To be shared between in nested QueryVisitors
struct GlobalInfo {
    std::string base_iri;

    std::unordered_map<std::string, std::string> iri_prefix_map;

    uint64_t blank_node_autogenerated_count = 0;
};

private:
    GlobalInfo& global_info;

    std::vector<VarId>                 select_variables;
    std::vector<std::unique_ptr<Expr>> select_variables_expressions;
    std::vector<OpTriple>              current_triples;
    std::vector<OpPath>                current_paths;

    // filter of the current group graph pattern
    std::stack<std::vector<std::unique_ptr<Expr>>> current_filters;

    std::vector<std::variant<VarId, std::unique_ptr<Expr>>> order_by_items;
    std::vector<std::pair<std::optional<VarId>, std::unique_ptr<Expr>>> group_by_items;
    std::vector<bool> order_by_ascending;

    std::vector<std::unique_ptr<Expr>> having_expressions;

    IdOrPath current_sparql_element = ObjectId::get_null(); // initial value won't be used

    std::stack<Id> subject_stack;
    std::stack<IdOrPath> predicate_stack;
    std::stack<Id> object_stack;

    uint64_t limit  = Op::DEFAULT_LIMIT;
    uint64_t offset = Op::DEFAULT_OFFSET;

    bool current_path_inverse;
    std::unique_ptr<RegularPathExpr> current_path;

    std::unique_ptr<Expr> current_expr;

    PathSemantic current_path_semantic;
    VarId current_path_var = VarId(0); // initial value won't be used

    // to avoid repeating paths in patterns like `?s :P1+ :o1, :o2`
    bool current_path_var_is_fresh = false;

    bool group_by_present = false;

    // Parsing helpers
    std::string iriCtxToString(SparqlParser::IriContext*);

    std::string stringCtxToString(SparqlParser::StringContext*);

    ObjectId handleIntegerString(const std::string&, const std::string&);

    VarId get_new_blank_node_var() {
        auto new_bnode_id = global_info.blank_node_autogenerated_count++;
        std::string new_var_name = "_:.b" + std::to_string(new_bnode_id);
        return get_query_ctx().get_or_create_var(new_var_name);
    }

public:
    QueryVisitor(GlobalInfo& global_info) : global_info(global_info) { }

    // The final result will be stored here to be moved out
    std::unique_ptr<Op> current_op;

    virtual std::any visitQuery(SparqlParser::QueryContext*) override;

    virtual std::any visitConstructQuery(SparqlParser::ConstructQueryContext*) override;
    virtual std::any visitDescribeQuery(SparqlParser::DescribeQueryContext*) override;
    virtual std::any visitAskQuery(SparqlParser::AskQueryContext*) override;
    virtual std::any visitPrologue(SparqlParser::PrologueContext*) override;
    virtual std::any visitBaseDecl(SparqlParser::BaseDeclContext*) override;
    virtual std::any visitPrefixDecl(SparqlParser::PrefixDeclContext*) override;
    virtual std::any visitSolutionModifier(SparqlParser::SolutionModifierContext*) override;
    virtual std::any visitOrderClause(SparqlParser::OrderClauseContext*) override;

    virtual std::any visitPrimaryExpression(SparqlParser::PrimaryExpressionContext*) override;
    virtual std::any visitUnaryExpression(SparqlParser::UnaryExpressionContext*) override;
    virtual std::any visitMultiplicativeExpression(SparqlParser::MultiplicativeExpressionContext*) override;
    virtual std::any visitAdditiveExpression(SparqlParser::AdditiveExpressionContext*) override;
    virtual std::any visitRelationalExpression(SparqlParser::RelationalExpressionContext*) override;
    virtual std::any visitConditionalAndExpression(SparqlParser::ConditionalAndExpressionContext*) override;
    virtual std::any visitConditionalOrExpression(SparqlParser::ConditionalOrExpressionContext*) override;

    virtual std::any visitAggregate(SparqlParser::AggregateContext*) override;
    virtual std::any visitSubStringExpression(SparqlParser::SubStringExpressionContext*) override;
    virtual std::any visitStrReplaceExpression(SparqlParser::StrReplaceExpressionContext*) override;
    virtual std::any visitRegexExpression(SparqlParser::RegexExpressionContext*) override;
    virtual std::any visitExistsFunction(SparqlParser::ExistsFunctionContext*) override;
    virtual std::any visitNotExistsFunction(SparqlParser::NotExistsFunctionContext*) override;

    virtual std::any visitSelectQuery(SparqlParser::SelectQueryContext*) override;
    virtual std::any visitSubSelect(SparqlParser::SubSelectContext*) override;
    virtual std::any visitSelectClause(SparqlParser::SelectClauseContext*) override;
    virtual std::any visitSelectSingleVariable(SparqlParser::SelectSingleVariableContext*) override;
    virtual std::any visitSelectExpressionAsVariable(SparqlParser::SelectExpressionAsVariableContext*) override;
    virtual std::any visitWhereClause(SparqlParser::WhereClauseContext*) override;
    virtual std::any visitGroupGraphPatternSub(SparqlParser::GroupGraphPatternSubContext*) override;
    virtual std::any visitTriplesSameSubjectPath(SparqlParser::TriplesSameSubjectPathContext*) override;
    virtual std::any visitTriplesSameSubject(SparqlParser::TriplesSameSubjectContext*) override;
    virtual std::any visitTriplesBlock(SparqlParser::TriplesBlockContext*) override;
    virtual std::any visitBlankNodePropertyListPath(SparqlParser::BlankNodePropertyListPathContext* ctx) override;
    virtual std::any visitPropertyListPathNotEmpty(SparqlParser::PropertyListPathNotEmptyContext*) override;
    virtual std::any visitPropertyListNotEmpty(SparqlParser::PropertyListNotEmptyContext*) override;
    virtual std::any visitObjectPath(SparqlParser::ObjectPathContext*) override;
    virtual std::any visitObject(SparqlParser::ObjectContext*) override;
    virtual std::any visitCollectionPath(SparqlParser::CollectionPathContext*) override;
    virtual std::any visitCollection(SparqlParser::CollectionContext*) override;

    virtual std::any visitGroupCondition(SparqlParser::GroupConditionContext*) override;
    virtual std::any visitHavingCondition(SparqlParser::HavingConditionContext*) override;

    virtual std::any visitVar(SparqlParser::VarContext*) override;
    virtual std::any visitIri(SparqlParser::IriContext*) override;
    virtual std::any visitRdfLiteral(SparqlParser::RdfLiteralContext*) override;
    virtual std::any visitNumericLiteralUnsigned(SparqlParser::NumericLiteralUnsignedContext*) override;
    virtual std::any visitNumericLiteralPositive(SparqlParser::NumericLiteralPositiveContext*) override;
    virtual std::any visitNumericLiteralNegative(SparqlParser::NumericLiteralNegativeContext*) override;
    virtual std::any visitBooleanLiteral(SparqlParser::BooleanLiteralContext*) override;
    virtual std::any visitBlankNode(SparqlParser::BlankNodeContext*) override;
    virtual std::any visitNil(SparqlParser::NilContext*) override;

    virtual std::any visitVerbPath(SparqlParser::VerbPathContext*) override;
    virtual std::any visitVerb(SparqlParser::VerbContext*) override;

    virtual std::any visitPathAlternative(SparqlParser::PathAlternativeContext*) override;
    virtual std::any visitPathSequence(SparqlParser::PathSequenceContext*) override;
    virtual std::any visitPathEltOrInverse(SparqlParser::PathEltOrInverseContext*) override;

    virtual std::any visitGroupOrUnionGraphPattern(SparqlParser::GroupOrUnionGraphPatternContext*) override;
    virtual std::any visitOptionalGraphPattern(SparqlParser::OptionalGraphPatternContext*) override;
    virtual std::any visitMinusGraphPattern(SparqlParser::MinusGraphPatternContext*) override;
    virtual std::any visitServiceGraphPattern(SparqlParser::ServiceGraphPatternContext*) override;
    virtual std::any visitGraphGraphPattern(SparqlParser::GraphGraphPatternContext*) override;
    virtual std::any visitBind(SparqlParser::BindContext*) override;
    virtual std::any visitValuesClause(SparqlParser::ValuesClauseContext*) override;
    virtual std::any visitInlineDataOneVar(SparqlParser::InlineDataOneVarContext*) override;
    virtual std::any visitInlineDataFull(SparqlParser::InlineDataFullContext*) override;

    virtual std::any visitFilter(SparqlParser::FilterContext*) override;
    virtual std::any visitBuiltInCall(SparqlParser::BuiltInCallContext*) override;
    virtual std::any visitFunctionCall(SparqlParser::FunctionCallContext*) override;
};
}