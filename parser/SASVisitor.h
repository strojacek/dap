
// Generated from SAS.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SASParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SASParser.
 */
class  SASVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SASParser.
   */
    virtual std::any visitParse(SASParser::ParseContext *context) = 0;

    virtual std::any visitSas_stmt_list(SASParser::Sas_stmt_listContext *context) = 0;

    virtual std::any visitIf_stmt(SASParser::If_stmtContext *context) = 0;

    virtual std::any visitIf_then_else_stmt(SASParser::If_then_else_stmtContext *context) = 0;

    virtual std::any visitDelete_stmt(SASParser::Delete_stmtContext *context) = 0;

    virtual std::any visitDo_to_stmt(SASParser::Do_to_stmtContext *context) = 0;

    virtual std::any visitDo_to_by_stmt(SASParser::Do_to_by_stmtContext *context) = 0;

    virtual std::any visitDo_to_while_stmt(SASParser::Do_to_while_stmtContext *context) = 0;

    virtual std::any visitDo_to_until_stmt(SASParser::Do_to_until_stmtContext *context) = 0;

    virtual std::any visitDo_while_stmt(SASParser::Do_while_stmtContext *context) = 0;

    virtual std::any visitDo_until_stmt(SASParser::Do_until_stmtContext *context) = 0;

    virtual std::any visitExpression(SASParser::ExpressionContext *context) = 0;

    virtual std::any visitExpressionList(SASParser::ExpressionListContext *context) = 0;

    virtual std::any visitOf_var_list(SASParser::Of_var_listContext *context) = 0;

    virtual std::any visitIdentifiers_list(SASParser::Identifiers_listContext *context) = 0;

    virtual std::any visitIn_var_list(SASParser::In_var_listContext *context) = 0;

    virtual std::any visitColonInts(SASParser::ColonIntsContext *context) = 0;

    virtual std::any visitLiteral(SASParser::LiteralContext *context) = 0;

    virtual std::any visitVariables(SASParser::VariablesContext *context) = 0;

    virtual std::any visitAbort_main(SASParser::Abort_mainContext *context) = 0;

    virtual std::any visitAbort_stmt(SASParser::Abort_stmtContext *context) = 0;

    virtual std::any visitFile_spec(SASParser::File_specContext *context) = 0;

    virtual std::any visitProc_main(SASParser::Proc_mainContext *context) = 0;

    virtual std::any visitProc_stmt(SASParser::Proc_stmtContext *context) = 0;

    virtual std::any visitProc_name(SASParser::Proc_nameContext *context) = 0;

    virtual std::any visitArray_main(SASParser::Array_mainContext *context) = 0;

    virtual std::any visitArray_stmt(SASParser::Array_stmtContext *context) = 0;

    virtual std::any visitArray_name(SASParser::Array_nameContext *context) = 0;

    virtual std::any visitArray_subscript(SASParser::Array_subscriptContext *context) = 0;

    virtual std::any visitArray_elements(SASParser::Array_elementsContext *context) = 0;

    virtual std::any visitInitial_value_list(SASParser::Initial_value_listContext *context) = 0;

    virtual std::any visitInitial_value_list_item(SASParser::Initial_value_list_itemContext *context) = 0;

    virtual std::any visitInitial_value_list_bk(SASParser::Initial_value_list_bkContext *context) = 0;

    virtual std::any visitConstant_iter_value(SASParser::Constant_iter_valueContext *context) = 0;

    virtual std::any visitConstant_value(SASParser::Constant_valueContext *context) = 0;

    virtual std::any visitAssign_main(SASParser::Assign_mainContext *context) = 0;

    virtual std::any visitAssign_stmt(SASParser::Assign_stmtContext *context) = 0;

    virtual std::any visitBy_main(SASParser::By_mainContext *context) = 0;

    virtual std::any visitBy_stmt(SASParser::By_stmtContext *context) = 0;

    virtual std::any visitCall_main(SASParser::Call_mainContext *context) = 0;

    virtual std::any visitCall_stmt(SASParser::Call_stmtContext *context) = 0;

    virtual std::any visitData_main(SASParser::Data_mainContext *context) = 0;

    virtual std::any visitData_stmt(SASParser::Data_stmtContext *context) = 0;

    virtual std::any visitDataset_name_opt(SASParser::Dataset_name_optContext *context) = 0;

    virtual std::any visitDatastmt_cmd(SASParser::Datastmt_cmdContext *context) = 0;

    virtual std::any visitView_dsname_opt(SASParser::View_dsname_optContext *context) = 0;

    virtual std::any visitView_name(SASParser::View_nameContext *context) = 0;

    virtual std::any visitDataset_name(SASParser::Dataset_nameContext *context) = 0;

    virtual std::any visitProgram_name(SASParser::Program_nameContext *context) = 0;

    virtual std::any visitPasswd_opt(SASParser::Passwd_optContext *context) = 0;

    virtual std::any visitSource_opt(SASParser::Source_optContext *context) = 0;

    virtual std::any visitDatalines_main(SASParser::Datalines_mainContext *context) = 0;

    virtual std::any visitDatalines_stmt(SASParser::Datalines_stmtContext *context) = 0;

    virtual std::any visitDatalines4_stmt(SASParser::Datalines4_stmtContext *context) = 0;

    virtual std::any visitDrop_main(SASParser::Drop_mainContext *context) = 0;

    virtual std::any visitDrop_stmt(SASParser::Drop_stmtContext *context) = 0;

    virtual std::any visitFilename_main(SASParser::Filename_mainContext *context) = 0;

    virtual std::any visitFilename_stmt(SASParser::Filename_stmtContext *context) = 0;

    virtual std::any visitInfile_main(SASParser::Infile_mainContext *context) = 0;

    virtual std::any visitInfile_stmt(SASParser::Infile_stmtContext *context) = 0;

    virtual std::any visitFile_specification(SASParser::File_specificationContext *context) = 0;

    virtual std::any visitDevice_type(SASParser::Device_typeContext *context) = 0;

    virtual std::any visitInfile_options(SASParser::Infile_optionsContext *context) = 0;

    virtual std::any visitInput_main(SASParser::Input_mainContext *context) = 0;

    virtual std::any visitInput_stmt(SASParser::Input_stmtContext *context) = 0;

    virtual std::any visitPut_stmt(SASParser::Put_stmtContext *context) = 0;

    virtual std::any visitInput_specification(SASParser::Input_specificationContext *context) = 0;

    virtual std::any visitPut_specification(SASParser::Put_specificationContext *context) = 0;

    virtual std::any visitPointer_control(SASParser::Pointer_controlContext *context) = 0;

    virtual std::any visitInformat_list(SASParser::Informat_listContext *context) = 0;

    virtual std::any visitInput_variable_format(SASParser::Input_variable_formatContext *context) = 0;

    virtual std::any visitInput_variable(SASParser::Input_variableContext *context) = 0;

    virtual std::any visitPut_variable_format(SASParser::Put_variable_formatContext *context) = 0;

    virtual std::any visitPut_variable(SASParser::Put_variableContext *context) = 0;

    virtual std::any visitColumn_point_control(SASParser::Column_point_controlContext *context) = 0;

    virtual std::any visitLine_point_control(SASParser::Line_point_controlContext *context) = 0;

    virtual std::any visitFormat_modifier(SASParser::Format_modifierContext *context) = 0;

    virtual std::any visitColumn_specifications(SASParser::Column_specificationsContext *context) = 0;

    virtual std::any visitLet_main(SASParser::Let_mainContext *context) = 0;

    virtual std::any visitLet_stmt(SASParser::Let_stmtContext *context) = 0;

    virtual std::any visitMeans_main(SASParser::Means_mainContext *context) = 0;

    virtual std::any visitMeans_proc(SASParser::Means_procContext *context) = 0;

    virtual std::any visitStatistic_keyword(SASParser::Statistic_keywordContext *context) = 0;

    virtual std::any visitSpaced_identifiers(SASParser::Spaced_identifiersContext *context) = 0;

    virtual std::any visitVar_stmt(SASParser::Var_stmtContext *context) = 0;

    virtual std::any visitGlm_main(SASParser::Glm_mainContext *context) = 0;

    virtual std::any visitGlm_proc(SASParser::Glm_procContext *context) = 0;

    virtual std::any visitFreq_main(SASParser::Freq_mainContext *context) = 0;

    virtual std::any visitFreq_proc(SASParser::Freq_procContext *context) = 0;

    virtual std::any visitImport_main(SASParser::Import_mainContext *context) = 0;

    virtual std::any visitImport_proc(SASParser::Import_procContext *context) = 0;

    virtual std::any visitTitle_main(SASParser::Title_mainContext *context) = 0;

    virtual std::any visitTitle_stmt(SASParser::Title_stmtContext *context) = 0;

    virtual std::any visitRun_main(SASParser::Run_mainContext *context) = 0;

    virtual std::any visitRun_stmt(SASParser::Run_stmtContext *context) = 0;


};

