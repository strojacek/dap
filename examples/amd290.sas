/* AMD pp. 290 - 295 using SAS
 * Mixed model, unbalanced
 */

data;
 infile "amd290.dat" firstobs=2;
 length machine $ 1 person $ 1;
 input machine person productivity;
run;

proc glm;
 class machine person;
 model productivity = machine person machine*person;
 test h=person e=machine*person;
 lsmeans machine / e=machine*person lsd;
run;