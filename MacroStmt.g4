grammar MacroStmt;
import CommonGrammar;
import MacroAbortStmt;

parse
 : (macro_stmt_list)* EOF
 ;

macro_stmt_list
 : macro_abort_stmt
 | array_stmt
 | by_stmt
 | call_stmt
 | datalines_stmt
 | datalines4_stmt
 | delete_stmt
 | drop_stmt
 | data_stmt
 | filename_stmt
 | if_stmt
 | if_then_else_stmt
 | macro_do_to_stmt
 | macro_do_to_by_stmt
 | macro_do_while_stmt
 | macro_do_until_stmt
 | macro_do_to_while_stmt
 | macro_do_to_until_stmt
 | infile_stmt
 | input_stmt
 | put_stmt
 | let_stmt
 | means_proc
 | glm_proc
 | freq_proc
 | proc_stmt
 // assign must go last
 | assign_stmt
 | run_stmt
 ;

if_stmt
 : '%'IF expression ';'
 ;

if_then_else_stmt
 : '%'IF expression '%'THEN macro_stmt_list ('%'ELSE macro_stmt_list)?
 ;

delete_stmt : DELETE ';' ;

do_to_stmt
 : '%'DO expression '%'TO expression ';' macro_stmt_list '%'END ';'
 ;

do_to_by_stmt
 : '%'DO expression '%'TO expression '%'BY expression ';' macro_stmt_list '%'END ';'
 ;

do_to_while_stmt
 : '%'DO expression '%'TO expression '%'WHILE expression ';' macro_stmt_list '%'END ';'
 ;

do_to_until_stmt
 : '%'DO expression '%'TO expression UNTIL expression ';' macro_stmt_list '%'END ';'
 ;

do_while_stmt
 : '%'DO '%'WHILE '(' expression expression expression ')' ';' macro_stmt_list ';' '%'END ';'
 ;

macro_do_until_stmt
 : '%'DO '%'UNTIL '(' expression expression expression ')' ';' macro_stmt_list ';' '%'END ';'
 ;

 macro_stmt :
 | '%'MACRO macro-name '('positional-parameter | keyword-parameter = value ')' ';' text-and-macro-statements '%'MEND macro-name ';'
 ;