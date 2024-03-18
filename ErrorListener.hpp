#include <iostream>
#include <string>
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace antlrcpp;
using namespace std;


class ErrorListener : public BaseErrorListener {

		private:
				ostream& stderr;

		public:
				ErrorListener(ostream& stderr) : stderr(stderr) {}

				virtual void syntaxError(Recognizer* recognizer,
										 Token* offendingSymbol,
										 size_t line,
										 size_t charPositionInLine,
										 const string& msg,
										 exception_ptr e) override {
		this->stderr << msg << endl;	
				}

};
