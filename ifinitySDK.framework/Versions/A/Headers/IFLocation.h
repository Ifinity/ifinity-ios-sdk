//
//  IFLocation.h
//  IfinitySDK
//
//  Created by GetIfinity on 25.03.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, IFRouteNodeType) {
    IFRouteNodeTypeUnknown = 0,
    IFRouteNodeTypeNormal = 1,
    IFRouteNodeTypeEnterExit = 2,
    IFRouteNodeTypeStairs = 3,
    IFRouteNodeTypeElevator = 4
};

/**
 *  Location object with extended description.
 */
@interface IFLocation : CLLocation
@property (nonatomic, copy) NSString *locationDescription;
@property (nonatomic) IFRouteNodeType type;
@property (nonatomic, strong) NSNumber *nodeId;
@property (nonatomic) NSUInteger index;
- (float)angleToLocation:(IFLocation *)second;

+ (float)angleFromCoordinate:(CLLocationCoordinate2D)first
                toCoordinate:(CLLocationCoordinate2D)second;

@end
