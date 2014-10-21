//
//  Floorplan+helper.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 06.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import "IFMFloorplan.h"
#import <MapKit/MapKit.h>

@interface IFMFloorplan (helper)

+ (IFMFloorplan *)fetchFloorplansWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchFloorplansWithPlaceID:(NSNumber *)placeID managedObjectContext:(NSManagedObjectContext *)context;

+ (IFMFloorplan *)addFloorplanRemoteID:(NSNumber *)remoteID
                            placeID:(NSNumber *)placeID
                              mapID:(NSString *)mapID
                               name:(NSString *)name
                              label:(NSString *)label
                               file:(NSString *)file
                            details:(id)details
                  managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *) fetchAll;
- (CLLocationCoordinate2D)center;

@end
