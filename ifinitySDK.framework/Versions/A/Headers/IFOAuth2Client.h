// IFOAuth2Client.h
//
// Copyright (c) 2012 Mattt Thompson (http://mattt.me/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#ifndef _SECURITY_SECITEM_H_
#warning Security framework not found in project, or not included in precompiled header. Keychain persistence functionality will not be available.
#endif
@import Foundation;

@class IFOAuthCredential;

/**
 `RCOAuth2Client` encapsulates common patterns to authenticate against a resource server conforming to the behavior outlined in the OAuth 2.0 specification.
 
 In your application, it is recommended that you use `RCOAuth2Client` exclusively to get an authorization token, which is then passed to another `AFHTTPClient` subclass.
 
 @see RFC 6749 The OAuth 2.0 Authorization Framework: http://tools.ietf.org/html/rfc6749
 */

@interface IFOAuth2Client : NSObject

///------------------------------------------
/// @name Accessing OAuth 2 Client Properties
///------------------------------------------

/**
 The service provider identifier used to store and retrieve OAuth credentials by `RCOAuthCredential`. Equivalent to the hostname of the client `baseURL`.
 */
@property (readonly, nonatomic) NSString *serviceProviderIdentifier;

/**
 The client identifier issued by the authorization server, uniquely representing the registration information provided by the client.
 */
@property (readonly, nonatomic) NSString *clientID;

///------------------------------------------------
/// @name Creating and Initializing OAuth 2 Clients
///------------------------------------------------

/**
 Creates and initializes an `RCOAuth2Client` object with the specified base URL, client identifier, and secret.
 
 @param url The base URL for the HTTP client. This argument must not be `nil`.
 @param clientID The client identifier issued by the authorization server, uniquely representing the registration information provided by the client.
 @param secret The client secret.
 
 @return The newly-initialized OAuth 2 client
 */
+ (instancetype)clientWithBaseURL:(NSURL *)url
                         clientID:(NSString *)clientID
                           secret:(NSString *)secret;

/**
 Initializes an `RCOAuth2Client` object with the specified base URL, client identifier, and secret.
 
 @param url The base URL for the HTTP client. This argument must not be `nil`.
 @param clientID The client identifier issued by the authorization server, uniquely representing the registration information provided by the client.
 @param secret The client secret.
 
 @return The newly-initialized OAuth 2 client
 */
- (id)initWithBaseURL:(NSURL *)url
             clientID:(NSString *)clientID
               secret:(NSString *)secret;

/**
 Sets the "Authorization" HTTP header set in request objects made by the HTTP client to a basic authentication value with Base64-encoded username and password. This overwrites any existing value for this header.
 
 @param credential The OAuth credential
 */
- (void)setAuthorizationHeaderWithCredential:(IFOAuthCredential *)credential;


- (void)setAuthorizationHeaderWithToken:(NSString *)token
                                 ofType:(NSString *)type;

///---------------------
/// @name Authenticating
///---------------------

/**
 Creates and enqueues an `AFHTTPRequestOperation` to authenticate against the server using a specified username and password, with a designated scope.
 
 @param urlString The string to be appended to the HTTP client's base URL and used as the request URL.
 @param username The username used for authentication
 @param password The password used for authentication
 @param scope The authorization scope
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single argument: the OAuth credential returned by the server.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error returned from the server.
 */
- (void)authenticateUsingOAuthWithURLString:(NSString *)urlString
                                   username:(NSString *)username
                                   password:(NSString *)password
                                      scope:(NSString *)scope
                                    success:(void (^)(IFOAuthCredential *credential))success
                                    failure:(void (^)(NSError *error))failure;

/**
 Creates and enqueues an `AFHTTPRequestOperation` to authenticate against the server with a designated scope.
 
 @param urlString The string to be appended to the HTTP client's base URL and used as the request URL.
 @param scope The authorization scope
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single argument: the OAuth credential returned by the server.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error returned from the server.
 */
- (void)authenticateUsingOAuthWithURLString:(NSString *)urlString
                                      scope:(NSString *)scope
                                    success:(void (^)(IFOAuthCredential *credential))success
                                    failure:(void (^)(NSError *error))failure;

/**
 Creates and enqueues an `AFHTTPRequestOperation` to authenticate against the server using the specified refresh token.
 
 @param urlString The string to be appended to the HTTP client's base URL and used as the request URL.
 @param refreshToken The OAuth refresh token
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single argument: the OAuth credential returned by the server.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error returned from the server.
 */
- (void)authenticateUsingOAuthWithURLString:(NSString *)urlString
                               refreshToken:(NSString *)refreshToken
                                    success:(void (^)(IFOAuthCredential *credential))success
                                    failure:(void (^)(NSError *error))failure;

/**
 Creates and enqueues an `AFHTTPRequestOperation` to authenticate against the server with an authorization code, redirecting to a specified URI upon successful authentication.
 
 @param urlString The string to be appended to the HTTP client's base URL and used as the request URL.
 @param code The authorization code
 @param redirectURI The URI to redirect to after successful authentication
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single argument: the OAuth credential returned by the server.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error returned from the server.
 */
- (void)authenticateUsingOAuthWithURLString:(NSString *)urlString
                                       code:(NSString *)code
                                redirectURI:(NSString *)uri
                                    success:(void (^)(IFOAuthCredential *credential))success
                                    failure:(void (^)(NSError *error))failure;

/**
 Creates and enqueues an `AFHTTPRequestOperation` to authenticate against the server with the specified parameters.
 
 @param urlString The string to be appended to the HTTP client's base URL and used as the request URL.
 @param parameters The parameters to be encoded and set in the request HTTP body.
 @param success A block object to be executed when the request operation finishes successfully. This block has no return value and takes a single argument: the OAuth credential returned by the server.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error returned from the server.
 */
- (void)authenticateUsingOAuthWithURLString:(NSString *)urlString
                                 parameters:(NSDictionary *)parameters
                                    success:(void (^)(IFOAuthCredential *credential))success
                                    failure:(void (^)(NSError *error))failure;

@end

#pragma mark -

/**
 `RCOAuthCredential` models the credentials returned from an OAuth server, storing the token type, access & refresh tokens, and whether the token is expired.
 
 OAuth credentials can be stored in the user's keychain, and retrieved on subsequent launches.
 */
@interface IFOAuthCredential : NSObject <NSCoding>

///--------------------------------------
/// @name Accessing Credential Properties
///--------------------------------------

/**
 The OAuth access token.
 */
@property (readonly, nonatomic) NSString *accessToken;

/**
 The OAuth token type (e.g. "bearer").
 */
@property (readonly, nonatomic) NSString *tokenType;

/**
 The OAuth refresh token.
 */
@property (readonly, nonatomic) NSString *refreshToken;

/**
 The OAuth token scope - comma spearated strings. 
 */
@property (readonly, nonatomic) NSSet *scope;

/**
 Whether the OAuth credentials are expired.
 */
@property (readonly, nonatomic, assign, getter = isExpired) BOOL expired;

///--------------------------------------------
/// @name Creating and Initializing Credentials
///--------------------------------------------

/**
 Create an OAuth credential from a token string, with a specified type.
 
 @param token The OAuth token string.
 @param type The OAuth token type.
 */
+ (instancetype)credentialWithOAuthToken:(NSString *)token
                               tokenType:(NSString *)type;

/**
 Initialize an OAuth credential from a token string, with a specified type.
 
 @param token The OAuth token string.
 @param type The OAuth token type.
 */
- (instancetype)initWithOAuthToken:(NSString *)token
               tokenType:(NSString *)type;

///----------------------------
/// @name Setting Refresh Token
///----------------------------

/**
 Set the credential refresh token, with a specified expiration.
 
 @param refreshToken The OAuth refresh token.
 @param expiration The expiration of the access token.
 @param scope String scopes in set.
 */
- (void)setRefreshToken:(NSString *)refreshToken
             expiration:(NSDate *)expiration
                  scope:(NSSet *)scope;

///-----------------------------------------
/// @name Storing and Retrieving Credentials
///-----------------------------------------

#ifdef _SECURITY_SECITEM_H_
/**
 Stores the specified OAuth credential for a given web service identifier in the Keychain.
 
 @param credential The OAuth credential to be stored.
 @param identifier The service identifier associated with the specified credential.
 
 @return Whether or not the credential was stored in the keychain.
 */
+ (BOOL)storeCredential:(IFOAuthCredential *)credential
         withIdentifier:(NSString *)identifier;

/**
 Retrieves the OAuth credential stored with the specified service identifier from the Keychain.
 
 @param identifier The service identifier associated with the specified credential.
 
 @return The retrieved OAuth credential.
 */
+ (IFOAuthCredential *)retrieveCredentialWithIdentifier:(NSString *)identifier;

/**
 Deletes the OAuth credential stored with the specified service identifier from the Keychain.
 
 @param identifier The service identifier associated with the specified credential.
 
 @return Whether or not the credential was deleted from the keychain.
 */
+ (BOOL)deleteCredentialWithIdentifier:(NSString *)identifier;

/**
 *  Delete all OAuth credentials stored in Keychain
 *
 *  @return <#return value description#>
 */
+ (BOOL)deleteAllCredential;
#endif

@end

///----------------
/// @name Constants
///----------------

/**
 ## OAuth Grant Types
 
 OAuth 2.0 provides several grant types, covering several different use cases. The following grant type string constants are provided:
 
 `kRCOAuthCodeGrantType`: "authorization_code"
 `kRCOAuthClientCredentialsGrantType`: "client_credentials"
 `kRCOAuthPasswordCredentialsGrantType`: "password"
 `kRCOAuthRefreshGrantType`: "refresh_token"
 */
extern NSString * const kRCOAuthCodeGrantType;
extern NSString * const kRCOAuthClientCredentialsGrantType;
extern NSString * const kRCOAuthPasswordCredentialsGrantType;
extern NSString * const kRCOAuthRefreshGrantType;
