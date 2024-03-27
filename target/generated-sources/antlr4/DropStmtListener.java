// Generated from DropStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DropStmtParser}.
 */
public interface DropStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#drop_main}.
	 * @param ctx the parse tree
	 */
	void enterDrop_main(DropStmtParser.Drop_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#drop_main}.
	 * @param ctx the parse tree
	 */
	void exitDrop_main(DropStmtParser.Drop_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#drop_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDrop_stmt(DropStmtParser.Drop_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#drop_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDrop_stmt(DropStmtParser.Drop_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(DropStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(DropStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(DropStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(DropStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(DropStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(DropStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(DropStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(DropStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(DropStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(DropStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(DropStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(DropStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(DropStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(DropStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link DropStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(DropStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link DropStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(DropStmtParser.VariablesContext ctx);
}