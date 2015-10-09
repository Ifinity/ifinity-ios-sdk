//
//  IFMPushContent.h
//  ifinitySDK
//
//  Created by Mario on 02.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMContent, IFMVenue;

@interface IFMPushContent : NSManagedObject

@property (nonatomic, retain) NSNumber * from;
@property (nonatomic, retain) NSNumber * to;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) IFMVenue *venue;
@property (nonatomic, retain) IFMContent *content;

@end
