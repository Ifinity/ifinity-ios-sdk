//
//  IFMContent.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 16.03.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMArea;

@interface IFMContent : NSManagedObject

@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * iconSmall;
@property (nonatomic, retain) NSString * iconThumb;
@property (nonatomic, retain) NSString * iconMedium;
@property (nonatomic, retain) NSString * iconOriginal;
@property (nonatomic, retain) NSNumber * notification;
@property (nonatomic, retain) NSSet *areas;
@end

@interface IFMContent (CoreDataGeneratedAccessors)

- (void)addAreasObject:(IFMArea *)value;
- (void)removeAreasObject:(IFMArea *)value;
- (void)addAreas:(NSSet *)values;
- (void)removeAreas:(NSSet *)values;

@end
