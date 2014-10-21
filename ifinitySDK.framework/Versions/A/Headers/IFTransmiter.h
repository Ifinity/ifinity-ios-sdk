//
//  BTTransmiter.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 24.07.2013.
//  Copyright (c) 2013 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <MapKit/MapKit.h>
#import "IFMBeacon+helper.h"

/**
 *  Every beacon object it's a type of IFTransmiter, we can get it's identifier, RSSI, distance, radius, coordinate, etc.
 */
@interface IFTransmiter : NSObject
@property (nonatomic, strong) NSNumber *RSSI;
@property (nonatomic, readonly) NSNumber *filteredRSSI;
@property (nonatomic) CLLocationCoordinate2D coordinate;
@property (nonatomic) BOOL active;
@property (nonatomic, retain) IFMBeacon *beacon;

- (id)initPeripheral:(CBPeripheral *)peripheral name:(NSString *)name;
- (NSString *)name;
- (NSString *)UUID;
- (float)distance;
- (float)filteredDistance;
- (float)radius;
- (BOOL)isNear;
- (BOOL)hasDissapear;
@end
