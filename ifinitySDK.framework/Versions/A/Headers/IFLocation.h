//
//  IFLocation.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 25.03.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 *  Location object with extended description.
 */
@interface IFLocation : CLLocation
@property (nonatomic, copy) NSString *locationDescription;

- (float)angleToLocation:(IFLocation *)second;

+ (float)angleFromCoordinate:(CLLocationCoordinate2D)first
                toCoordinate:(CLLocationCoordinate2D)second;

@end
