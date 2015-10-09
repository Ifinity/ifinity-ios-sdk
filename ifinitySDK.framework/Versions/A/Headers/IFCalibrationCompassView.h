//
//  IFCalibrationCompassView.h
//  ifinitySDK
//
//  Created by Mario on 26.08.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IFCalibrationCompassContainerView.h"

@interface IFCalibrationCompassView : UIView

@property (nonatomic, strong) IFCalibrationCompassContainerView *calibrationCompassContainerView;

- (void)setDistance:(double)distance;

@end
