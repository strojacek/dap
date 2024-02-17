#include <dap.h>
void main()
{
pict *_saspict_[256];
int _saspictcnt_[256];
int _saspictpage_[256];
int _sasnpicts_ = 0, _saspictn_, _saspictindex_;
infile("amd128.dat", " ")
{
char treat[7],block[7];
double y;
input("treat block y ");
outset("sastmp01", "");
treat[6] = '\0';
block[6] = '\0';
skip(2 - 1);
while (step())
{
output();
}
}
sort("sastmp01", " treat block  ", "");
means("sastmp01.srt", "y", "N MEAN VAR", " treat block  ");
effects("sastmp01.srt.mns", "y  treat block  ", "treat block treat * block ", "");
ftest("sastmp01.srt.mns.con", "y  treat block  ", "treat", "", "");
lsmeans("sastmp01.srt.mns.tst", "LSD", 0.05, "y  treat block  ", "treat", "", "s12");
ftest("sastmp01.srt.mns.con", "y  treat block  ", "block", "", "");
lsmeans("sastmp01.srt.mns.tst", "LSD", 0.05, "y  treat block  ", "block", "", "s12");
ftest("sastmp01.srt.mns.con", "y  treat block  ", "treat*block", "", "");
}
