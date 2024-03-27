// Generated from InfileStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link InfileStmtParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface InfileStmtVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#infile_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_main(InfileStmtParser.Infile_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#infile_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_stmt(InfileStmtParser.Infile_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#file_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile_specification(InfileStmtParser.File_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#device_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDevice_type(InfileStmtParser.Device_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#infile_options}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_options(InfileStmtParser.Infile_optionsContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(InfileStmtParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(InfileStmtParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(InfileStmtParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(InfileStmtParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(InfileStmtParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(InfileStmtParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(InfileStmtParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link InfileStmtParser#variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(InfileStmtParser.VariablesContext ctx);
}