#ifndef _GFX_H_
#define _GFX_H_

#include <string>

void gfxInit(std::string info);
void gfxResize(int w, int h);
void gfxTick();

#endif // !_GFX_H_