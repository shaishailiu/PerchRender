//
//  ViewController.m
//  render
//
//  Created by toy on 2020/1/21.
//  Copyright © 2020 toy. All rights reserved.
//

#import "ViewController.h"
#import "kGLView.h"

@interface ViewController ()
{
    kGLView *kglView;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    kglView = [[kGLView alloc] initWithFrame:self.view.bounds];
    self.view = kglView;
}


@end
