//
//  AreaPoint.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 03.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface IFMAreaPoint : NSManagedObject

@property (nonatomic, retain) NSNumber * lat;
@property (nonatomic, retain) NSNumber * lng;
@property (nonatomic, retain) NSNumber * order;
@property (nonatomic, retain) NSManagedObject *area;

@end
