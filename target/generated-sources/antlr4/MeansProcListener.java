// Generated from MeansProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MeansProcParser}.
 */
public interface MeansProcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#means_main}.
	 * @param ctx the parse tree
	 */
	void enterMeans_main(MeansProcParser.Means_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#means_main}.
	 * @param ctx the parse tree
	 */
	void exitMeans_main(MeansProcParser.Means_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#means_proc}.
	 * @param ctx the parse tree
	 */
	void enterMeans_proc(MeansProcParser.Means_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#means_proc}.
	 * @param ctx the parse tree
	 */
	void exitMeans_proc(MeansProcParser.Means_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void enterStatistic_keyword(MeansProcParser.Statistic_keywordContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void exitStatistic_keyword(MeansProcParser.Statistic_keywordContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void enterSpaced_identifiers(MeansProcParser.Spaced_identifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void exitSpaced_identifiers(MeansProcParser.Spaced_identifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void enterVar_stmt(MeansProcParser.Var_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void exitVar_stmt(MeansProcParser.Var_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(MeansProcParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(MeansProcParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(MeansProcParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(MeansProcParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(MeansProcParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(MeansProcParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(MeansProcParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(MeansProcParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(MeansProcParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(MeansProcParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(MeansProcParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(MeansProcParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(MeansProcParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(MeansProcParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link MeansProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(MeansProcParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link MeansProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(MeansProcParser.VariablesContext ctx);
}