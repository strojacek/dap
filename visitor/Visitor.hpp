#include <iostream>
#include <stdexcept>
#include "JazzInterpreterState.h" // Assuming you have a header file for JazzInterpreterState
#include "JazzValue.h" // Assuming you have a header file for JazzValue
#include "SASBaseVisitor.h" // Assuming you have a header file for SASBaseVisitor
#include "SASParser.h" // Assuming you have a header file for SASParser
#include "Table.h" // Assuming you have a header file for Table

class Visitor : public SASBaseVisitor<JazzValue> {
private:
    std::istream& stdin;
    std::ostream& stdout;
    JazzInterpreterState& state;
    std::ostream& printStream;

    // Create a Table object as a class member
    Table dataTable;

public:
    // Constructor
    Visitor(std::istream& in, std::ostream& out, JazzInterpreterState& s) : stdin(in), stdout(out), state(s), printStream(std::cout), dataTable(Table()) {}

    // Getter method to retrieve the created table
    Table getDataTable() {
        return dataTable;
    }

    // Override visit methods from SASBaseVisitor
    virtual JazzValue visitParse(SASParser::ParseContext *ctx) override {
        return visitChildren(ctx);
    }

    // Implement other visit methods similarly...

    virtual JazzValue visitData_main(SASParser::Data_mainContext *ctx) override {
        // Implementation for visiting data_main context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    virtual JazzValue visitData_stmt(SASParser::Data_stmtContext *ctx) override {
        // Implementation for visiting data_stmt context
        // You can handle this as per your requirements
        std::string dataStepName = ctx->getText();
        dataTable = Table::create(dataStepName);
        return JazzValue(dataTable); // Assuming JazzValue constructor accepts a Table object
    }

    virtual JazzValue visitInput_stmt(SASParser::Input_stmtContext *ctx) override {
        // Implementation for visiting input_stmt context
        // You can handle this as per your requirements
        // Assuming you have a method addColumns() in Table class to add new columns
        for (auto inputVariable : ctx->input_specification()->input_variable()) {
            std::string variableName = inputVariable->getText();
            // Assuming you have a Table object where you want to add the new column
            Table table = state.getCurrentTable(); // You need to adapt this to your code structure
            // Create a new column with the variable name and add it to the table
            table.addColumns(tech::tablesaw::api::StringColumn::create(variableName, ""));
        }
        // Return a placeholder JazzValue or handle it according to your logic
        return JazzValue(ctx); // Modify this based on your requirements
    }

    // Implement the remaining visit methods...

    virtual JazzValue visitPut_stmt(SASParser::Put_stmtContext *ctx) override {
        // Implementation for visiting put_stmt context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    virtual JazzValue visitDatastmt_cmd(SASParser::Datastmt_cmdContext *ctx) override {
        // Implementation for visiting datastmt_cmd context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    // Implement other visit methods similarly...

    virtual JazzValue visitMeans_main(SASParser::Means_mainContext *ctx) override {
        // Implementation for visiting means_main context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    virtual JazzValue visitMeans_proc(SASParser::Means_procContext *ctx) override {
        // Implementation for visiting means_proc context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    virtual JazzValue visitStatistic_keyword(SASParser::Statistic_keywordContext *ctx) override {
        // Implementation for visiting statistic_keyword context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    // Implement other visit methods similarly...

    virtual JazzValue visitRun_main(SASParser::Run_mainContext *ctx) override {
        // Implementation for visiting run_main context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }

    virtual JazzValue visitRun_stmt(SASParser::Run_stmtContext *ctx) override {
        // Implementation for visiting run_stmt context
        // You can handle this as per your requirements
        return visitChildren(ctx);
    }
};
    

