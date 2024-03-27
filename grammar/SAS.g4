grammar SAS;
import CommonGrammar, AbortStmt, ProcStmt, ArrayStmt, AssignmentStmt,
	ByStmt, CallStmt, DataStmt, DatalinesStmt, DropStmt, FilenameStmt, InfileStmt, InputStmt, LetStmt, MeansProc, GLMProc, FreqProc, ImportProc, TitleStmt,
	RunStmt;

parse
 : (sas_stmt_list)* EOF
 ;

sas_stmt_list
 : abort_stmt
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
 | do_to_stmt
 | do_to_by_stmt
 | do_while_stmt
 | do_until_stmt
 | do_to_while_stmt
 | do_to_until_stmt
 | infile_stmt
 | input_stmt
 | put_stmt
 | let_stmt
 | means_proc
 | glm_proc
 | freq_proc
 | import_proc
 | proc_stmt
 // assign must go last
 | assign_stmt
 | run_stmt
 ;
 
if_stmt 
 : IF expression ';'
 ;

if_then_else_stmt
 : IF expression THEN sas_stmt_list (ELSE sas_stmt_list)? 
 ;
 
delete_stmt : DELETE ';' ;

do_to_stmt
 : DO expression TO expression ';' sas_stmt_list END ';'
 ;

do_to_by_stmt
 : DO expression TO expression BY expression ';' sas_stmt_list END ';'
 ;

do_to_while_stmt
 : DO expression TO expression WHILE expression ';' sas_stmt_list END ';'
 ;

do_to_until_stmt
 : DO expression TO expression UNTIL expression ';' sas_stmt_list END ';'
 ;

do_while_stmt
 : DO WHILE '(' expression expression expression ')' ';' sas_stmt_list ';' END ';'
 ;

do_until_stmt
 : DO UNTIL '(' expression expression expression ')' ';' sas_stmt_list ';' END ';'
 ;