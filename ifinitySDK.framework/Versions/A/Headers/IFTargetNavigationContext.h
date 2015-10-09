//
//  IFTargetNavigationContext.h
//  ifinitySDK
//
//  Created by Mario on 14.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFMVenue.h"
#import "IFMArea.h"
#import "IFDataManager.h"
#import "IFRouteDetails.h"
#import "IFPolyline.h"

@interface IFTargetNavigationContext : NSObject

@property (nonatomic, strong, readonly) IFRouteDetails *nextNodeDetails;
@property (nonatomic, readonly) CLLocationCoordinate2D endPoint;
@property (nonatomic, readonly) BOOL ready;
@property (nonatomic) IFRouteSegmentType type;

- (NSArray *)allRoutes;
- (NSArray *)nodeForKey:(NSString *)key;
- (CLLocationCoordinate2D)nextNodeLocation;
- (IFPolyline *)routeForKey:(NSString *)key;
- (NSString *)nextNodeDescription;
- (NSUInteger)nextNodeRouteIndex;

- (CLLocationDistance)targetDistanceToUser:(CLLocationCoordinate2D)userCoordinate;
- (CLLocationDistance)totalDistanceToUser:(CLLocationCoordinate2D)userCoordinate;
- (CLLocationDistance)totalNodeDistanceToUser:(CLLocationCoordinate2D)userCoordinate;

- (void)setEndPoint:(CLLocationCoordinate2D)endPoint;
- (void)setRoute:(IFPolyline *)route forKey:(NSString *)key;
- (void)setNodes:(NSDictionary *)node;
- (void)setUserPosition:(CLLocationCoordinate2D)coordinate forKey:(NSString *)key;

+ (CLLocationDirection)angleFromCoordinate:(CLLocationCoordinate2D)first toCoordinate:(CLLocationCoordinate2D)second;

@end
