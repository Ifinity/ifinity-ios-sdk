//
//  IFMVenueImage.h
//  ifinitySDK
//
//  Created by Wojciech Chojnacki on 14.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "IFMImage.h"

@class IFMVenue;

@interface IFMVenueImage : IFMImage

@property (nonatomic, retain) IFMVenue *venue;

@end
