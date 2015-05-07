//
//  IFTransmiter.h
//  IfinitySDK
//
//  Created by GetIfinity on 24.07.2013.
//  Copyright (c) 2013 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <MapKit/MapKit.h>
#import "IFMBeacon+helper.h"

/**
 *  Every beacon object it's a type of IFTransmitter, we can get it's identifier, RSSI, distance, radius, coordinate, etc.
 */
@interface IFTransmitter : NSObject
@property (nonatomic, readonly) CBPeripheral *peripheral;
@property (nonatomic) BOOL active;

/**
 *  Last RSSI value
 */
@property (nonatomic, strong) NSNumber *RSSI;
/**
 *  RSSI value filtered with our algorithms. This value is more 'stable' and less sensitive to signal strength fluctuations.
 */
@property (nonatomic, readonly) NSNumber *filteredRSSI;

/**
 *  Parameter describing transmitter as near (is in near proximity), default is -30
 */
@property (nonatomic) NSInteger nearRSSI;

/**
 *  Transmitter (beacon) name
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 * Peripheral identifier as string.
 * This value is created from calling [[CBPeripheral identifier] UUIDString]
 */
@property (nonatomic, strong, readonly) NSString *UUID;

/**
 *  Transmitter distance in meters based on current RSSI
 *
 *  @return distance in meters
 */
- (float)distance;
/**
 * Transmitter distance in meters based on current RSSI with the use of filtering algorithms.
 *
 *  @return distance in meters using filtering algorithms
 */
- (float)filteredDistance;
/**
 *  Is device very near to reciver (ca. 0.3m)
 *
 *  @return YES when near
 */
- (BOOL)isNear;
/**
 *  Disappearing mean no transmitter signal for some time.
 *
 *  @return YES when disappeared
 */
- (BOOL)hasDisappeared;

#pragma mark - Geos stuff
/**
 *  Get assigned model object describing beacon in geos system.
 */
@property (nonatomic, retain) IFMBeacon *beacon;
/**
 *  Transmitter geo coordinates assigned in geos system.
 */
@property (nonatomic) CLLocationCoordinate2D coordinate;
@end
