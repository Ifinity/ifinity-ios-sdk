//
//  RingCentralSDK.h
//  RingcentralAPI
//
//  Created by GetIfinity.com on 06.11.2013.
//  Copyright (c) 2013 inventica.mobi. All rights reserved.
//

#import "IFOAuth2Client.h"

@class IFAreaDataProvider;
@class IFBeaconDataProvider;
@class IFFloorplanDataProvider;
@class IFRouteDataProvider;
/**
 * Production API URL, need's to be changed to match the current CMS URL
 */
#ifdef PRODUCTION
#define kServiceURL @"http://geos.zone"
#else
#define kServiceURL @"http://bcdev.palladio.net.pl/web"
#endif
@class IFDataManager;
/**
 *  A shortcode for all the methods we're getting from the server with success
 *
 *  @param operation      An operation we were trying to execute
 *  @param responseObject Response from the server
 */
typedef void (^IFManagerClientSuccess)(NSURLResponse *response, id responseObject);
/**
 *  A shortcode for all the methods we're getting from the server with error
 *
 *  @param operation      An operation we were trying to execute
 *  @param error          Error from the server
 */
typedef void (^IFManagerClientFailure)(NSURLResponse *response, NSError *error);

typedef enum{
    IFManagerMethodPost = 0,
    IFManagerMethodGet = 1
} IFManagerMethod;

/**
 *  Managers are the most important part of the application, you can get all the information about position, bluetooth data and content throught it's delegates.
 */
@protocol IFManagerDelegate <NSObject>
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

@interface IFDataManager : NSObject
/**
 *  An information about the current access token.
 */
@property (nonatomic, readonly) NSString *accessToken;
/**
 *  Delegate responsible for passing all the events from the manager
 */
@property (nonatomic, weak) id<IFManagerDelegate>delegate;


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
 *  Authenticate user and obtain api access token
 *  Use with blocks or delegates
 */
- (void)authenticateWithSuccess:(void (^)(IFOAuthCredential *credential))success failure:(void (^)(NSError *error))failure;

/**
 *  OAuth token refreshal - all authomaticly. Internal method, no need to fire it from the custom applications.
 *
 *  @param success Callback methods
 *  @param failure Callback methods
 */
- (void)forceRefreshAccessTokenWithSuccess:(IFManagerClientSuccess)success
                                   failure:(IFManagerClientFailure)failure;


#pragma mark - Data providers

/**
 *  Data manager is used to create IFAreaDataProvider using Factory Design Pattern
 */
- (IFAreaDataProvider *)areaDataProvider;

/**
 *  Data manager is used to create IFBeaconDataProvider using Factory Design Pattern
 */
- (IFBeaconDataProvider *)beaconDataProvider;

/**
 *  Data manager is used to create IFFloorplanDataProvider using Factory Design Pattern
 */
- (IFFloorplanDataProvider *)floorplanDataProvider;

/**
 *  Data manager is used to create IFRouteDataProvider using Factory Design Pattern
 */
- (IFRouteDataProvider *)routeDataProvider;

@end