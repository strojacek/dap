// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/ArrayStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ArrayStmtParser}.
 */
public interface ArrayStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#array_main}.
	 * @param ctx the parse tree
	 */
	void enterArray_main(ArrayStmtParser.Array_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#array_main}.
	 * @param ctx the parse tree
	 */
	void exitArray_main(ArrayStmtParser.Array_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#array_stmt}.
	 * @param ctx the parse tree
	 */
	void enterArray_stmt(ArrayStmtParser.Array_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#array_stmt}.
	 * @param ctx the parse tree
	 */
	void exitArray_stmt(ArrayStmtParser.Array_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#array_name}.
	 * @param ctx the parse tree
	 */
	void enterArray_name(ArrayStmtParser.Array_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#array_name}.
	 * @param ctx the parse tree
	 */
	void exitArray_name(ArrayStmtParser.Array_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#array_subscript}.
	 * @param ctx the parse tree
	 */
	void enterArray_subscript(ArrayStmtParser.Array_subscriptContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#array_subscript}.
	 * @param ctx the parse tree
	 */
	void exitArray_subscript(ArrayStmtParser.Array_subscriptContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#array_elements}.
	 * @param ctx the parse tree
	 */
	void enterArray_elements(ArrayStmtParser.Array_elementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#array_elements}.
	 * @param ctx the parse tree
	 */
	void exitArray_elements(ArrayStmtParser.Array_elementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#initial_value_list}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list(ArrayStmtParser.Initial_value_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#initial_value_list}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list(ArrayStmtParser.Initial_value_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list_item(ArrayStmtParser.Initial_value_list_itemContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list_item(ArrayStmtParser.Initial_value_list_itemContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list_bk(ArrayStmtParser.Initial_value_list_bkContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list_bk(ArrayStmtParser.Initial_value_list_bkContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#constant_iter_value}.
	 * @param ctx the parse tree
	 */
	void enterConstant_iter_value(ArrayStmtParser.Constant_iter_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#constant_iter_value}.
	 * @param ctx the parse tree
	 */
	void exitConstant_iter_value(ArrayStmtParser.Constant_iter_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#constant_value}.
	 * @param ctx the parse tree
	 */
	void enterConstant_value(ArrayStmtParser.Constant_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#constant_value}.
	 * @param ctx the parse tree
	 */
	void exitConstant_value(ArrayStmtParser.Constant_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ArrayStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ArrayStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(ArrayStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(ArrayStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(ArrayStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(ArrayStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(ArrayStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(ArrayStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(ArrayStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(ArrayStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(ArrayStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(ArrayStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ArrayStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ArrayStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArrayStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(ArrayStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArrayStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(ArrayStmtParser.VariablesContext ctx);
}