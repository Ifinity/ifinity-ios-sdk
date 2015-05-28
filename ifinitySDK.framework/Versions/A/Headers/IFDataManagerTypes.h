//
//  IFDataManagerTypes.h
//  ifinitySDK
//
//  Created by GetIfinity on 24.10.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>

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