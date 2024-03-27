// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/DatalinesStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link DatalinesStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface DatalinesStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#datalines_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines_main(DatalinesStmtParser.Datalines_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#datalines_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines_stmt(DatalinesStmtParser.Datalines_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines4_stmt(DatalinesStmtParser.Datalines4_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(DatalinesStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(DatalinesStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(DatalinesStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(DatalinesStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(DatalinesStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(DatalinesStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(DatalinesStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link DatalinesStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(DatalinesStmtParser.VariablesContext ctx);
}