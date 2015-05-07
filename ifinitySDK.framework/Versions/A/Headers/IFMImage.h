//
//  IFMImage.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 14.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface IFMImage : NSManagedObject

@property (nonatomic, retain) NSString * imageMedium;
@property (nonatomic, retain) NSString * imageOriginal;
@property (nonatomic, retain) NSString * imageSmall;
@property (nonatomic, retain) NSString * imageThumb;
@property (nonatomic, retain) NSNumber * remote_id;

@end
