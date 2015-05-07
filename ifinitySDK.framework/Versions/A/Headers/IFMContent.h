//
//  IFMContent.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 14.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMArea, IFMContentImage, IFMVenue;

@interface IFMContent : NSManagedObject

@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * notification;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSSet *areas;
@property (nonatomic, retain) IFMVenue *venue;
@property (nonatomic, retain) IFMContentImage *icon;
@end

@interface IFMContent (CoreDataGeneratedAccessors)

- (void)addAreasObject:(IFMArea *)value;
- (void)removeAreasObject:(IFMArea *)value;
- (void)addAreas:(NSSet *)values;
- (void)removeAreas:(NSSet *)values;

@end
