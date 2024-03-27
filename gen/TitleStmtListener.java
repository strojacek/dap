// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/TitleStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link TitleStmtParser}.
 */
public interface TitleStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link TitleStmtParser#title_main}.
	 * @param ctx the parse tree
	 */
	void enterTitle_main(TitleStmtParser.Title_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link TitleStmtParser#title_main}.
	 * @param ctx the parse tree
	 */
	void exitTitle_main(TitleStmtParser.Title_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link TitleStmtParser#title_stmt}.
	 * @param ctx the parse tree
	 */
	void enterTitle_stmt(TitleStmtParser.Title_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link TitleStmtParser#title_stmt}.
	 * @param ctx the parse tree
	 */
	void exitTitle_stmt(TitleStmtParser.Title_stmtContext ctx);
}