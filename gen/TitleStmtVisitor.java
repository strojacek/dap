// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/TitleStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link TitleStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface TitleStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link TitleStmtParser#title_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTitle_main(TitleStmtParser.Title_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link TitleStmtParser#title_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTitle_stmt(TitleStmtParser.Title_stmtContext ctx);
}