//
//  IFMVenue.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 14.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMBeacon, IFMContent, IFMFloorplan, IFMVenueImage;

@interface IFMVenue : NSManagedObject

@property (nonatomic, retain) NSNumber * center_lat;
@property (nonatomic, retain) NSNumber * center_lng;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * publicVenue;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * type;
@property (nonatomic, retain) NSNumber * update_time;
@property (nonatomic, retain) NSSet *beacons;
@property (nonatomic, retain) IFMContent *content;
@property (nonatomic, retain) NSSet *floorplans;
@property (nonatomic, retain) IFMVenueImage *image;
@end

@interface IFMVenue (CoreDataGeneratedAccessors)

- (void)addBeaconsObject:(IFMBeacon *)value;
- (void)removeBeaconsObject:(IFMBeacon *)value;
- (void)addBeacons:(NSSet *)values;
- (void)removeBeacons:(NSSet *)values;

- (void)addFloorplansObject:(IFMFloorplan *)value;
- (void)removeFloorplansObject:(IFMFloorplan *)value;
- (void)addFloorplans:(NSSet *)values;
- (void)removeFloorplans:(NSSet *)values;

@end
