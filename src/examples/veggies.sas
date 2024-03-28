data veg;
		infile "veggies.txt";
		input Name $ Code $ Days Number Price;
		double CostPerSeed = Price / Number;
run;

proc print veg;
run;
