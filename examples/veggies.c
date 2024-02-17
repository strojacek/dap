#include <dap.h>
void main()
{
pict *_saspict_[256];
int _saspictcnt_[256];
int _saspictpage_[256];
int _sasnpicts_ = 0, _saspictn_, _saspictindex_;
infile("veggies.txt", " ")
{
double Name,$,Code,Days,Number,Price,double;
input("Name $ Code $ Days Number Price ");
outset("veg", "");
while (step())
{
double CostPerSeed = Price / Number ;
run ;
output();
}
}
print("veg", "");
}
