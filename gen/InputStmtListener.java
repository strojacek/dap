// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/InputStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link InputStmtParser}.
 */
public interface InputStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#input_main}.
	 * @param ctx the parse tree
	 */
	void enterInput_main(InputStmtParser.Input_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#input_main}.
	 * @param ctx the parse tree
	 */
	void exitInput_main(InputStmtParser.Input_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#input_stmt}.
	 * @param ctx the parse tree
	 */
	void enterInput_stmt(InputStmtParser.Input_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#input_stmt}.
	 * @param ctx the parse tree
	 */
	void exitInput_stmt(InputStmtParser.Input_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#put_stmt}.
	 * @param ctx the parse tree
	 */
	void enterPut_stmt(InputStmtParser.Put_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#put_stmt}.
	 * @param ctx the parse tree
	 */
	void exitPut_stmt(InputStmtParser.Put_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#input_specification}.
	 * @param ctx the parse tree
	 */
	void enterInput_specification(InputStmtParser.Input_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#input_specification}.
	 * @param ctx the parse tree
	 */
	void exitInput_specification(InputStmtParser.Input_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#put_specification}.
	 * @param ctx the parse tree
	 */
	void enterPut_specification(InputStmtParser.Put_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#put_specification}.
	 * @param ctx the parse tree
	 */
	void exitPut_specification(InputStmtParser.Put_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#pointer_control}.
	 * @param ctx the parse tree
	 */
	void enterPointer_control(InputStmtParser.Pointer_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#pointer_control}.
	 * @param ctx the parse tree
	 */
	void exitPointer_control(InputStmtParser.Pointer_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#informat_list}.
	 * @param ctx the parse tree
	 */
	void enterInformat_list(InputStmtParser.Informat_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#informat_list}.
	 * @param ctx the parse tree
	 */
	void exitInformat_list(InputStmtParser.Informat_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#input_variable_format}.
	 * @param ctx the parse tree
	 */
	void enterInput_variable_format(InputStmtParser.Input_variable_formatContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#input_variable_format}.
	 * @param ctx the parse tree
	 */
	void exitInput_variable_format(InputStmtParser.Input_variable_formatContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#input_variable}.
	 * @param ctx the parse tree
	 */
	void enterInput_variable(InputStmtParser.Input_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#input_variable}.
	 * @param ctx the parse tree
	 */
	void exitInput_variable(InputStmtParser.Input_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#put_variable_format}.
	 * @param ctx the parse tree
	 */
	void enterPut_variable_format(InputStmtParser.Put_variable_formatContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#put_variable_format}.
	 * @param ctx the parse tree
	 */
	void exitPut_variable_format(InputStmtParser.Put_variable_formatContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#put_variable}.
	 * @param ctx the parse tree
	 */
	void enterPut_variable(InputStmtParser.Put_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#put_variable}.
	 * @param ctx the parse tree
	 */
	void exitPut_variable(InputStmtParser.Put_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#column_point_control}.
	 * @param ctx the parse tree
	 */
	void enterColumn_point_control(InputStmtParser.Column_point_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#column_point_control}.
	 * @param ctx the parse tree
	 */
	void exitColumn_point_control(InputStmtParser.Column_point_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#line_point_control}.
	 * @param ctx the parse tree
	 */
	void enterLine_point_control(InputStmtParser.Line_point_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#line_point_control}.
	 * @param ctx the parse tree
	 */
	void exitLine_point_control(InputStmtParser.Line_point_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#format_modifier}.
	 * @param ctx the parse tree
	 */
	void enterFormat_modifier(InputStmtParser.Format_modifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#format_modifier}.
	 * @param ctx the parse tree
	 */
	void exitFormat_modifier(InputStmtParser.Format_modifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#column_specifications}.
	 * @param ctx the parse tree
	 */
	void enterColumn_specifications(InputStmtParser.Column_specificationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#column_specifications}.
	 * @param ctx the parse tree
	 */
	void exitColumn_specifications(InputStmtParser.Column_specificationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(InputStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(InputStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(InputStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(InputStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(InputStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(InputStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(InputStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(InputStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(InputStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(InputStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(InputStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(InputStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(InputStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(InputStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(InputStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(InputStmtParser.VariablesContext ctx);
}