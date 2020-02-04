#include "gfx.h"
#include "log.h"
#include "gl.h"

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *)glGetString(s);
    Log("GL %s = %s\n", name, v);
}

void gfxInit(std::string info) {
    Log("engin init : %s \n", info.c_str());
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);
}
void gfxResize(int w, int h) {
    Log("engin resize : %d,%d \n", w, h);
}
void gfxTick() {
    glClearColor(1.0f, 0.25f, 1.25f, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}


