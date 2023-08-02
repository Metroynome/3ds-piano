#include <string.h>
#include <stdio.h>
#include <3ds.h>
#include "draw.h"

#include "PC2_bin.h"
#include "PDb2_bin.h"
#include "PD2_bin.h"
#include "PEb2_bin.h"
#include "PE2_bin.h"
#include "PF2_bin.h"
#include "PGb2_bin.h"
#include "PG2_bin.h"
#include "PAb2_bin.h"
#include "PA2_bin.h"
#include "PBb2_bin.h"
#include "PB2_bin.h"

#include "PC3_bin.h"
#include "PDb3_bin.h"
#include "PD3_bin.h"
#include "PEb3_bin.h"
#include "PE3_bin.h"
#include "PF3_bin.h"
#include "PGb3_bin.h"
#include "PG3_bin.h"
#include "PAb3_bin.h"
#include "PA3_bin.h"
#include "PBb3_bin.h"
#include "PB3_bin.h"

#include "PC4_bin.h"
#include "PDb4_bin.h"
#include "PD4_bin.h"
#include "PEb4_bin.h"
#include "PE4_bin.h"
#include "PF4_bin.h"
#include "PGb4_bin.h"
#include "PG4_bin.h"
#include "PAb4_bin.h"
#include "PA4_bin.h"
#include "PBb4_bin.h"
#include "PB4_bin.h"

#include "PC5_bin.h"

#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60
int time = 0;

int main() {
    // Initialize services
    srvInit();
    aptInit();
    hidInit(NULL);
    gfxInit();
    CSND_initialize(NULL);
    //gfxSet3D(true); // uncomment if using stereoscopic 3D
    
    int Playing = 0;
    int Touching = 0;
    int Glissando = 0;
    int Octave = 1; //Start out on center octave.
    
    u8 *PC2 = linearAlloc(PC2_bin_size);
    u8 *PDb2 = linearAlloc(PDb2_bin_size);
    u8 *PD2 = linearAlloc(PD2_bin_size);
    u8 *PEb2 = linearAlloc(PEb2_bin_size);
    u8 *PE2 = linearAlloc(PE2_bin_size);
    u8 *PF2 = linearAlloc(PF2_bin_size);
    u8 *PGb2 = linearAlloc(PGb2_bin_size);
    u8 *PG2 = linearAlloc(PG2_bin_size);
    u8 *PAb2 = linearAlloc(PAb2_bin_size);
    u8 *PA2 = linearAlloc(PA2_bin_size);
    u8 *PBb2 = linearAlloc(PBb2_bin_size);
    u8 *PB2 = linearAlloc(PB2_bin_size);
    
    u8 *PC3 = linearAlloc(PC3_bin_size);
    u8 *PDb3 = linearAlloc(PDb3_bin_size);
    u8 *PD3 = linearAlloc(PD3_bin_size);
    u8 *PEb3 = linearAlloc(PEb3_bin_size);
    u8 *PE3 = linearAlloc(PE3_bin_size);
    u8 *PF3 = linearAlloc(PF3_bin_size);
    u8 *PGb3 = linearAlloc(PGb3_bin_size);
    u8 *PG3 = linearAlloc(PG3_bin_size);
    u8 *PAb3 = linearAlloc(PAb3_bin_size);
    u8 *PA3 = linearAlloc(PA3_bin_size);
    u8 *PBb3 = linearAlloc(PBb3_bin_size);
    u8 *PB3 = linearAlloc(PB3_bin_size);
    
    u8 *PC4 = linearAlloc(PC4_bin_size);
    u8 *PDb4 = linearAlloc(PDb4_bin_size);
    u8 *PD4 = linearAlloc(PD4_bin_size);
    u8 *PEb4 = linearAlloc(PEb4_bin_size);
    u8 *PE4 = linearAlloc(PE4_bin_size);
    u8 *PF4 = linearAlloc(PF4_bin_size);
    u8 *PGb4 = linearAlloc(PGb4_bin_size);
    u8 *PG4 = linearAlloc(PG4_bin_size);
    u8 *PAb4 = linearAlloc(PAb4_bin_size);
    u8 *PA4 = linearAlloc(PA4_bin_size);
    u8 *PBb4 = linearAlloc(PBb4_bin_size);
    u8 *PB4 = linearAlloc(PB4_bin_size);
    
    u8 *PC5 = linearAlloc(PC5_bin_size);
    
    memcpy(PC2, PC2_bin, PC2_bin_size);
    memcpy(PDb2, PDb2_bin, PDb2_bin_size);
    memcpy(PD2, PD2_bin, PD2_bin_size);
    memcpy(PEb2, PEb2_bin, PEb2_bin_size);
    memcpy(PE2, PE2_bin, PE2_bin_size);
    memcpy(PF2, PF2_bin, PF2_bin_size);
    memcpy(PGb2, PGb2_bin, PGb2_bin_size);
    memcpy(PG2, PG2_bin, PG2_bin_size);
    memcpy(PAb2, PAb2_bin, PAb2_bin_size);
    memcpy(PA2, PA2_bin, PA2_bin_size);
    memcpy(PBb2, PBb2_bin, PBb2_bin_size);
    memcpy(PB2, PB2_bin, PB2_bin_size);
    
    memcpy(PC3, PC3_bin, PC3_bin_size);
    memcpy(PDb3, PDb3_bin, PDb3_bin_size);
    memcpy(PD3, PD3_bin, PD3_bin_size);
    memcpy(PEb3, PEb3_bin, PEb3_bin_size);
    memcpy(PE3, PE3_bin, PE3_bin_size);
    memcpy(PF3, PF3_bin, PF3_bin_size);
    memcpy(PGb3, PGb3_bin, PGb3_bin_size);
    memcpy(PG3, PG3_bin, PG3_bin_size);
    memcpy(PAb3, PAb3_bin, PAb3_bin_size);
    memcpy(PA3, PA3_bin, PA3_bin_size);
    memcpy(PBb3, PBb3_bin, PBb3_bin_size);
    memcpy(PB3, PB3_bin, PB3_bin_size);
    
    memcpy(PC4, PC4_bin, PC4_bin_size);
    memcpy(PDb4, PDb4_bin, PDb4_bin_size);
    memcpy(PD4, PD4_bin, PD4_bin_size);
    memcpy(PEb4, PEb4_bin, PEb4_bin_size);
    memcpy(PE4, PE4_bin, PE4_bin_size);
    memcpy(PF4, PF4_bin, PF4_bin_size);
    memcpy(PGb4, PGb4_bin, PGb4_bin_size);
    memcpy(PG4, PG4_bin, PG4_bin_size);
    memcpy(PAb4, PAb4_bin, PAb4_bin_size);
    memcpy(PA4, PA4_bin, PA4_bin_size);
    memcpy(PBb4, PBb4_bin, PBb4_bin_size);
    memcpy(PB4, PB4_bin, PB4_bin_size);
    
    memcpy(PC5, PC5_bin, PC5_bin_size);
    
    // Main loop
    while (aptMainLoop())
    {
        gspWaitForVBlank();
        hidScanInput();
        
        u32 kDown = hidKeysDown();
        u32 kUp = hidKeysUp();
        
        if (kDown & KEY_START){
            break; // break in order to return to hbmenu
        }
        
        u8* ft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
        u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_BOTTOM, NULL, NULL);
        memset(ft, 0, 240*400*3);
        memset(fb, 0, 240*320*3);
        
        char a[100];
        sprintf(a, "Piano v1");
        drawString(a, 0, 0, 255, 255, 255, ft, GFX_LEFT);
        sprintf(a, "Created by Agent Moose/Metroynome");
        drawString(a, 0, 8, 255, 255, 255, ft, GFX_LEFT);
        sprintf(a, "Octave: %d", Octave);
        drawString(a, 0, 232, 255, 255, 255, ft, GFX_LEFT);
        
        
        u64 timeInSeconds = osGetTime() / 1000;
        u64 dayTime = timeInSeconds % SECONDS_IN_DAY;
        u64 secTime = dayTime % SECONDS_IN_MINUTE;
        //sprintf(a, "%llu", secTime);
        //drawString(a, 0, 16, 255, 255, 255, ft, GFX_LEFT);
        
        touchPosition myTouchPosition;
        hidTouchRead(&myTouchPosition);
        u16 posX = myTouchPosition.px;
        u16 posY = myTouchPosition.py;
        if((posX >= 1 && posY >= 1) && (posX <= 320 && posY <= 240)){
            Touching = 1;
        }else{
            Touching = 0;
        }
        if(kDown & KEY_LEFT){
            if(Octave == 1 || Octave == 2){
                Octave = Octave - 1;
            }
        }
        if(kDown & KEY_RIGHT){
            if(Octave == 0 || Octave == 1){
                Octave = Octave + 1;
            }
        }
        
        if((Glissando == 1 || Glissando == 2 || Glissando == 3 || Glissando == 4 || Glissando == 5 || Glissando == 6 || Glissando == 7 || Glissando == 8 || Glissando == 9 || Glissando == 10 || Glissando == 11 || Glissando == 12 || Glissando == 13) || (Playing == 0 && Touching == 1)){
            if(Glissando != 1 && (posX > 0 && posX <= 39) && (posY > 0 && posY <= 240) && !((posX >= 25 && posX <= 39) && posY <= 100)){
                Playing = 1;
                Glissando = 1;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC2, NULL, PC2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC3, NULL, PC3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC4, NULL, PC4_bin_size, 2, 0);
                }
            }
            if(Glissando != 2 && (posX >= 25 && posX <= 55) && (posY > 0 && posY <= 100)){
                Playing = 1;
                Glissando = 2;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PDb2, NULL, PDb2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PDb3, NULL, PDb3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PDb4, NULL, PDb4_bin_size, 2, 0);
                }
            }
            if(Glissando != 3 && (posX >= 40 && posX <= 79) && (posY > 0 && posY <= 240) && !(((posX >= 40 && posX <= 55) || (posX >= 65 && posX <= 79)) && posY <= 100)){
                Playing = 1;
                Glissando = 3;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PD2, NULL, PD2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PD3, NULL, PD3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PD4, NULL, PD4_bin_size, 2, 0);
                }
            }
            if(Glissando != 4 && (posX >= 65 && posX <= 95) && (posY > 0 && posY <= 100)){
                Playing = 1;
                Glissando = 4;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PEb2, NULL, PEb2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PEb3, NULL, PEb3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PEb4, NULL, PEb4_bin_size, 2, 0);
                }
            }
            if(Glissando != 5 && (posX >= 80 && posX <= 119) && (posY > 0 && posY <= 240) && !((posX >= 80 && posX <= 95) && posY <= 100)){
                Playing = 1;
                Glissando = 5;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PE2, NULL, PE2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PE3, NULL, PE3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PE4, NULL, PE4_bin_size, 2, 0);
                }
            }
            if(Glissando != 6 && (posX >= 120 && posX <= 159) && (posY > 0 && posY <= 240) && !((posX >= 145 && posX <= 159) && posY <= 100)){
                Playing = 1;
                Glissando = 6;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PF2, NULL, PF2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PF3, NULL, PF3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PF4, NULL, PF4_bin_size, 2, 0);
                }
            }
            if(Glissando != 7 && (posX >= 145 && posX <= 175) && (posY > 0 && posY <= 100)){
                Playing = 1;
                Glissando = 7;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PGb2, NULL, PGb2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PGb3, NULL, PGb3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PGb4, NULL, PGb4_bin_size, 2, 0);
                }
            }
            if(Glissando != 8 && (posX >= 160 && posX <= 199) && (posY > 0 && posY <= 240) && !(((posX >= 160 && posX <= 175) || (posX >= 185 && posX <= 199)) && posY <= 100)){
                Playing = 1;
                Glissando = 8;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PG2, NULL, PG2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PG3, NULL, PG3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PG4, NULL, PG4_bin_size, 2, 0);
                }
            }
            if(Glissando != 9 && (posX >= 185 && posX <= 215) && (posY > 0 && posY <= 100)){
                Playing = 1;
                Glissando = 9;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PAb2, NULL, PAb2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PAb3, NULL, PAb3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PAb4, NULL, PAb4_bin_size, 2, 0);
                }
            }
            if(Glissando != 10 && (posX >= 200 && posX <= 239) && (posY > 0 && posY <= 240) && !(((posX >= 200 && posX <= 215) || (posX >= 225 && posX <= 239)) && posY <= 100)){
                Playing = 1;
                Glissando = 10;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PA2, NULL, PA2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PA3, NULL, PA3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PA4, NULL, PA4_bin_size, 2, 0);
                }
            }
            if(Glissando != 11 && (posX >= 225 && posX <= 255) && (posY > 0 && posY <= 100)){
                Playing = 1;
                Glissando = 11;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PBb2, NULL, PBb2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PBb3, NULL, PBb3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PBb4, NULL, PBb4_bin_size, 2, 0);
                }
            }
            if(Glissando != 12 && (posX >= 240 && posX <= 279) && (posY > 0 && posY <= 240) && !((posX >= 240 && posX <= 255) && posY <= 100)){
                Playing = 1;
                Glissando = 12;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PB2, NULL, PB2_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PB3, NULL, PB3_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PB4, NULL, PB4_bin_size, 2, 0);
                }
            }
            if(Glissando != 13 && (posX >= 280 && posX <= 320) && (posY > 0 && posY <= 240)){
                Playing = 1;
                Glissando = 13;
                if(Octave == 0){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC3, NULL, PC3_bin_size, 2, 0);
                }
                if(Octave == 1){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC4, NULL, PC4_bin_size, 2, 0);
                }
                if(Octave == 2){
                    CSND_playsound(0x8, CSND_LOOP_ENABLE, CSND_ENCODING_PCM16, 44100, (u32*)PC5, NULL, PC5_bin_size, 2, 0);
                }
            }
        }
        if(Playing == 1 && Touching == 0){
            Playing = 0;
            Glissando = 0;
            CSND_setchannel_playbackstate(0x8, 0);
            CSND_sharedmemtype0_cmdupdatestate(0);
        }
    
        drawFillRect(0, 0, 39, 240, 255, 255, 255, fb); //C3
        drawFillRect(40, 0, 79, 240, 255, 255, 255, fb); //D3
        drawFillRect(80, 0, 119, 240, 255, 255, 255, fb); //E3
        drawFillRect(120, 0, 159, 240, 255, 255, 255, fb); //F3
        drawFillRect(160, 0, 199, 240, 255, 255, 255, fb); //G3
        drawFillRect(200, 0, 239, 240, 255, 255, 255, fb); //A3
        drawFillRect(240, 0, 279, 240, 255, 255, 255, fb); //B3
        drawFillRect(280, 0, 320, 240, 255, 255, 255, fb); //C4
        
        drawFillRect(25, 0, 55, 100, 0, 0, 0, fb); //Db3
        drawFillRect(65, 0, 95, 100, 0, 0, 0, fb); //Eb3
        drawFillRect(145, 0, 175, 100, 0, 0, 0, fb); //Gb3
        drawFillRect(185, 0, 215, 100, 0, 0, 0, fb); //Ab3
        drawFillRect(225, 0, 255, 100, 0, 0, 0, fb); //Bb3

        drawFillRect(39, 0, 40, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(79, 0, 80, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(119, 0, 120, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(159, 0, 160, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(199, 0, 200, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(239, 0, 240, 240, 0, 0, 0, fb); //Seperator
        drawFillRect(279, 0, 280, 240, 0, 0, 0, fb); //Seperator
        
        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    
    CSND_shutdown();
    linearFree(PC2);
    linearFree(PDb2);
    linearFree(PD2);
    linearFree(PEb2);
    linearFree(PE2);
    linearFree(PF2);
    linearFree(PGb2);
    linearFree(PG2);
    linearFree(PAb2);
    linearFree(PA2);
    linearFree(PBb2);
    linearFree(PB2);
    linearFree(PC3);
    linearFree(PDb3);
    linearFree(PD3);
    linearFree(PEb3);
    linearFree(PE3);
    linearFree(PF3);
    linearFree(PGb3);
    linearFree(PG3);
    linearFree(PAb3);
    linearFree(PA3);
    linearFree(PBb3);
    linearFree(PB3);
    linearFree(PC4);
    linearFree(PDb4);
    linearFree(PD4);
    linearFree(PEb4);
    linearFree(PE4);
    linearFree(PF4);
    linearFree(PGb4);
    linearFree(PG4);
    linearFree(PAb4);
    linearFree(PA4);
    linearFree(PBb4);
    linearFree(PB4);
    linearFree(PC5);
    // Exit services
    gfxExit();
    hidExit();
    aptExit();
    srvExit();
    return 0;
}
