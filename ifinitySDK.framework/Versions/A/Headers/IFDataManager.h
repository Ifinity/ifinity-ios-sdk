//
//  RingCentralSDK.h
//  RingcentralAPI
//
//  Created by GetIfinity.com on 06.11.2013.
//  Copyright (c) 2013 inventica.mobi. All rights reserved.
//

#import "IFDataManagerTypes.h"
#import "IFOAuth2Client.h"
#import <CoreLocation/CoreLocation.h>

/**
 *  Notification send when new data are inserted/updated in cache database.
 */
extern NSString * const IFDataManagerNotificationPlacesUpdate;
extern NSString * const IFDataManagerNotificationCacheClear;


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
-(void)setClientID:(NSString *)clientID
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


- (void)loadDataForLocation:(CLLocation *)location withPublicVenues:(BOOL)publicVenues block:(void (^)(BOOL success))block;

/**
 *  Query backend for route calculation between two points
 *
 *  @param fromFloorId    start floor id
 *  @param fromCoordinate start coordinate
 *  @param toFloorId      destination floor id
 *  @param toCoordinate   destination coordinates
 *  @param type           route type
 *  @param success        success block, array routes filled with IFPolygon objects
 *  @param failure        failure block
 */
- (void)routeFromFloorId:(NSNumber *)fromFloorId
          fromCoordinate:(CLLocationCoordinate2D)fromCoordinate
               toFloorId:(NSNumber *)toFloorId
            toCoordinate:(CLLocationCoordinate2D)toCoordinate
           transportType:(IFRouteType)type
                 success:(void (^)(NSDictionary *routes, CLLocationCoordinate2D endPoint))success
                 failure:(void (^)(NSError *error))failure;
@end
