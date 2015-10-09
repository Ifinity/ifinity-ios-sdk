//
//  IFMPush+helper.h
//  ifinitySDK
//
//  Created by Mariusz Graczkowski on 12.05.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import "IFMPush.h"

@interface IFMPush (helper)
+ (IFMPush *)fetchPushWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (NSArray *)fetchAll;
+ (NSArray *)fetchAllWithRemoteID:(NSNumber *)remoteID limited:(NSUInteger)limited managedObjectContext:(NSManagedObjectContext *)context;
+ (IFMPush *)fetchLastRemotePush;
@end
