// Generated from RunStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link RunStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface RunStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#run_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRun_main(RunStmtParser.Run_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#run_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRun_stmt(RunStmtParser.Run_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(RunStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(RunStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(RunStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(RunStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(RunStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(RunStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(RunStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link RunStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(RunStmtParser.VariablesContext ctx);
}