// Generated from LetStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link LetStmtParser}.
 */
public interface LetStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#let_main}.
	 * @param ctx the parse tree
	 */
	void enterLet_main(LetStmtParser.Let_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#let_main}.
	 * @param ctx the parse tree
	 */
	void exitLet_main(LetStmtParser.Let_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAbort_stmt(LetStmtParser.Abort_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAbort_stmt(LetStmtParser.Abort_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(LetStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(LetStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(LetStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(LetStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(LetStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(LetStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(LetStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(LetStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(LetStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(LetStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(LetStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(LetStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(LetStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(LetStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link LetStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(LetStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link LetStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(LetStmtParser.VariablesContext ctx);
}