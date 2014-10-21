//
//  Area.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 17.02.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMAreaPoint, IFMContent, IFMFloorplan;

@interface IFMArea : NSManagedObject

@property (nonatomic, retain) NSNumber * atype_id;
@property (nonatomic, retain) NSNumber * lat;
@property (nonatomic, retain) NSNumber * lng;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSNumber * floorplan_id;
@property (nonatomic, retain) NSSet *contents;
@property (nonatomic, retain) NSSet *points;
@property (nonatomic, retain) IFMFloorplan *floorplan;
@end

@interface IFMArea (CoreDataGeneratedAccessors)

- (void)addContentsObject:(IFMContent *)value;
- (void)removeContentsObject:(IFMContent *)value;
- (void)addContents:(NSSet *)values;
- (void)removeContents:(NSSet *)values;

- (void)addPointsObject:(IFMAreaPoint *)value;
- (void)removePointsObject:(IFMAreaPoint *)value;
- (void)addPoints:(NSSet *)values;
- (void)removePoints:(NSSet *)values;

@end
