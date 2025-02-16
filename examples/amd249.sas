/* AMD pp. 249 - 251
 * Two factors crossed, another nested within
 * levels of one crossed factor
 */

data; 
 infile "amd249.dat" firstobs=2;
 length a $ 1 b $ 1 c $ 1;
 input b c a y1 y2; /* two values per cell */
 y = y1;
 output;
 y = y2;
 output;

proc glm;
 class a b c;
 model y = a b a*b c*b a*c*b;
 test h=a e=a*b;
 test h=b e=a*b b*c a*b*c;
 test h=a*b e=a*b*c;
 test h=c*b e=a*c*b;
