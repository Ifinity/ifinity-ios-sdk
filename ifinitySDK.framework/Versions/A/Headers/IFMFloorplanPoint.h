//
//  IFMFloorplanPoint.h
//  Pods
//
//  Created by Mario on 01/07/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>

@class IFMFloorplan;

@interface IFMFloorplanPoint : NSManagedObject

@property (nonatomic, retain) NSNumber * ne_lng;
@property (nonatomic, retain) NSNumber * ne_lat;
@property (nonatomic, retain) NSNumber * nw_lng;
@property (nonatomic, retain) NSNumber * nw_lat;
@property (nonatomic, retain) NSNumber * se_lng;
@property (nonatomic, retain) NSNumber * se_lat;
@property (nonatomic, retain) NSNumber * sw_lng;
@property (nonatomic, retain) NSNumber * sw_lat;
@property (nonatomic, retain) IFMFloorplan *floorplan;

- (CLLocation *)ne_location;
- (CLLocation *)nw_location;
- (CLLocation *)se_location;
- (CLLocation *)sw_location;

@end
