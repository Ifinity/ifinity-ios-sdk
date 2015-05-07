//
//  IFBluetoothManager.h
//  IfinitySDK
//
//  Created by GetIfinity on 04.01.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "IFMFloorplan+helper.h"
#import "IFTransmitter.h"

@class IFBluetoothManager;

/**
 *  Managers are the most important part of the application, you can get all the information about position, bluetooth data and content throught it's delegates.
 */
@protocol IFBluetoothManagerDelegate <NSObject>

@optional

/**
 *  Transmitter RSSI updated
 *
 *  @param manager    IFBluetoothManager manager
 *  @param transmitter Transmitter object
 */
- (void)manager:(IFBluetoothManager *)manager didUpdateTransmitter:(IFTransmitter *)transmitter;

/**
 *  We found some active beacons for the floor
 *
 *  @param manager    IFBluetoothManager manager
 *  @param floorplan Floorplan with available beacons
 */
- (void)manager:(IFBluetoothManager *)manager didDiscoverActiveBeaconsForFloorplan:(IFMFloorplan *)floorplan __attribute__((deprecated));

/**
 *  We found some active beacons for the venue and floor
 *
 *  @param manager    IFBluetoothManager manager
 *  @param venue IFMVenue with available beacons
 *  @param floorplan Floorplan with available beacons
 */
- (void)manager:(IFBluetoothManager *)manager didDiscoverActiveBeaconsForVenue:(IFMVenue *)venue floorplan:(IFMFloorplan *)floorplan;

/**
 *  We lost the connection with all of the beacons inside the floor
 *
 *  @param manager    IFBluetoothManager manager
 *  @param floorplan Floorplan with no active beacons
 */
- (void)manager:(IFBluetoothManager *)manager didLostAllBeaconsForFloorplan:(IFMFloorplan *)floorplan;

/**
 *  We lost the connection with all of the beacons inside the venue
 *
 *  @param manager    IFBluetoothManager manager
 *  @param venue IFMVenue with no active beacons
 */
- (void)manager:(IFBluetoothManager *)manager didLostAllBeaconsForVenue:(IFMVenue *)venue;

/**
 *  There are some new beacons nearby
 *
 *  @param manager    IFBluetoothManager manager
 *  @param transmitters Nearby beacons array
 */
- (void)manager:(IFBluetoothManager *)manager didChangeTransmittersCount:(NSDictionary *)transmitters;

/**
 *  A new beacon has been found
 *
 *  @param manager    IFBluetoothManager manager
 *  @param transmitter A Beacon object
 */
- (void)manager:(IFBluetoothManager *)manager didDiscoverTransmitter:(IFTransmitter *)transmitter;

/**
 *  A Beacon dissapeared
 *
 *  @param manager    IFBluetoothManager manager
 *  @param transmitter A Beacon object
 */
- (void)manager:(IFBluetoothManager *)manager didLostTransmitter:(IFTransmitter *)transmitter;

/**
 *  This method allow to ignore some peripherals. 
 *  If method is implemented and returns NO, then peripheral is ignored and not process further.
 *
 *  @param manager    bluetooth manager
 *  @param peripheral peripheral to check
 *  @param advertisementData  advertisement data recived in peripheral packet
 *  @param RSSI       peripheral RSSI value
 *
 *  @return If NO peripheral is ignored and not processed. If YES, peripheral is processed further and at some point pass to IFTransmitter.
 */
- (BOOL)manager:(IFBluetoothManager *)manager isValidPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI
;

/**
 *  Invoked whenever the central manager's state has been updated.
 *
 *  @param manager bluetooth manager
 *  @param central current state of the CBCentralManger
 *
 *  @see centralManagerState
 */
- (void)manager:(IFBluetoothManager *)manager didUpdateCentralManagerState:(CBCentralManagerState)centralManagerState;
@end


/**
 *  'IFBluetoothManager' provide interface for bluetooth operations.
 *
 *  # Usage
 *
 *  1. Set delegate to recive manager "events".
 *  2. Start discovering Bluetooth devices by call [IFBluetoothManager startManager].
 *  3. When you done using bluetooth, be nice and stop BluetoothManager with [IFBluetoothManager stopManager]
 *
 */
@interface IFBluetoothManager : NSObject

/**
 *  IFBluetoothManagerDelegate responsible for passing all the events from the manager
 */
@property (nonatomic, weak) id <IFBluetoothManagerDelegate> delegate;

/**
 *  Parameter describing transmitter as near (is in near proximity), default is -30
 */
@property (nonatomic) NSInteger nearRSSI;

/**
 *  When useOnlyNearbyBeacons is equal YES, we're adding only beacons within the range of aprox. 1m - it's good for proximity mode, for the navigation it should be disabled!
 */
@property (nonatomic) BOOL useOnlyNearbyBeacons;

/**
 *  The current state of the CBCentralManager
 */
@property (nonatomic, readonly) CBCentralManagerState centralManagerState;
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
- (NSDictionary *)transmitters;

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
- (void)resetTransmitters;

/**
 *  Tourns our device into a beacon with name "virtualbeacon" proximity uuid="2FF70926-AAD1-4710-BCEA-2E48CA4A4655" major="01" minor="02"
 */
- (void)startVirtualBeacon;

/**
 *  Stops sending virtual beacon data
 */
- (void)stopVirtualBeacon;

@end
