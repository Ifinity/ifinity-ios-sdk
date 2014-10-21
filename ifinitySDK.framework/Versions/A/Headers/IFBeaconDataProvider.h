//
//  IFBeaconManager.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import "IFDataProvider.h"

@class IFBeaconDataProvider;

@protocol IFBeaconProviderDelegate <NSObject>
@optional

/**
 *  Invoked once the information about the beacons will be updated
 *
 *  @param manager This manager
 *  @param areas   New Beacons
 */
- (void) dataProvider:(IFBeaconDataProvider *)provider didUpdateBeacons:(NSArray *)beacons;

/**
 *  Invoked only when we reach some API error
 *
 *  @param manager This manager
 *  @param areas   New Areas
 */
- (void) dataProvider:(IFBeaconDataProvider *)provider queryError:(NSError *)error;
@end



@interface IFBeaconDataProvider : IFDataProvider

@property(nonatomic, weak) id<IFBeaconProviderDelegate>delegate;

/**
 *  Internal method, called always once the user position from the GPS changes radically.
 *
 *  @param lat      GPS Latitude
 *  @param lng      GPS Longitude
 *  @param distance Range
 */
- (void)queryBeaconsForLat: (NSNumber *)lat lng:(NSNumber *)lng distance:(NSNumber *)distance;

/**
 *  Query DB, fetchs all the beacons and convert them to annotations.
 *
 *  @return An array of annotations
 */
- (NSArray *)fetchBeaconAnnotations;

@end
