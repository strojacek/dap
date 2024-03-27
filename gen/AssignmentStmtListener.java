// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/AssignmentStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link AssignmentStmtParser}.
 */
public interface AssignmentStmtListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#assign_main}.
	 * @param ctx the parse tree
	 */
	void enterAssign_main(AssignmentStmtParser.Assign_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#assign_main}.
	 * @param ctx the parse tree
	 */
	void exitAssign_main(AssignmentStmtParser.Assign_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#assign_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAssign_stmt(AssignmentStmtParser.Assign_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#assign_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAssign_stmt(AssignmentStmtParser.Assign_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(AssignmentStmtParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(AssignmentStmtParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(AssignmentStmtParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(AssignmentStmtParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(AssignmentStmtParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(AssignmentStmtParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(AssignmentStmtParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(AssignmentStmtParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(AssignmentStmtParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(AssignmentStmtParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(AssignmentStmtParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(AssignmentStmtParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(AssignmentStmtParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(AssignmentStmtParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link AssignmentStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(AssignmentStmtParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link AssignmentStmtParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(AssignmentStmtParser.VariablesContext ctx);
}