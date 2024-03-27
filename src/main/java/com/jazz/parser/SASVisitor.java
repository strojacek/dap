package com.jazz.parser;// Generated from SAS.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link SASParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface SASVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link SASParser#parse}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParse(SASParser.ParseContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#sas_stmt_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSas_stmt_list(SASParser.Sas_stmt_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#if_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf_stmt(SASParser.If_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#if_then_else_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf_then_else_stmt(SASParser.If_then_else_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#delete_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDelete_stmt(SASParser.Delete_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_to_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_to_stmt(SASParser.Do_to_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_to_by_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_to_by_stmt(SASParser.Do_to_by_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_to_while_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_to_while_stmt(SASParser.Do_to_while_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_to_until_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_to_until_stmt(SASParser.Do_to_until_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_while_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_while_stmt(SASParser.Do_while_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#do_until_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDo_until_stmt(SASParser.Do_until_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(SASParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(SASParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#of_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOf_var_list(SASParser.Of_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#identifiers_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifiers_list(SASParser.Identifiers_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#in_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIn_var_list(SASParser.In_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#colonInts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColonInts(SASParser.ColonIntsContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(SASParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser variables}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariables(SASParser.VariablesContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#abort_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbort_main(SASParser.Abort_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#abort_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbort_stmt(SASParser.Abort_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#file_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile_spec(SASParser.File_specContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#proc_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_main(SASParser.Proc_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#proc_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_stmt(SASParser.Proc_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#proc_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProc_name(SASParser.Proc_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#array_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_main(SASParser.Array_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#array_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_stmt(SASParser.Array_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#array_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_name(SASParser.Array_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#array_subscript}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_subscript(SASParser.Array_subscriptContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#array_elements}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArray_elements(SASParser.Array_elementsContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#initial_value_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list(SASParser.Initial_value_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list_item(SASParser.Initial_value_list_itemContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitial_value_list_bk(SASParser.Initial_value_list_bkContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#constant_iter_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant_iter_value(SASParser.Constant_iter_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#constant_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant_value(SASParser.Constant_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#assign_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_main(SASParser.Assign_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#assign_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_stmt(SASParser.Assign_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#by_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBy_main(SASParser.By_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#by_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBy_stmt(SASParser.By_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#call_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_main(SASParser.Call_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#call_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall_stmt(SASParser.Call_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#data_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitData_main(SASParser.Data_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#data_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitData_stmt(SASParser.Data_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#dataset_name_opt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDataset_name_opt(SASParser.Dataset_name_optContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#datastmt_cmd}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatastmt_cmd(SASParser.Datastmt_cmdContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#view_dsname_opt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitView_dsname_opt(SASParser.View_dsname_optContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#view_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitView_name(SASParser.View_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#dataset_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDataset_name(SASParser.Dataset_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#program_name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram_name(SASParser.Program_nameContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#passwd_opt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPasswd_opt(SASParser.Passwd_optContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#source_opt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSource_opt(SASParser.Source_optContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#datalines_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines_main(SASParser.Datalines_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#datalines_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines_stmt(SASParser.Datalines_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDatalines4_stmt(SASParser.Datalines4_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#drop_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDrop_main(SASParser.Drop_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#drop_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDrop_stmt(SASParser.Drop_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#filename_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFilename_main(SASParser.Filename_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#filename_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFilename_stmt(SASParser.Filename_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#infile_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_main(SASParser.Infile_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#infile_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_stmt(SASParser.Infile_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#file_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile_specification(SASParser.File_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#device_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDevice_type(SASParser.Device_typeContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#infile_options}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInfile_options(SASParser.Infile_optionsContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#input_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_main(SASParser.Input_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#input_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_stmt(SASParser.Input_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#put_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_stmt(SASParser.Put_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#input_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_specification(SASParser.Input_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#put_specification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_specification(SASParser.Put_specificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#pointer_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPointer_control(SASParser.Pointer_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#informat_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInformat_list(SASParser.Informat_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#input_variable_format}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_variable_format(SASParser.Input_variable_formatContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#input_variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInput_variable(SASParser.Input_variableContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#put_variable_format}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_variable_format(SASParser.Put_variable_formatContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#put_variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut_variable(SASParser.Put_variableContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#column_point_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColumn_point_control(SASParser.Column_point_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#line_point_control}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLine_point_control(SASParser.Line_point_controlContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#format_modifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormat_modifier(SASParser.Format_modifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#column_specifications}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitColumn_specifications(SASParser.Column_specificationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#means_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMeans_main(SASParser.Means_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#means_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMeans_proc(SASParser.Means_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#statistic_keyword}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatistic_keyword(SASParser.Statistic_keywordContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSpaced_identifiers(SASParser.Spaced_identifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#var_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_stmt(SASParser.Var_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#glm_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlm_main(SASParser.Glm_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#glm_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGlm_proc(SASParser.Glm_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#freq_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFreq_main(SASParser.Freq_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#freq_proc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFreq_proc(SASParser.Freq_procContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#run_main}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRun_main(SASParser.Run_mainContext ctx);
	/**
	 * Visit a parse tree produced by {@link SASParser#run_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRun_stmt(SASParser.Run_stmtContext ctx);
}