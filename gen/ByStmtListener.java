// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/ByStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ByStmtParser}.
 */
public interface ByStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#by_main}.
	 * @param ctx the parse tree
	 */
	void enterBy_main(ByStmtParser.By_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#by_main}.
	 * @param ctx the parse tree
	 */
	void exitBy_main(ByStmtParser.By_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#by_stmt}.
	 * @param ctx the parse tree
	 */
	void enterBy_stmt(ByStmtParser.By_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#by_stmt}.
	 * @param ctx the parse tree
	 */
	void exitBy_stmt(ByStmtParser.By_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ByStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ByStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(ByStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(ByStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(ByStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(ByStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(ByStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(ByStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(ByStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(ByStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(ByStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(ByStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ByStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ByStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ByStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(ByStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link ByStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(ByStmtParser.VariablesContext ctx);
}