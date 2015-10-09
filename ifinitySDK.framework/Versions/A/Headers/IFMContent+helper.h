//
//  Content+helper.h
//  IfinitySDK
//
//  Created by GetIfinity on 04.01.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import "IFMContent.h"

@interface IFMContent (helper)

+ (IFMContent *)fetchContentWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
+ (IFMContent *)addContentRemoteID:(NSNumber *)remoteID
                            areaID:(NSNumber *)areaID
                              name:(NSString *)name
              managedObjectContext:(NSManagedObjectContext *)context;
- (NSString *)getContentURL;
- (BOOL)validateContent;

@end
