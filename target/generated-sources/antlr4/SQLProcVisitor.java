// Generated from SQLProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link SQLProcParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface SQLProcVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#sql_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSql_main(SQLProcParser.Sql_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#sql_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSql_proc(SQLProcParser.Sql_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(SQLProcParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(SQLProcParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(SQLProcParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(SQLProcParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(SQLProcParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(SQLProcParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(SQLProcParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link SQLProcParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(SQLProcParser.VariablesContext ctx);
}