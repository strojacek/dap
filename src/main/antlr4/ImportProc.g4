grammar ImportProc;
import CommonGrammar;


import_main
 : (import_proc)* EOF
 ;

import_proc
 : DROP (variables | variables '-' variables)+ ';'
 | NOTRAP
 | SUMSIZE '='
 | (statistic_keyword)* ';'
 | var_stmt
 ;

 statistic_keyword
 : SK_MIN
 | SK_MAX
 | SK_MEAN
 | SK_N
 | SK_SUM
 | SK_VAR
 ;

spaced_identifiers
 : Identifier Identifier*
 ;

var_stmt
 : spaced_identifiers ';'
 ;


 SK_MIN : 'MIN' ;
 SK_MAX : 'MAX' ;
 SK_MEAN : 'MEAN' ;
 SK_N : 'N' ;
 SK_SUM : 'SUM' ;
 SK_VAR : 'VAR' ;
 SUMSIZE : 'SUMSIZE' ;
 NOTRAP : 'NOTRAP' ;