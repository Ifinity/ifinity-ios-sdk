//
//  IFFloorplanDataProvider.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 06.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFDataProvider.h"

@class IFFloorplanDataProvider;

@protocol IFFloorplanDataProviderDelegate <NSObject>
@optional

/**
 *  Invoked once the information about the floorplans will be updated
 *
 *  TODO: We probably don't need this parameter here, once we're using the singleton design pattern
 *  @param manager This manager
 *  @param areas   New Floorplans
 */
- (void) dataProvider:(IFFloorplanDataProvider *)provider didUpdateFloorplans:(NSArray *)floorplans;

/**
 *  Invoked only when we reach some API error
 *
 *  @param manager This manager
 *  @param areas   New Areas
 */
- (void) dataProvider:(IFFloorplanDataProvider *)provider queryError:(NSError *)error;
@end



@interface IFFloorplanDataProvider : IFDataProvider

@property(nonatomic, weak) id<IFFloorplanDataProviderDelegate>delegate;

/**
 *  Internal method, called always once the user position from the GPS changes radically.
 *
 *  @param lat      GPS Latitude
 *  @param lng      GPS Longitude
 *  @param distance Range
 */
- (void)queryFloorplansForLat: (NSNumber *)lat lng:(NSNumber *)lng distance:(NSNumber *)distance;;

@end
