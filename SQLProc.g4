grammar SQLProc;
import CommonGrammar;

sql_main
 : (sql_proc)* EOF
 ;

sql_proc
 : BY variables ';'
 | EXACT variables ';'
 | TABLES variables ';'
 | TEST variables ';'
 | WEIGHT variables ';'
 ;
EXACT : E X A C T;
TABLES : T A B L E S;
TEST : T E S T;
WEIGHT : W E I G H T;