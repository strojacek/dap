// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/ImportProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ImportProcParser}.
 */
public interface ImportProcListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#import_main}.
	 * @param ctx the parse tree
	 */
	void enterImport_main(ImportProcParser.Import_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#import_main}.
	 * @param ctx the parse tree
	 */
	void exitImport_main(ImportProcParser.Import_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#import_proc}.
	 * @param ctx the parse tree
	 */
	void enterImport_proc(ImportProcParser.Import_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#import_proc}.
	 * @param ctx the parse tree
	 */
	void exitImport_proc(ImportProcParser.Import_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void enterStatistic_keyword(ImportProcParser.Statistic_keywordContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void exitStatistic_keyword(ImportProcParser.Statistic_keywordContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void enterSpaced_identifiers(ImportProcParser.Spaced_identifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void exitSpaced_identifiers(ImportProcParser.Spaced_identifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void enterVar_stmt(ImportProcParser.Var_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void exitVar_stmt(ImportProcParser.Var_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ImportProcParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ImportProcParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(ImportProcParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(ImportProcParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(ImportProcParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(ImportProcParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(ImportProcParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(ImportProcParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(ImportProcParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(ImportProcParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(ImportProcParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(ImportProcParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ImportProcParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ImportProcParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ImportProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(ImportProcParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link ImportProcParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(ImportProcParser.VariablesContext ctx);
}