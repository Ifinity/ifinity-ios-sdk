//
//  Floorplan+helper.h
//  IfinitySDK
//
//  Created by GetIfinity on 06.01.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import "IFMFloorplan.h"
#import <MapKit/MapKit.h>

@interface IFMFloorplan (helper)

+ (IFMFloorplan *)fetchFloorplansWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchFloorplansWithVenueID:(NSNumber *)venueID managedObjectContext:(NSManagedObjectContext *)context;

+ (IFMFloorplan *)addFloorplanRemoteID:(NSNumber *)remoteID
                            venueID:(NSNumber *)venueID
                              mapID:(NSString *)mapID
                               name:(NSString *)name
                              label:(NSNumber *)label
                               file:(NSString *)file
                               data:(id)data
                            details:(id)details
                  managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *) fetchAll;
- (CLLocationCoordinate2D)center;

@end
