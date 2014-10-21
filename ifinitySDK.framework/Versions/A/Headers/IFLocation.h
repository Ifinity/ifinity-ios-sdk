//
//  IFLocation.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 25.03.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 *  Location object with extended description.
 */
@interface IFLocation : CLLocation

- (void) setDescription:(NSString *)description;
- (NSString *) description;

@end
