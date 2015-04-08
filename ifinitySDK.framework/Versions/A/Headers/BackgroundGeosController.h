//
//  BacgroundGeosController.h
//  GeosInBackground
//
//  Created by Wojciech Chojnacki on 24.03.2015.
//  Copyright (c) 2015 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreLocation;

/**
 * This controller contains methods to handle collecting data in the background/foreground and do other stuff like notifications.
 *
 * Discussion:
 *   This class helps to setup and handle all operation in background required to collect ibeacons stats.
 *   It requires some preparations in app, like turn on app background modes and requestAlwaysAuthorization in CLLocationManager.
 *   This class can also work as CLLocationManagerDelegate, otherwise calls from methods in CLLocationManagerDelegate have to be passed to this class.
 *
 */
@interface BackgroundGeosController : NSObject <CLLocationManagerDelegate>

/**
 *  Initialize object with location manager and set self as manager delegate.
 *
 *  @param manager location manager
 *
 *  @return object
 */
- (instancetype)initWithLocationManager:(CLLocationManager *)manager;
- (void)updateLocation:(CLLocation *)location;

#pragma mark - CLLOcationManagerDelegate methods

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;
- (void)locationManager:(CLLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didEnterRegion:(CLRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didExitRegion:(CLRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;

@end
