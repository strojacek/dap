// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/FreqProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link FreqProcParser}.
 */
public interface FreqProcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#freq_main}.
	 * @param ctx the parse tree
	 */
	void enterFreq_main(FreqProcParser.Freq_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#freq_main}.
	 * @param ctx the parse tree
	 */
	void exitFreq_main(FreqProcParser.Freq_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#freq_proc}.
	 * @param ctx the parse tree
	 */
	void enterFreq_proc(FreqProcParser.Freq_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#freq_proc}.
	 * @param ctx the parse tree
	 */
	void exitFreq_proc(FreqProcParser.Freq_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(FreqProcParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(FreqProcParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(FreqProcParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(FreqProcParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(FreqProcParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(FreqProcParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(FreqProcParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(FreqProcParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(FreqProcParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(FreqProcParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(FreqProcParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(FreqProcParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(FreqProcParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(FreqProcParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link FreqProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(FreqProcParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link FreqProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(FreqProcParser.VariablesContext ctx);
}