//
//  Beacon+helper.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import "IFMBeacon.h"

@interface IFMBeacon (helper)

+ (IFMBeacon *)fetchBeaconWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchBeaconsWithFloorplanID:(NSNumber *)floorplanID managedObjectContext:(NSManagedObjectContext *)context;

+ (IFMBeacon *)addBeaconRemoteID:(NSNumber *)remoteID
                       areaID:(NSNumber *)areaID
                  floorplanID:(NSNumber *)floorplanID
                         name:(NSString *)name
                    iBeaconID:(NSString *)iBeaconID
                         uuid:(NSString *)uuid
                          lat:(NSNumber *)lat
                          lng:(NSNumber *)lng
         managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchAll;
+ (BOOL)hasBeacons;
+ (IFMBeacon *)beaconForUUID:(NSString *)uuid;
+ (IFMBeacon *)beaconForiBeaconID:(NSString *)iBeaconID;
+ (IFMBeacon *)beaconForName:(NSString *)name;

@end