//
//  IFMVenue.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 16.03.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class IFMFloorplan;

@interface IFMVenue : NSManagedObject

@property (nonatomic, retain) NSNumber * center_lat;
@property (nonatomic, retain) NSNumber * center_lng;
@property (nonatomic, retain) NSString * imageOriginal;
@property (nonatomic, retain) NSString * imageThumb;
@property (nonatomic, retain) NSString * imageMedium;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * publicVenue;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSNumber * update_time;
@property (nonatomic, retain) NSString * imageSmall;
@property (nonatomic, retain) NSSet *floorplans;
@end

@interface IFMVenue (CoreDataGeneratedAccessors)

- (void)addFloorplansObject:(IFMFloorplan *)value;
- (void)removeFloorplansObject:(IFMFloorplan *)value;
- (void)addFloorplans:(NSSet *)values;
- (void)removeFloorplans:(NSSet *)values;

@end
