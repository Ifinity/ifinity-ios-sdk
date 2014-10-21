//
//  IFRouteDataProvider.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 27.02.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFDataManager.h"
#import "IFBluetoothManager.h"
#import "IFRouteDetails.h"
#import "IFPolyline.h"
#import "IFDataProvider.h"


/** 
 *  There could be different type of routes: Shortest, Stairs only, Elevator only
 */
typedef enum {
    IFRouteTypeDefault = 0,
    IFRouteTypeStairs  = 1,
    IFRouteTypeElevator = 2
} IFRouteType;

/**
 *  Used to calculate the shortes route from the current location to the destination location. All the calculations is made on the server side, this class is responsible for creating the request only.
 */
@interface IFRouteDataProvider : IFDataProvider

/**
 *  Query the server for the shourtest route
 *
 *  @param fromFloor      Starting floor
 *  @param fromCoordinate Starting coordinate
 *  @param toFloor        Target floor
 *  @param toCoordinate   Target coordinate
 *  @param transportType  Route type (default/stairs/elevator)
 *  @param success        Success Callback
 *  @param failure        Error Callback
 */
- (void)queryRouteFromFloor:(IFMFloorplan *)fromFloor
                 fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
                    toFloor:(IFMFloorplan *)toFloor
                 toCoordinate:(CLLocationCoordinate2D)toCoordinate
              transportType:(IFRouteType)type
                    success:(void (^)(NSDictionary *routes, CLLocationCoordinate2D endPoint))success
                    failure:(IFManagerClientFailure)failure;

/**
 *  Gets the information about the next node, current angle, and target distance, based on the pXy coordinate
 *
 *  @param pXy      Coordinate to snap
 *  @param polyline Polyline we want to snap to
 *
 *  @return Route details
 */
- (IFRouteDetails *) getCoordinateClosestTo:(CLLocationCoordinate2D)pXy onPolyline:(IFPolyline *)polyline;

@end
