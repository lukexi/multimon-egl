#if !defined(DISPLAY_H)
#define DISPLAY_H

#include <stdbool.h>

void* DisplayInit();
void DisplaySwapBuffers(void* DisplayState);
void DisplayGetResolution(void* DisplayState, int* WidthOut, int* HeightOut);
void DisplayGetFramebufferResolution(void* DisplayState, int* WidthOut, int* HeightOut);
float DisplayGetPixelRatio(void* DisplayState);
bool DisplayShouldQuit();

#endif // DISPLAY_H
