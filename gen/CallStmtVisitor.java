// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/CallStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link CallStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface CallStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#call_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_main(CallStmtParser.Call_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#call_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_stmt(CallStmtParser.Call_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(CallStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(CallStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(CallStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(CallStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(CallStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(CallStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(CallStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link CallStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(CallStmtParser.VariablesContext ctx);
}