#include <memory.h>
#include <stdlib.h>
#include "display.h"
#include "utils.h"
#include "egl.h"
#include "kms.h"

typedef struct {
    EGLDisplay eglDisplay;
    EGLDeviceEXT eglDevice;
    EGLSurface eglSurface;
    int Width;
    int Height;
} EGLState;

void* DisplayInit() {
    EGLDisplay eglDisplay;
    EGLDeviceEXT eglDevice;
    int drmFd, Width, Height;
    uint32_t PlaneID = 0;
    EGLSurface eglSurface;

    GetEglExtensionFunctionPointers();

    eglDevice = GetEglDevice();

    drmFd = GetDrmFd(eglDevice);

    // From kms.c
    SetMode(drmFd, &PlaneID, &Width, &Height);

    eglDisplay = GetEglDisplay(eglDevice, drmFd);

    eglSurface = SetUpEgl(eglDisplay, PlaneID, Width, Height);

    EGLState* eglState = (EGLState*)calloc(1, sizeof(EGLState));
    eglState->eglDisplay = eglDisplay;
    eglState->eglDevice = eglDevice;
    eglState->eglSurface = eglSurface;
    eglState->Width = Width;
    eglState->Height = Height;
    return eglState;
}

void DisplaySwapBuffers(void* DisplayState) {
    EGLState* eglState = (EGLState*)DisplayState;
    eglSwapBuffers(eglState->eglDisplay, eglState->eglSurface);
}

void DisplayGetResolution(void* DisplayState, int* WidthOut, int* HeightOut) {
    EGLState* eglState = (EGLState*)DisplayState;
    *WidthOut  = eglState->Width;
    *HeightOut = eglState->Height;
}

void DisplayGetFramebufferResolution(void* DisplayState, int* WidthOut, int* HeightOut) {
    DisplayGetResolution(DisplayState, WidthOut, HeightOut); // No 2x display scaling on Linux
}

float DisplayGetPixelRatio(void* DisplayState) {
    UNUSED(DisplayState);
    return 1; // No 2x display scaling on Linux
}

bool DisplayShouldQuit(void* DisplayState) {
    UNUSED(DisplayState);
    return false; // Don't need to check for this on Linux; ctrl-c works just fine.
}

