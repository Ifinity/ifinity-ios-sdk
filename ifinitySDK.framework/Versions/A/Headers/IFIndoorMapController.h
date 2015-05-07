//
//  IndoorMapController.h
//  ifinitySDK
//
//  Created by GetIfinity on 20.03.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "IFMFloorplan.h"
#import "IFMVenue.h"

@class IFIndoorMapController;


/**
 *  Map controler delegate
 */
@protocol IFIndoorMapControllerDelegate <NSObject>

@optional
/**
 *  Called on area enter
 *
 *  @param indoorMapController map controller
 *  @param area                area
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didEnterArea:(IFMArea *)area;

/**
 *  Called on area exit
 *
 *  @param indoorMapController map controller
 *  @param area                area
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didExitArea:(IFMArea *)area;

/**
 *  Called when framework detects strongest beacon assigned for venue and floor.
 *
 *  @param indoorMapController map controller
 *  @param floor               closest floor base on beacon signal
 *  @param venue               closest venue base on beacon signal
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didEnterFloor:(IFMFloorplan *)floor venue:(IFMVenue *)venue;

/**
 *  Called when framework detects strongest beacon assigned for floor.
 *
 *  @param indoorMapController map controller
 *  @param floor               closest floor base on beacon signal
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didEnterFloor:(IFMFloorplan *)floor __attribute__((deprecated));

/**
 *  Distance value change to closest node in path
 *
 *  @param indoorMapController map controller
 *  @param distance            updated distance value
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didChangeTargetNodeDistance:(double)distance;

/**
 *  Total distance value change to navigation target
 *
 *  @param indoorMapController map controller
 *  @param distance            updated total distance value
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didChangeTargetTotalDistance:(double)distance;

/**
 *  Change of heading to navigation target
 *
 *  @param indoorMapController map controller
 *  @param heading             new heading value
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didChangeTargetHeading:(double)heading;

/**
 *  Called when floor plan was successful added to map
 *
 *  @param indoorMapController map controller
 *  @param floor               floor plan model object
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didAddFloorPlanInMap:(IFMFloorplan *)floor;

/**
 *  All route nodes in target.
 *
 *  @param indoorMapController map controller
 *  @param nodes               route nodes
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController nodesInRoute:(NSArray *)nodes;

/**
 *  Called when map drag action ends.
 *
 *  @param indoorMapController map controller
 *  @param gestureRecognizer   drag gesture
 */
- (void)indoorMapController:(IFIndoorMapController *)indoorMapController didDragMap:(UIGestureRecognizer*)gestureRecognizer;

/**
 *  Helper method to extend current map with new annotations. 
 *  If annotation is not supported by IFINdoorMapController this method is called. This allows to provide own AnnotationView.
 *
 *  @param indoorMapController 
 *  @param mapView
 *  @param annotation
 *
 *  @return
 */
- (MKAnnotationView *)indoorMapController:(IFIndoorMapController *)indoorMapController mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation> )annotation __attribute__((deprecated));

@end


@interface IFIndoorMapController : NSObject <CLLocationManagerDelegate, MKMapViewDelegate>

@property (nonatomic, weak) IBOutlet id<IFIndoorMapControllerDelegate> delegate;
/**
 *  Current floorplan
 */
@property (nonatomic, strong) IFMFloorplan *currentFloorplan;
/**
 *  Image for beacon map annotation. Set if you want to change default image.
 */
@property (nonatomic, strong) UIImage *annotationIconBeacon;
/**
 *  Content is in area icon image. Set if you want to change default image.
 */
@property (nonatomic, strong) UIImage *annotationIconInfoContent;
/**
 *  Image for current user annotation.
 */
@property (nonatomic, strong) UIImage *annotationIconYou;
/**
 *  Display beacons on the map
 */
@property (nonatomic, assign) BOOL shouldAddBeaconsToMap;
/**
 *  Is target navigation in progress
 */
@property (nonatomic, assign, getter=isTargetNavigationEnabled) BOOL targetNavigationEnabled;
/**
 *  Is heading enabled
 */
@property (nonatomic, assign, readonly, getter=isHeading) BOOL heading;
/**
 *  Current user location calclutated with indoor navigation module.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D userCoordinate;

/**
 *  Initialize map view with location manager and set self as manager delegate.
 *
 *  @param mapView        map view
 *  @param viewController view controller with map
 *  @param floorplan      floorplan data model
 *  @param manager location manager
 */
- (void)setupWithMapView:(MKMapView *)mapView viewController:(UIViewController *)viewController floorplan:(IFMFloorplan *)floorplan locationManager:(CLLocationManager *)manager;

/**
 *  Start indoor navigation
 */
- (void)start;

/**
 *  Stop indoor navigation
 */
- (void)stop;
/**
 *  Calculate and start navigation to area
 *
 *  @param targetArea target area
 */
- (void)startNavigationToArea:(IFMArea *)targetArea;
/**
 *  End navigation to area
 */
- (void)stopNavigationToArea;
/**
 *  Current area base on position from indoor navigation
 *
 *  @return area model object
 */
- (IFMArea *)currentArea;
/**
 *  Target area in navigation
 *
 *  @return nil if no navigation, area model if navigation in progress
 */
- (IFMArea *)navigateArea;
/**
 *  Enable map rotation based on heading
 *
 *  @param heading enable/disable heading
 */
- (void)setFollowHeading:(BOOL)heading;

#pragma mark - CLLocationManagerDelegate methods

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;
- (BOOL)locationManagerShouldDisplayHeadingCalibration:(CLLocationManager *)manager;
- (void)locationManager:(CLLocationManager *)manager didUpdateHeading:(CLHeading *)heading;
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;

#pragma mark - MKMapViewDelegate methods

- (MKOverlayRenderer *)mapView:(MKMapView *)mapView rendererForOverlay:(id <MKOverlay> )overlay;
- (void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated;
- (MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation> )annotation;

@end
