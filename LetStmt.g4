grammar LetStmt;

import CommonGrammar;

let_main
 : (let_stmt)* EOF
 ;
let_stmt
 : '%'LET variables '=' literal ';'
    ;


