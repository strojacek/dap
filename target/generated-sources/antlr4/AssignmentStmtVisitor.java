// Generated from AssignmentStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link AssignmentStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface AssignmentStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#assign_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_main(AssignmentStmtParser.Assign_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#assign_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_stmt(AssignmentStmtParser.Assign_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(AssignmentStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(AssignmentStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(AssignmentStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(AssignmentStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(AssignmentStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(AssignmentStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(AssignmentStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link AssignmentStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(AssignmentStmtParser.VariablesContext ctx);
}