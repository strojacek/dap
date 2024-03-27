// Generated from SQLProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link SQLProcParser}.
 */
public interface SQLProcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#sql_main}.
	 * @param ctx the parse tree
	 */
	void enterSql_main(SQLProcParser.Sql_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#sql_main}.
	 * @param ctx the parse tree
	 */
	void exitSql_main(SQLProcParser.Sql_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#sql_proc}.
	 * @param ctx the parse tree
	 */
	void enterSql_proc(SQLProcParser.Sql_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#sql_proc}.
	 * @param ctx the parse tree
	 */
	void exitSql_proc(SQLProcParser.Sql_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(SQLProcParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(SQLProcParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(SQLProcParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(SQLProcParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(SQLProcParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(SQLProcParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(SQLProcParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(SQLProcParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(SQLProcParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(SQLProcParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(SQLProcParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(SQLProcParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(SQLProcParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(SQLProcParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link SQLProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(SQLProcParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link SQLProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(SQLProcParser.VariablesContext ctx);
}