//
//  IFMImage+helper.h
//  ifinitySDK
//
//  Created by GetIfinity on 10.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import "IFMImage.h"

@interface IFMImage (helper)
+ (IFMImage *)fetchImageWithRemoteID:(NSNumber *)remoteID managedObjectContext:(NSManagedObjectContext *)context;
@end
