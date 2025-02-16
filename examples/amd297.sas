/* AMD pp. 297 - 308 using SBS
 * Split plot
 */

data;
 infile "amd297.dat" firstobs=2;
 length fertilizer $ 1 block $ 1 variety $ 1;
 input block variety fertilizer yield;

proc glm;
 title "Whole plot (block, fertilizer) analysis";
 class fertilizer block variety;
 model yield = fertilizer block;
 lsmeans fertilizer / e=fertilizer*block LSD;

proc glm;
 title "Subplot (variety) analysis";
 class fertilizer block variety;
 model yield = fertilizer block variety
               fertilizer*block fertilizer*variety;
