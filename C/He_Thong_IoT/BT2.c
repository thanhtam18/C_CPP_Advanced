#include <stdio.h>
#include <stdarg.h>

typedef enum {
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
}DeviceType;

typedef enum {
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
}CommandType;

void controlDevice(DeviceType device, CommandType cmd, ...){
    va_list args;
    va_start(args, cmd);
    switch (device){
        case LIGHT:
            (cmd == ON) ? printf("Light turned ON") : printf("Light turned OFF");
            break;
        case AIR_CONDITIONER:
            switch(cmd){
                case SET_TEMPERATURE:
                    printf("Air conditioner temperature set to %d degrees", va_arg(args,int));
                    break;
                case SET_MODE:
                    printf("Air conditioner Mode %s", va_arg(args,char*));
                    break;
            }
            break;
        case FINGERPRINT_LOCK:
            (cmd == LOCK) ? printf("FingerPrintLock Locked") : printf("FingerPrintLock Unclocked");
            break;
        case MUSIC_PLAYER:
            switch(cmd){
                case ON:
                    printf("Music player ON");
                    break;
                case OFF:
                    printf("Music player OFF");
                    break;
                case INCREASE_VOLUME:
                    printf("Music player Increase Volume");
                    break;
                case DECREASE_VOLUME:
                    printf("Music player Decrease Volume");
                    break;
                case CHANGE_TRACK:
                    printf("Music player Change Track");
                    break;
            }
            break;
    }
    va_end (args);
}


int main(int argc, char const *argv[]){
    controlDevice(LIGHT,ON);
    printf("\r\n");
    controlDevice(AIR_CONDITIONER,SET_MODE,"Cool");
    printf("\r\n");
    controlDevice(AIR_CONDITIONER,SET_TEMPERATURE,25);
    printf("\r\n");
    controlDevice(FINGERPRINT_LOCK,LOCK);
    printf("\r\n");
    controlDevice(MUSIC_PLAYER,CHANGE_TRACK);
    printf("\r\n");
    return 0;
}

