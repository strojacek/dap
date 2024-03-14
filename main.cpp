// --- Includes ---
#include <iostream>
#include "antlr4-runtime.h"
#include "libs/SASLexer.cpp"
#include "libs/SASParser.cpp"
#include "libs/SASVisitor.cpp"
#include <string>
#include <regex>
#include <iostream>
#include <wordexp.h>
#include <fstream>
#include <istream>
#include "libs/cpptrim.h"
#include <stdio.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <random>
#include "libs/chtext.h"

// --- Namespaces ---
using namespace std;
using namespace antlr4;

// --- Constants ---
const string VERSION = "1.0";
const string VERSIONNAME = "Amazing Archaeopteryx";
#define TYPE_STRING  0
#define TYPE_NUMBER  1
#define TYPE_BOOLEAN 2
#define LAPL_NUMBER_EPSILON 0.00000001
#define EXCEPTION_CONTINUE 0
#define EXCEPTION_BREAK 1
#define EXCEPTION_RETURN 2

// --- Custom Types ---
typedef double sas_number;
typedef char sas_type;
typedef chText sas_string;
class sas_variable;
class sas_function;


// --- Global Variables ---
vector<unordered_map<string, sas_variable>> variable_scope;
vector<unordered_map<string, sas_function>> function_scope;

// --- Function Declarations ---
string expandPath(const string & input);
string parseArguments(int argc, const char* argv[]);
string loadFileContents(const string & path);
void error(const string & msg);
sas_number stoln(const sas_string & str);
sas_string to_sas_string(const sas_number x);
void displayVersionInformation();
sas_type getValueType(const antlrcpp::Any & type);
void declareVariable(const string & var_name, const antlrcpp::Any & value);
void setVariable(const string & var_name, const antlrcpp::Any & value);
void addVariableScope();
void delVariableScope();
void addFunctionScope();
void delFunctionScope();
bool variableExists(const string & var_name);
sas_variable & getVariable(const string & var_name);
void setFunction(const string & function_name, const vector<string> & parameters, tree::ParseTree * execution_tree);
sas_function & getFunction(const string & function_name);
void printFunctionScope();
void printVariableScope();
sas_number getRandomNumber();
bool stringIsNumber(const sas_string & text);
chText str_replace(string s, string find, string replace);

// --- Class Definitions ---
class sas_variable
{
    private:
    // All variables default to false.
    sas_type type = TYPE_BOOLEAN;
    antlrcpp::Any value = make_shared<bool>(false);
    sas_number number_value;

    public:
    void setValue(antlrcpp::Any value)
    {
        this->type = getValueType(value);
        /*if (this->type == TYPE_STRING)
        {
            this->value = make_shared<sas_string>(
                *value.as<shared_ptr<sas_string>>()
            );
        }
        else if (this->type == TYPE_NUMBER)
        {
            this->number_value = *value.as<shared_ptr<sas_number>>();
            this->value = make_shared<sas_number>(this->number_value);
        }
        else if (this->type == TYPE_BOOLEAN)
        {
            this->value = make_shared<bool>(
                *value.as<shared_ptr<bool>>()
            );
        }*/
        this->value = value;
    }
    antlrcpp::Any getValue()
    {
        return this->value;
    }
    sas_type getType()
    {
        return this->type;
    }
};

class sas_function
{
    private:
    vector<string> parameters;
    tree::ParseTree * execution_tree;

    public:
    void define(const vector<string> & parameters, tree::ParseTree * execution_tree)
    {
        for(const string & parameter : parameters)
        {
            this->parameters.push_back(parameter);
        }
        this->execution_tree = execution_tree;
    }
    tree::ParseTree * getTree()
    {
        return this->execution_tree;
    }
    unsigned int parameterCount()
    {
        return this->parameters.size();
    }
    vector<string> & getParameters()
    {
        return this->parameters;
    }
};

// --- Visitor Class ---
class SASVisitor : public sasVisitor
{

	
    virtual std::any visitParse(SASParser::ParseContext *context) {

        return visitChildren(context);    
	}

    virtual std::any visitSas_stmt_list(SASParser::Sas_stmt_listContext *context) {
		
		return visitChildren(context);	
	}

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

	*/


    virtual antlrcpp::Any visitLapl_source(SASParser::Lapl_sourceContext *context)
    {
        return visitChildren(context);
    }

    virtual antlrcpp::Any visitStatement(SASParser::StatementContext *context)
    {
        return visitChildren(context);
    }

    virtual antlrcpp::Any visitBlock(SASParser::BlockContext *context)
    {
        // while blocks, if blocks and functiond declarations are also blocks
        // because they not require a ; at the end (the statement that follows
        // them does) and thus it was simpler to make them blocks from a syntactic
        // point of view.
        if(context->BLOCK_OPEN() and context->BLOCK_CLOSE())
        {
            addVariableScope();
            addFunctionScope();
            try
            {
                visitChildren(context);
            }
            catch(int e)
            {
                delFunctionScope();
                delVariableScope();
                throw e;
            }
            delFunctionScope();
            delVariableScope();
        }
        else
        {
            visitChildren(context);
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitEmpty_line(SASParser::Empty_lineContext *context)
    {
        return visitChildren(context);
    }

    virtual antlrcpp::Any visitLine_statement(SASParser::Line_statementContext *context)
    {
        return visitChildren(context);
    }

    virtual antlrcpp::Any visitString(SASParser::StringContext *context)
    {
        if (context->STRING())
        {
            string stringValue = context->STRING()->toString();
            stringValue = stringValue.substr(1, stringValue.length() - 2);
            replaceAll(stringValue, "\\n", "\n");
            replaceAll(stringValue, "\\r", "\r");
            replaceAll(stringValue, "\\t", "\t");
            replaceAll(stringValue, "\\\\", "\\");
            replaceAll(stringValue, "\\0", "\0");
            shared_ptr<sas_string> valueToReturn = make_shared<sas_string>(sas_string(stringValue));
            return valueToReturn;
        }
        if (context->LINEFEED())
        {
            shared_ptr<sas_string> valueToReturn = make_shared<sas_string>(sas_string("\n"));
            return valueToReturn;
        }
        if (context->CRLF())
        {
            shared_ptr<sas_string> valueToReturn = make_shared<sas_string>(sas_string("\r\n"));
            return valueToReturn;
        }
        else if (context->STR_OP())
        {
            sas_number numeric_value = *visit(context->children[1]).as<shared_ptr<sas_number>>();
            sas_string string_value = to_sas_string(numeric_value);
            shared_ptr<sas_string> valueToReturn = make_shared<sas_string>(string_value);
            return valueToReturn;
        }
    }

    virtual antlrcpp::Any visitNumber(SASParser::NumberContext *context)
    {
        if (context->NUMBER())
        {
            sas_number numberValue = stoln(context->getText());
            shared_ptr<sas_number> valueToReturn = make_shared<sas_number>(numberValue);
            return valueToReturn;
        }
        else if (context->NUM_OP())
        {
            sas_string string_value = *visit(context->children[1]).as<shared_ptr<sas_string>>();
            sas_number numeric_value = stoln(string_value);
            shared_ptr<sas_number> valueToReturn = make_shared<sas_number>(numeric_value);
            return valueToReturn;
        }
        else if (context->TYPE())
        {
            sas_number numberValue = getValueType(visit(context->value()));
            shared_ptr<sas_number> valueToReturn = make_shared<sas_number>(numberValue);
            return valueToReturn;
        }
    }

    virtual antlrcpp::Any visitNumber_expression(SASParser::Number_expressionContext *context)
    {
        if (context->number())
        {
            return visit(context->number());
        }
        else if (context->PLUS_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(value1 + value2);
        }
        else if (context->MINUS_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(value1 - value2);
        }
        else if (context->TIMES_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(value1 * value2);
        }
        else if (context->DIV_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(value1 / value2);
        }
        else if (context->MOD_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>((long long)(value1) % (long long)(value2));
        }
        else if (context->POW_OP())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(pow(value1, value2));
        }
        else if (context->FLOOR_OP())
        {
            sas_number value1 = *visit(context->children[1]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(floor(value1));
        }
        else if (context->CEIL_OP())
        {
            sas_number value1 = *visit(context->children[1]).as<shared_ptr<sas_number>>();
            return make_shared<sas_number>(ceil(value1));
        }
        else if (context->LPAR() and context->RPAR())
        {
            return visit(context->children[1]);
        }
        else if (context->function_call())
        {
            antlrcpp::Any return_value = visit(context->function_call());
            if(getValueType(return_value) != TYPE_NUMBER)
            {
                error("the returned value is not a number.");
            }
            return return_value;
        }
        else if (context->VARIABLE())
        {
            string var_name = context->VARIABLE()->toString();
            sas_variable & var = getVariable(var_name);
            if(var.getType() != TYPE_NUMBER)
            {
                error("the variable '" + var_name + "' doesn't hold a number.");
            }
            return var.getValue();
        }
        else if (context->builtin_number_function())
        {
            return visit(context->builtin_number_function());
        }
    }

    virtual antlrcpp::Any visitString_expression(SASParser::String_expressionContext *context)
    {
        if (context->string())
        {
            return visit(context->string());
        }
        else if (context->CONCAT_OP())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<sas_string>(value1 + value2);
        }
        else if (context->LPAR() and context->RPAR())
        {
            return visit(context->children[1]);
        }
        else if (context->INDEX_ACCESS_O() and context->INDEX_ACCESS_C() and context->COMMA())
        {
            sas_string string_value = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_number index_val_min = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            sas_number index_val_max = *visit(context->children[4]).as<shared_ptr<sas_number>>();
            if (index_val_min < 0)
            {
                index_val_min = string_value.length() + index_val_min;
            }
            if (index_val_max < 0)
            {
                index_val_max = string_value.length();
            }
            if (index_val_min + index_val_max > string_value.length())
            {
                index_val_max = string_value.length() - index_val_min;
            }
            cout << index_val_min << endl;
            cout << index_val_max << endl;
            return make_shared<sas_string>(string_value.substr(index_val_min, index_val_max));
        }
        else if (context->INDEX_ACCESS_O() and context->INDEX_ACCESS_C())
        {
            sas_string string_value = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_number index_val = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            if (index_val < 0)
            {
                index_val = string_value.length() + index_val;
            }
            if (index_val < 0 or index_val >= string_value.length())
            {
                return make_shared<sas_string>("");
            }
            return make_shared<sas_string>(string_value.substr(index_val, 1));
        }
        else if (context->function_call())
        {
            antlrcpp::Any return_value = visit(context->function_call());
            if(getValueType(return_value) != TYPE_STRING) 
            {
                error("the returned value is not a string.");
            }
            return return_value;
        }
        else if (context->VARIABLE())
        {
            string var_name = context->VARIABLE()->toString();
            sas_variable & var = getVariable(var_name);
            if(var.getType() != TYPE_STRING)
            {
                error("the variable '" + var_name + "' doesn't hold a string."); //TODO add line number to errors
            }
            return var.getValue();
        }
        else if (context->builtin_string_function())
        {
            return visit(context->builtin_string_function());
        }
    }

    //virtual antlrcpp::Any visitArray(SASParser::ArrayContext *context){}

    //virtual antlrcpp::Any visitMap(SASParser::MapContext *context){}

    //virtual antlrcpp::Any visitArray_expression(SASParser::Array_expressionContext *context){}

    //virtual antlrcpp::Any visitMap_expression(SASParser::Map_expressionContext *context){}

    virtual antlrcpp::Any visitValue(SASParser::ValueContext *context)
    {
        if (context->string_expression())
        {
            return visit(context->string_expression());
        }
        else if (context->number_expression())
        {
            return visit(context->number_expression());
        }
        else if (context->boolean_expr())
        {
            return visit(context->boolean_expr());
        }
        /*else if (context->array_expression())
        {
            return visit(context->array_expression());
        }
        else if (context->map_expression())
        {
            return visit(context->map_expression());
        }*/
        else if (context->VARIABLE())
        {
            string var_name = context->VARIABLE()->toString();
            sas_variable & variable = getVariable(var_name);
            return variable.getValue();      
        }
        else if (context->function_call())
        {
            return visit(context->function_call());
        }
    }

    virtual antlrcpp::Any visitArgument(SASParser::ArgumentContext *context)
    {
        if(context->value())
        {
            return visit(context->value());
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitAssignment(SASParser::AssignmentContext *context)
    {
        if(context->VARIABLE() and not context->VAR() and context->ASSIGN_OP())
        {
            string var_name = context->VARIABLE()->toString();
            setVariable(var_name, visit(context->value()));
        }
        else if(context->VARIABLE() and context->VAR() and context->ASSIGN_OP())
        {
            string var_name = context->VARIABLE()->toString();
            declareVariable(var_name, visit(context->value()));
        }
        else if(context->VARIABLE() and context->VAR() and not context->ASSIGN_OP())
        {
            string var_name = context->VARIABLE()->toString();
            declareVariable(var_name, make_shared<bool>(false));
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitFunction_call(SASParser::Function_callContext *context)
    {
        string function_name = context->IDENTIFIER()->toString();
        string function_return_name = "$" + function_name;
        antlrcpp::Any return_value;
        sas_function & function = getFunction(function_name);
        addVariableScope();
        addFunctionScope();
        declareVariable(function_return_name, make_shared<bool>(false));
        size_t parameter_number = 0;
        if(context->argument().size() != function.parameterCount())
        {
            error("argument count mismatch for function '" + function_name + "'.");
        }
        vector<string> & parameters = function.getParameters();
        for(const auto & argument : context->argument())
        {
            declareVariable(parameters[parameter_number], visit(argument));
            ++parameter_number;
        }
        try
        {
            visit(function.getTree());
        }
        catch(int e)
        {
            if (e == EXCEPTION_CONTINUE)
            {
                error("continue cannot be used in this context.");
            }
            else if(e == EXCEPTION_BREAK)
            {
                error("break cannot be used in this context.");
            }
            else if(e == EXCEPTION_RETURN)
            {
                // Exit the function
            }
            else {
                return_value = getVariable(function_return_name).getValue();
                delFunctionScope();
                delVariableScope();
                throw e;
            }
        }
        return_value = getVariable(function_return_name).getValue();
        delFunctionScope();
        delVariableScope();
        return return_value;
    }

    virtual antlrcpp::Any visitWhile_block(SASParser::While_blockContext *context)
    {
        while(true)
        {
            bool boolean_value = *visit(context->boolean_expr()).as<shared_ptr<bool>>();
            if(!boolean_value) break;
            else{
                try
                {
                    visit(context->statement());
                }
                catch(int e)
                {
                    // Break or continue!
                    if (e == EXCEPTION_CONTINUE)
                    {
                        continue;
                    }
                    else if(e == EXCEPTION_BREAK)
                    {
                        break;
                    }
                    else {
                        throw e;
                    }
                }
            }
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitBoolean_value(SASParser::Boolean_valueContext *context)
    {
        bool booleanValue = context->TRUE() ? true : false;
        shared_ptr<bool> valueToReturn = make_shared<bool>(booleanValue);
        return valueToReturn;
    }

    virtual antlrcpp::Any visitBoolean_expr(SASParser::Boolean_exprContext *context)
    {
        if (context->boolean_value())
        {
            return visit(context->boolean_value());
        }
        else if (context->NOT_OP())
        {
            bool value1 = *visit(context->children[1]).as<shared_ptr<bool>>();
            return make_shared<bool>(not value1);
        }
        else if (context->AND_OP())
        {
            bool value1 = *visit(context->children[0]).as<shared_ptr<bool>>();
            bool value2 = *visit(context->children[2]).as<shared_ptr<bool>>();
            return make_shared<bool>(value1 and value2);
        }
        else if (context->OR_OP())
        {
            bool value1 = *visit(context->children[0]).as<shared_ptr<bool>>();
            bool value2 = *visit(context->children[2]).as<shared_ptr<bool>>();
            return make_shared<bool>(value1 or value2);
        }
        else if (context->EQ_OP() and not context->boolean_expr().empty())
        {
            bool value1 = *visit(context->children[0]).as<shared_ptr<bool>>();
            bool value2 = *visit(context->children[2]).as<shared_ptr<bool>>();
            return make_shared<bool>(value1 == value2);
        }
        else if (context->NEQ_OP() and not context->boolean_expr().empty())
        {
            bool value1 = *visit(context->children[0]).as<shared_ptr<bool>>();
            bool value2 = *visit(context->children[2]).as<shared_ptr<bool>>();
            return make_shared<bool>(value1 != value2);
        }
        else if (context->EQ_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 == value2);
        }
        else if (context->NEQ_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 != value2);
        }
        else if (context->LT_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 < value2);
        }
        else if (context->GT_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 > value2);
        }
        else if (context->LE_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 <= value2);
        }
        else if (context->GE_OP() and not context->string_expression().empty())
        {
            sas_string value1 = *visit(context->children[0]).as<shared_ptr<sas_string>>();
            sas_string value2 = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(value1 >= value2);
        }
        else if (context->EQ_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(fabs(value1 - value2) < LAPL_NUMBER_EPSILON);
        }
        else if (context->NEQ_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(value1 != value2);
        }
        else if (context->LT_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(value1 < value2);
        }
        else if (context->GT_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(value1 > value2);
        }
        else if (context->LE_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(value1 <= value2);
        }
        else if (context->GE_OP() and not context->number_expression().empty())
        {
            sas_number value1 = *visit(context->children[0]).as<shared_ptr<sas_number>>();
            sas_number value2 = *visit(context->children[2]).as<shared_ptr<sas_number>>();
            return make_shared<bool>(value1 >= value2);
        }
        else if (context->LPAR() and context->RPAR())
        {
            return visit(context->children[1]);
        }
        else if (context->function_call())
        {
            antlrcpp::Any return_value = visit(context->function_call());
            if(getValueType(return_value) != TYPE_BOOLEAN)
            {
                error("the returned value is not a boolean.");
            }
            return return_value;
        }
        else if (context->VARIABLE())
        {
            string var_name = context->VARIABLE()->toString();
            sas_variable & var = getVariable(var_name);
            if(var.getType() != TYPE_BOOLEAN)
            {
                error("the variable '" + var_name + "' doesn't hold a boolean.");
            }
            return var.getValue();
        }
        else if (context->builtin_boolean_function())
        {
            return visit(context->builtin_boolean_function());
        }
    }

    virtual antlrcpp::Any visitIf_block(SASParser::If_blockContext *context)
    {
        bool boolean_value = *visit(context->boolean_expr()).as<shared_ptr<bool>>();
        if(boolean_value) visit(context->statement());
        else
        {
            if(context->else_block())
            {
                visit(context->else_block());
            }
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitElse_block(SASParser::Else_blockContext *context)
    {
        visit(context->statement());
        return nullptr;
    }

    virtual antlrcpp::Any visitContinue_statement(SASParser::Continue_statementContext *context)
    {
       throw EXCEPTION_CONTINUE;
    }

    virtual antlrcpp::Any visitBreak_statement(SASParser::Break_statementContext *context)
    {
        throw EXCEPTION_BREAK;
    }

    virtual antlrcpp::Any visitReturn_statement(SASParser::Return_statementContext *context)
    {
        throw EXCEPTION_RETURN;
    }

    virtual antlrcpp::Any visitExit_statement(SASParser::Exit_statementContext *context)
    {
        if (context->number_expression())
        {
            sas_number exit_code = *visit(context->children[1]).as<shared_ptr<sas_number>>();
            exit((int) exit_code);
        }
        else exit(0);
    }

    virtual antlrcpp::Any visitFunction_declaration(SASParser::Function_declarationContext *context)
    {
        string function_name = context->IDENTIFIER()->toString();
        vector<string> parameters;
        for(const auto & parameter : context->VARIABLE())
        {
            parameters.push_back(parameter->toString());
        }
        setFunction(function_name, parameters, context->statement());
        return nullptr;
    }

    virtual antlrcpp::Any visitDisplay_statement(SASParser::Display_statementContext *context)
    {
        return visit(context->display_values());
    }

    virtual antlrcpp::Any visitDisplay_values(SASParser::Display_valuesContext *context)
    {
        for (auto & child : context->children)
        {
            antlrcpp::Any value_to_print = visit(child);
            if (value_to_print.is<shared_ptr<sas_string>>())
            {
                sas_string string_to_print = *value_to_print.as<shared_ptr<sas_string>>();
                cout << string_to_print << flush;
            }
            else if (value_to_print.is<shared_ptr<sas_number>>())
            {
                sas_number number_to_print = *value_to_print.as<shared_ptr<sas_number>>();
                cout << to_sas_string(number_to_print) << flush;
            }
            else if (value_to_print.is<shared_ptr<bool>>())
            {
                bool boolean_value = *value_to_print.as<shared_ptr<bool>>();
                cout << (boolean_value ? "true" : "false") << flush;
            }
        }
        return nullptr;
    }

    virtual antlrcpp::Any visitBuiltin_number_function(SASParser::Builtin_number_functionContext *context)
    {
        // len(string)
        if(context->BIF_LEN())
        {
            sas_string value = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<sas_number>(value.length());
        }
        // random()
        else if(context->RANDOM())
        {
            return make_shared<sas_number>(getRandomNumber());
        }
    }

    virtual antlrcpp::Any visitBuiltin_string_function(SASParser::Builtin_string_functionContext *context)
    {
        // accept()
        if(context->ACCEPT())
        {
            string s = "";
            getline(cin, s);
            sas_string chs = s;
            return make_shared<sas_string>(chs);
        }
        // replace(string, string, string)
        else if(context->BIF_REPLACE())
        {
            return make_shared<sas_string>(
                str_replace(
                    *visit(context->children[2]).as<shared_ptr<sas_string>>(), 
                    *visit(context->children[4]).as<shared_ptr<sas_string>>(), 
                    *visit(context->children[6]).as<shared_ptr<sas_string>>()
                )
            );
        }
    }

    virtual antlrcpp::Any visitBuiltin_boolean_function(SASParser::Builtin_boolean_functionContext *context)
    {
        // isNumeric(string)
        if(context->BIF_ISNUM())
        {
            sas_string value = *visit(context->children[2]).as<shared_ptr<sas_string>>();
            return make_shared<bool>(stringIsNumber(value));
        }
    }
};

// --- Main ---
int main(int argc, const char * argv[])
{
    string fileName = parseArguments(argc, argv);
    string filePath = expandPath(fileName);
    string fileContents = loadFileContents(filePath);

    //https://stackoverflow.com/questions/44515370/how-to-override-error-reporting-in-c-target-of-antlr4
    ANTLRInputStream input(fileContents);
    sasLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SASParser parser(&tokens);
    tree::ParseTree *tree = parser.sas_source();
    SASVisitor visitor;

    addVariableScope();
    addFunctionScope();
    try
    {
        visitor.visit(tree);
    }
    catch(int e)
    {
        if (e == EXCEPTION_CONTINUE)
        {
            error("continue cannot be used in this context.");
        }
        else if(e == EXCEPTION_BREAK)
        {
            error("break cannot be used in this context.");
        }
        else {
            throw e;
        }
    }

    return 0;
}

// --- Functions ---
string expandPath(const string & input)
{
    string text = input;
    wordexp_t expandedPath;
    char** expandedPathString;
    wordexp(text.c_str(), &expandedPath, 0);
    expandedPathString = expandedPath.we_wordv;
    text = "";
    for (size_t i = 0; i < expandedPath.we_wordc; i++)
    {
        text += expandedPathString[i];
        text += " ";
    }
    wordfree(&expandedPath);
    trim(text);
    return text;
}

string parseArguments(int argc, const char * argv[])
{
    vector<string> args(argv + 1, argv + argc);
    string filename = "";
    for (string & arg : args)
    {
        if (arg == "-h" || arg == "--help")
        {
            //TODO
            exit(0);
        }
        else if (arg == "-v" || arg == "--version")
        {
            displayVersionInformation();
            exit(0);
        }
        else if (arg[0] == '-')
        {
            error("unrecognized switch '" + arg +"'.");
        }
        else if(filename == "")
        {
            filename = arg;
        }
        else
        {
            error("multiple file paths found.");
        }
    }
    return filename;
}

string loadFileContents(const string & path)
{
    string fileContents = "";
    ifstream file(path);
    if (file.is_open())
    {
        string line = "";
        while (getline(file, line))
        {
            fileContents += line;
            fileContents += "\n";
        }
    }
    else
    {
        error("file '" + path + "' not found.");
    }
    return fileContents;
}

void error(const string & msg)
{
    cerr << "\033[1;31mFatal LAPL Error: ";
    cerr << msg;
    cerr << "\033[0m" << endl;
    exit(1);
}

sas_number stoln(const sas_string & str)
{
    if(stringIsNumber(str)) return stod(str);
    error("the string '" + str + "' is not numeric and cannot be converted to a number.");
}

sas_string to_sas_string(const sas_number x)
{
    ostringstream out;
    out.precision(10);
    out << fixed << x;
    string str = out.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    str.erase(str.find_last_not_of('.') + 1, string::npos);
    return str;
}

void displayVersionInformation()
{
    cout << endl;
    cout << " This is \033[32;1mLAPL version " << VERSION << "\033[0m '\033[32;1m" << VERSIONNAME << "\033[0m'." << endl << endl;
    cout << " Copyright 2020, \033[35;1mMartín del Río\033[0m (www.lartu.net)." << endl;
    cout << endl;
    cout << " LAPL may be copied only under the terms of the Apache License" << endl;
    cout << " Version 2.0, which may be found in the LAPL repository." << endl;
    /*cout << endl;
    cout << " This binary was compiled on \033[31;1m" << COMPILEDATE << "\033[0m at \033[31;1m" << COMPILEHOUR << "\033[0m." << endl;*/
    cout << endl;
}

sas_type getValueType(const antlrcpp::Any & type)
{
    if (type.is<shared_ptr<sas_string>>())
    {
        return TYPE_STRING;
    }
    else if (type.is<shared_ptr<sas_number>>())
    {
        return TYPE_NUMBER;
    }
    else if (type.is<shared_ptr<bool>>())
    {
        return TYPE_BOOLEAN;
    }
    error("unkown type for value; very, very fatal error. Please report this!");
    return -1;
}

void addVariableScope()
{
    variable_scope.push_back(unordered_map<string, sas_variable>());
}

void delVariableScope()
{
    variable_scope.pop_back();
}

void addFunctionScope()
{
    function_scope.push_back(unordered_map<string, sas_function>());
}

void delFunctionScope()
{
    function_scope.pop_back();
}

void declareVariable(const string & var_name, const antlrcpp::Any & value)
{
    int last_scope = variable_scope.size() - 1;
    sas_variable & var = variable_scope[last_scope][var_name];
    var = sas_variable();
    var.setValue(value);
}

void setVariable(const string & var_name, const antlrcpp::Any & value)
{
    for(int scope_depth = variable_scope.size() - 1; scope_depth >= 0; --scope_depth)
    {
        unordered_map<string, sas_variable> & scope = variable_scope[scope_depth];
        if(scope.find(var_name) != scope.end())
        {
            sas_variable & var = variable_scope[scope_depth][var_name];
            var.setValue(value);
            return;
        }
    }
    declareVariable(var_name, value);
}

bool variableExists(const string & var_name)
{
    for(int scope_depth = variable_scope.size() - 1; scope_depth >= 0; --scope_depth)
    {
        unordered_map<string, sas_variable> & scope = variable_scope[scope_depth];
        if(scope.find(var_name) != scope.end()) return true;
    }
    return false;
}

sas_variable & getVariable(const string & var_name)
{
    for(int scope_depth = variable_scope.size() - 1; scope_depth >= 0; --scope_depth)
    {
        unordered_map<string, sas_variable> & scope = variable_scope[scope_depth];
        if(scope.find(var_name) != scope.end())
        {
            return scope[var_name];
        }
    }
    error("the variable '" + var_name + "' hasn't been declared in this scope.");
}

void setFunction(const string & function_name, const vector<string> & parameters, tree::ParseTree * execution_tree)
{
    /*for(int scope_depth = 0; scope_depth < function_scope.size(); ++scope_depth)
    {
        auto & scope = function_scope[scope_depth];
        if(scope.find(function_name) != scope.end())
        {
            sas_function & fun = function_scope[scope_depth][function_name];
            fun.define(parameters, execution_tree);
            return;
        }
    }*/
    int last_scope = function_scope.size() - 1;
    sas_function & fun = function_scope[last_scope][function_name];
    fun = sas_function();
    fun.define(parameters, execution_tree);
}

sas_function & getFunction(const string & function_name)
{
    for(int scope_depth = function_scope.size() - 1; scope_depth >= 0; --scope_depth)
    {
        auto & scope = function_scope[scope_depth];
        if(scope.find(function_name) != scope.end())
        {
            return scope[function_name];
        }
    }
    error("the function '" + function_name + "' hasn't been declared in this scope.");
}

void printFunctionScope()
{
    cout << "--- Function Scope ---" << endl;
    size_t depth = 0;
    for(const auto & scope : function_scope)
    {
        for(const auto & tuple : scope)
        {
            cout << "Depth " << depth << " ";
            for(size_t i = 1; i <= depth + 1; ++i)
            {
                cout << "..";
            }
            cout << " " << tuple.first << endl;
        }
        ++depth;
    }
    cout << "----------------------" << endl;
}

void printVariableScope()
{
    cout << "--- Variable Scope ---" << endl;
    size_t depth = 0;
    for(const auto & scope : variable_scope)
    {
        for(const auto & tuple : scope)
        {
            cout << "Depth " << depth << " ";
            for(size_t i = 1; i <= depth + 1; ++i)
            {
                cout << "..";
            }
            cout << " " << tuple.first << " = ";
            sas_variable var = tuple.second;
            antlrcpp::Any value_to_print = var.getValue();
            if (value_to_print.is<shared_ptr<sas_string>>())
            {
                sas_string string_to_print = *value_to_print.as<shared_ptr<sas_string>>();
                cout << string_to_print << flush;
            }
            else if (value_to_print.is<shared_ptr<sas_number>>())
            {
                sas_number number_to_print = *value_to_print.as<shared_ptr<sas_number>>();
                cout << to_sas_string(number_to_print) << flush;
            }
            else if (value_to_print.is<shared_ptr<bool>>())
            {
                bool boolean_value = *value_to_print.as<shared_ptr<bool>>();
                cout << (boolean_value ? "true" : "false") << flush;
            }
            cout << endl;
        }
        ++depth;
    }
    cout << "----------------------" << endl;
}

sas_number getRandomNumber(){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);
    sas_number r = (sas_number) dist(mt);
    return r;
}

bool stringIsNumber(const sas_string & text)
{
    try
    {
        stod(text);
    }
    catch (std::invalid_argument const &)
    {
        return false;
    }
    return true;
}

chText str_replace(string s, string find, string replace)
{
    string result;
    size_t find_len = find.size();
    size_t pos, from=0;
    while (string::npos != (pos=s.find(find,from)))
    {
        result.append(s, from, pos-from);
        result.append(replace);
        from = pos + find_len;
    }
    result.append(s, from , string::npos);
    return result;
}
