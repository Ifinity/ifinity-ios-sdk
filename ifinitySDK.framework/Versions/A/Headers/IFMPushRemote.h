//
//  IFMPushRemote.h
//  ifinitySDK
//
//  Created by Mariusz Graczkowski on 14.05.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMPush;

@interface IFMPushRemote : NSManagedObject

@property (nonatomic, retain) NSNumber * background_mode;
@property (nonatomic, retain) NSString * background_url;
@property (nonatomic, retain) NSNumber * push_id;
@property (nonatomic, retain) NSNumber * update_time;
@property (nonatomic, retain) IFMPush *push;

@end
