Filename apples "c:\fruits\apples.txt";
data apples;
    infile apples;
    input Type $15. Quantity 6. Price_per_unit 6.2;
    purchase_cost = Quantity * Price_per_unit ;
run;


proc print apples;
run;