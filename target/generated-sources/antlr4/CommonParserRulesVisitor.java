// Generated from CommonParserRules.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link CommonParserRules}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface CommonParserRulesVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(CommonParserRules.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(CommonParserRules.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(CommonParserRules.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(CommonParserRules.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(CommonParserRules.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link CommonParserRules#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(CommonParserRules.LiteralContext ctx);
}