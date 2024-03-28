// Generated from DataStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DataStmtParser}.
 */
public interface DataStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#data_main}.
	 * @param ctx the parse tree
	 */
	void enterData_main(DataStmtParser.Data_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#data_main}.
	 * @param ctx the parse tree
	 */
	void exitData_main(DataStmtParser.Data_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#data_stmt}.
	 * @param ctx the parse tree
	 */
	void enterData_stmt(DataStmtParser.Data_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#data_stmt}.
	 * @param ctx the parse tree
	 */
	void exitData_stmt(DataStmtParser.Data_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#dataset_name_opt}.
	 * @param ctx the parse tree
	 */
	void enterDataset_name_opt(DataStmtParser.Dataset_name_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#dataset_name_opt}.
	 * @param ctx the parse tree
	 */
	void exitDataset_name_opt(DataStmtParser.Dataset_name_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#datastmt_cmd}.
	 * @param ctx the parse tree
	 */
	void enterDatastmt_cmd(DataStmtParser.Datastmt_cmdContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#datastmt_cmd}.
	 * @param ctx the parse tree
	 */
	void exitDatastmt_cmd(DataStmtParser.Datastmt_cmdContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#view_dsname_opt}.
	 * @param ctx the parse tree
	 */
	void enterView_dsname_opt(DataStmtParser.View_dsname_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#view_dsname_opt}.
	 * @param ctx the parse tree
	 */
	void exitView_dsname_opt(DataStmtParser.View_dsname_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#view_name}.
	 * @param ctx the parse tree
	 */
	void enterView_name(DataStmtParser.View_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#view_name}.
	 * @param ctx the parse tree
	 */
	void exitView_name(DataStmtParser.View_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#dataset_name}.
	 * @param ctx the parse tree
	 */
	void enterDataset_name(DataStmtParser.Dataset_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#dataset_name}.
	 * @param ctx the parse tree
	 */
	void exitDataset_name(DataStmtParser.Dataset_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#program_name}.
	 * @param ctx the parse tree
	 */
	void enterProgram_name(DataStmtParser.Program_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#program_name}.
	 * @param ctx the parse tree
	 */
	void exitProgram_name(DataStmtParser.Program_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#passwd_opt}.
	 * @param ctx the parse tree
	 */
	void enterPasswd_opt(DataStmtParser.Passwd_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#passwd_opt}.
	 * @param ctx the parse tree
	 */
	void exitPasswd_opt(DataStmtParser.Passwd_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#source_opt}.
	 * @param ctx the parse tree
	 */
	void enterSource_opt(DataStmtParser.Source_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#source_opt}.
	 * @param ctx the parse tree
	 */
	void exitSource_opt(DataStmtParser.Source_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(DataStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(DataStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(DataStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(DataStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(DataStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(DataStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(DataStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(DataStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(DataStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(DataStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(DataStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(DataStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(DataStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(DataStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link DataStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(DataStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link DataStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(DataStmtParser.VariablesContext ctx);
}