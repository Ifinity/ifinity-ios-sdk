//
//  IFAPIModel.h
//  ifinitySDK
//
//  Created by GetIfinity on 28.04.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "IFLocation.h"
#import "IFMPush.h"
#import "IFMVenue.h"
#import "IFMContent.h"

@class IFContentModel;
@class IFImageModel;
@interface IFVenueModel : NSObject

@property (nonatomic, strong) NSNumber *venueId;
@property (nonatomic, strong) NSNumber *publicVenue;
@property (nonatomic, strong) NSNumber *compassCalibration;
@property (nonatomic, strong) NSNumber *outdoor;
@property (nonatomic, strong) NSNumber *updateTime;
@property (nonatomic, strong) CLLocation *centerLocation;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray *floorplans;
@property (nonatomic, strong) IFImageModel *image;
@property (nonatomic, strong) IFContentModel *content;
@property (nonatomic, strong) NSArray *beacons;
@property (nonatomic, strong) NSArray *pushContents;
@property (nonatomic, strong) NSString *ibeaconUUID;
@property (nonatomic, assign) IFMVenueType venueType;

@end

typedef NS_ENUM (NSInteger, IFFloorplanTileStatus) {
    IFFloorplanTileStatusUnknown = 0,
    IFFloorplanTileStatusReady = 1,
    IFFloorplanTileStatusWaiting = 2,
    IFFloorplanTileStatusGenerates = 3,
    IFFloorplanTileStatusError = 4
};

@class IFFloorplanPointModel;

@interface IFFloorplanModel : NSObject

@property (nonatomic, retain) NSNumber *floorplanId;
@property (nonatomic, retain) NSNumber *label;
@property (nonatomic, retain) NSString *mapId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) CLLocation *ne;
@property (nonatomic, retain) CLLocation *sw;
@property (nonatomic, retain) NSNumber *rotation;
@property (nonatomic, strong) NSArray *areas;
@property (nonatomic, strong) NSArray *beacons;
@property (nonatomic) IFFloorplanTileStatus tileStatus;
@property (nonatomic, retain) IFFloorplanPointModel *point;

@end

@interface IFFloorplanPointModel : NSObject

@property (nonatomic, retain) CLLocation *ne;
@property (nonatomic, retain) CLLocation *nw;
@property (nonatomic, retain) CLLocation *se;
@property (nonatomic, retain) CLLocation *sw;

@end

@interface IFAreaModel : NSObject

@property (nonatomic, retain) NSNumber *areaId;
@property (nonatomic, retain) NSNumber *atypeId;
@property (nonatomic, retain) CLLocation *location;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSSet *contents;
@property (nonatomic, retain) NSSet *points;

@end

@interface IFContentModel : NSObject

@property (nonatomic, retain) NSNumber *contentId;
@property (nonatomic, retain) NSString *contentShort;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSNumber *notification;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) IFImageModel *icon;
@property (nonatomic, assign) IFMContentType type;

@end

@interface IFImageModel : NSObject

@property (nonatomic, strong) NSString *original;
@property (nonatomic, strong) NSString *thumb;
@property (nonatomic, strong) NSString *small;
@property (nonatomic, strong) NSString *medium;
@property (nonatomic, strong) NSDictionary *meta;
@property (nonatomic, strong) NSNumber *imageId;

@end

@interface IFBeaconModel : NSObject

@property (nonatomic, retain) NSNumber *beaconId;
@property (nonatomic, retain) IFAreaModel *area;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *ibeaconUUID;
@property (nonatomic, retain) NSNumber *ibeaconMajor;
@property (nonatomic, retain) NSNumber *ibeaconMinor;
@property (nonatomic, retain) CLLocation *location;
@property (nonatomic, retain) NSSet *alerts;

@end

@interface IFAreaPointModel : NSObject

@property (nonatomic, retain) CLLocation *location;
@property (nonatomic, retain) NSNumber *order;

@end

@interface IFAlertModel : NSObject

@property (nonatomic, retain) NSNumber *alertId;
@property (nonatomic, retain) NSNumber *distance;
@property (nonatomic, retain) NSString *action;
@property (nonatomic, retain) NSDate *validFrom;
@property (nonatomic, retain) NSDate *validTo;

@end

typedef NS_ENUM(NSInteger, IFRouteSegmentType) {
    IFRouteSegmentTypeIndoorNavigation = 0,
    IFRouteSegmentTypeExternal = 1
};

@interface IFRouteModel : NSObject

@property (nonatomic, strong) NSArray *nodes;
@property (nonatomic) IFRouteSegmentType type;
@property (nonatomic, strong) NSNumber *venueId;

@end

@class IFRouteNodeModel;
@interface IFRouteNodeModel : NSObject

@property (nonatomic, strong) CLLocation *location;
@property (nonatomic, strong) NSNumber *nodeId;
@property (nonatomic, strong) NSNumber *floorplanId;
@property (nonatomic, strong) NSNumber *areaId;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *name;
@property (nonatomic) IFRouteNodeType type;

@end

@class IFPushLocalModel, IFPushRemoteModel;
@interface IFPushModel : NSObject

@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * info;
@property (nonatomic, assign) IFMPushType type;
@property (nonatomic, retain) NSString * content;
@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSString * icon;
@property (nonatomic, retain) IFPushLocalModel *pushLocal;
@property (nonatomic, retain) IFPushRemoteModel *pushRemote;

@end

@interface IFPushLocalModel : NSObject

@property (nonatomic, retain) NSNumber * area_id;
@property (nonatomic, retain) NSNumber * venue_id;
@property (nonatomic, retain) NSNumber * content_id;

@end

@interface IFPushRemoteModel : NSObject

@property (nonatomic, retain) NSNumber * update_time;
@property (nonatomic, retain) NSNumber * background_mode;
@property (nonatomic, retain) NSString * background_url;

@end

@interface IFPushContentModel : NSObject

@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, retain) NSNumber * from;
@property (nonatomic, retain) NSNumber * to;
@property (nonatomic, strong) IFContentModel *content;

@end
