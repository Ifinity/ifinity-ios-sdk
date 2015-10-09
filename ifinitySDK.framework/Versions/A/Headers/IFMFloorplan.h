//
//  IFMFloorplan.h
//  ifinitySDK
//
//  Created by Mario on 28.07.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMArea, IFMBeacon, IFMFloorplanPoint, IFMVenue;

@interface IFMFloorplan : NSManagedObject

@property (nonatomic, retain) NSNumber * label;
@property (nonatomic, retain) NSString * map_id;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * nelat;
@property (nonatomic, retain) NSNumber * nelng;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSNumber * rotation;
@property (nonatomic, retain) NSNumber * swlat;
@property (nonatomic, retain) NSNumber * swlng;
@property (nonatomic, retain) NSNumber * tileStatus;
@property (nonatomic, retain) NSNumber * venue_id;
@property (nonatomic, retain) NSSet *areas;
@property (nonatomic, retain) NSSet *beacons;
@property (nonatomic, retain) IFMFloorplanPoint *point;
@property (nonatomic, retain) IFMVenue *venue;
@end

@interface IFMFloorplan (CoreDataGeneratedAccessors)

- (void)addAreasObject:(IFMArea *)value;
- (void)removeAreasObject:(IFMArea *)value;
- (void)addAreas:(NSSet *)values;
- (void)removeAreas:(NSSet *)values;

- (void)addBeaconsObject:(IFMBeacon *)value;
- (void)removeBeaconsObject:(IFMBeacon *)value;
- (void)addBeacons:(NSSet *)values;
- (void)removeBeacons:(NSSet *)values;

@end
