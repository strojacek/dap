grammar GLMProc;
import CommonGrammar;

glm_main
 : (glm_proc)* EOF
 ;

glm_proc
 : CLASS variables ';'
 | MODEL variables ';'
 | BY variables ';'
 | FREQ variables ';'
 | ID variables ';'
 | WEIGHT variables ';'
 ;
CLASS : C L A S S;
MODEL : M O D E L;
FREQ : F R E Q;
ID : I D;
WEIGHT : W E I G H T;