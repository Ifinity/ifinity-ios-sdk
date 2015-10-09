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


/**
 *  Method to provide to IFIndoorLocationManager beacon coordinates. 
 *  If this method is immplemented it overrides data from internal cache (data from geos).
 *  In theory this delegate should allow to implement own beacons source for navigation logic.
 *
 *  @param area Area we've just left
 */
- (CLLocation *)manager:(IFIndoorLocationManager *)manager locationForTransmitter:(IFTransmitter *)transmitter;

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
 *  Start detecting current area base on calculated position. When area changed notify about it by calling methods in delegate (didEnterArea, didExitArea).
 *
 *  @param floorplan A floorplan we're interested in
 */
- (void)startCheckingAreasForFloorplan:(IFMFloorplan *)floorplan;

/**
 *  Stop checking areas for current position.
 */
- (void)stopCheckingAreas;

/**
 *  Current area base on position
 *
 *  @return area model object
 */
- (IFMArea *)currentArea;

@end
