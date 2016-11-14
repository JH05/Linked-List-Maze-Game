#ifdef  WAITFORINPUT_H
#define SystemPause system("read") // Pauses the console in OS X / LINUX
#else
#define SystemPause system("pause") // Pauses the console in MSDOS
#endif 
