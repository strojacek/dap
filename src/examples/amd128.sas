/* AMD pp. 128 - 134: unbalanced layout  */

data;
  infile "amd128.dat" firstobs=2;
  length treat $ 6 block $ 6;
  input treat block y;

proc glm;
 class treat block;
 model y = treat block treat*block;
 lsmeans treat block / lsd;
