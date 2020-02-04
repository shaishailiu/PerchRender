#import <Foundation/Foundation.h>

@interface GfxIOS : NSObject

- (void)inits;
- (void)resize :(int) width :(int) height;
- (void)tick;

@end
