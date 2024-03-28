// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/AbortStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link AbortStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface AbortStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link AbortStmtParser#abort_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbort_main(AbortStmtParser.Abort_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link AbortStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbort_stmt(AbortStmtParser.Abort_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link AbortStmtParser#file_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile_spec(AbortStmtParser.File_specContext ctx);
}