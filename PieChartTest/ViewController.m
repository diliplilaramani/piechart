//
//  ViewController.m
//  PieChartTest
//
//  Created by Dilip Lilaramani on 5/29/13.
//  Copyright (c) 2013 Dilip Lilaramani. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize pieChartView;

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    NSMutableArray *dataArray = [NSMutableArray arrayWithCapacity:10];
    
    for(int i = 0; i < 8; i ++)
    {
        NSNumber *one = [NSNumber numberWithInt:rand()%60+20];
        [dataArray addObject:one];
    }
    
    [self.pieChartView renderInLayer:self.pieChartView dataArray:dataArray];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
