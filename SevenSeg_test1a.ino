// test by Nicu FLORICA (niq_ro) using library from // https://github.com/sigvaldm
// see http://sim.marebakken.com/SevenSeg.pdf

# include <SevenSeg.h> 
SevenSeg disp (0,1,2,3,4,5,6); // a,b,c,d,e,f,g
#define DPPin 7 // DP
const int numOfDigits=4; // number of digits
int digitPins[numOfDigits]={8 ,9 ,10 ,11}; // D1 (left), D2, D3, D4 (right)

int hmax = 120; 
int ora, minut;
int ceas;
int temperatura;
int umiditate;

void setup ()
{
disp.setCommonCathode();
disp.setDigitPins ( numOfDigits , digitPins );
disp.setDPPin(DPPin);
}

void loop ()
{

ora = random(24);
minut = random(60);
ceas = ora*100+minut;
for(int k = 0; k<6; k++)
{
for (int h = 0; h<hmax/2; h++)
{
disp.write(ceas,2);
}
for (int h = 0; h<hmax/2; h++)
{
disp.write(ceas);
}
} 

temperatura = random(30);
char tempe[10] = "";
//sprintf(tempe, "%d\370C", temperatura); // https://www.reddit.com/r/arduino/comments/3alyz1/how_can_i_convertadd_integer_to_char_array/

if (temperatura < 10) sprintf(tempe, " %d\370C", temperatura);
else
sprintf(tempe, "%d\370C", temperatura);

for (int h = 0; h<3*hmax; h++)
{
// disp.write(" 24\370C");
// disp.write("24\370C");
 disp.write(tempe);
}

umiditate = random(75);
char umidi[10] = "";
if (umiditate < 10) sprintf(umidi, " %drh", umiditate);
else
sprintf(umidi, "%drh", umiditate);

for (int h = 0; h<3*hmax; h++)
{
// disp.write("47rh");
disp.write(umidi);
}

 }
