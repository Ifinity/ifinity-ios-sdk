//
//  IFIndoorLocationManager.h
//  ifinitySDK
//
//  Created by GetIfinity on 17.10.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "IFBluetoothManager.h"

/**
 *  IFIndoorLocationManager is used to track user position within the buildings, notifies when user enters into area, or leaves it
 */
@class IFIndoorLocationManager;

/**
 *  Delegate for `IFIndoorLocationManager`
 */
@protocol IFIndoorLocationManagerDelegate <NSObject>
@optional

/**
 *  We've just enter into the new area
 *
 *  @param area Active area.
 */
- (void)manager:(IFIndoorLocationManager *)manager didUpdateIndoorLocation:(CLLocation *)location;

/**
 *  We've just enter into the new area
 *
 *  @param area Active area.
 */
- (void)manager:(IFIndoorLocationManager *)manager didEnterArea:(IFMArea *)area;

/**
 *  We've just leave the area
 *
 *  @param area Area we've just left
 */
- (void)manager:(IFIndoorLocationManager *)manager didExitArea:(IFMArea *)area;

@end

/**
 *  The `IFIndoorLocationManager` class is central point for delivering information about indoor device position.
 *
 */
@interface IFIndoorLocationManager : NSObject
@property (nonatomic, weak) id<IFIndoorLocationManagerDelegate> delegate;

/**
 *  Current user position (indoors)
 */
@property (nonatomic, readonly) CLLocation *currentLocation;

/** 
 * shared instance of IFBluetoothManager
 */
- (instancetype)initWithBluetoothManager:(IFBluetoothManager *)manager;

/**
 * Once we want to be notified about user indoor position updates
 */
- (void)startUpdatingIndoorLocation;

/**
 * Shuts down the indoor monitoring process
 */
- (void)stopUpdatingIndoorLocation;

/**
 *  Ask manager to search for the areas nearby, and get's notified about they presence
 *
 *  @param floorplan A floorplan we're interested in
 */
- (void)startCheckingAreasForFloorplan:(IFMFloorplan *)floorplan;

/**
 *  When we don't need information about the areas any more
 */
- (void)stopCheckingAreas;

@end
