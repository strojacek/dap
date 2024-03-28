// Generated from ProcStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ProcStmtParser}.
 */
public interface ProcStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#proc_main}.
	 * @param ctx the parse tree
	 */
	void enterProc_main(ProcStmtParser.Proc_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#proc_main}.
	 * @param ctx the parse tree
	 */
	void exitProc_main(ProcStmtParser.Proc_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#proc_stmt}.
	 * @param ctx the parse tree
	 */
	void enterProc_stmt(ProcStmtParser.Proc_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#proc_stmt}.
	 * @param ctx the parse tree
	 */
	void exitProc_stmt(ProcStmtParser.Proc_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#proc_name}.
	 * @param ctx the parse tree
	 */
	void enterProc_name(ProcStmtParser.Proc_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#proc_name}.
	 * @param ctx the parse tree
	 */
	void exitProc_name(ProcStmtParser.Proc_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ProcStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ProcStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(ProcStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(ProcStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(ProcStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(ProcStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(ProcStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(ProcStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(ProcStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(ProcStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(ProcStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(ProcStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ProcStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ProcStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(ProcStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(ProcStmtParser.VariablesContext ctx);
}