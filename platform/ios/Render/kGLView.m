//
//  kGLView.m
//  gl
//
//  Created by yqs on 2020/1/20.
//  Copyright © 2020 yqs. All rights reserved.
//

#import "kGLView.h"
#import <OpenGLES/ES2/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <GLKit/GLKit.h>

#import "GfxIOS.h"


@interface kGLView()
{
    EAGLContext *_eaglContext;
    CAEAGLLayer *_eaglLayer;
    GLuint _colorBufferRender;
    GLuint _frameBuffer;
    GLuint _glProgram;
    GLuint _positionSlot;
    GLuint _textureSlot;
    GLuint _textureCoordsSlot;
    GLuint _textureID;
    CGRect _frameCAEAGLLayer;
    GfxIOS *_gfxIOS;
}

@end

@implementation kGLView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

-(instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self initContex];
    }
    return self;
}



-(void)initContex
{
    _gfxIOS = [GfxIOS new];
    
    
    _eaglContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    [EAGLContext setCurrentContext:_eaglContext];
    
    [_gfxIOS inits];
    
    _eaglLayer = (CAEAGLLayer*)self.layer;
    _eaglLayer.frame = self.frame;
    _eaglLayer.opaque = YES;
    _eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:YES],kEAGLDrawablePropertyRetainedBacking,kEAGLColorFormatRGBA8,kEAGLDrawablePropertyColorFormat, nil];
    
    [_gfxIOS resize:self.frame.size.width*2 :self.frame.size.height*2];
    
    glGenRenderbuffers(1, &_colorBufferRender);
    glBindRenderbuffer(GL_RENDERBUFFER, _colorBufferRender);
    [_eaglContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:_eaglLayer];
    
    glGenFramebuffers(1, &_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _frameBuffer);
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              _colorBufferRender);
    
    [_gfxIOS tick];
    //glClearColor(1.0, 0.25, 0.25, 1.0f);
    //NSString* str = [_gfxIOS getHelloWorld];
    //NSLog(@"%@",str);
    //glClear(GL_COLOR_BUFFER_BIT);

    [_eaglContext presentRenderbuffer:GL_RENDERBUFFER];
}

+ (Class)layerClass{
    return [CAEAGLLayer class];
}

@end
