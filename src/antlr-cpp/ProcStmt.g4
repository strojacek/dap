grammar ProcStmt;
import CommonGrammar ;

proc_main
 : (proc_stmt)* EOF
 ;
 
proc_stmt
 : PROC proc_name (~';')*? ';'
 ;
 
proc_name
 : ANOVA
 | CORR
 | MEANS
 | REG
 | SGPLOT
 | PRINT
 | GLM
 | FREQ
 | SQL
 | UNIVARIATE
 | NPAR1WAY
 | IMPORT
 | SORT
 | DATASETS
 | TABULATE
 | RANK
 | CHART
 | LOGISTIC
 | SURVEYSELCT
 ;
