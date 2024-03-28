// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/CommonGrammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CommonGrammarParser}.
 */
public interface CommonGrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(CommonGrammarParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(CommonGrammarParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(CommonGrammarParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(CommonGrammarParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(CommonGrammarParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(CommonGrammarParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(CommonGrammarParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(CommonGrammarParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(CommonGrammarParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(CommonGrammarParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(CommonGrammarParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(CommonGrammarParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(CommonGrammarParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(CommonGrammarParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonGrammarParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(CommonGrammarParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonGrammarParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(CommonGrammarParser.VariablesContext ctx);
}