/* AMD pp. 285 - 289
 * Mixed model, balanced
 */

data;
 infile "amd285.dat" firstobs=2;
 length machine $ 1 person $ 1;
 input machine person prod1 prod2 prod3; /* 3 observations per cell */
 productivity = prod1;
 output;
 productivity = prod2;
 output;
 productivity = prod3;
 output;

proc glm;
 class machine person;
 model productivity = machine person machine*person;
 test h=person e=machine*person;
 lsmeans machine / e=machine*person lsd;
