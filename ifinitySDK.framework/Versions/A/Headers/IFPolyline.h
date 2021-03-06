//
//  IFPolyline.h
//  IfinitySDK
//
//  Created by GetIfinity on 25.03.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <MapKit/MapKit.h>
#import "IFRouteDetails.h"

typedef NS_ENUM (NSInteger, IFPolylineType) {
    IFPolylineTypeNone = 0,
    IFPolylineTypeCompassTranslate = 1,
    IFPolylineTypeCompassLeastSquare = 2,
    IFPolylineTypeCompassAll = 3
};

/**
 *  Extended Polyline view, used to get the information about each node description. Important for visually impaired.
 */
@interface IFPolyline : MKPolyline

@property (nonatomic, strong) NSArray *descriptions;
@property (nonatomic, strong) NSArray *nodeRouteIndexs;
@property (nonatomic, assign) IFPolylineType type;

- (NSString *)descriptionAtIndex:(NSUInteger)index;
- (NSNumber *)nodesRouteIndexAtIndex:(NSUInteger)index;

/**
 *  Calculate full path lenght from current position to end of the path.
 *
 *  @param coordinate real not translated coordinate
 *  @param idx        index of next point in path
 *
 *  @return length in meters
 */
- (CLLocationDistance)pathLenghtFromCoordinate:(CLLocationCoordinate2D)coordinate andIndex:(NSUInteger)idx;

@end
