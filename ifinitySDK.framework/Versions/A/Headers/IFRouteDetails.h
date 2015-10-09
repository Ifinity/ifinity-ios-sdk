//
//  RouteDetails.h
//  IfinitySDK
//
//  Created by GetIfinity on 07.03.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

/**
 *  Holds the information about the route, from and to coordinates, distance and next node details. 
 */
@interface IFRouteDetails : NSObject
@property (nonatomic) NSUInteger indexInRoute;
@property (nonatomic) CLLocationCoordinate2D currentLocation;
@property (nonatomic) CLLocationCoordinate2D nextNodeLocation;
@property (nonatomic) NSString *nextNodeDescription;
@property (nonatomic) NSUInteger nextNodeRouteIndex;
@property (nonatomic) double distanceToEnd;
@property (nonatomic) double distanceToStart;
@property (nonatomic) double distanceToRoute;
@property (nonatomic) double distanceToNext;
@property (nonatomic) double headingToNext;
@property (nonatomic) BOOL reachedEndOfTheRoad;

@end
