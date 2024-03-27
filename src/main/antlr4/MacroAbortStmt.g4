grammar MacroAbortStmt;

import CommonLexerRules;

macro_abort_main
 : (macro_abort_stmt)* EOF
 ;
macro_abort_stmt
 : '%'ABORT (ABEND | CANCEL (file_spec)? | RETURN )? INT? NOLIST? ';';

file_spec: STRINGLITERAL ;

