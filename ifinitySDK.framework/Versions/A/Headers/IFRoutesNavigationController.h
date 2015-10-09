//
//  IFRouteNavigationGeosController.h
//  ifinitySDK
//
//  Created by Mario on 14.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFMFloorplan.h"
#import "IFMArea.h"
#import "IFDataManager.h"
#import "IFTargetNavigationContext.h"
#import "IFDataManager+Private.h"

/**
 * This controller contains methods to generate routing between two points. We have an opportunity in finding a route to another venue, another area or another area in another venue
 *
 * Discussion:
 * This class helps in calculating a route between two points
 * class holds all route segments
 * It allows you to receive information on the current distance to the target based on the supplied user's position
 * Holds objects to help in navigating to end point
 *
 */

@class IFRoutesNavigationController;

@protocol IFRoutesNavigationControllerDelegate <NSObject>

@optional
/**
 *  Success create route to destination
 *
 *  @param routesNavigationController    IFRoutesNavigationController
 *  @param segments array segments with IFRouteModel
 *  @param indexContext current index segment
 *  @param navigationContext current navigationContext(IFRouteModel parsed on IFTargetNavigationContext)
 */
- (void)successDestinationRoutesNavigation:(IFRoutesNavigationController *)routesNavigationController
                                  segments:(NSArray *)segments
                              indexContext:(NSUInteger)indexContext
                         navigationContext:(IFTargetNavigationContext *)navigationContext;
/**
 *  Error create route to destination
 *
 *  @param error
 */
- (void)failureDestinationRoutesNavigation:(IFRoutesNavigationController *)routesNavigationController
                                     error:(NSError *)error;
/**
 *  There is a new index segments. Changed the current navigation context
 *
 *  @param routesNavigationController    IFRoutesNavigationController
 *  @param navigationContext current navigationContext(IFRouteModel parsed on IFTargetNavigationContext)
 */
- (void)changeContextNavigation:(IFRoutesNavigationController *)routesNavigationController
              navigationContext:(IFTargetNavigationContext *)navigationContext;
/**
 *  Finish of navigation. There are no more segments or the number of segments is null
 *
 *  @param routesNavigationController    IFRoutesNavigationController
 */
- (void)finishNavigation:(IFRoutesNavigationController *)routesNavigationController;

@end

@interface IFRoutesNavigationController : NSObject

@property (nonatomic, weak) id<IFRoutesNavigationControllerDelegate> delegate;

/**
 *  Start floorplan id
 */
@property (nonatomic, strong, readonly) NSNumber *fromFloorplanID;

/**
 *  Start venue id
 */
@property (nonatomic, strong, readonly) NSNumber *fromVenueID;

/**
 *  Stop floorplan id
 */
@property (nonatomic, strong, readonly) NSNumber *toFloorplanID;

/**
 *  Stop venue id
 */
@property (nonatomic, strong, readonly) NSNumber *toVenueID;

/**
 *  Calculate route is ready
 */
@property (nonatomic, readonly) BOOL ready;

/**
 *  Gets the route and create
 */
@property (nonatomic, readonly) BOOL loading;

/**
 *  Finish of navigation. There are no more segments or the number of segments is null
 */
@property (nonatomic, readonly) BOOL finish;

/**
 *  Current index is the last index of an array of segments
 */
@property (nonatomic, readonly) BOOL isLastSegment;

/**
 *  The current object from an array of segments parsed(IFRouteModel parsed on IFTargetNavigationContext)
 */
@property (nonatomic, strong, readonly) IFTargetNavigationContext *currentNavigationContext;

/**
 *  The current index from an array of segments
 */
@property (nonatomic, readonly) NSUInteger indexSegment;

/**
 *  Max index array of segments
 */
@property (nonatomic, readonly) NSUInteger maxSegment;

/**
 *  The current object from an array of segments
 */
@property (nonatomic, strong, readonly) IFRouteModel *currentSegment;

/**
 *  Call API to find a route between two points. The endpoint area in a different venue
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param fromVenueId    start venue id
 *  @param toFloorId      destination floor id
 *  @param toVenueId      destination venue id
 *  @param toCoordinate   destination coordinates
 *  @param type           route type
 */
- (void)setDestinationFromFloorplanID:(NSNumber *)fromFloorplanId
                       fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
                          fromVenueID:(NSNumber *)fromVenueId
                        toFloorplanID:(NSNumber *)toFloorplanId
                            toVenueID:(NSNumber *)toVenueId
                         toCoordinate:(CLLocationCoordinate2D)toCoordinate
                             withType:(IFRouteType)type;

/**
 *  Call API to find a route between two points. The endpoint other venue
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param fromVenueId    start venue id
 *  @param toVenueId      destination venue id
 *  @param type           route type
 */
- (void)setDestinationFromFloorplanID:(NSNumber *)fromFloorplanId
                       fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
                          fromVenueID:(NSNumber *)fromVenueId
                            toVenueID:(NSNumber *)toVenueId
                             withType:(IFRouteType)type;

/**
 *  Get object from an array of segments based on the index
 */
- (IFRouteModel *)segmentAtIndex:(NSUInteger)index;

/**
 *  Change current index from an array of segments
 */
- (void)nextSegment;

/**
 *  Total distance of all segments to endpoint
 */
- (CLLocationDistance)totalDistanceToUser:(CLLocationCoordinate2D)userCoordinate;

@end
