//
//  Beacon.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 06.03.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>

@class IFMAlert, IFMFloorplan;

@interface IFMBeacon : NSManagedObject
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * floorplan_id;
@property (nonatomic, retain) NSString * ibeacon_id;
@property (nonatomic, retain) NSNumber * lat;
@property (nonatomic, retain) NSNumber * lng;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * uuid;
@property (nonatomic, retain) NSNumber * area_id;
@property (nonatomic, retain) NSSet *alerts;
@property (nonatomic, retain) IFMFloorplan *floorplan;

- (CLLocation *)location;
@end

@interface IFMBeacon (CoreDataGeneratedAccessors)

- (void)addAlertsObject:(IFMAlert *)value;
- (void)removeAlertsObject:(IFMAlert *)value;
- (void)addAlerts:(NSSet *)values;
- (void)removeAlerts:(NSSet *)values;

@end
