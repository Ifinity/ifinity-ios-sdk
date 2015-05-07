//
//  BacgroundGeosController.h
//  GeosInBackground
//
//  Created by GetIfinity on 24.03.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
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
@interface IFBackgroundGeosController : NSObject <CLLocationManagerDelegate>

/**
 *  Enable notifications
 */
@property (nonatomic) BOOL enableNotifications;
/**
 *  How many past/displayed notifactions should be ignored, default value 10. Set 0 to disable notifications buffer and show all of them - not recommended on production. 
 *  This buffer prevents from spamming users with too many notifications.
 */
@property (nonatomic) NSUInteger notificationsBufferSize;
/**
 *  Initialize object with location manager and set self as manager delegate.
 *
 *  @param manager location manager
 *
 *  @return object
 */
- (instancetype)initWithLocationManager:(CLLocationManager *)manager;
- (void)updateLocation:(CLLocation *)location;

#pragma mark - CLLocationManagerDelegate methods

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;
- (void)locationManager:(CLLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didEnterRegion:(CLRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didExitRegion:(CLRegion *)region;
- (void)locationManager:(CLLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;

@end
