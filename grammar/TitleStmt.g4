grammar TitleStmt;

import CommonLexerRules;

title_main
 : (title_stmt)* EOF
 ;

title_stmt
 : TITLE Identifier ';';