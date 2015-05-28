//
//  IFMPushLocal.h
//  ifinitySDK
//
//  Created by Mariusz Graczkowski on 13.05.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMPush;

@interface IFMPushLocal : NSManagedObject

@property (nonatomic, retain) NSNumber * area_id;
@property (nonatomic, retain) NSNumber * push_id;
@property (nonatomic, retain) NSNumber * venue_id;
@property (nonatomic, retain) NSNumber * content_id;
@property (nonatomic, retain) IFMPush *push;

@end
