grammar FreqProc;
import CommonGrammar;

freq_main
 : (freq_proc)* EOF
 ;

freq_proc
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