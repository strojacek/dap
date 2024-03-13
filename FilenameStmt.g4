grammar FilenameStmt;
import CommonGrammar;

filename_main
 : (filename_stmt)* EOF
 ;

filename_stmt
 : FILENAME  variables literal ';'
 ;