#import "GfxIOS.h"
#include "gfx/gfx.h"

@implementation GfxIOS

- (void)resize:(int)width :(int)height { 
    gfxResize(width, height);
}

- (void)tick { 
    gfxTick();
}

- (void)inits { 
    gfxInit("ios");
}

@end
