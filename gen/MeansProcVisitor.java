// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/MeansProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MeansProcParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MeansProcVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#means_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMeans_main(MeansProcParser.Means_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#means_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMeans_proc(MeansProcParser.Means_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatistic_keyword(MeansProcParser.Statistic_keywordContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSpaced_identifiers(MeansProcParser.Spaced_identifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#var_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_stmt(MeansProcParser.Var_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(MeansProcParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(MeansProcParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(MeansProcParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(MeansProcParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(MeansProcParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(MeansProcParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(MeansProcParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link MeansProcParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(MeansProcParser.VariablesContext ctx);
}