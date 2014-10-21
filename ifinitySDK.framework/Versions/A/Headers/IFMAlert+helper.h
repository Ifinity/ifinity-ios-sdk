//
//  Alert+helper.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import "IFMAlert.h"

@interface IFMAlert (helper)

+ (IFMAlert *)fetchAlertWithRemoteID:(NSNumber *)remoteID;

+ (IFMAlert *)addAlertRemoteID:(NSNumber *)remoteID
                     beacon:(NSSet *)beacons
                   distance:(NSNumber *)distance
                  validFrom:(NSDate *)from
                    validTo:(NSDate *)to
          managedObjectContext:(NSManagedObjectContext *)context;


@end
