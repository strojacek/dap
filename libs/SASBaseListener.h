
// Generated from SAS.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SASListener.h"


/**
 * This class provides an empty implementation of SASListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SASBaseListener : public SASListener {
public:

  virtual void enterParse(SASParser::ParseContext * /*ctx*/) override { }
  virtual void exitParse(SASParser::ParseContext * /*ctx*/) override { }

  virtual void enterSas_stmt_list(SASParser::Sas_stmt_listContext * /*ctx*/) override { }
  virtual void exitSas_stmt_list(SASParser::Sas_stmt_listContext * /*ctx*/) override { }

  virtual void enterIf_stmt(SASParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(SASParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterIf_then_else_stmt(SASParser::If_then_else_stmtContext * /*ctx*/) override { }
  virtual void exitIf_then_else_stmt(SASParser::If_then_else_stmtContext * /*ctx*/) override { }

  virtual void enterDelete_stmt(SASParser::Delete_stmtContext * /*ctx*/) override { }
  virtual void exitDelete_stmt(SASParser::Delete_stmtContext * /*ctx*/) override { }

  virtual void enterDo_to_stmt(SASParser::Do_to_stmtContext * /*ctx*/) override { }
  virtual void exitDo_to_stmt(SASParser::Do_to_stmtContext * /*ctx*/) override { }

  virtual void enterDo_to_by_stmt(SASParser::Do_to_by_stmtContext * /*ctx*/) override { }
  virtual void exitDo_to_by_stmt(SASParser::Do_to_by_stmtContext * /*ctx*/) override { }

  virtual void enterDo_to_while_stmt(SASParser::Do_to_while_stmtContext * /*ctx*/) override { }
  virtual void exitDo_to_while_stmt(SASParser::Do_to_while_stmtContext * /*ctx*/) override { }

  virtual void enterDo_to_until_stmt(SASParser::Do_to_until_stmtContext * /*ctx*/) override { }
  virtual void exitDo_to_until_stmt(SASParser::Do_to_until_stmtContext * /*ctx*/) override { }

  virtual void enterDo_while_stmt(SASParser::Do_while_stmtContext * /*ctx*/) override { }
  virtual void exitDo_while_stmt(SASParser::Do_while_stmtContext * /*ctx*/) override { }

  virtual void enterDo_until_stmt(SASParser::Do_until_stmtContext * /*ctx*/) override { }
  virtual void exitDo_until_stmt(SASParser::Do_until_stmtContext * /*ctx*/) override { }

  virtual void enterExpression(SASParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SASParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionList(SASParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(SASParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterOf_var_list(SASParser::Of_var_listContext * /*ctx*/) override { }
  virtual void exitOf_var_list(SASParser::Of_var_listContext * /*ctx*/) override { }

  virtual void enterIdentifiers_list(SASParser::Identifiers_listContext * /*ctx*/) override { }
  virtual void exitIdentifiers_list(SASParser::Identifiers_listContext * /*ctx*/) override { }

  virtual void enterIn_var_list(SASParser::In_var_listContext * /*ctx*/) override { }
  virtual void exitIn_var_list(SASParser::In_var_listContext * /*ctx*/) override { }

  virtual void enterColonInts(SASParser::ColonIntsContext * /*ctx*/) override { }
  virtual void exitColonInts(SASParser::ColonIntsContext * /*ctx*/) override { }

  virtual void enterLiteral(SASParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(SASParser::LiteralContext * /*ctx*/) override { }

  virtual void enterVariables(SASParser::VariablesContext * /*ctx*/) override { }
  virtual void exitVariables(SASParser::VariablesContext * /*ctx*/) override { }

  virtual void enterAbort_main(SASParser::Abort_mainContext * /*ctx*/) override { }
  virtual void exitAbort_main(SASParser::Abort_mainContext * /*ctx*/) override { }

  virtual void enterAbort_stmt(SASParser::Abort_stmtContext * /*ctx*/) override { }
  virtual void exitAbort_stmt(SASParser::Abort_stmtContext * /*ctx*/) override { }

  virtual void enterFile_spec(SASParser::File_specContext * /*ctx*/) override { }
  virtual void exitFile_spec(SASParser::File_specContext * /*ctx*/) override { }

  virtual void enterProc_main(SASParser::Proc_mainContext * /*ctx*/) override { }
  virtual void exitProc_main(SASParser::Proc_mainContext * /*ctx*/) override { }

  virtual void enterProc_stmt(SASParser::Proc_stmtContext * /*ctx*/) override { }
  virtual void exitProc_stmt(SASParser::Proc_stmtContext * /*ctx*/) override { }

  virtual void enterProc_name(SASParser::Proc_nameContext * /*ctx*/) override { }
  virtual void exitProc_name(SASParser::Proc_nameContext * /*ctx*/) override { }

  virtual void enterArray_main(SASParser::Array_mainContext * /*ctx*/) override { }
  virtual void exitArray_main(SASParser::Array_mainContext * /*ctx*/) override { }

  virtual void enterArray_stmt(SASParser::Array_stmtContext * /*ctx*/) override { }
  virtual void exitArray_stmt(SASParser::Array_stmtContext * /*ctx*/) override { }

  virtual void enterArray_name(SASParser::Array_nameContext * /*ctx*/) override { }
  virtual void exitArray_name(SASParser::Array_nameContext * /*ctx*/) override { }

  virtual void enterArray_subscript(SASParser::Array_subscriptContext * /*ctx*/) override { }
  virtual void exitArray_subscript(SASParser::Array_subscriptContext * /*ctx*/) override { }

  virtual void enterArray_elements(SASParser::Array_elementsContext * /*ctx*/) override { }
  virtual void exitArray_elements(SASParser::Array_elementsContext * /*ctx*/) override { }

  virtual void enterInitial_value_list(SASParser::Initial_value_listContext * /*ctx*/) override { }
  virtual void exitInitial_value_list(SASParser::Initial_value_listContext * /*ctx*/) override { }

  virtual void enterInitial_value_list_item(SASParser::Initial_value_list_itemContext * /*ctx*/) override { }
  virtual void exitInitial_value_list_item(SASParser::Initial_value_list_itemContext * /*ctx*/) override { }

  virtual void enterInitial_value_list_bk(SASParser::Initial_value_list_bkContext * /*ctx*/) override { }
  virtual void exitInitial_value_list_bk(SASParser::Initial_value_list_bkContext * /*ctx*/) override { }

  virtual void enterConstant_iter_value(SASParser::Constant_iter_valueContext * /*ctx*/) override { }
  virtual void exitConstant_iter_value(SASParser::Constant_iter_valueContext * /*ctx*/) override { }

  virtual void enterConstant_value(SASParser::Constant_valueContext * /*ctx*/) override { }
  virtual void exitConstant_value(SASParser::Constant_valueContext * /*ctx*/) override { }

  virtual void enterAssign_main(SASParser::Assign_mainContext * /*ctx*/) override { }
  virtual void exitAssign_main(SASParser::Assign_mainContext * /*ctx*/) override { }

  virtual void enterAssign_stmt(SASParser::Assign_stmtContext * /*ctx*/) override { }
  virtual void exitAssign_stmt(SASParser::Assign_stmtContext * /*ctx*/) override { }

  virtual void enterBy_main(SASParser::By_mainContext * /*ctx*/) override { }
  virtual void exitBy_main(SASParser::By_mainContext * /*ctx*/) override { }

  virtual void enterBy_stmt(SASParser::By_stmtContext * /*ctx*/) override { }
  virtual void exitBy_stmt(SASParser::By_stmtContext * /*ctx*/) override { }

  virtual void enterCall_main(SASParser::Call_mainContext * /*ctx*/) override { }
  virtual void exitCall_main(SASParser::Call_mainContext * /*ctx*/) override { }

  virtual void enterCall_stmt(SASParser::Call_stmtContext * /*ctx*/) override { }
  virtual void exitCall_stmt(SASParser::Call_stmtContext * /*ctx*/) override { }

  virtual void enterData_main(SASParser::Data_mainContext * /*ctx*/) override { }
  virtual void exitData_main(SASParser::Data_mainContext * /*ctx*/) override { }

  virtual void enterData_stmt(SASParser::Data_stmtContext * /*ctx*/) override { }
  virtual void exitData_stmt(SASParser::Data_stmtContext * /*ctx*/) override { }

  virtual void enterDataset_name_opt(SASParser::Dataset_name_optContext * /*ctx*/) override { }
  virtual void exitDataset_name_opt(SASParser::Dataset_name_optContext * /*ctx*/) override { }

  virtual void enterDatastmt_cmd(SASParser::Datastmt_cmdContext * /*ctx*/) override { }
  virtual void exitDatastmt_cmd(SASParser::Datastmt_cmdContext * /*ctx*/) override { }

  virtual void enterView_dsname_opt(SASParser::View_dsname_optContext * /*ctx*/) override { }
  virtual void exitView_dsname_opt(SASParser::View_dsname_optContext * /*ctx*/) override { }

  virtual void enterView_name(SASParser::View_nameContext * /*ctx*/) override { }
  virtual void exitView_name(SASParser::View_nameContext * /*ctx*/) override { }

  virtual void enterDataset_name(SASParser::Dataset_nameContext * /*ctx*/) override { }
  virtual void exitDataset_name(SASParser::Dataset_nameContext * /*ctx*/) override { }

  virtual void enterProgram_name(SASParser::Program_nameContext * /*ctx*/) override { }
  virtual void exitProgram_name(SASParser::Program_nameContext * /*ctx*/) override { }

  virtual void enterPasswd_opt(SASParser::Passwd_optContext * /*ctx*/) override { }
  virtual void exitPasswd_opt(SASParser::Passwd_optContext * /*ctx*/) override { }

  virtual void enterSource_opt(SASParser::Source_optContext * /*ctx*/) override { }
  virtual void exitSource_opt(SASParser::Source_optContext * /*ctx*/) override { }

  virtual void enterDatalines_main(SASParser::Datalines_mainContext * /*ctx*/) override { }
  virtual void exitDatalines_main(SASParser::Datalines_mainContext * /*ctx*/) override { }

  virtual void enterDatalines_stmt(SASParser::Datalines_stmtContext * /*ctx*/) override { }
  virtual void exitDatalines_stmt(SASParser::Datalines_stmtContext * /*ctx*/) override { }

  virtual void enterDatalines4_stmt(SASParser::Datalines4_stmtContext * /*ctx*/) override { }
  virtual void exitDatalines4_stmt(SASParser::Datalines4_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_main(SASParser::Drop_mainContext * /*ctx*/) override { }
  virtual void exitDrop_main(SASParser::Drop_mainContext * /*ctx*/) override { }

  virtual void enterDrop_stmt(SASParser::Drop_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_stmt(SASParser::Drop_stmtContext * /*ctx*/) override { }

  virtual void enterFilename_main(SASParser::Filename_mainContext * /*ctx*/) override { }
  virtual void exitFilename_main(SASParser::Filename_mainContext * /*ctx*/) override { }

  virtual void enterFilename_stmt(SASParser::Filename_stmtContext * /*ctx*/) override { }
  virtual void exitFilename_stmt(SASParser::Filename_stmtContext * /*ctx*/) override { }

  virtual void enterInfile_main(SASParser::Infile_mainContext * /*ctx*/) override { }
  virtual void exitInfile_main(SASParser::Infile_mainContext * /*ctx*/) override { }

  virtual void enterInfile_stmt(SASParser::Infile_stmtContext * /*ctx*/) override { }
  virtual void exitInfile_stmt(SASParser::Infile_stmtContext * /*ctx*/) override { }

  virtual void enterFile_specification(SASParser::File_specificationContext * /*ctx*/) override { }
  virtual void exitFile_specification(SASParser::File_specificationContext * /*ctx*/) override { }

  virtual void enterDevice_type(SASParser::Device_typeContext * /*ctx*/) override { }
  virtual void exitDevice_type(SASParser::Device_typeContext * /*ctx*/) override { }

  virtual void enterInfile_options(SASParser::Infile_optionsContext * /*ctx*/) override { }
  virtual void exitInfile_options(SASParser::Infile_optionsContext * /*ctx*/) override { }

  virtual void enterInput_main(SASParser::Input_mainContext * /*ctx*/) override { }
  virtual void exitInput_main(SASParser::Input_mainContext * /*ctx*/) override { }

  virtual void enterInput_stmt(SASParser::Input_stmtContext * /*ctx*/) override { }
  virtual void exitInput_stmt(SASParser::Input_stmtContext * /*ctx*/) override { }

  virtual void enterPut_stmt(SASParser::Put_stmtContext * /*ctx*/) override { }
  virtual void exitPut_stmt(SASParser::Put_stmtContext * /*ctx*/) override { }

  virtual void enterInput_specification(SASParser::Input_specificationContext * /*ctx*/) override { }
  virtual void exitInput_specification(SASParser::Input_specificationContext * /*ctx*/) override { }

  virtual void enterPut_specification(SASParser::Put_specificationContext * /*ctx*/) override { }
  virtual void exitPut_specification(SASParser::Put_specificationContext * /*ctx*/) override { }

  virtual void enterPointer_control(SASParser::Pointer_controlContext * /*ctx*/) override { }
  virtual void exitPointer_control(SASParser::Pointer_controlContext * /*ctx*/) override { }

  virtual void enterInformat_list(SASParser::Informat_listContext * /*ctx*/) override { }
  virtual void exitInformat_list(SASParser::Informat_listContext * /*ctx*/) override { }

  virtual void enterInput_variable_format(SASParser::Input_variable_formatContext * /*ctx*/) override { }
  virtual void exitInput_variable_format(SASParser::Input_variable_formatContext * /*ctx*/) override { }

  virtual void enterInput_variable(SASParser::Input_variableContext * /*ctx*/) override { }
  virtual void exitInput_variable(SASParser::Input_variableContext * /*ctx*/) override { }

  virtual void enterPut_variable_format(SASParser::Put_variable_formatContext * /*ctx*/) override { }
  virtual void exitPut_variable_format(SASParser::Put_variable_formatContext * /*ctx*/) override { }

  virtual void enterPut_variable(SASParser::Put_variableContext * /*ctx*/) override { }
  virtual void exitPut_variable(SASParser::Put_variableContext * /*ctx*/) override { }

  virtual void enterColumn_point_control(SASParser::Column_point_controlContext * /*ctx*/) override { }
  virtual void exitColumn_point_control(SASParser::Column_point_controlContext * /*ctx*/) override { }

  virtual void enterLine_point_control(SASParser::Line_point_controlContext * /*ctx*/) override { }
  virtual void exitLine_point_control(SASParser::Line_point_controlContext * /*ctx*/) override { }

  virtual void enterFormat_modifier(SASParser::Format_modifierContext * /*ctx*/) override { }
  virtual void exitFormat_modifier(SASParser::Format_modifierContext * /*ctx*/) override { }

  virtual void enterColumn_specifications(SASParser::Column_specificationsContext * /*ctx*/) override { }
  virtual void exitColumn_specifications(SASParser::Column_specificationsContext * /*ctx*/) override { }

  virtual void enterLet_main(SASParser::Let_mainContext * /*ctx*/) override { }
  virtual void exitLet_main(SASParser::Let_mainContext * /*ctx*/) override { }

  virtual void enterLet_stmt(SASParser::Let_stmtContext * /*ctx*/) override { }
  virtual void exitLet_stmt(SASParser::Let_stmtContext * /*ctx*/) override { }

  virtual void enterMeans_main(SASParser::Means_mainContext * /*ctx*/) override { }
  virtual void exitMeans_main(SASParser::Means_mainContext * /*ctx*/) override { }

  virtual void enterMeans_proc(SASParser::Means_procContext * /*ctx*/) override { }
  virtual void exitMeans_proc(SASParser::Means_procContext * /*ctx*/) override { }

  virtual void enterStatistic_keyword(SASParser::Statistic_keywordContext * /*ctx*/) override { }
  virtual void exitStatistic_keyword(SASParser::Statistic_keywordContext * /*ctx*/) override { }

  virtual void enterSpaced_identifiers(SASParser::Spaced_identifiersContext * /*ctx*/) override { }
  virtual void exitSpaced_identifiers(SASParser::Spaced_identifiersContext * /*ctx*/) override { }

  virtual void enterVar_stmt(SASParser::Var_stmtContext * /*ctx*/) override { }
  virtual void exitVar_stmt(SASParser::Var_stmtContext * /*ctx*/) override { }

  virtual void enterGlm_main(SASParser::Glm_mainContext * /*ctx*/) override { }
  virtual void exitGlm_main(SASParser::Glm_mainContext * /*ctx*/) override { }

  virtual void enterGlm_proc(SASParser::Glm_procContext * /*ctx*/) override { }
  virtual void exitGlm_proc(SASParser::Glm_procContext * /*ctx*/) override { }

  virtual void enterFreq_main(SASParser::Freq_mainContext * /*ctx*/) override { }
  virtual void exitFreq_main(SASParser::Freq_mainContext * /*ctx*/) override { }

  virtual void enterFreq_proc(SASParser::Freq_procContext * /*ctx*/) override { }
  virtual void exitFreq_proc(SASParser::Freq_procContext * /*ctx*/) override { }

  virtual void enterImport_main(SASParser::Import_mainContext * /*ctx*/) override { }
  virtual void exitImport_main(SASParser::Import_mainContext * /*ctx*/) override { }

  virtual void enterImport_proc(SASParser::Import_procContext * /*ctx*/) override { }
  virtual void exitImport_proc(SASParser::Import_procContext * /*ctx*/) override { }

  virtual void enterTitle_main(SASParser::Title_mainContext * /*ctx*/) override { }
  virtual void exitTitle_main(SASParser::Title_mainContext * /*ctx*/) override { }

  virtual void enterTitle_stmt(SASParser::Title_stmtContext * /*ctx*/) override { }
  virtual void exitTitle_stmt(SASParser::Title_stmtContext * /*ctx*/) override { }

  virtual void enterRun_main(SASParser::Run_mainContext * /*ctx*/) override { }
  virtual void exitRun_main(SASParser::Run_mainContext * /*ctx*/) override { }

  virtual void enterRun_stmt(SASParser::Run_stmtContext * /*ctx*/) override { }
  virtual void exitRun_stmt(SASParser::Run_stmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

