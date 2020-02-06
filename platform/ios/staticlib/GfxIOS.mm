#import "GfxIOS.h"
#include "core/Perch.h"

@implementation GfxIOS

- (void)resize:(int)width :(int)height { 
    perchResize(width, height);
}

- (void)tick { 
    perchTick();
}

- (void)inits { 
    perchInit("ios");
}

@end
