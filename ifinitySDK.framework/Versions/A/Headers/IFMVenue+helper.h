//
//  IFMVenue+helper.h
//  ifinitySDK
//
//  Created by GetIfinity on 09.12.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import "IFMVenue.h"

@interface IFMVenue (helper)
+ (IFMVenue *)fetchVenueWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchAll;
@end
