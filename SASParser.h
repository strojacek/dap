
// Generated from SAS.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SASParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, ABEND = 10, END = 11, LENGTH = 12, QKUPCASE = 13, 
    SYSEVALF = 14, ABORT = 15, EVAL = 16, LET = 17, QSCAN = 18, SYSEXEC = 19, 
    ACT = 20, FILE = 21, LIST = 22, QSUBSTR = 23, SYSFUNC = 24, ACTIVATE = 25, 
    GLOBAL = 26, LISTM = 27, QSYSFUNC = 28, SYSGET = 29, BQUOTE = 30, GO = 31, 
    LOCAL = 32, QUOTE = 33, SYSRPUT = 34, BY = 35, GOTO = 36, MACRO = 37, 
    QUPCASE = 38, THEN = 39, CLEAR = 40, IF = 41, MEND = 42, RESOLVE = 43, 
    TO = 44, CLOSE = 45, INC = 46, PAUSE = 47, RETURN = 48, TSO = 49, CMS = 50, 
    INCLUDE = 51, NRSTR = 52, RUN = 53, UNQUOTE = 54, COMANDR = 55, INDEX = 56, 
    ON = 57, SAVE = 58, UNSTR = 59, COPY = 60, INFILE = 61, OPEN = 62, SCAN = 63, 
    UNTIL = 64, DEACT = 65, INPUT = 66, PUT = 67, STOP = 68, UPCASE = 69, 
    DEL = 70, KCMPRES = 71, NRBQUOTE = 72, STR = 73, WHILE = 74, DELETE = 75, 
    KINDEX = 76, NRQUOTE = 77, SYSCALL = 78, WINDOW = 79, DISPLAY = 80, 
    KLEFT = 81, METASYM = 82, SUBSTR = 83, DMIDSPLY = 84, KLENGTH = 85, 
    QKCMPRES = 86, SUPERQ = 87, DMISPLIT = 88, KSCAN = 89, QKLEFT = 90, 
    SYMDEL = 91, DO = 92, KSUBSTR = 93, QKSCAN = 94, SYMEXIST = 95, EDIT = 96, 
    KTRIM = 97, QKSUBSTR = 98, SYMGLOBL = 99, ELSE = 100, KUPCASE = 101, 
    QKTRIM = 102, SYMLOCAL = 103, Tk_NULL = 104, CANCEL = 105, NOLIST = 106, 
    ARRAY = 107, ARRAY_NUMERIC_ELEMENTS = 108, ARRAY_CHARACTER_ELEMENTS = 109, 
    ARRAY_ALL_ELEMENTS = 110, GROUPFORMAT = 111, NOTSORTED = 112, DESCENDING = 113, 
    CALL = 114, DEBUG = 115, NESTING = 116, STACK = 117, READ = 118, PW = 119, 
    SOURCE = 120, VIEW = 121, PGM = 122, ENCRYPT = 123, NOSAVE = 124, DATALINES = 125, 
    CARDS = 126, LINES = 127, DATALINES4 = 128, CARDS4 = 129, LINES4 = 130, 
    END_DATALINES4 = 131, ALTER = 132, DISK = 133, DUMMY = 134, GTERM = 135, 
    PIPE = 136, PLOTTER = 137, PRINTER = 138, TAPE = 139, TEMP = 140, TERMINAL = 141, 
    UPRINTER = 142, DSD = 143, EXPANDTABS = 144, NOEXPANDTABS = 145, FLOWOVER = 146, 
    MISSOVER = 147, PAD = 148, NOPAD = 149, SCANOVER = 150, SHAREBUFFERS = 151, 
    STOPOVER = 152, TRUNCOVER = 153, V_INFILE_ = 154, INPUT_ODS = 155, DATE = 156, 
    DATETIME = 157, DDMMYY = 158, INFORMAT_COMMA = 159, INFORMAT_CHAR = 160, 
    DROP = 161, PROC = 162, ANOVA = 163, MEANS = 164, REG = 165, CORR = 166, 
    SGPLOT = 167, PRINT = 168, DATA = 169, GLM = 170, FREQ = 171, SQL = 172, 
    UNIVARIATE = 173, NPAR1WAY = 174, IMPORT = 175, SORT = 176, DATASETS = 177, 
    TABULATE = 178, RANK = 179, CHART = 180, LOGISTIC = 181, SURVEYSELECT = 182, 
    Informat = 183, DOLLAR = 184, EQ = 185, NE = 186, GT = 187, LT = 188, 
    GE = 189, LE = 190, IN = 191, EQC = 192, NEC = 193, GTC = 194, LTC = 195, 
    GEC = 196, LEC = 197, INColon = 198, AND = 199, OR = 200, NOT = 201, 
    MIN = 202, MAX = 203, DateLiteral = 204, TimeLiteral = 205, DateTimeLiteral = 206, 
    BitLiteral = 207, NameLiteral = 208, HexLiteral = 209, STRINGLITERAL = 210, 
    INT = 211, FloatingPointLiteral = 212, Identifier = 213, DOT = 214, 
    AT = 215, EQUAL = 216, COMMA = 217, LBracket = 218, RBracket = 219, 
    WS = 220, COMMENT = 221, LINE_COMMENT = 222, SEMICOLON = 223, OF = 224, 
    MissingValueLiteral = 225, COLON = 226, PERCENT = 227, ADD = 228, SUB = 229, 
    MUL = 230, DIV = 231, VERLINE = 232, EXCLAMATION = 233, LParentheses = 234, 
    RParentheses = 235, LBraces = 236, RBraces = 237, LSqBracket = 238, 
    RSqBracket = 239, SK_MIN = 240, SK_MAX = 241, SK_MEAN = 242, SK_N = 243, 
    SK_SUM = 244, SK_VAR = 245, SUMSIZE = 246, NOTRAP = 247, CLASS = 248, 
    MODEL = 249, ID = 250, WEIGHT = 251, EXACT = 252, TABLES = 253, TEST = 254, 
    SURVEYSELCT = 255, FILENAME = 256, TITLE = 257
  };

  enum {
    RuleParse = 0, RuleSas_stmt_list = 1, RuleIf_stmt = 2, RuleIf_then_else_stmt = 3, 
    RuleDelete_stmt = 4, RuleDo_to_stmt = 5, RuleDo_to_by_stmt = 6, RuleDo_to_while_stmt = 7, 
    RuleDo_to_until_stmt = 8, RuleDo_while_stmt = 9, RuleDo_until_stmt = 10, 
    RuleExpression = 11, RuleExpressionList = 12, RuleOf_var_list = 13, 
    RuleIdentifiers_list = 14, RuleIn_var_list = 15, RuleColonInts = 16, 
    RuleLiteral = 17, RuleVariables = 18, RuleAbort_main = 19, RuleAbort_stmt = 20, 
    RuleFile_spec = 21, RuleProc_main = 22, RuleProc_stmt = 23, RuleProc_name = 24, 
    RuleArray_main = 25, RuleArray_stmt = 26, RuleArray_name = 27, RuleArray_subscript = 28, 
    RuleArray_elements = 29, RuleInitial_value_list = 30, RuleInitial_value_list_item = 31, 
    RuleInitial_value_list_bk = 32, RuleConstant_iter_value = 33, RuleConstant_value = 34, 
    RuleAssign_main = 35, RuleAssign_stmt = 36, RuleBy_main = 37, RuleBy_stmt = 38, 
    RuleCall_main = 39, RuleCall_stmt = 40, RuleData_main = 41, RuleData_stmt = 42, 
    RuleDataset_name_opt = 43, RuleDatastmt_cmd = 44, RuleView_dsname_opt = 45, 
    RuleView_name = 46, RuleDataset_name = 47, RuleProgram_name = 48, RulePasswd_opt = 49, 
    RuleSource_opt = 50, RuleDatalines_main = 51, RuleDatalines_stmt = 52, 
    RuleDatalines4_stmt = 53, RuleDrop_main = 54, RuleDrop_stmt = 55, RuleFilename_main = 56, 
    RuleFilename_stmt = 57, RuleInfile_main = 58, RuleInfile_stmt = 59, 
    RuleFile_specification = 60, RuleDevice_type = 61, RuleInfile_options = 62, 
    RuleInput_main = 63, RuleInput_stmt = 64, RulePut_stmt = 65, RuleInput_specification = 66, 
    RulePut_specification = 67, RulePointer_control = 68, RuleInformat_list = 69, 
    RuleInput_variable_format = 70, RuleInput_variable = 71, RulePut_variable_format = 72, 
    RulePut_variable = 73, RuleColumn_point_control = 74, RuleLine_point_control = 75, 
    RuleFormat_modifier = 76, RuleColumn_specifications = 77, RuleLet_main = 78, 
    RuleLet_stmt = 79, RuleMeans_main = 80, RuleMeans_proc = 81, RuleStatistic_keyword = 82, 
    RuleSpaced_identifiers = 83, RuleVar_stmt = 84, RuleGlm_main = 85, RuleGlm_proc = 86, 
    RuleFreq_main = 87, RuleFreq_proc = 88, RuleImport_main = 89, RuleImport_proc = 90, 
    RuleTitle_main = 91, RuleTitle_stmt = 92, RuleRun_main = 93, RuleRun_stmt = 94
  };

  explicit SASParser(antlr4::TokenStream *input);

  SASParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SASParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ParseContext;
  class Sas_stmt_listContext;
  class If_stmtContext;
  class If_then_else_stmtContext;
  class Delete_stmtContext;
  class Do_to_stmtContext;
  class Do_to_by_stmtContext;
  class Do_to_while_stmtContext;
  class Do_to_until_stmtContext;
  class Do_while_stmtContext;
  class Do_until_stmtContext;
  class ExpressionContext;
  class ExpressionListContext;
  class Of_var_listContext;
  class Identifiers_listContext;
  class In_var_listContext;
  class ColonIntsContext;
  class LiteralContext;
  class VariablesContext;
  class Abort_mainContext;
  class Abort_stmtContext;
  class File_specContext;
  class Proc_mainContext;
  class Proc_stmtContext;
  class Proc_nameContext;
  class Array_mainContext;
  class Array_stmtContext;
  class Array_nameContext;
  class Array_subscriptContext;
  class Array_elementsContext;
  class Initial_value_listContext;
  class Initial_value_list_itemContext;
  class Initial_value_list_bkContext;
  class Constant_iter_valueContext;
  class Constant_valueContext;
  class Assign_mainContext;
  class Assign_stmtContext;
  class By_mainContext;
  class By_stmtContext;
  class Call_mainContext;
  class Call_stmtContext;
  class Data_mainContext;
  class Data_stmtContext;
  class Dataset_name_optContext;
  class Datastmt_cmdContext;
  class View_dsname_optContext;
  class View_nameContext;
  class Dataset_nameContext;
  class Program_nameContext;
  class Passwd_optContext;
  class Source_optContext;
  class Datalines_mainContext;
  class Datalines_stmtContext;
  class Datalines4_stmtContext;
  class Drop_mainContext;
  class Drop_stmtContext;
  class Filename_mainContext;
  class Filename_stmtContext;
  class Infile_mainContext;
  class Infile_stmtContext;
  class File_specificationContext;
  class Device_typeContext;
  class Infile_optionsContext;
  class Input_mainContext;
  class Input_stmtContext;
  class Put_stmtContext;
  class Input_specificationContext;
  class Put_specificationContext;
  class Pointer_controlContext;
  class Informat_listContext;
  class Input_variable_formatContext;
  class Input_variableContext;
  class Put_variable_formatContext;
  class Put_variableContext;
  class Column_point_controlContext;
  class Line_point_controlContext;
  class Format_modifierContext;
  class Column_specificationsContext;
  class Let_mainContext;
  class Let_stmtContext;
  class Means_mainContext;
  class Means_procContext;
  class Statistic_keywordContext;
  class Spaced_identifiersContext;
  class Var_stmtContext;
  class Glm_mainContext;
  class Glm_procContext;
  class Freq_mainContext;
  class Freq_procContext;
  class Import_mainContext;
  class Import_procContext;
  class Title_mainContext;
  class Title_stmtContext;
  class Run_mainContext;
  class Run_stmtContext; 

  class  ParseContext : public antlr4::ParserRuleContext {
  public:
    ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Sas_stmt_listContext *> sas_stmt_list();
    Sas_stmt_listContext* sas_stmt_list(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParseContext* parse();

  class  Sas_stmt_listContext : public antlr4::ParserRuleContext {
  public:
    Sas_stmt_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Abort_stmtContext *abort_stmt();
    Array_stmtContext *array_stmt();
    By_stmtContext *by_stmt();
    Call_stmtContext *call_stmt();
    Datalines_stmtContext *datalines_stmt();
    Datalines4_stmtContext *datalines4_stmt();
    Delete_stmtContext *delete_stmt();
    Drop_stmtContext *drop_stmt();
    Data_stmtContext *data_stmt();
    Filename_stmtContext *filename_stmt();
    If_stmtContext *if_stmt();
    If_then_else_stmtContext *if_then_else_stmt();
    Do_to_stmtContext *do_to_stmt();
    Do_to_by_stmtContext *do_to_by_stmt();
    Do_while_stmtContext *do_while_stmt();
    Do_until_stmtContext *do_until_stmt();
    Do_to_while_stmtContext *do_to_while_stmt();
    Do_to_until_stmtContext *do_to_until_stmt();
    Infile_stmtContext *infile_stmt();
    Input_stmtContext *input_stmt();
    Put_stmtContext *put_stmt();
    Let_stmtContext *let_stmt();
    Means_procContext *means_proc();
    Glm_procContext *glm_proc();
    Freq_procContext *freq_proc();
    Import_procContext *import_proc();
    Proc_stmtContext *proc_stmt();
    Assign_stmtContext *assign_stmt();
    Run_stmtContext *run_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sas_stmt_listContext* sas_stmt_list();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_stmtContext* if_stmt();

  class  If_then_else_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_then_else_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *THEN();
    std::vector<Sas_stmt_listContext *> sas_stmt_list();
    Sas_stmt_listContext* sas_stmt_list(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_then_else_stmtContext* if_then_else_stmt();

  class  Delete_stmtContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delete_stmtContext* delete_stmt();

  class  Do_to_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_to_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_to_stmtContext* do_to_stmt();

  class  Do_to_by_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_to_by_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *BY();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_to_by_stmtContext* do_to_by_stmt();

  class  Do_to_while_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_to_while_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *WHILE();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_to_while_stmtContext* do_to_while_stmt();

  class  Do_to_until_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_to_until_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *UNTIL();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_to_until_stmtContext* do_to_until_stmt();

  class  Do_while_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_while_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LParentheses();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RParentheses();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_while_stmtContext* do_while_stmt();

  class  Do_until_stmtContext : public antlr4::ParserRuleContext {
  public:
    Do_until_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *LParentheses();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RParentheses();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    Sas_stmt_listContext *sas_stmt_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_until_stmtContext* do_until_stmt();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LParentheses();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RParentheses();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PERCENT();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *EQC();
    antlr4::tree::TerminalNode *NEC();
    antlr4::tree::TerminalNode *GTC();
    antlr4::tree::TerminalNode *LTC();
    antlr4::tree::TerminalNode *GEC();
    antlr4::tree::TerminalNode *LEC();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *LBraces();
    antlr4::tree::TerminalNode *RBraces();
    antlr4::tree::TerminalNode *LSqBracket();
    antlr4::tree::TerminalNode *RSqBracket();
    In_var_listContext *in_var_list();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *INColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<Of_var_listContext *> of_var_list();
    Of_var_listContext* of_var_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ExpressionListContext *> expressionList();
    ExpressionListContext* expressionList(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();
  ExpressionListContext* expressionList(int precedence);
  class  Of_var_listContext : public antlr4::ParserRuleContext {
  public:
    Of_var_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *LSqBracket();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *RSqBracket();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Of_var_listContext* of_var_list();

  class  Identifiers_listContext : public antlr4::ParserRuleContext {
  public:
    Identifiers_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifiers_listContext* identifiers_list();

  class  In_var_listContext : public antlr4::ParserRuleContext {
  public:
    In_var_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LParentheses();
    antlr4::tree::TerminalNode *RParentheses();
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);
    std::vector<ColonIntsContext *> colonInts();
    ColonIntsContext* colonInts(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  In_var_listContext* in_var_list();

  class  ColonIntsContext : public antlr4::ParserRuleContext {
  public:
    ColonIntsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColonIntsContext* colonInts();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FloatingPointLiteral();
    antlr4::tree::TerminalNode *STRINGLITERAL();
    antlr4::tree::TerminalNode *DateLiteral();
    antlr4::tree::TerminalNode *TimeLiteral();
    antlr4::tree::TerminalNode *DateTimeLiteral();
    antlr4::tree::TerminalNode *BitLiteral();
    antlr4::tree::TerminalNode *NameLiteral();
    antlr4::tree::TerminalNode *HexLiteral();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  VariablesContext : public antlr4::ParserRuleContext {
  public:
    VariablesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *DROP();
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariablesContext* variables();
  VariablesContext* variables(int precedence);
  class  Abort_mainContext : public antlr4::ParserRuleContext {
  public:
    Abort_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Abort_stmtContext *> abort_stmt();
    Abort_stmtContext* abort_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Abort_mainContext* abort_main();

  class  Abort_stmtContext : public antlr4::ParserRuleContext {
  public:
    Abort_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ABEND();
    antlr4::tree::TerminalNode *CANCEL();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *NOLIST();
    File_specContext *file_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Abort_stmtContext* abort_stmt();

  class  File_specContext : public antlr4::ParserRuleContext {
  public:
    File_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRINGLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  File_specContext* file_spec();

  class  Proc_mainContext : public antlr4::ParserRuleContext {
  public:
    Proc_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Proc_stmtContext *> proc_stmt();
    Proc_stmtContext* proc_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Proc_mainContext* proc_main();

  class  Proc_stmtContext : public antlr4::ParserRuleContext {
  public:
    Proc_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROC();
    Proc_nameContext *proc_name();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Proc_stmtContext* proc_stmt();

  class  Proc_nameContext : public antlr4::ParserRuleContext {
  public:
    Proc_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANOVA();
    antlr4::tree::TerminalNode *CORR();
    antlr4::tree::TerminalNode *MEANS();
    antlr4::tree::TerminalNode *REG();
    antlr4::tree::TerminalNode *SGPLOT();
    antlr4::tree::TerminalNode *PRINT();
    antlr4::tree::TerminalNode *GLM();
    antlr4::tree::TerminalNode *FREQ();
    antlr4::tree::TerminalNode *SQL();
    antlr4::tree::TerminalNode *UNIVARIATE();
    antlr4::tree::TerminalNode *NPAR1WAY();
    antlr4::tree::TerminalNode *IMPORT();
    antlr4::tree::TerminalNode *SORT();
    antlr4::tree::TerminalNode *DATASETS();
    antlr4::tree::TerminalNode *TABULATE();
    antlr4::tree::TerminalNode *RANK();
    antlr4::tree::TerminalNode *CHART();
    antlr4::tree::TerminalNode *LOGISTIC();
    antlr4::tree::TerminalNode *SURVEYSELCT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Proc_nameContext* proc_name();

  class  Array_mainContext : public antlr4::ParserRuleContext {
  public:
    Array_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Array_stmtContext *> array_stmt();
    Array_stmtContext* array_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_mainContext* array_main();

  class  Array_stmtContext : public antlr4::ParserRuleContext {
  public:
    Array_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    Array_nameContext *array_name();
    antlr4::tree::TerminalNode *LBracket();
    Array_subscriptContext *array_subscript();
    antlr4::tree::TerminalNode *RBracket();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *DOLLAR();
    antlr4::tree::TerminalNode *INT();
    Array_elementsContext *array_elements();
    Initial_value_listContext *initial_value_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_stmtContext* array_stmt();

  class  Array_nameContext : public antlr4::ParserRuleContext {
  public:
    Array_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_nameContext* array_name();

  class  Array_subscriptContext : public antlr4::ParserRuleContext {
  public:
    Array_subscriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUL();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_subscriptContext* array_subscript();

  class  Array_elementsContext : public antlr4::ParserRuleContext {
  public:
    Array_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY_NUMERIC_ELEMENTS();
    antlr4::tree::TerminalNode *ARRAY_CHARACTER_ELEMENTS();
    antlr4::tree::TerminalNode *ARRAY_ALL_ELEMENTS();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *SUB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_elementsContext* array_elements();

  class  Initial_value_listContext : public antlr4::ParserRuleContext {
  public:
    Initial_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LParentheses();
    antlr4::tree::TerminalNode *RParentheses();
    std::vector<Initial_value_list_itemContext *> initial_value_list_item();
    Initial_value_list_itemContext* initial_value_list_item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initial_value_listContext* initial_value_list();

  class  Initial_value_list_itemContext : public antlr4::ParserRuleContext {
  public:
    Initial_value_list_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *COLON();
    Constant_iter_valueContext *constant_iter_value();
    antlr4::tree::TerminalNode *MUL();
    Initial_value_listContext *initial_value_list();
    Constant_valueContext *constant_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initial_value_list_itemContext* initial_value_list_item();

  class  Initial_value_list_bkContext : public antlr4::ParserRuleContext {
  public:
    Initial_value_list_bkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LParentheses();
    antlr4::tree::TerminalNode *RParentheses();
    std::vector<Constant_valueContext *> constant_value();
    Constant_valueContext* constant_value(size_t i);
    std::vector<Constant_iter_valueContext *> constant_iter_value();
    Constant_iter_valueContext* constant_iter_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUL();
    antlr4::tree::TerminalNode* MUL(size_t i);
    std::vector<Initial_value_listContext *> initial_value_list();
    Initial_value_listContext* initial_value_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initial_value_list_bkContext* initial_value_list_bk();

  class  Constant_iter_valueContext : public antlr4::ParserRuleContext {
  public:
    Constant_iter_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_iter_valueContext* constant_iter_value();

  class  Constant_valueContext : public antlr4::ParserRuleContext {
  public:
    Constant_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FloatingPointLiteral();
    antlr4::tree::TerminalNode *STRINGLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_valueContext* constant_value();

  class  Assign_mainContext : public antlr4::ParserRuleContext {
  public:
    Assign_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Assign_stmtContext *> assign_stmt();
    Assign_stmtContext* assign_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_mainContext* assign_main();

  class  Assign_stmtContext : public antlr4::ParserRuleContext {
  public:
    Assign_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_stmtContext* assign_stmt();

  class  By_mainContext : public antlr4::ParserRuleContext {
  public:
    By_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<By_stmtContext *> by_stmt();
    By_stmtContext* by_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  By_mainContext* by_main();

  class  By_stmtContext : public antlr4::ParserRuleContext {
  public:
    By_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *NOTSORTED();
    antlr4::tree::TerminalNode *GROUPFORMAT();
    std::vector<antlr4::tree::TerminalNode *> DESCENDING();
    antlr4::tree::TerminalNode* DESCENDING(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  By_stmtContext* by_stmt();

  class  Call_mainContext : public antlr4::ParserRuleContext {
  public:
    Call_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Call_stmtContext *> call_stmt();
    Call_stmtContext* call_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_mainContext* call_main();

  class  Call_stmtContext : public antlr4::ParserRuleContext {
  public:
    Call_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LParentheses();
    antlr4::tree::TerminalNode *RParentheses();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_stmtContext* call_stmt();

  class  Data_mainContext : public antlr4::ParserRuleContext {
  public:
    Data_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Data_stmtContext *> data_stmt();
    Data_stmtContext* data_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_mainContext* data_main();

  class  Data_stmtContext : public antlr4::ParserRuleContext {
  public:
    Data_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATA();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *Tk_NULL();
    Datastmt_cmdContext *datastmt_cmd();
    antlr4::tree::TerminalNode *NOLIST();
    std::vector<Dataset_name_optContext *> dataset_name_opt();
    Dataset_name_optContext* dataset_name_opt(size_t i);
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *VIEW();
    antlr4::tree::TerminalNode *EQUAL();
    View_nameContext *view_name();
    std::vector<View_dsname_optContext *> view_dsname_opt();
    View_dsname_optContext* view_dsname_opt(size_t i);
    Passwd_optContext *passwd_opt();
    Source_optContext *source_opt();
    antlr4::tree::TerminalNode *NESTING();
    Dataset_nameContext *dataset_name();
    antlr4::tree::TerminalNode *PGM();
    Program_nameContext *program_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_stmtContext* data_stmt();

  class  Dataset_name_optContext : public antlr4::ParserRuleContext {
  public:
    Dataset_name_optContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Dataset_nameContext *dataset_name();
    std::vector<antlr4::tree::TerminalNode *> LParentheses();
    antlr4::tree::TerminalNode* LParentheses(size_t i);
    VariablesContext *variables();
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<antlr4::tree::TerminalNode *> RParentheses();
    antlr4::tree::TerminalNode* RParentheses(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dataset_name_optContext* dataset_name_opt();

  class  Datastmt_cmdContext : public antlr4::ParserRuleContext {
  public:
    Datastmt_cmdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *DEBUG();
    antlr4::tree::TerminalNode *NESTING();
    antlr4::tree::TerminalNode *STACK();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Datastmt_cmdContext* datastmt_cmd();

  class  View_dsname_optContext : public antlr4::ParserRuleContext {
  public:
    View_dsname_optContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LParentheses();
    antlr4::tree::TerminalNode* LParentheses(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<antlr4::tree::TerminalNode *> RParentheses();
    antlr4::tree::TerminalNode* RParentheses(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  View_dsname_optContext* view_dsname_opt();

  class  View_nameContext : public antlr4::ParserRuleContext {
  public:
    View_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariablesContext *variables();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  View_nameContext* view_name();

  class  Dataset_nameContext : public antlr4::ParserRuleContext {
  public:
    Dataset_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariablesContext *variables();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dataset_nameContext* dataset_name();

  class  Program_nameContext : public antlr4::ParserRuleContext {
  public:
    Program_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariablesContext *variables();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_nameContext* program_name();

  class  Passwd_optContext : public antlr4::ParserRuleContext {
  public:
    Passwd_optContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LParentheses();
    antlr4::tree::TerminalNode* LParentheses(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<antlr4::tree::TerminalNode *> RParentheses();
    antlr4::tree::TerminalNode* RParentheses(size_t i);
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *PW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Passwd_optContext* passwd_opt();

  class  Source_optContext : public antlr4::ParserRuleContext {
  public:
    Source_optContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LParentheses();
    antlr4::tree::TerminalNode *SOURCE();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *RParentheses();
    antlr4::tree::TerminalNode *SAVE();
    antlr4::tree::TerminalNode *ENCRYPT();
    antlr4::tree::TerminalNode *NOSAVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Source_optContext* source_opt();

  class  Datalines_mainContext : public antlr4::ParserRuleContext {
  public:
    Datalines_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Datalines_stmtContext *> datalines_stmt();
    Datalines_stmtContext* datalines_stmt(size_t i);
    std::vector<Datalines4_stmtContext *> datalines4_stmt();
    Datalines4_stmtContext* datalines4_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Datalines_mainContext* datalines_main();

  class  Datalines_stmtContext : public antlr4::ParserRuleContext {
  public:
    Datalines_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *DATALINES();
    antlr4::tree::TerminalNode *CARDS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Datalines_stmtContext* datalines_stmt();

  class  Datalines4_stmtContext : public antlr4::ParserRuleContext {
  public:
    Datalines4_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *END_DATALINES4();
    antlr4::tree::TerminalNode *DATALINES4();
    antlr4::tree::TerminalNode *CARDS4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Datalines4_stmtContext* datalines4_stmt();

  class  Drop_mainContext : public antlr4::ParserRuleContext {
  public:
    Drop_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Drop_stmtContext *> drop_stmt();
    Drop_stmtContext* drop_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Drop_mainContext* drop_main();

  class  Drop_stmtContext : public antlr4::ParserRuleContext {
  public:
    Drop_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Drop_stmtContext* drop_stmt();

  class  Filename_mainContext : public antlr4::ParserRuleContext {
  public:
    Filename_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Filename_stmtContext *> filename_stmt();
    Filename_stmtContext* filename_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Filename_mainContext* filename_main();

  class  Filename_stmtContext : public antlr4::ParserRuleContext {
  public:
    Filename_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILENAME();
    VariablesContext *variables();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Filename_stmtContext* filename_stmt();

  class  Infile_mainContext : public antlr4::ParserRuleContext {
  public:
    Infile_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Infile_stmtContext *> infile_stmt();
    Infile_stmtContext* infile_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Infile_mainContext* infile_main();

  class  Infile_stmtContext : public antlr4::ParserRuleContext {
  public:
    Infile_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INFILE();
    File_specificationContext *file_specification();
    antlr4::tree::TerminalNode *SEMICOLON();
    Device_typeContext *device_type();
    std::vector<Infile_optionsContext *> infile_options();
    Infile_optionsContext* infile_options(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Infile_stmtContext* infile_stmt();

  class  File_specificationContext : public antlr4::ParserRuleContext {
  public:
    File_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRINGLITERAL();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *CARDS();
    antlr4::tree::TerminalNode *CARDS4();
    antlr4::tree::TerminalNode *DATALINES();
    antlr4::tree::TerminalNode *DATALINES4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  File_specificationContext* file_specification();

  class  Device_typeContext : public antlr4::ParserRuleContext {
  public:
    Device_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DISK();
    antlr4::tree::TerminalNode *DUMMY();
    antlr4::tree::TerminalNode *GTERM();
    antlr4::tree::TerminalNode *PIPE();
    antlr4::tree::TerminalNode *PLOTTER();
    antlr4::tree::TerminalNode *PRINTER();
    antlr4::tree::TerminalNode *TAPE();
    antlr4::tree::TerminalNode *TEMP();
    antlr4::tree::TerminalNode *TERMINAL();
    antlr4::tree::TerminalNode *UPRINTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Device_typeContext* device_type();

  class  Infile_optionsContext : public antlr4::ParserRuleContext {
  public:
    Infile_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUAL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DSD();
    antlr4::tree::TerminalNode *EXPANDTABS();
    antlr4::tree::TerminalNode *NOEXPANDTABS();
    antlr4::tree::TerminalNode *FLOWOVER();
    antlr4::tree::TerminalNode *MISSOVER();
    antlr4::tree::TerminalNode *PAD();
    antlr4::tree::TerminalNode *NOPAD();
    antlr4::tree::TerminalNode *SCANOVER();
    antlr4::tree::TerminalNode *SHAREBUFFERS();
    antlr4::tree::TerminalNode *STOPOVER();
    antlr4::tree::TerminalNode *TRUNCOVER();
    antlr4::tree::TerminalNode *V_INFILE_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Infile_optionsContext* infile_options();

  class  Input_mainContext : public antlr4::ParserRuleContext {
  public:
    Input_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Input_stmtContext *> input_stmt();
    Input_stmtContext* input_stmt(size_t i);
    std::vector<Put_stmtContext *> put_stmt();
    Put_stmtContext* put_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_mainContext* input_main();

  class  Input_stmtContext : public antlr4::ParserRuleContext {
  public:
    Input_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<Input_specificationContext *> input_specification();
    Input_specificationContext* input_specification(size_t i);
    antlr4::tree::TerminalNode *INPUT_ODS();
    std::vector<antlr4::tree::TerminalNode *> AT();
    antlr4::tree::TerminalNode* AT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_stmtContext* input_stmt();

  class  Put_stmtContext : public antlr4::ParserRuleContext {
  public:
    Put_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUT();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<Put_specificationContext *> put_specification();
    Put_specificationContext* put_specification(size_t i);
    antlr4::tree::TerminalNode *INPUT_ODS();
    std::vector<antlr4::tree::TerminalNode *> AT();
    antlr4::tree::TerminalNode* AT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Put_stmtContext* put_stmt();

  class  Input_specificationContext : public antlr4::ParserRuleContext {
  public:
    Input_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pointer_controlContext *pointer_control();
    Input_variable_formatContext *input_variable_format();
    Column_specificationsContext *column_specifications();
    std::vector<antlr4::tree::TerminalNode *> LParentheses();
    antlr4::tree::TerminalNode* LParentheses(size_t i);
    Identifiers_listContext *identifiers_list();
    std::vector<antlr4::tree::TerminalNode *> RParentheses();
    antlr4::tree::TerminalNode* RParentheses(size_t i);
    Informat_listContext *informat_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_specificationContext* input_specification();

  class  Put_specificationContext : public antlr4::ParserRuleContext {
  public:
    Put_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pointer_controlContext *pointer_control();
    Put_variable_formatContext *put_variable_format();
    Column_specificationsContext *column_specifications();
    std::vector<antlr4::tree::TerminalNode *> LParentheses();
    antlr4::tree::TerminalNode* LParentheses(size_t i);
    Identifiers_listContext *identifiers_list();
    std::vector<antlr4::tree::TerminalNode *> RParentheses();
    antlr4::tree::TerminalNode* RParentheses(size_t i);
    Informat_listContext *informat_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Put_specificationContext* put_specification();

  class  Pointer_controlContext : public antlr4::ParserRuleContext {
  public:
    Pointer_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Line_point_controlContext *line_point_control();
    Column_point_controlContext *column_point_control();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pointer_controlContext* pointer_control();

  class  Informat_listContext : public antlr4::ParserRuleContext {
  public:
    Informat_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Informat();
    antlr4::tree::TerminalNode* Informat(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Pointer_controlContext *> pointer_control();
    Pointer_controlContext* pointer_control(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Informat_listContext* informat_list();

  class  Input_variable_formatContext : public antlr4::ParserRuleContext {
  public:
    Input_variable_formatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Input_variableContext *input_variable();
    antlr4::tree::TerminalNode *EQUAL();
    Format_modifierContext *format_modifier();
    antlr4::tree::TerminalNode *Informat();
    antlr4::tree::TerminalNode *DOLLAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_variable_formatContext* input_variable_format();

  class  Input_variableContext : public antlr4::ParserRuleContext {
  public:
    Input_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *LBraces();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *RBraces();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_variableContext* input_variable();

  class  Put_variable_formatContext : public antlr4::ParserRuleContext {
  public:
    Put_variable_formatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Put_variableContext *put_variable();
    antlr4::tree::TerminalNode *EQUAL();
    Format_modifierContext *format_modifier();
    antlr4::tree::TerminalNode *Informat();
    antlr4::tree::TerminalNode *DOLLAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Put_variable_formatContext* put_variable_format();

  class  Put_variableContext : public antlr4::ParserRuleContext {
  public:
    Put_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *V_INFILE_();
    antlr4::tree::TerminalNode *ARRAY_ALL_ELEMENTS();
    Input_variableContext *input_variable();
    antlr4::tree::TerminalNode *STRINGLITERAL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MUL();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Put_variableContext* put_variable();

  class  Column_point_controlContext : public antlr4::ParserRuleContext {
  public:
    Column_point_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FloatingPointLiteral();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LParentheses();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RParentheses();
    antlr4::tree::TerminalNode *ADD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_point_controlContext* column_point_control();

  class  Line_point_controlContext : public antlr4::ParserRuleContext {
  public:
    Line_point_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FloatingPointLiteral();
    antlr4::tree::TerminalNode *LParentheses();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RParentheses();
    antlr4::tree::TerminalNode *DIV();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Line_point_controlContext* line_point_control();

  class  Format_modifierContext : public antlr4::ParserRuleContext {
  public:
    Format_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Format_modifierContext* format_modifier();

  class  Column_specificationsContext : public antlr4::ParserRuleContext {
  public:
    Column_specificationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *SUB();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_specificationsContext* column_specifications();

  class  Let_mainContext : public antlr4::ParserRuleContext {
  public:
    Let_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Let_stmtContext *> let_stmt();
    Let_stmtContext* let_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_mainContext* let_main();

  class  Let_stmtContext : public antlr4::ParserRuleContext {
  public:
    Let_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PERCENT();
    antlr4::tree::TerminalNode *LET();
    VariablesContext *variables();
    antlr4::tree::TerminalNode *EQUAL();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_stmtContext* let_stmt();

  class  Means_mainContext : public antlr4::ParserRuleContext {
  public:
    Means_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Means_procContext *> means_proc();
    Means_procContext* means_proc(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Means_mainContext* means_main();

  class  Means_procContext : public antlr4::ParserRuleContext {
  public:
    Means_procContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);
    antlr4::tree::TerminalNode *NOTRAP();
    antlr4::tree::TerminalNode *SUMSIZE();
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<Statistic_keywordContext *> statistic_keyword();
    Statistic_keywordContext* statistic_keyword(size_t i);
    Var_stmtContext *var_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Means_procContext* means_proc();

  class  Statistic_keywordContext : public antlr4::ParserRuleContext {
  public:
    Statistic_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SK_MIN();
    antlr4::tree::TerminalNode *SK_MAX();
    antlr4::tree::TerminalNode *SK_MEAN();
    antlr4::tree::TerminalNode *SK_N();
    antlr4::tree::TerminalNode *SK_SUM();
    antlr4::tree::TerminalNode *SK_VAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statistic_keywordContext* statistic_keyword();

  class  Spaced_identifiersContext : public antlr4::ParserRuleContext {
  public:
    Spaced_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Spaced_identifiersContext* spaced_identifiers();

  class  Var_stmtContext : public antlr4::ParserRuleContext {
  public:
    Var_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Spaced_identifiersContext *spaced_identifiers();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_stmtContext* var_stmt();

  class  Glm_mainContext : public antlr4::ParserRuleContext {
  public:
    Glm_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Glm_procContext *> glm_proc();
    Glm_procContext* glm_proc(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Glm_mainContext* glm_main();

  class  Glm_procContext : public antlr4::ParserRuleContext {
  public:
    Glm_procContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    VariablesContext *variables();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *MODEL();
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *FREQ();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *WEIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Glm_procContext* glm_proc();

  class  Freq_mainContext : public antlr4::ParserRuleContext {
  public:
    Freq_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Freq_procContext *> freq_proc();
    Freq_procContext* freq_proc(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Freq_mainContext* freq_main();

  class  Freq_procContext : public antlr4::ParserRuleContext {
  public:
    Freq_procContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BY();
    VariablesContext *variables();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EXACT();
    antlr4::tree::TerminalNode *TABLES();
    antlr4::tree::TerminalNode *TEST();
    antlr4::tree::TerminalNode *WEIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Freq_procContext* freq_proc();

  class  Import_mainContext : public antlr4::ParserRuleContext {
  public:
    Import_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Import_procContext *> import_proc();
    Import_procContext* import_proc(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_mainContext* import_main();

  class  Import_procContext : public antlr4::ParserRuleContext {
  public:
    Import_procContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<VariablesContext *> variables();
    VariablesContext* variables(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB();
    antlr4::tree::TerminalNode* SUB(size_t i);
    antlr4::tree::TerminalNode *NOTRAP();
    antlr4::tree::TerminalNode *SUMSIZE();
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<Statistic_keywordContext *> statistic_keyword();
    Statistic_keywordContext* statistic_keyword(size_t i);
    Var_stmtContext *var_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_procContext* import_proc();

  class  Title_mainContext : public antlr4::ParserRuleContext {
  public:
    Title_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Title_stmtContext *> title_stmt();
    Title_stmtContext* title_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Title_mainContext* title_main();

  class  Title_stmtContext : public antlr4::ParserRuleContext {
  public:
    Title_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TITLE();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Title_stmtContext* title_stmt();

  class  Run_mainContext : public antlr4::ParserRuleContext {
  public:
    Run_mainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Run_stmtContext *> run_stmt();
    Run_stmtContext* run_stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Run_mainContext* run_main();

  class  Run_stmtContext : public antlr4::ParserRuleContext {
  public:
    Run_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RUN();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *CANCEL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Run_stmtContext* run_stmt();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool expressionListSempred(ExpressionListContext *_localctx, size_t predicateIndex);
  bool variablesSempred(VariablesContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

