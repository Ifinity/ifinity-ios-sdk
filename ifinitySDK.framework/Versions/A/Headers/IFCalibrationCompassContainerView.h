//
//  CalibrationCompasuView.h
//  Pods
//
//  Created by Mario on 26.08.2015.
//
//

#import <UIKit/UIKit.h>

@interface IFCalibrationCompassContainerView : UIView

/**
 *  Start the compass calibration
 */
- (void)startCalibration;

/**
 *  Stop the compass calibration
 */
- (void)stopCalibration;

/**
 *  Restart the compass calibration
 */
- (void)restartCalibration;

/**
 *  Distance in meters that need to go in order to calibrate the compass
 *
 *  @return distance needed calibration
 */
- (int)getDistanceNeededToCalibrationCompass;

@end
