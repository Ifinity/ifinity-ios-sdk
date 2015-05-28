//
//  Beacon+helper.h
//  IfinitySDK
//
//  Created by GetIfinity on 04.01.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import "IFMBeacon.h"

@interface IFMBeacon (helper)

+ (IFMBeacon *)fetchBeaconWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchBeaconsWithFloorplanID:(NSNumber *)floorplanID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchBeaconsWithVenueId:(NSNumber *)venueId;
+ (IFMBeacon *)addBeaconRemoteID:(NSNumber *)remoteID
                       areaID:(NSNumber *)areaID
                  floorplanID:(NSNumber *)floorplanID
                         name:(NSString *)name
                         uuid:(NSString *)uuid
                        major:(NSNumber *)major
                        minor:(NSNumber *)minor
                          lat:(NSNumber *)lat
                          lng:(NSNumber *)lng
         managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchAll;
+ (BOOL)hasBeacons;
+ (IFMBeacon *)beaconForUUID:(NSString *)uuid;
+ (IFMBeacon *)beaconForiBeaconID:(NSString *)iBeaconID;
+ (IFMBeacon *)beaconForName:(NSString *)name;

@end
