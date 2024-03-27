// Generated from ArrayStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ArrayStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ArrayStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#array_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_main(ArrayStmtParser.Array_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#array_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_stmt(ArrayStmtParser.Array_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#array_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_name(ArrayStmtParser.Array_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#array_subscript}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_subscript(ArrayStmtParser.Array_subscriptContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#array_elements}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_elements(ArrayStmtParser.Array_elementsContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#initial_value_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list(ArrayStmtParser.Initial_value_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list_item(ArrayStmtParser.Initial_value_list_itemContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list_bk(ArrayStmtParser.Initial_value_list_bkContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#constant_iter_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant_iter_value(ArrayStmtParser.Constant_iter_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#constant_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant_value(ArrayStmtParser.Constant_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(ArrayStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(ArrayStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(ArrayStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(ArrayStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(ArrayStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(ArrayStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(ArrayStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArrayStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(ArrayStmtParser.VariablesContext ctx);
}