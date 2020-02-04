//
//  ViewController.m
//  Render
//
//  Created by yanfeiliu(刘延非) on 2020/1/20.
//  Copyright © 2020 yanfeiliu(刘延非). All rights reserved.
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
    // Do any additional setup after loading the view.
    
    kglView = [[kGLView alloc] initWithFrame:self.view.bounds];
    self.view = kglView;
}


@end
