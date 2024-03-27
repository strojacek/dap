// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/RunStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link RunStmtParser}.
 */
public interface RunStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#run_main}.
	 * @param ctx the parse tree
	 */
	void enterRun_main(RunStmtParser.Run_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#run_main}.
	 * @param ctx the parse tree
	 */
	void exitRun_main(RunStmtParser.Run_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#run_stmt}.
	 * @param ctx the parse tree
	 */
	void enterRun_stmt(RunStmtParser.Run_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#run_stmt}.
	 * @param ctx the parse tree
	 */
	void exitRun_stmt(RunStmtParser.Run_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(RunStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(RunStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(RunStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(RunStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(RunStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(RunStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(RunStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(RunStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(RunStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(RunStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(RunStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(RunStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(RunStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(RunStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link RunStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(RunStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link RunStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(RunStmtParser.VariablesContext ctx);
}