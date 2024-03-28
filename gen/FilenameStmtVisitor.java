// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/FilenameStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link FilenameStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface FilenameStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#filename_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFilename_main(FilenameStmtParser.Filename_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#filename_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFilename_stmt(FilenameStmtParser.Filename_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(FilenameStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(FilenameStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(FilenameStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(FilenameStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(FilenameStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(FilenameStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(FilenameStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link FilenameStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(FilenameStmtParser.VariablesContext ctx);
}