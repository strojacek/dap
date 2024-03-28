package com.dap.parser;// Generated from SAS.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link SASParser}.
 */
public interface SASListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link SASParser#parse}.
	 * @param ctx the parse tree
	 */
	void enterParse(SASParser.ParseContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#parse}.
	 * @param ctx the parse tree
	 */
	void exitParse(SASParser.ParseContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#sas_stmt_list}.
	 * @param ctx the parse tree
	 */
	void enterSas_stmt_list(SASParser.Sas_stmt_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#sas_stmt_list}.
	 * @param ctx the parse tree
	 */
	void exitSas_stmt_list(SASParser.Sas_stmt_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#if_stmt}.
	 * @param ctx the parse tree
	 */
	void enterIf_stmt(SASParser.If_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#if_stmt}.
	 * @param ctx the parse tree
	 */
	void exitIf_stmt(SASParser.If_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#if_then_else_stmt}.
	 * @param ctx the parse tree
	 */
	void enterIf_then_else_stmt(SASParser.If_then_else_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#if_then_else_stmt}.
	 * @param ctx the parse tree
	 */
	void exitIf_then_else_stmt(SASParser.If_then_else_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#delete_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDelete_stmt(SASParser.Delete_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#delete_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDelete_stmt(SASParser.Delete_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_to_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_to_stmt(SASParser.Do_to_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_to_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_to_stmt(SASParser.Do_to_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_to_by_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_to_by_stmt(SASParser.Do_to_by_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_to_by_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_to_by_stmt(SASParser.Do_to_by_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_to_while_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_to_while_stmt(SASParser.Do_to_while_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_to_while_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_to_while_stmt(SASParser.Do_to_while_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_to_until_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_to_until_stmt(SASParser.Do_to_until_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_to_until_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_to_until_stmt(SASParser.Do_to_until_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_while_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_while_stmt(SASParser.Do_while_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_while_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_while_stmt(SASParser.Do_while_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#do_until_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDo_until_stmt(SASParser.Do_until_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#do_until_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDo_until_stmt(SASParser.Do_until_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(SASParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(SASParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(SASParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(SASParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void enterOf_var_list(SASParser.Of_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#of_var_list}.
	 * @param ctx the parse tree
	 */
	void exitOf_var_list(SASParser.Of_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(SASParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(SASParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void enterIn_var_list(SASParser.In_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#in_var_list}.
	 * @param ctx the parse tree
	 */
	void exitIn_var_list(SASParser.In_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void enterColonInts(SASParser.ColonIntsContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#colonInts}.
	 * @param ctx the parse tree
	 */
	void exitColonInts(SASParser.ColonIntsContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(SASParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(SASParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#variables}.
	 * @param ctx the parse tree
	 */
	void enterVariables(SASParser.VariablesContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#variables}.
	 * @param ctx the parse tree
	 */
	void exitVariables(SASParser.VariablesContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#abort_main}.
	 * @param ctx the parse tree
	 */
	void enterAbort_main(SASParser.Abort_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#abort_main}.
	 * @param ctx the parse tree
	 */
	void exitAbort_main(SASParser.Abort_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAbort_stmt(SASParser.Abort_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#abort_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAbort_stmt(SASParser.Abort_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#file_spec}.
	 * @param ctx the parse tree
	 */
	void enterFile_spec(SASParser.File_specContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#file_spec}.
	 * @param ctx the parse tree
	 */
	void exitFile_spec(SASParser.File_specContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#proc_main}.
	 * @param ctx the parse tree
	 */
	void enterProc_main(SASParser.Proc_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#proc_main}.
	 * @param ctx the parse tree
	 */
	void exitProc_main(SASParser.Proc_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#proc_stmt}.
	 * @param ctx the parse tree
	 */
	void enterProc_stmt(SASParser.Proc_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#proc_stmt}.
	 * @param ctx the parse tree
	 */
	void exitProc_stmt(SASParser.Proc_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#proc_name}.
	 * @param ctx the parse tree
	 */
	void enterProc_name(SASParser.Proc_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#proc_name}.
	 * @param ctx the parse tree
	 */
	void exitProc_name(SASParser.Proc_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#array_main}.
	 * @param ctx the parse tree
	 */
	void enterArray_main(SASParser.Array_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#array_main}.
	 * @param ctx the parse tree
	 */
	void exitArray_main(SASParser.Array_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#array_stmt}.
	 * @param ctx the parse tree
	 */
	void enterArray_stmt(SASParser.Array_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#array_stmt}.
	 * @param ctx the parse tree
	 */
	void exitArray_stmt(SASParser.Array_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#array_name}.
	 * @param ctx the parse tree
	 */
	void enterArray_name(SASParser.Array_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#array_name}.
	 * @param ctx the parse tree
	 */
	void exitArray_name(SASParser.Array_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#array_subscript}.
	 * @param ctx the parse tree
	 */
	void enterArray_subscript(SASParser.Array_subscriptContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#array_subscript}.
	 * @param ctx the parse tree
	 */
	void exitArray_subscript(SASParser.Array_subscriptContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#array_elements}.
	 * @param ctx the parse tree
	 */
	void enterArray_elements(SASParser.Array_elementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#array_elements}.
	 * @param ctx the parse tree
	 */
	void exitArray_elements(SASParser.Array_elementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#initial_value_list}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list(SASParser.Initial_value_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#initial_value_list}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list(SASParser.Initial_value_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list_item(SASParser.Initial_value_list_itemContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#initial_value_list_item}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list_item(SASParser.Initial_value_list_itemContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 */
	void enterInitial_value_list_bk(SASParser.Initial_value_list_bkContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#initial_value_list_bk}.
	 * @param ctx the parse tree
	 */
	void exitInitial_value_list_bk(SASParser.Initial_value_list_bkContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#constant_iter_value}.
	 * @param ctx the parse tree
	 */
	void enterConstant_iter_value(SASParser.Constant_iter_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#constant_iter_value}.
	 * @param ctx the parse tree
	 */
	void exitConstant_iter_value(SASParser.Constant_iter_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#constant_value}.
	 * @param ctx the parse tree
	 */
	void enterConstant_value(SASParser.Constant_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#constant_value}.
	 * @param ctx the parse tree
	 */
	void exitConstant_value(SASParser.Constant_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#assign_main}.
	 * @param ctx the parse tree
	 */
	void enterAssign_main(SASParser.Assign_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#assign_main}.
	 * @param ctx the parse tree
	 */
	void exitAssign_main(SASParser.Assign_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#assign_stmt}.
	 * @param ctx the parse tree
	 */
	void enterAssign_stmt(SASParser.Assign_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#assign_stmt}.
	 * @param ctx the parse tree
	 */
	void exitAssign_stmt(SASParser.Assign_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#by_main}.
	 * @param ctx the parse tree
	 */
	void enterBy_main(SASParser.By_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#by_main}.
	 * @param ctx the parse tree
	 */
	void exitBy_main(SASParser.By_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#by_stmt}.
	 * @param ctx the parse tree
	 */
	void enterBy_stmt(SASParser.By_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#by_stmt}.
	 * @param ctx the parse tree
	 */
	void exitBy_stmt(SASParser.By_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#call_main}.
	 * @param ctx the parse tree
	 */
	void enterCall_main(SASParser.Call_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#call_main}.
	 * @param ctx the parse tree
	 */
	void exitCall_main(SASParser.Call_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#call_stmt}.
	 * @param ctx the parse tree
	 */
	void enterCall_stmt(SASParser.Call_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#call_stmt}.
	 * @param ctx the parse tree
	 */
	void exitCall_stmt(SASParser.Call_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#data_main}.
	 * @param ctx the parse tree
	 */
	void enterData_main(SASParser.Data_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#data_main}.
	 * @param ctx the parse tree
	 */
	void exitData_main(SASParser.Data_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#data_stmt}.
	 * @param ctx the parse tree
	 */
	void enterData_stmt(SASParser.Data_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#data_stmt}.
	 * @param ctx the parse tree
	 */
	void exitData_stmt(SASParser.Data_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#dataset_name_opt}.
	 * @param ctx the parse tree
	 */
	void enterDataset_name_opt(SASParser.Dataset_name_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#dataset_name_opt}.
	 * @param ctx the parse tree
	 */
	void exitDataset_name_opt(SASParser.Dataset_name_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#datastmt_cmd}.
	 * @param ctx the parse tree
	 */
	void enterDatastmt_cmd(SASParser.Datastmt_cmdContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#datastmt_cmd}.
	 * @param ctx the parse tree
	 */
	void exitDatastmt_cmd(SASParser.Datastmt_cmdContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#view_dsname_opt}.
	 * @param ctx the parse tree
	 */
	void enterView_dsname_opt(SASParser.View_dsname_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#view_dsname_opt}.
	 * @param ctx the parse tree
	 */
	void exitView_dsname_opt(SASParser.View_dsname_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#view_name}.
	 * @param ctx the parse tree
	 */
	void enterView_name(SASParser.View_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#view_name}.
	 * @param ctx the parse tree
	 */
	void exitView_name(SASParser.View_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#dataset_name}.
	 * @param ctx the parse tree
	 */
	void enterDataset_name(SASParser.Dataset_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#dataset_name}.
	 * @param ctx the parse tree
	 */
	void exitDataset_name(SASParser.Dataset_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#program_name}.
	 * @param ctx the parse tree
	 */
	void enterProgram_name(SASParser.Program_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#program_name}.
	 * @param ctx the parse tree
	 */
	void exitProgram_name(SASParser.Program_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#passwd_opt}.
	 * @param ctx the parse tree
	 */
	void enterPasswd_opt(SASParser.Passwd_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#passwd_opt}.
	 * @param ctx the parse tree
	 */
	void exitPasswd_opt(SASParser.Passwd_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#source_opt}.
	 * @param ctx the parse tree
	 */
	void enterSource_opt(SASParser.Source_optContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#source_opt}.
	 * @param ctx the parse tree
	 */
	void exitSource_opt(SASParser.Source_optContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#datalines_main}.
	 * @param ctx the parse tree
	 */
	void enterDatalines_main(SASParser.Datalines_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#datalines_main}.
	 * @param ctx the parse tree
	 */
	void exitDatalines_main(SASParser.Datalines_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#datalines_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDatalines_stmt(SASParser.Datalines_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#datalines_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDatalines_stmt(SASParser.Datalines_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDatalines4_stmt(SASParser.Datalines4_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#datalines4_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDatalines4_stmt(SASParser.Datalines4_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#drop_main}.
	 * @param ctx the parse tree
	 */
	void enterDrop_main(SASParser.Drop_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#drop_main}.
	 * @param ctx the parse tree
	 */
	void exitDrop_main(SASParser.Drop_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#drop_stmt}.
	 * @param ctx the parse tree
	 */
	void enterDrop_stmt(SASParser.Drop_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#drop_stmt}.
	 * @param ctx the parse tree
	 */
	void exitDrop_stmt(SASParser.Drop_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#filename_main}.
	 * @param ctx the parse tree
	 */
	void enterFilename_main(SASParser.Filename_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#filename_main}.
	 * @param ctx the parse tree
	 */
	void exitFilename_main(SASParser.Filename_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#filename_stmt}.
	 * @param ctx the parse tree
	 */
	void enterFilename_stmt(SASParser.Filename_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#filename_stmt}.
	 * @param ctx the parse tree
	 */
	void exitFilename_stmt(SASParser.Filename_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#infile_main}.
	 * @param ctx the parse tree
	 */
	void enterInfile_main(SASParser.Infile_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#infile_main}.
	 * @param ctx the parse tree
	 */
	void exitInfile_main(SASParser.Infile_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#infile_stmt}.
	 * @param ctx the parse tree
	 */
	void enterInfile_stmt(SASParser.Infile_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#infile_stmt}.
	 * @param ctx the parse tree
	 */
	void exitInfile_stmt(SASParser.Infile_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#file_specification}.
	 * @param ctx the parse tree
	 */
	void enterFile_specification(SASParser.File_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#file_specification}.
	 * @param ctx the parse tree
	 */
	void exitFile_specification(SASParser.File_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#device_type}.
	 * @param ctx the parse tree
	 */
	void enterDevice_type(SASParser.Device_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#device_type}.
	 * @param ctx the parse tree
	 */
	void exitDevice_type(SASParser.Device_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#infile_options}.
	 * @param ctx the parse tree
	 */
	void enterInfile_options(SASParser.Infile_optionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#infile_options}.
	 * @param ctx the parse tree
	 */
	void exitInfile_options(SASParser.Infile_optionsContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#input_main}.
	 * @param ctx the parse tree
	 */
	void enterInput_main(SASParser.Input_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#input_main}.
	 * @param ctx the parse tree
	 */
	void exitInput_main(SASParser.Input_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#input_stmt}.
	 * @param ctx the parse tree
	 */
	void enterInput_stmt(SASParser.Input_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#input_stmt}.
	 * @param ctx the parse tree
	 */
	void exitInput_stmt(SASParser.Input_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#put_stmt}.
	 * @param ctx the parse tree
	 */
	void enterPut_stmt(SASParser.Put_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#put_stmt}.
	 * @param ctx the parse tree
	 */
	void exitPut_stmt(SASParser.Put_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#input_specification}.
	 * @param ctx the parse tree
	 */
	void enterInput_specification(SASParser.Input_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#input_specification}.
	 * @param ctx the parse tree
	 */
	void exitInput_specification(SASParser.Input_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#put_specification}.
	 * @param ctx the parse tree
	 */
	void enterPut_specification(SASParser.Put_specificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#put_specification}.
	 * @param ctx the parse tree
	 */
	void exitPut_specification(SASParser.Put_specificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#pointer_control}.
	 * @param ctx the parse tree
	 */
	void enterPointer_control(SASParser.Pointer_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#pointer_control}.
	 * @param ctx the parse tree
	 */
	void exitPointer_control(SASParser.Pointer_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#informat_list}.
	 * @param ctx the parse tree
	 */
	void enterInformat_list(SASParser.Informat_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#informat_list}.
	 * @param ctx the parse tree
	 */
	void exitInformat_list(SASParser.Informat_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#input_variable_format}.
	 * @param ctx the parse tree
	 */
	void enterInput_variable_format(SASParser.Input_variable_formatContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#input_variable_format}.
	 * @param ctx the parse tree
	 */
	void exitInput_variable_format(SASParser.Input_variable_formatContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#input_variable}.
	 * @param ctx the parse tree
	 */
	void enterInput_variable(SASParser.Input_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#input_variable}.
	 * @param ctx the parse tree
	 */
	void exitInput_variable(SASParser.Input_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#put_variable_format}.
	 * @param ctx the parse tree
	 */
	void enterPut_variable_format(SASParser.Put_variable_formatContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#put_variable_format}.
	 * @param ctx the parse tree
	 */
	void exitPut_variable_format(SASParser.Put_variable_formatContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#put_variable}.
	 * @param ctx the parse tree
	 */
	void enterPut_variable(SASParser.Put_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#put_variable}.
	 * @param ctx the parse tree
	 */
	void exitPut_variable(SASParser.Put_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#column_point_control}.
	 * @param ctx the parse tree
	 */
	void enterColumn_point_control(SASParser.Column_point_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#column_point_control}.
	 * @param ctx the parse tree
	 */
	void exitColumn_point_control(SASParser.Column_point_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#line_point_control}.
	 * @param ctx the parse tree
	 */
	void enterLine_point_control(SASParser.Line_point_controlContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#line_point_control}.
	 * @param ctx the parse tree
	 */
	void exitLine_point_control(SASParser.Line_point_controlContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#format_modifier}.
	 * @param ctx the parse tree
	 */
	void enterFormat_modifier(SASParser.Format_modifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#format_modifier}.
	 * @param ctx the parse tree
	 */
	void exitFormat_modifier(SASParser.Format_modifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#column_specifications}.
	 * @param ctx the parse tree
	 */
	void enterColumn_specifications(SASParser.Column_specificationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#column_specifications}.
	 * @param ctx the parse tree
	 */
	void exitColumn_specifications(SASParser.Column_specificationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#means_main}.
	 * @param ctx the parse tree
	 */
	void enterMeans_main(SASParser.Means_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#means_main}.
	 * @param ctx the parse tree
	 */
	void exitMeans_main(SASParser.Means_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#means_proc}.
	 * @param ctx the parse tree
	 */
	void enterMeans_proc(SASParser.Means_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#means_proc}.
	 * @param ctx the parse tree
	 */
	void exitMeans_proc(SASParser.Means_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void enterStatistic_keyword(SASParser.Statistic_keywordContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#statistic_keyword}.
	 * @param ctx the parse tree
	 */
	void exitStatistic_keyword(SASParser.Statistic_keywordContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void enterSpaced_identifiers(SASParser.Spaced_identifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#spaced_identifiers}.
	 * @param ctx the parse tree
	 */
	void exitSpaced_identifiers(SASParser.Spaced_identifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void enterVar_stmt(SASParser.Var_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void exitVar_stmt(SASParser.Var_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#glm_main}.
	 * @param ctx the parse tree
	 */
	void enterGlm_main(SASParser.Glm_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#glm_main}.
	 * @param ctx the parse tree
	 */
	void exitGlm_main(SASParser.Glm_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#glm_proc}.
	 * @param ctx the parse tree
	 */
	void enterGlm_proc(SASParser.Glm_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#glm_proc}.
	 * @param ctx the parse tree
	 */
	void exitGlm_proc(SASParser.Glm_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#freq_main}.
	 * @param ctx the parse tree
	 */
	void enterFreq_main(SASParser.Freq_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#freq_main}.
	 * @param ctx the parse tree
	 */
	void exitFreq_main(SASParser.Freq_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#freq_proc}.
	 * @param ctx the parse tree
	 */
	void enterFreq_proc(SASParser.Freq_procContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#freq_proc}.
	 * @param ctx the parse tree
	 */
	void exitFreq_proc(SASParser.Freq_procContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#run_main}.
	 * @param ctx the parse tree
	 */
	void enterRun_main(SASParser.Run_mainContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#run_main}.
	 * @param ctx the parse tree
	 */
	void exitRun_main(SASParser.Run_mainContext ctx);
	/**
	 * Enter a parse tree produced by {@link SASParser#run_stmt}.
	 * @param ctx the parse tree
	 */
	void enterRun_stmt(SASParser.Run_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link SASParser#run_stmt}.
	 * @param ctx the parse tree
	 */
	void exitRun_stmt(SASParser.Run_stmtContext ctx);
}
