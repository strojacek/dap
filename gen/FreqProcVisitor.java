// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/FreqProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link FreqProcParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface FreqProcVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#freq_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFreq_main(FreqProcParser.Freq_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#freq_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFreq_proc(FreqProcParser.Freq_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(FreqProcParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(FreqProcParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(FreqProcParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(FreqProcParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(FreqProcParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(FreqProcParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(FreqProcParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link FreqProcParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(FreqProcParser.VariablesContext ctx);
}