// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/GLMProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link GLMProcParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface GLMProcVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#glm_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlm_main(GLMProcParser.Glm_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#glm_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlm_proc(GLMProcParser.Glm_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(GLMProcParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(GLMProcParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(GLMProcParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(GLMProcParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(GLMProcParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(GLMProcParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(GLMProcParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link GLMProcParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(GLMProcParser.VariablesContext ctx);
}