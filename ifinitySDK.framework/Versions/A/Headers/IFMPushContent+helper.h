//
//  IFMPushContent+helper.h
//  ifinitySDK
//
//  Created by Mario on 03.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import "IFMPushContent.h"

@interface IFMPushContent (helper)

+ (IFMPushContent *)fetchPushContentForVenueId:(NSNumber *)venueId backgroundNotification:(BOOL)notification;

@end
