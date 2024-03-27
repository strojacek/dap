// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/DatalinesStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DatalinesStmtParser}.
 */
public interface DatalinesStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#datalines_main}.
	 * @param ctx the parse tree
	 */
	void enterDatalines_main(DatalinesStmtParser.Datalines_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#datalines_main}.
	 * @param ctx the parse tree
	 */
	void exitDatalines_main(DatalinesStmtParser.Datalines_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#datalines_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDatalines_stmt(DatalinesStmtParser.Datalines_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#datalines_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDatalines_stmt(DatalinesStmtParser.Datalines_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDatalines4_stmt(DatalinesStmtParser.Datalines4_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDatalines4_stmt(DatalinesStmtParser.Datalines4_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(DatalinesStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(DatalinesStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(DatalinesStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(DatalinesStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(DatalinesStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(DatalinesStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(DatalinesStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(DatalinesStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(DatalinesStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(DatalinesStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(DatalinesStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(DatalinesStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(DatalinesStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(DatalinesStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link DatalinesStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(DatalinesStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link DatalinesStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(DatalinesStmtParser.VariablesContext ctx);
}