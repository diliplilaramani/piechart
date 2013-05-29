//
//  DLPieChart.h
//  DLPieChart
//
//  Created by XY Feng on 5/29/13.
//  Copyright (c) 2013 Dilip Lilaramani. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#import <UIKit/UIKit.h>

@class DLPieChart;
@protocol XYPieChartDataSource <NSObject>
@required
- (NSUInteger)numberOfSlicesInPieChart:(DLPieChart *)pieChart;
- (CGFloat)pieChart:(DLPieChart *)pieChart valueForSliceAtIndex:(NSUInteger)index;
@optional
- (UIColor *)pieChart:(DLPieChart *)pieChart colorForSliceAtIndex:(NSUInteger)index;
- (NSString *)pieChart:(DLPieChart *)pieChart textForSliceAtIndex:(NSUInteger)index;
@end

@protocol XYPieChartDelegate <NSObject>
@optional
- (void)pieChart:(DLPieChart *)pieChart willSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart didSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart willDeselectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart didDeselectSliceAtIndex:(NSUInteger)index;
@end

@interface DLPieChart : UIView <XYPieChartDelegate, XYPieChartDataSource>

@property(nonatomic, strong) id<XYPieChartDataSource> dataSource;
@property(nonatomic, strong) id<XYPieChartDelegate> delegate;
@property(nonatomic, assign) CGFloat startPieAngle;
@property(nonatomic, assign) CGFloat animationSpeed;
@property(nonatomic, assign) CGPoint pieCenter;
@property(nonatomic, assign) CGFloat pieRadius;
@property(nonatomic, assign) BOOL    showLabel;
@property(nonatomic, strong) UIFont  *labelFont;
@property(nonatomic, strong) UIColor *labelColor;
@property(nonatomic, strong) UIColor *labelShadowColor;
@property(nonatomic, assign) CGFloat labelRadius;
@property(nonatomic, assign) CGFloat selectedSliceStroke;
@property(nonatomic, assign) CGFloat selectedSliceOffsetRadius;
@property(nonatomic, assign) BOOL    showPercentage;
- (id)initWithFrame:(CGRect)frame Center:(CGPoint)center Radius:(CGFloat)radius;
- (void)reloadData;
- (void)setPieBackgroundColor:(UIColor *)color;

- (void)setSliceSelectedAtIndex:(NSInteger)index;
- (void)setSliceDeselectedAtIndex:(NSInteger)index;

//My methods
- (void)renderInLayer:(DLPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray;

- (void)customamizeDraw:(DLPieChart*)pieChart
              pieCentre:(CGPoint)pieCentre
            animationSpeed:(CGFloat)speed
            labelRadius:(CGFloat)labelRadius;

-(void)drawLegends:(DLPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray;

@property (nonatomic ,retain) NSMutableArray *xyDataArray;
@property (nonatomic, retain) NSMutableArray *xyColorsArray;
@property (nonatomic, retain) DLPieChart *xyPieChartView;

@end;
