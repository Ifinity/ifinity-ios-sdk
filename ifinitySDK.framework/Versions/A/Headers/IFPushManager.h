//
//  IFPushManager.h
//  ifinitySDK
//
//  Created by Mariusz Graczkowski on 11.05.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFAPIModel.h"
#import "IFMPush.h"

/**
 * This controller includes methods for handling notifications related to the location near the venue or area
 *
 * Discussion:
 * Holds a list of all events
 * Notifications when new data are inserted/updated in cache database.
 *
 */

/**
 *  Notification send when new data are inserted/updated in cache database.
 */
extern NSString * const IFPushManagerNotificationPushAdd;//when add database
extern NSString * const IFPushManagerNotificationPushDelete;//when delete database

/**
 *  When will come push in background and you call function "addReceiveLocalNotification" passing the object "UILocalNotification.userInfo" from its UIApplication "didReceiveLocalNotification"
 */
extern NSString * const IFPushManagerNotificationPushAreaBackgroundAdd;
extern NSString * const IFPushManagerNotificationPushVenueBackgroundAdd;

/**
 *  When you call function "addReceiveRemoteNotification" passing the object "userInfo" from its UIApplication "didReceiveRemoteNotification"
 */
extern NSString * const IFPushManagerNotificationPushRemoteBackgroundAdd;

@interface IFPushManager : NSObject

+ (IFPushManager *)sharedManager;

/**
 *  List of all places Push
 */
- (NSArray *)fetchAll;

/**
 *  Pass the object "userInfo" from its UIApplication "didReceiveRemoteNotification"
 */
- (void)addReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 *  Pass the object "UILocalNotification.userInfo" from its UIApplication "didReceiveLocalNotification"
 */
- (void)addReceiveLocalNotification:(NSDictionary *)userInfo;

@end
