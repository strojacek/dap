/* AMD pp. 265 - 273
 * Random model, unbalanced
 */

data;
 infile "amd265.dat" firstobs=2;
 length plant $ 1 site $ 1 worker $ 1;
 input plant worker site efficiency;

proc glm;
 class plant site worker;
 model efficiency = plant plant*worker plant*site plant*site*worker;
 test h=site*plant e=site*worker*plant;

proc glm;
 class plant site worker;
 model efficiency = plant plant*worker site*worker*plant;
 test h=worker*plant e=site*worker*plant;
 test h=plant e=worker*plant site*worker*plant;
