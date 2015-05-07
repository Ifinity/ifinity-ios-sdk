//
//  IFMContentImage.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 14.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "IFMImage.h"

@class IFMContent;

@interface IFMContentImage : IFMImage

@property (nonatomic, retain) IFMContent *content;

@end
