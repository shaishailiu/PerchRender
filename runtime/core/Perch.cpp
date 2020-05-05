#include "Perch.h"
#include "log.h"
#include "gl.h"

#include "core/Engine.h"

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *)glGetString(s);
    Log("GL %s = %s\n", name, v);
}

void perchInit(std::string info) {
    Log("engin init : %s \n", info.c_str());
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    Instance<Engine>().startUp();
}
void perchResize(int w, int h) {
    Log("engin resize : %d,%d \n", w, h);
}
void perchTick() {
    Instance<Engine>().beginFrame();
    glClearColor(1.0f, 0.25f, 1.25f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    Instance<Engine>().endFrame();
}

