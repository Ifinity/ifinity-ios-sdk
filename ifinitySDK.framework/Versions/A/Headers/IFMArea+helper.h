//
//  Area+helper.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import "IFMArea.h"
#import <MapKit/MapKit.h>

#define AreaTypePolygon @1

@interface IFMArea (helper)

+ (IFMArea *)fetchAreaWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchAreasWithFloorplanID:(NSNumber *)floorplanID managedObjectContext:(NSManagedObjectContext *)context;

+ (IFMArea *)addAreaRemoteID:(NSNumber *)remoteID
              floorplanID:(NSNumber *)floorplanID
                     type:(NSNumber *)type
                     name:(NSString *)name
                      lat:(NSNumber *)lat
                      lng:(NSNumber *)lng
                   points:(NSArray *)points
        managedObjectContext:(NSManagedObjectContext *)context;

+ (NSArray *) fetchAll;
+ (NSArray *) fetchAllNotIn:(NSArray *)areas;
- (CLLocationCoordinate2D) center;

@end
