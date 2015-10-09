//
//  IFMBeacon.h
//  ifinitySDK
//
//  Created by Mario on 08.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>

@class IFMAlert, IFMFloorplan, IFMVenue;

@interface IFMBeacon : NSManagedObject

@property (nonatomic, retain) NSNumber * area_id;
@property (nonatomic, retain) NSNumber * floorplan_id;
@property (nonatomic, retain) NSNumber * lat;
@property (nonatomic, retain) NSNumber * lng;
@property (nonatomic, retain) NSNumber * major;
@property (nonatomic, retain) NSNumber * minor;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * uuid;
@property (nonatomic, retain) NSNumber * venue_id;
@property (nonatomic, retain) NSSet *alerts;
@property (nonatomic, retain) IFMFloorplan *floorplan;
@property (nonatomic, retain) IFMVenue *venue;

- (CLLocation *)location;

@end

@interface IFMBeacon (CoreDataGeneratedAccessors)

- (void)addAlertsObject:(IFMAlert *)value;
- (void)removeAlertsObject:(IFMAlert *)value;
- (void)addAlerts:(NSSet *)values;
- (void)removeAlerts:(NSSet *)values;

@end
