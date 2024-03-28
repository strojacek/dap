// Generated from AbortStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link AbortStmtParser}.
 */
public interface AbortStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link AbortStmtParser#abort_main}.
	 * @param ctx the parse tree
	 */
	void enterAbort_main(AbortStmtParser.Abort_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link AbortStmtParser#abort_main}.
	 * @param ctx the parse tree
	 */
	void exitAbort_main(AbortStmtParser.Abort_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link AbortStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAbort_stmt(AbortStmtParser.Abort_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link AbortStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAbort_stmt(AbortStmtParser.Abort_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link AbortStmtParser#file_spec}.
	 * @param ctx the parse tree
	 */
	void enterFile_spec(AbortStmtParser.File_specContext ctx);
	/**
	 * Exit a parse tree produced by {@link AbortStmtParser#file_spec}.
	 * @param ctx the parse tree
	 */
	void exitFile_spec(AbortStmtParser.File_specContext ctx);
}