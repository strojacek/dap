
// Generated from SAS.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SASParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SASParser.
 */
class  SASListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParse(SASParser::ParseContext *ctx) = 0;
  virtual void exitParse(SASParser::ParseContext *ctx) = 0;

  virtual void enterSas_stmt_list(SASParser::Sas_stmt_listContext *ctx) = 0;
  virtual void exitSas_stmt_list(SASParser::Sas_stmt_listContext *ctx) = 0;

  virtual void enterIf_stmt(SASParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(SASParser::If_stmtContext *ctx) = 0;

  virtual void enterIf_then_else_stmt(SASParser::If_then_else_stmtContext *ctx) = 0;
  virtual void exitIf_then_else_stmt(SASParser::If_then_else_stmtContext *ctx) = 0;

  virtual void enterDelete_stmt(SASParser::Delete_stmtContext *ctx) = 0;
  virtual void exitDelete_stmt(SASParser::Delete_stmtContext *ctx) = 0;

  virtual void enterDo_to_stmt(SASParser::Do_to_stmtContext *ctx) = 0;
  virtual void exitDo_to_stmt(SASParser::Do_to_stmtContext *ctx) = 0;

  virtual void enterDo_to_by_stmt(SASParser::Do_to_by_stmtContext *ctx) = 0;
  virtual void exitDo_to_by_stmt(SASParser::Do_to_by_stmtContext *ctx) = 0;

  virtual void enterDo_to_while_stmt(SASParser::Do_to_while_stmtContext *ctx) = 0;
  virtual void exitDo_to_while_stmt(SASParser::Do_to_while_stmtContext *ctx) = 0;

  virtual void enterDo_to_until_stmt(SASParser::Do_to_until_stmtContext *ctx) = 0;
  virtual void exitDo_to_until_stmt(SASParser::Do_to_until_stmtContext *ctx) = 0;

  virtual void enterDo_while_stmt(SASParser::Do_while_stmtContext *ctx) = 0;
  virtual void exitDo_while_stmt(SASParser::Do_while_stmtContext *ctx) = 0;

  virtual void enterDo_until_stmt(SASParser::Do_until_stmtContext *ctx) = 0;
  virtual void exitDo_until_stmt(SASParser::Do_until_stmtContext *ctx) = 0;

  virtual void enterExpression(SASParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SASParser::ExpressionContext *ctx) = 0;

  virtual void enterExpressionList(SASParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(SASParser::ExpressionListContext *ctx) = 0;

  virtual void enterOf_var_list(SASParser::Of_var_listContext *ctx) = 0;
  virtual void exitOf_var_list(SASParser::Of_var_listContext *ctx) = 0;

  virtual void enterIdentifiers_list(SASParser::Identifiers_listContext *ctx) = 0;
  virtual void exitIdentifiers_list(SASParser::Identifiers_listContext *ctx) = 0;

  virtual void enterIn_var_list(SASParser::In_var_listContext *ctx) = 0;
  virtual void exitIn_var_list(SASParser::In_var_listContext *ctx) = 0;

  virtual void enterColonInts(SASParser::ColonIntsContext *ctx) = 0;
  virtual void exitColonInts(SASParser::ColonIntsContext *ctx) = 0;

  virtual void enterLiteral(SASParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(SASParser::LiteralContext *ctx) = 0;

  virtual void enterVariables(SASParser::VariablesContext *ctx) = 0;
  virtual void exitVariables(SASParser::VariablesContext *ctx) = 0;

  virtual void enterAbort_main(SASParser::Abort_mainContext *ctx) = 0;
  virtual void exitAbort_main(SASParser::Abort_mainContext *ctx) = 0;

  virtual void enterAbort_stmt(SASParser::Abort_stmtContext *ctx) = 0;
  virtual void exitAbort_stmt(SASParser::Abort_stmtContext *ctx) = 0;

  virtual void enterFile_spec(SASParser::File_specContext *ctx) = 0;
  virtual void exitFile_spec(SASParser::File_specContext *ctx) = 0;

  virtual void enterProc_main(SASParser::Proc_mainContext *ctx) = 0;
  virtual void exitProc_main(SASParser::Proc_mainContext *ctx) = 0;

  virtual void enterProc_stmt(SASParser::Proc_stmtContext *ctx) = 0;
  virtual void exitProc_stmt(SASParser::Proc_stmtContext *ctx) = 0;

  virtual void enterProc_name(SASParser::Proc_nameContext *ctx) = 0;
  virtual void exitProc_name(SASParser::Proc_nameContext *ctx) = 0;

  virtual void enterArray_main(SASParser::Array_mainContext *ctx) = 0;
  virtual void exitArray_main(SASParser::Array_mainContext *ctx) = 0;

  virtual void enterArray_stmt(SASParser::Array_stmtContext *ctx) = 0;
  virtual void exitArray_stmt(SASParser::Array_stmtContext *ctx) = 0;

  virtual void enterArray_name(SASParser::Array_nameContext *ctx) = 0;
  virtual void exitArray_name(SASParser::Array_nameContext *ctx) = 0;

  virtual void enterArray_subscript(SASParser::Array_subscriptContext *ctx) = 0;
  virtual void exitArray_subscript(SASParser::Array_subscriptContext *ctx) = 0;

  virtual void enterArray_elements(SASParser::Array_elementsContext *ctx) = 0;
  virtual void exitArray_elements(SASParser::Array_elementsContext *ctx) = 0;

  virtual void enterInitial_value_list(SASParser::Initial_value_listContext *ctx) = 0;
  virtual void exitInitial_value_list(SASParser::Initial_value_listContext *ctx) = 0;

  virtual void enterInitial_value_list_item(SASParser::Initial_value_list_itemContext *ctx) = 0;
  virtual void exitInitial_value_list_item(SASParser::Initial_value_list_itemContext *ctx) = 0;

  virtual void enterInitial_value_list_bk(SASParser::Initial_value_list_bkContext *ctx) = 0;
  virtual void exitInitial_value_list_bk(SASParser::Initial_value_list_bkContext *ctx) = 0;

  virtual void enterConstant_iter_value(SASParser::Constant_iter_valueContext *ctx) = 0;
  virtual void exitConstant_iter_value(SASParser::Constant_iter_valueContext *ctx) = 0;

  virtual void enterConstant_value(SASParser::Constant_valueContext *ctx) = 0;
  virtual void exitConstant_value(SASParser::Constant_valueContext *ctx) = 0;

  virtual void enterAssign_main(SASParser::Assign_mainContext *ctx) = 0;
  virtual void exitAssign_main(SASParser::Assign_mainContext *ctx) = 0;

  virtual void enterAssign_stmt(SASParser::Assign_stmtContext *ctx) = 0;
  virtual void exitAssign_stmt(SASParser::Assign_stmtContext *ctx) = 0;

  virtual void enterBy_main(SASParser::By_mainContext *ctx) = 0;
  virtual void exitBy_main(SASParser::By_mainContext *ctx) = 0;

  virtual void enterBy_stmt(SASParser::By_stmtContext *ctx) = 0;
  virtual void exitBy_stmt(SASParser::By_stmtContext *ctx) = 0;

  virtual void enterCall_main(SASParser::Call_mainContext *ctx) = 0;
  virtual void exitCall_main(SASParser::Call_mainContext *ctx) = 0;

  virtual void enterCall_stmt(SASParser::Call_stmtContext *ctx) = 0;
  virtual void exitCall_stmt(SASParser::Call_stmtContext *ctx) = 0;

  virtual void enterData_main(SASParser::Data_mainContext *ctx) = 0;
  virtual void exitData_main(SASParser::Data_mainContext *ctx) = 0;

  virtual void enterData_stmt(SASParser::Data_stmtContext *ctx) = 0;
  virtual void exitData_stmt(SASParser::Data_stmtContext *ctx) = 0;

  virtual void enterDataset_name_opt(SASParser::Dataset_name_optContext *ctx) = 0;
  virtual void exitDataset_name_opt(SASParser::Dataset_name_optContext *ctx) = 0;

  virtual void enterDatastmt_cmd(SASParser::Datastmt_cmdContext *ctx) = 0;
  virtual void exitDatastmt_cmd(SASParser::Datastmt_cmdContext *ctx) = 0;

  virtual void enterView_dsname_opt(SASParser::View_dsname_optContext *ctx) = 0;
  virtual void exitView_dsname_opt(SASParser::View_dsname_optContext *ctx) = 0;

  virtual void enterView_name(SASParser::View_nameContext *ctx) = 0;
  virtual void exitView_name(SASParser::View_nameContext *ctx) = 0;

  virtual void enterDataset_name(SASParser::Dataset_nameContext *ctx) = 0;
  virtual void exitDataset_name(SASParser::Dataset_nameContext *ctx) = 0;

  virtual void enterProgram_name(SASParser::Program_nameContext *ctx) = 0;
  virtual void exitProgram_name(SASParser::Program_nameContext *ctx) = 0;

  virtual void enterPasswd_opt(SASParser::Passwd_optContext *ctx) = 0;
  virtual void exitPasswd_opt(SASParser::Passwd_optContext *ctx) = 0;

  virtual void enterSource_opt(SASParser::Source_optContext *ctx) = 0;
  virtual void exitSource_opt(SASParser::Source_optContext *ctx) = 0;

  virtual void enterDatalines_main(SASParser::Datalines_mainContext *ctx) = 0;
  virtual void exitDatalines_main(SASParser::Datalines_mainContext *ctx) = 0;

  virtual void enterDatalines_stmt(SASParser::Datalines_stmtContext *ctx) = 0;
  virtual void exitDatalines_stmt(SASParser::Datalines_stmtContext *ctx) = 0;

  virtual void enterDatalines4_stmt(SASParser::Datalines4_stmtContext *ctx) = 0;
  virtual void exitDatalines4_stmt(SASParser::Datalines4_stmtContext *ctx) = 0;

  virtual void enterDrop_main(SASParser::Drop_mainContext *ctx) = 0;
  virtual void exitDrop_main(SASParser::Drop_mainContext *ctx) = 0;

  virtual void enterDrop_stmt(SASParser::Drop_stmtContext *ctx) = 0;
  virtual void exitDrop_stmt(SASParser::Drop_stmtContext *ctx) = 0;

  virtual void enterFilename_main(SASParser::Filename_mainContext *ctx) = 0;
  virtual void exitFilename_main(SASParser::Filename_mainContext *ctx) = 0;

  virtual void enterFilename_stmt(SASParser::Filename_stmtContext *ctx) = 0;
  virtual void exitFilename_stmt(SASParser::Filename_stmtContext *ctx) = 0;

  virtual void enterInfile_main(SASParser::Infile_mainContext *ctx) = 0;
  virtual void exitInfile_main(SASParser::Infile_mainContext *ctx) = 0;

  virtual void enterInfile_stmt(SASParser::Infile_stmtContext *ctx) = 0;
  virtual void exitInfile_stmt(SASParser::Infile_stmtContext *ctx) = 0;

  virtual void enterFile_specification(SASParser::File_specificationContext *ctx) = 0;
  virtual void exitFile_specification(SASParser::File_specificationContext *ctx) = 0;

  virtual void enterDevice_type(SASParser::Device_typeContext *ctx) = 0;
  virtual void exitDevice_type(SASParser::Device_typeContext *ctx) = 0;

  virtual void enterInfile_options(SASParser::Infile_optionsContext *ctx) = 0;
  virtual void exitInfile_options(SASParser::Infile_optionsContext *ctx) = 0;

  virtual void enterInput_main(SASParser::Input_mainContext *ctx) = 0;
  virtual void exitInput_main(SASParser::Input_mainContext *ctx) = 0;

  virtual void enterInput_stmt(SASParser::Input_stmtContext *ctx) = 0;
  virtual void exitInput_stmt(SASParser::Input_stmtContext *ctx) = 0;

  virtual void enterPut_stmt(SASParser::Put_stmtContext *ctx) = 0;
  virtual void exitPut_stmt(SASParser::Put_stmtContext *ctx) = 0;

  virtual void enterInput_specification(SASParser::Input_specificationContext *ctx) = 0;
  virtual void exitInput_specification(SASParser::Input_specificationContext *ctx) = 0;

  virtual void enterPut_specification(SASParser::Put_specificationContext *ctx) = 0;
  virtual void exitPut_specification(SASParser::Put_specificationContext *ctx) = 0;

  virtual void enterPointer_control(SASParser::Pointer_controlContext *ctx) = 0;
  virtual void exitPointer_control(SASParser::Pointer_controlContext *ctx) = 0;

  virtual void enterInformat_list(SASParser::Informat_listContext *ctx) = 0;
  virtual void exitInformat_list(SASParser::Informat_listContext *ctx) = 0;

  virtual void enterInput_variable_format(SASParser::Input_variable_formatContext *ctx) = 0;
  virtual void exitInput_variable_format(SASParser::Input_variable_formatContext *ctx) = 0;

  virtual void enterInput_variable(SASParser::Input_variableContext *ctx) = 0;
  virtual void exitInput_variable(SASParser::Input_variableContext *ctx) = 0;

  virtual void enterPut_variable_format(SASParser::Put_variable_formatContext *ctx) = 0;
  virtual void exitPut_variable_format(SASParser::Put_variable_formatContext *ctx) = 0;

  virtual void enterPut_variable(SASParser::Put_variableContext *ctx) = 0;
  virtual void exitPut_variable(SASParser::Put_variableContext *ctx) = 0;

  virtual void enterColumn_point_control(SASParser::Column_point_controlContext *ctx) = 0;
  virtual void exitColumn_point_control(SASParser::Column_point_controlContext *ctx) = 0;

  virtual void enterLine_point_control(SASParser::Line_point_controlContext *ctx) = 0;
  virtual void exitLine_point_control(SASParser::Line_point_controlContext *ctx) = 0;

  virtual void enterFormat_modifier(SASParser::Format_modifierContext *ctx) = 0;
  virtual void exitFormat_modifier(SASParser::Format_modifierContext *ctx) = 0;

  virtual void enterColumn_specifications(SASParser::Column_specificationsContext *ctx) = 0;
  virtual void exitColumn_specifications(SASParser::Column_specificationsContext *ctx) = 0;

  virtual void enterLet_main(SASParser::Let_mainContext *ctx) = 0;
  virtual void exitLet_main(SASParser::Let_mainContext *ctx) = 0;

  virtual void enterLet_stmt(SASParser::Let_stmtContext *ctx) = 0;
  virtual void exitLet_stmt(SASParser::Let_stmtContext *ctx) = 0;

  virtual void enterMeans_main(SASParser::Means_mainContext *ctx) = 0;
  virtual void exitMeans_main(SASParser::Means_mainContext *ctx) = 0;

  virtual void enterMeans_proc(SASParser::Means_procContext *ctx) = 0;
  virtual void exitMeans_proc(SASParser::Means_procContext *ctx) = 0;

  virtual void enterStatistic_keyword(SASParser::Statistic_keywordContext *ctx) = 0;
  virtual void exitStatistic_keyword(SASParser::Statistic_keywordContext *ctx) = 0;

  virtual void enterSpaced_identifiers(SASParser::Spaced_identifiersContext *ctx) = 0;
  virtual void exitSpaced_identifiers(SASParser::Spaced_identifiersContext *ctx) = 0;

  virtual void enterVar_stmt(SASParser::Var_stmtContext *ctx) = 0;
  virtual void exitVar_stmt(SASParser::Var_stmtContext *ctx) = 0;

  virtual void enterGlm_main(SASParser::Glm_mainContext *ctx) = 0;
  virtual void exitGlm_main(SASParser::Glm_mainContext *ctx) = 0;

  virtual void enterGlm_proc(SASParser::Glm_procContext *ctx) = 0;
  virtual void exitGlm_proc(SASParser::Glm_procContext *ctx) = 0;

  virtual void enterFreq_main(SASParser::Freq_mainContext *ctx) = 0;
  virtual void exitFreq_main(SASParser::Freq_mainContext *ctx) = 0;

  virtual void enterFreq_proc(SASParser::Freq_procContext *ctx) = 0;
  virtual void exitFreq_proc(SASParser::Freq_procContext *ctx) = 0;

  virtual void enterImport_main(SASParser::Import_mainContext *ctx) = 0;
  virtual void exitImport_main(SASParser::Import_mainContext *ctx) = 0;

  virtual void enterImport_proc(SASParser::Import_procContext *ctx) = 0;
  virtual void exitImport_proc(SASParser::Import_procContext *ctx) = 0;

  virtual void enterTitle_main(SASParser::Title_mainContext *ctx) = 0;
  virtual void exitTitle_main(SASParser::Title_mainContext *ctx) = 0;

  virtual void enterTitle_stmt(SASParser::Title_stmtContext *ctx) = 0;
  virtual void exitTitle_stmt(SASParser::Title_stmtContext *ctx) = 0;

  virtual void enterRun_main(SASParser::Run_mainContext *ctx) = 0;
  virtual void exitRun_main(SASParser::Run_mainContext *ctx) = 0;

  virtual void enterRun_stmt(SASParser::Run_stmtContext *ctx) = 0;
  virtual void exitRun_stmt(SASParser::Run_stmtContext *ctx) = 0;


};

