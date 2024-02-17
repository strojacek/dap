#include <dap.h>
void dap_main()
{
pict *_saspict_[256];
int _saspictcnt_[256];
int _saspictpage_[256];
int _sasnpicts_ = 0, _saspictn_, _saspictindex_;
infile("veggies.txt", " ");
{
double Name,$,Code,Days,Number,Price,double;dap_vd("Name -1", 0);dap_dl("Name", &Name);dap_vd("$ -1", 0);dap_dl("$", &$);dap_vd("Code -1", 0);dap_dl("Code", &Code);dap_vd("Days -1", 0);dap_dl("Days", &Days);dap_vd("Number -1", 0);dap_dl("Number", &Number);dap_vd("Price -1", 0);dap_dl("Price", &Price);dap_vd("double -1", 0);dap_dl("double", &double);
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
