/* ED pp. 122 - 125 using SBS
 * Latin square
 */

data;
 infile "ed122.dat" firstobs=2;
 length sampler $ 1 area $ 1 order $ 1;
 input order area sampler error;
  
proc glm;
 class sampler area order;
 model error = sampler area order;
 lsmeans sampler / lsd;
