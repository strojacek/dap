// Generated from GLMProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link GLMProcParser}.
 */
public interface GLMProcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#glm_main}.
	 * @param ctx the parse tree
	 */
	void enterGlm_main(GLMProcParser.Glm_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#glm_main}.
	 * @param ctx the parse tree
	 */
	void exitGlm_main(GLMProcParser.Glm_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#glm_proc}.
	 * @param ctx the parse tree
	 */
	void enterGlm_proc(GLMProcParser.Glm_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#glm_proc}.
	 * @param ctx the parse tree
	 */
	void exitGlm_proc(GLMProcParser.Glm_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(GLMProcParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(GLMProcParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(GLMProcParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(GLMProcParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(GLMProcParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(GLMProcParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(GLMProcParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(GLMProcParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(GLMProcParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(GLMProcParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(GLMProcParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(GLMProcParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(GLMProcParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(GLMProcParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link GLMProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(GLMProcParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link GLMProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(GLMProcParser.VariablesContext ctx);
}