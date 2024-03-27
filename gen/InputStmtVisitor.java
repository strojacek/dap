// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/InputStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link InputStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface InputStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#input_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_main(InputStmtParser.Input_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#input_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_stmt(InputStmtParser.Input_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#put_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_stmt(InputStmtParser.Put_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#input_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_specification(InputStmtParser.Input_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#put_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_specification(InputStmtParser.Put_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#pointer_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPointer_control(InputStmtParser.Pointer_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#informat_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInformat_list(InputStmtParser.Informat_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#input_variable_format}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_variable_format(InputStmtParser.Input_variable_formatContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#input_variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_variable(InputStmtParser.Input_variableContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#put_variable_format}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_variable_format(InputStmtParser.Put_variable_formatContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#put_variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_variable(InputStmtParser.Put_variableContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#column_point_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColumn_point_control(InputStmtParser.Column_point_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#line_point_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLine_point_control(InputStmtParser.Line_point_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#format_modifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormat_modifier(InputStmtParser.Format_modifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#column_specifications}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColumn_specifications(InputStmtParser.Column_specificationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(InputStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(InputStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(InputStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(InputStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(InputStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(InputStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(InputStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link InputStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(InputStmtParser.VariablesContext ctx);
}