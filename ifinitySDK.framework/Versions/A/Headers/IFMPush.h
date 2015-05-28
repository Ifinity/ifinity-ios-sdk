//
//  IFMPush.h
//  ifinitySDK
//
//  Created by Mariusz Graczkowski on 14.05.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

enum {
    IFMPushTypeNone = 0,
    IFMPushTypeRemote = 1,
    IFMPushTypeLocal = 2,
    IFMPushTypeLocalBackground = 3
};
typedef int16_t IFMPushType;

@class IFMPushLocal, IFMPushRemote;

@interface IFMPush : NSManagedObject

@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSDate * date;
@property (nonatomic, retain) NSString * icon;
@property (nonatomic, retain) NSString * info;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, assign) IFMPushType type;
@property (nonatomic, retain) IFMPushLocal *pushLocal;
@property (nonatomic, retain) IFMPushRemote *pushRemote;

@end
