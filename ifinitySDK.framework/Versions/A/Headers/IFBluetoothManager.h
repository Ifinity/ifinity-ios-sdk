//
//  IFBluetoothManager.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "IFMFloorplan+helper.h"
#import "IFTransmiter.h"

@class IFBluetoothManager;

/**
 *  Managers are the most important part of the application, you can get all the information about position, bluetooth data and content throught it's delegates.
 */
@protocol IFBluetoothManagerDelegate <NSObject>

@optional

/**
 *  Transmiter RSSI updated
 *
 *  @param manager    Bluetooth manager
 *  @param transmiter Transmiter object
 */
- (void)manager:(IFBluetoothManager *)manager didUpdateTransmiter:(IFTransmiter *)transmiter;

/**
 *  We found some active beacons for the floor
 *
 *  @param floorplan Floorplan with available beacons
 */
- (void)manager:(IFBluetoothManager *)manager didDiscoverActiveBeaconsForFloorplan:(IFMFloorplan *)floorplan;

/**
 *  We lost the connection with all of the beacons inside the floor
 *
 *  @param floorplan Floorplan with no active beacons
 */
- (void)manager:(IFBluetoothManager *)manager didLostAllBeaconsForFloorplan:(IFMFloorplan *)floorplan;

/**
 *  There are some new beacons nearby
 *
 *  @param transmiters Nearby beacons array
 */
- (void)manager:(IFBluetoothManager *)manager didChangeTransmitersCount:(NSDictionary *)transmiters;

/**
 *  A new beacon has been found
 *
 *  @param transmiter A Beacon object
 */
- (void)manager:(IFBluetoothManager *)manager didDiscoverTransmiter:(IFTransmiter *)transmiter;

/**
 *  A Beacon dissapeared
 *
 *  @param transmiter A Beacon object
 */
- (void)manager:(IFBluetoothManager *)manager didLostTransmiter:(IFTransmiter *)transmiter;

@end



@interface IFBluetoothManager : NSObject

/**
 *  IFBluetoothManagerDelegate responsible for passing all the events from the manager
 */
@property (nonatomic, weak) id <IFBluetoothManagerDelegate> delegate;

/**
 *  When useOnlyNearbyBeacons is equal YES, we're adding only beacons within the range of aprox. 1m - it's good for proximity mode, for the navigation it should be disabled!
 */
@property (nonatomic) BOOL useOnlyNearbyBeacons;

/**
 *  Each manager is a singleton, they are accessible by the sharedManager method
 *
 *  @return IFBluettothManager object
 */
+ (IFBluetoothManager *)sharedManager;

/**
 *  The most recent information about all the bacons nearby
 *
 *  @return Beacons array
 */
- (NSDictionary *)transmiters;

/**
 *  The only way to start looking for beacons and instatiate the bluetooth manager
 */
- (void)startManager;

/**
 *  When we don't need the manager any more
 */
- (void)stopManager;

/**
 *  Removes all beacons from the cache
 */
- (void)resetTransmiters;

/**
 *  Tourns our device into a beacon
 */
- (void)startVirtualBeacon;

/**
 *  Stops sending virtual beacon data
 */
- (void)stopVirtualBeacon;

@end
