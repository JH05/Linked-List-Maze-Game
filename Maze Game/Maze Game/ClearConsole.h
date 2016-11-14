#ifdef  CONSOLECLEAR_H
#define ConsoleClear system ("clear") // Clears the console in POSIX
#else
#define ConsoleClear system ("cls") // Clears the console in MSDOS
#endif 