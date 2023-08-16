#include <PA9.h>
#include <maxmod9.h>
#include "soundbank_bin.h"
#include "soundbank.h"

int main(){
	PA_Init();
	PA_Init8bitBg(1,0);
	PA_Init8bitBg(0,0);
	PA_InitText(1,0);
	PA_InitRand();
	PA_SetBgPalCol(1,1,PA_RGB(PA_RandMinMax(10,31),PA_RandMinMax(0,31),PA_RandMinMax(0,31)));
	PA_SetBgPalCol(0,1,PA_RGB(PA_RandMinMax(10,31),PA_RandMinMax(0,31),PA_RandMinMax(0,31)));
	PA_8bitText(1,20,96,255,0,"ROMS DOWNLOADER!!",1,4,0,100);
	PA_8bitText(0,20,96,255,0,"ROMS DOWNLOADER!!",1,4,0,100);
	PA_OutputSimpleText(1,0,0,"GET AERGLASS'D");
	mmInitDefaultMem((mm_addr)soundbank_bin);

	mmLoad(MOD_RULE6HAHA);
	mmStart(MOD_RULE6HAHA,MM_PLAY_LOOP);
	mmSetModuleTempo(2000);
	u8 timer = 0;
	while(true){
		timer++;
		if(timer == 10) {
			PA_SetBgPalCol(1,1,PA_RGB(PA_RandMinMax(10,31),PA_RandMinMax(0,31),PA_RandMinMax(0,31)));
			PA_SetBgPalCol(0,1,PA_RGB(PA_RandMinMax(10,31),PA_RandMinMax(0,31),PA_RandMinMax(0,31)));
			timer = 0;
		}
		PA_8bitText(0,PA_RandMinMax(0,200),PA_RandMinMax(0,220),255,0,"WOW!!!",1,4,0,100);
		PA_WaitForVBL();
	}
}
