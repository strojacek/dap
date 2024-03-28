// Generated from LetStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link LetStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface LetStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#let_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLet_main(LetStmtParser.Let_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbort_stmt(LetStmtParser.Abort_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(LetStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(LetStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(LetStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(LetStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(LetStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(LetStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(LetStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link LetStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(LetStmtParser.VariablesContext ctx);
}