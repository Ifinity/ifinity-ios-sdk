//
//  RingCentralSDK.h
//  RingcentralAPI
//
//  Created by GetIfinity on 06.11.2013.
//  Copyright (c) 2013 GetIfinity. All rights reserved.
//

#import "IFDataManagerTypes.h"
#import "IFOAuth2Client.h"
#import <CoreLocation/CoreLocation.h>
#import "IFAPIModel.h"
@class IFMBeacon;
@class IFMContent;
@class IFMPush;
@class IFMPushContent;

/**
 *  Notification send when new data are inserted/updated in cache database.
 */
extern NSString * const IFDataManagerNotificationVenuesUpdate;
extern NSString * const IFDataManagerNotificationVenueUpdate;
extern NSString * const IFDataManagerNotificationCacheClear;

/**
 *  @deprecated
 */
extern NSString * const IFDataManagerNotificationPlacesUpdate __attribute__((deprecated));


@class IFDataManager;

/**
 *  There could be different type of routes: Shortest, Stairs only, Elevator only
 */
typedef NS_ENUM(NSInteger, IFRouteType) {
    IFRouteTypeDefault = 0,
    IFRouteTypeStairs  = 1,
    IFRouteTypeElevator = 2
};

/**
 *  Delegate for `IFDataManager` class.
 *
 *  ## Misc
 *  `IFDataManagerDelegate` extends Data Providers Delegates (*ProviderDelegate). This way allow to debug fetching data from api.
 */
@protocol IFDataManagerDelegate <NSObject>
@optional

/**
 *  We're authenticated
 *
 *  @param manager    Current manager instance
 *  @param credential Logged-in user details
 */
- (void)manager:(IFDataManager *) manager authenticatedUserWithCredential:(IFOAuthCredential *) credential;

/**
 *  If they would be any errors while authentication process this delegate method should be fired automaticaly.
 *
 *  @param manager Current manager instance
 *  @param error   Error details
 */
- (void)manager:(IFDataManager *) manager authenticationError:(NSError *)error;
@end

/**
`IFDataManager` handle all operations on data and communicate with API.
 
# Initialization
 
1. Get application id and secret for your account on http://geos.zone.
2. Set application id & secret in IFDataManager
 
       [[IFDataManager sharedManager] setClientID:applicationId secret:applicationSecret];
 
3. Obtain access token with function [IFDataManager authenticateWithSuccess:failure:]

       [[IFDataManager sharedManager] authenticateWithSuccess: ^(IFOAuthCredential *credential) {
           NSLog(@"my access_toke=%@", credential.access_token);
       } failure: ^(NSError *error) {
           NSLog(@"error: %@", error);
       }];


# Cache
Most of data received from API is converted to coredata model object and stored in internal database. Model object starts with `IFM` prefix.
 */
@interface IFDataManager : NSObject
/**
 *  An information about the current access token.
 */
@property (nonatomic, readonly) NSString *accessToken;
/**
 *  Delegate responsible for passing all the events from the manager
 */
@property (nonatomic, weak) id<IFDataManagerDelegate>delegate;


/**
 *  Each manager is a singleton, they are accessible by the sharedManager method
 *
 *  @return IFDataManager object
 */
+ (IFDataManager *)sharedManager;

/**
 *  Get the information whether current user is authenticated, or no
 *
 *  @return Is the current user authenticated
 */
- (BOOL)authenticated;

/**
 *  Set client id & client secret
 *
 *  @param clientID     Should be generated in the CMS
 *  @param clientSecret Should be generated in the CMS
 */
- (void)setClientID:(NSString *)clientID
            secret:(NSString *)clientSecret;

/**
 *  Authenticate user and obtain API access token
 *  Use with blocks or delegates
 */
- (void)authenticateWithSuccess:(void (^)(IFOAuthCredential *credential))success failure:(void (^)(NSError *error))failure;

/**
 *  Remove all authentication information and invalidate access token.
 */
- (void)unauthenticate;

/**
 *  Clear local cache
 */
- (void)clearCaches;

- (void)loadDataForLocation:(CLLocation *)location
           withPublicVenues:(BOOL)publicVenues
                      block:(void (^)(BOOL success))block __attribute__((deprecated));

- (void)loadDataForLocation:(CLLocation *)location
           withPublicVenues:(BOOL)publicVenues
               successBlock:(void (^)(NSArray* venues))successBlock
                    failure:(void (^)(NSError *error))failure __attribute__((deprecated));

/**
 *  Call API to find venues in set geo coordinates
 *
 *  @param location         coordinate
 *  @param distance         radius
 *  @param publicVenues
 *  @param successBlock     success block, array venues
 *  @param failure          failure block
 */
- (void)loadDataForLocation:(CLLocation *)location
                   distance:(NSNumber *)distance
           withPublicVenues:(BOOL)publicVenues
               successBlock:(void (^)(NSArray* venues))successBlock
                    failure:(void (^)(NSError *error))failure;

/**
 *  Call API to find venue based on venue id
 *
 *  @param successBlock     success block, array venues
 *  @param failure          failure block
 */
- (void)loadVenueForVenueID:(NSNumber *)venueId
               successBlock:(void (^)(NSArray* venues))successBlock
                    failure:(void (^)(NSError *error))failure;

- (void)loadDataForSearchQuery:(NSString *)query
                      location:(CLLocation *)location
                          page:(NSNumber *)page
                         limit:(NSNumber *)limit
              withPublicVenues:(BOOL)publicVenues
                  successBlock:(void (^)(NSArray* venues))successBlock
                       failure:(void (^)(NSError *error))failure;

/**
 *  Fetch all venues
 *
 *  @param successBlock   success block, array venues
 */
- (void)fetchVenuesFromCacheWithBlock:(void(^)(NSArray *venues))block;
/**
 *  Fetch all venues outdoor of the type
 *
 *  @param venue type
 *  @param successBlock   success block, array venues
 */
- (void)fetchAllVenuesOutdoor:(BOOL)outdoor type:(IFMVenueType)type block:(void(^)(NSArray *venues))block;
/**
 *  Fetch venue from venue id
 *
 *  @param successBlock   success block, array venues
 */
- (void)fetchVenuesFromCacheForVenueId:(NSNumber *)venueId block:(void(^)(NSArray *venues))block;
/**
 *  Fetch venue from floorplan id
 *
 *  @param successBlock   success block, array venues
 */
- (void)fetchVenuesFromCacheForFloorId:(NSNumber *)floorId block:(void(^)(NSArray *venues))block;
/**
 *  Fetch all floorplans from venue id
 *
 *  @param successBlock   success block, array floorplans
 */
- (void)fetchFloorsFromCacheForVenueId:(NSNumber *)venueId block:(void(^)(NSArray *floors))block;
/**
 *  Fetch all floorplans from floorplan id
 *
 *  @param successBlock   success block, array floorplans
 */
- (void)fetchFloorsFromCacheForFloorId:(NSNumber *)floorId block:(void(^)(NSArray *floors))block;
/**
 *  Fetch all areas from venue id
 *
 *  @param successBlock   success block, array areas
 */
- (void)fetchAreasFromCacheForVenueId:(NSNumber *)venueId block:(void(^)(NSArray *areas))block;
/**
 *  Fetch all areas from floorplan id
 *
 *  @param successBlock   success block, array areas
 */
- (void)fetchAreasFromCacheForFloorId:(NSNumber *)floorId block:(void(^)(NSArray *areas))block;
/**
 *  Fetch all areas from area id
 *
 *  @param successBlock   success block, array areas
 */
- (void)fetchAreasFromCacheForAreaId:(NSNumber *)areaId block:(void(^)(NSArray *areas))block;
/**
 *  Fetch all areas when name CONTAINS search text
 *
 *  @param search text
 *  @param successBlock   success block, array areas
 */
- (void)fetchAreasFromCacheForVenueId:(NSNumber *)venueId searchText:(NSString *)searchText block:(void(^)(NSArray *areas))block;
/**
 *  Fetch all contents from content id
 *
 *  @param successBlock   success block, array contents
 */
- (void)fetchContentFromCacheForContentId:(NSNumber *)contentId block:(void(^)(NSArray *contents))block;
/**
 *  Fetch content from area id
 *
 *  @param successBlock   success block, object content
 */
- (void)fetchContentForAreaId:(NSNumber *)areaId block:(void(^)(IFMContent *content))block;
/**
 *  Fetch content from area id
 *
 *  @param backgroundNotification   notification in background
 *  @param successBlock             success block, object content
 */
- (void)fetchContentForAreaId:(NSNumber *)areaId backgroundNotification:(BOOL)notification block:(void(^)(IFMContent *content))block;
/**
 *  Fetch content from venue id
 *
 *  @param successBlock   success block, object content
 */
- (void)fetchContentForVenueId:(NSNumber *)venueId block:(void(^)(IFMContent *content))block;
/**
 *  Fetch beacon based on parameters
 *
 *  @param uuid
 *  @param major
 *  @param minor
 *  @param successBlock   success block, object beacon
 */
- (void)fetchBeaconByUUID:(NSUUID *)uuid major:(NSInteger)major minor:(NSInteger)minor block:(void(^)(IFMBeacon *beacon))block;
/**
 *  Fetch push from push id
 *
 *  @param successBlock   success block, object push
 */
- (void)fetchPushFromPushId:(NSNumber *)pushId block:(void(^)(IFMPush *push))block;
/**
 *  Fetch pushContent from pushContent id
 *
 *  @param successBlock   success block, array pushContents
 */
- (void)fetchPushContentFromCacheForPushContentId:(NSNumber *)pushContentId block:(void(^)(NSArray *pushContents))block;

/**
 *  Query backend for route calculation between two points
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param toFloorId      destination floor id
 *  @param toCoordinate   destination coordinates
 *  @param type           route type
 *  @param successBlock   success block, array routes filled with IFPolygon objects
 *  @param failure        failure block
 */
- (void)routeFromFloorId:(NSNumber *)fromFloorId
          fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
               toFloorId:(NSNumber *)toFloorId
            toCoordinate:(CLLocationCoordinate2D)toCoordinate
           transportType:(IFRouteType)type
                 successBlock:(void (^)(NSDictionary *routes, NSDictionary *floorNodes, CLLocationCoordinate2D endPoint))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  Query backend for route calculation between two points
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param toFloorId      destination floor id
 *  @param toCoordinate   destination coordinates
 *  @param type           route type
 *  @param success        success block, object IFRouteModel
 *  @param failure        failure block
 */
- (void)routeFromFloorId:(NSNumber *)fromFloorId
          fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
               toFloorId:(NSNumber *)toFloorId
            toCoordinate:(CLLocationCoordinate2D)toCoordinate
           transportType:(IFRouteType)type
                 success:(void (^)(IFRouteModel *route))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  Query backend for route segment calculation between two points
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param toFloorId      destination floor id
 *  @param toVenueId      destination venue id
 *  @param toCoordinate   destination coordinates
 *  @param type           route type
 *  @param success        success block, array segments route
 *  @param failure        failure block
 */
- (void)routeFromFloorId:(NSNumber *)fromFloorId
          fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
               toFloorId:(NSNumber *)toFloorId
               toVenueId:(NSNumber *)toVenueId
            toCoordinate:(CLLocationCoordinate2D)toCoordinate
           transportType:(IFRouteType)type
                 success:(void (^)(NSArray *segments))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  Query backend for route segment calculation between two points
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param toVenueId      destination venue id
 *  @param type           route type
 *  @param success        success block, array segments route
 *  @param failure        failure block
 */
- (void)routeFromFloorId:(NSNumber *)fromFloorId
          fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
               toVenueId:(NSNumber *)toVenueId
           transportType:(IFRouteType)type
                 success:(void (^)(NSArray *segments))success
                 failure:(void (^)(NSError *error))failure;

/**
 *  Parser objects IFRouteModel, return route as MKPolyline, all Nodes divided into floors and the end point
 *
 *  @param route        route object MKPolyline
 *  @param block        success block, all routes, all floors nodes, end point coordinate
 */
+ (void)parserRouteModel:(IFRouteModel *)route block:(void (^)(NSDictionary *routes, NSDictionary *floorNodes, CLLocationCoordinate2D endPoint))block;

@end
