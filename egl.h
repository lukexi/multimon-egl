#if !defined(EGL_H)
#define EGL_H

#include <EGL/egl.h>
#include <EGL/eglext.h>

EGLDeviceEXT GetEglDevice(void);

int GetDrmFd(EGLDeviceEXT device);

EGLDisplay GetEglDisplay(EGLDeviceEXT device, int drmFd);

EGLSurface SetUpEgl(EGLDisplay eglDpy, uint32_t crtcID, int width, int height, EGLContext *context);



EGLBoolean ExtensionIsSupported(
    const char *extensionString,
    const char *extension);

void GetEglExtensionFunctionPointers(void);

extern PFNEGLQUERYDEVICESEXTPROC pEglQueryDevicesEXT;
extern PFNEGLQUERYDEVICESTRINGEXTPROC pEglQueryDeviceStringEXT;
extern PFNEGLGETPLATFORMDISPLAYEXTPROC pEglGetPlatformDisplayEXT;
extern PFNEGLGETOUTPUTLAYERSEXTPROC pEglGetOutputLayersEXT;
extern PFNEGLCREATESTREAMKHRPROC pEglCreateStreamKHR;
extern PFNEGLSTREAMCONSUMEROUTPUTEXTPROC pEglStreamConsumerOutputEXT;
extern PFNEGLCREATESTREAMPRODUCERSURFACEKHRPROC pEglCreateStreamProducerSurfaceKHR;


#endif /* EGL_H */
