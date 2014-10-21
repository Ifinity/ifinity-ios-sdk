//
//  Alert.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 03.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface IFMAlert : NSManagedObject

@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSNumber * distance;
@property (nonatomic, retain) NSString * action;
@property (nonatomic, retain) NSDate * valid_from;
@property (nonatomic, retain) NSDate * valid_to;
@property (nonatomic, retain) NSSet *beacons;
@end

@interface IFMAlert (CoreDataGeneratedAccessors)

- (void)addBeaconsObject:(NSManagedObject *)value;
- (void)removeBeaconsObject:(NSManagedObject *)value;
- (void)addBeacons:(NSSet *)values;
- (void)removeBeacons:(NSSet *)values;

@end
