// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/ImportProc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ImportProcParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ImportProcVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#import_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImport_main(ImportProcParser.Import_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#import_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImport_proc(ImportProcParser.Import_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#statistic_keyword}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatistic_keyword(ImportProcParser.Statistic_keywordContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSpaced_identifiers(ImportProcParser.Spaced_identifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#var_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_stmt(ImportProcParser.Var_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(ImportProcParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(ImportProcParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(ImportProcParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(ImportProcParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(ImportProcParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(ImportProcParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(ImportProcParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link ImportProcParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(ImportProcParser.VariablesContext ctx);
}