//
//  Content.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 03.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface IFMContent : NSManagedObject

@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSSet *areas;
@end

@interface IFMContent (CoreDataGeneratedAccessors)

- (void)addAreasObject:(NSManagedObject *)value;
- (void)removeAreasObject:(NSManagedObject *)value;
- (void)addAreas:(NSSet *)values;
- (void)removeAreas:(NSSet *)values;

@end
