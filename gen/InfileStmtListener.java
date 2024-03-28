// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/InfileStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link InfileStmtParser}.
 */
public interface InfileStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#infile_main}.
	 * @param ctx the parse tree
	 */
	void enterInfile_main(InfileStmtParser.Infile_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#infile_main}.
	 * @param ctx the parse tree
	 */
	void exitInfile_main(InfileStmtParser.Infile_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#infile_stmt}.
	 * @param ctx the parse tree
	 */
	void enterInfile_stmt(InfileStmtParser.Infile_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#infile_stmt}.
	 * @param ctx the parse tree
	 */
	void exitInfile_stmt(InfileStmtParser.Infile_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#file_specification}.
	 * @param ctx the parse tree
	 */
	void enterFile_specification(InfileStmtParser.File_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#file_specification}.
	 * @param ctx the parse tree
	 */
	void exitFile_specification(InfileStmtParser.File_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#device_type}.
	 * @param ctx the parse tree
	 */
	void enterDevice_type(InfileStmtParser.Device_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#device_type}.
	 * @param ctx the parse tree
	 */
	void exitDevice_type(InfileStmtParser.Device_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#infile_options}.
	 * @param ctx the parse tree
	 */
	void enterInfile_options(InfileStmtParser.Infile_optionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#infile_options}.
	 * @param ctx the parse tree
	 */
	void exitInfile_options(InfileStmtParser.Infile_optionsContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(InfileStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(InfileStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(InfileStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(InfileStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(InfileStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(InfileStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(InfileStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(InfileStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(InfileStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(InfileStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(InfileStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(InfileStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(InfileStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(InfileStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link InfileStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(InfileStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link InfileStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(InfileStmtParser.VariablesContext ctx);
}