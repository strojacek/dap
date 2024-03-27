// Generated from CommonParserRules.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CommonParserRules}.
 */
public interface CommonParserRulesListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(CommonParserRules.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(CommonParserRules.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(CommonParserRules.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(CommonParserRules.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(CommonParserRules.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(CommonParserRules.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(CommonParserRules.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(CommonParserRules.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(CommonParserRules.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(CommonParserRules.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CommonParserRules#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(CommonParserRules.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link CommonParserRules#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(CommonParserRules.LiteralContext ctx);
}