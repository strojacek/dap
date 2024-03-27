
// Generated from SAS.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SASVisitor.h"


/**
 * This class provides an empty implementation of SASVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SASBaseVisitor : public SASVisitor {
public:

  virtual std::any visitParse(SASParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSas_stmt_list(SASParser::Sas_stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_stmt(SASParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_then_else_stmt(SASParser::If_then_else_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDelete_stmt(SASParser::Delete_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_to_stmt(SASParser::Do_to_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_to_by_stmt(SASParser::Do_to_by_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_to_while_stmt(SASParser::Do_to_while_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_to_until_stmt(SASParser::Do_to_until_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_while_stmt(SASParser::Do_while_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_until_stmt(SASParser::Do_until_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(SASParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(SASParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOf_var_list(SASParser::Of_var_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifiers_list(SASParser::Identifiers_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIn_var_list(SASParser::In_var_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColonInts(SASParser::ColonIntsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(SASParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariables(SASParser::VariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbort_main(SASParser::Abort_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbort_stmt(SASParser::Abort_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFile_spec(SASParser::File_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProc_main(SASParser::Proc_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProc_stmt(SASParser::Proc_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProc_name(SASParser::Proc_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_main(SASParser::Array_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_stmt(SASParser::Array_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_name(SASParser::Array_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_subscript(SASParser::Array_subscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_elements(SASParser::Array_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitial_value_list(SASParser::Initial_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitial_value_list_item(SASParser::Initial_value_list_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitial_value_list_bk(SASParser::Initial_value_list_bkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_iter_value(SASParser::Constant_iter_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_value(SASParser::Constant_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_main(SASParser::Assign_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_stmt(SASParser::Assign_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBy_main(SASParser::By_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBy_stmt(SASParser::By_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_main(SASParser::Call_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_stmt(SASParser::Call_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitData_main(SASParser::Data_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitData_stmt(SASParser::Data_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataset_name_opt(SASParser::Dataset_name_optContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatastmt_cmd(SASParser::Datastmt_cmdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitView_dsname_opt(SASParser::View_dsname_optContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitView_name(SASParser::View_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataset_name(SASParser::Dataset_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram_name(SASParser::Program_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPasswd_opt(SASParser::Passwd_optContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSource_opt(SASParser::Source_optContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatalines_main(SASParser::Datalines_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatalines_stmt(SASParser::Datalines_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatalines4_stmt(SASParser::Datalines4_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDrop_main(SASParser::Drop_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDrop_stmt(SASParser::Drop_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilename_main(SASParser::Filename_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilename_stmt(SASParser::Filename_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfile_main(SASParser::Infile_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfile_stmt(SASParser::Infile_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFile_specification(SASParser::File_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDevice_type(SASParser::Device_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfile_options(SASParser::Infile_optionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_main(SASParser::Input_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_stmt(SASParser::Input_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPut_stmt(SASParser::Put_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_specification(SASParser::Input_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPut_specification(SASParser::Put_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointer_control(SASParser::Pointer_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInformat_list(SASParser::Informat_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_variable_format(SASParser::Input_variable_formatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_variable(SASParser::Input_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPut_variable_format(SASParser::Put_variable_formatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPut_variable(SASParser::Put_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_point_control(SASParser::Column_point_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLine_point_control(SASParser::Line_point_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormat_modifier(SASParser::Format_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn_specifications(SASParser::Column_specificationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_main(SASParser::Let_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_stmt(SASParser::Let_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeans_main(SASParser::Means_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeans_proc(SASParser::Means_procContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatistic_keyword(SASParser::Statistic_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSpaced_identifiers(SASParser::Spaced_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_stmt(SASParser::Var_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlm_main(SASParser::Glm_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlm_proc(SASParser::Glm_procContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFreq_main(SASParser::Freq_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFreq_proc(SASParser::Freq_procContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_main(SASParser::Import_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_proc(SASParser::Import_procContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTitle_main(SASParser::Title_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTitle_stmt(SASParser::Title_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRun_main(SASParser::Run_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRun_stmt(SASParser::Run_stmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

