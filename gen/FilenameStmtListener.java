// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/FilenameStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link FilenameStmtParser}.
 */
public interface FilenameStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#filename_main}.
	 * @param ctx the parse tree
	 */
	void enterFilename_main(FilenameStmtParser.Filename_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#filename_main}.
	 * @param ctx the parse tree
	 */
	void exitFilename_main(FilenameStmtParser.Filename_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#filename_stmt}.
	 * @param ctx the parse tree
	 */
	void enterFilename_stmt(FilenameStmtParser.Filename_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#filename_stmt}.
	 * @param ctx the parse tree
	 */
	void exitFilename_stmt(FilenameStmtParser.Filename_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(FilenameStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(FilenameStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(FilenameStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(FilenameStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(FilenameStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(FilenameStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(FilenameStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(FilenameStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(FilenameStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(FilenameStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(FilenameStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(FilenameStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(FilenameStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(FilenameStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link FilenameStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(FilenameStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link FilenameStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(FilenameStmtParser.VariablesContext ctx);
}