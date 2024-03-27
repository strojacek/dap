// Generated from ProcStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ProcStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ProcStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#proc_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_main(ProcStmtParser.Proc_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#proc_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_stmt(ProcStmtParser.Proc_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#proc_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_name(ProcStmtParser.Proc_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(ProcStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(ProcStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(ProcStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(ProcStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(ProcStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(ProcStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(ProcStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link ProcStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(ProcStmtParser.VariablesContext ctx);
}