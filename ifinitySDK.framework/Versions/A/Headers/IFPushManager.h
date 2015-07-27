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
 *  Notification send when new data are inserted/updated in cache database.
 */
extern NSString * const IFPushManagerNotificationPushAdd;//when add database
extern NSString * const IFPushManagerNotificationPushDelete;//when delete database
extern NSString * const IFPushManagerNotificationPushAreaBackgroundAdd;
extern NSString * const IFPushManagerNotificationPushVenueBackgroundAdd;
extern NSString * const IFPushManagerNotificationPushRemoteBackgroundAdd;

@interface IFPushManager : NSObject

+ (IFPushManager *)sharedManager;

- (NSArray *)fetchAll;
- (void)addReceiveRemoteNotification:(NSDictionary *)userInfo;
- (void)addReceiveLocalNotification:(NSDictionary *)userInfo;

@end
