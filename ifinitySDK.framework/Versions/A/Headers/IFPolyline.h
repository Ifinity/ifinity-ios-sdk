//
//  IFPolyline.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 25.03.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <MapKit/MapKit.h>

/**
 *  Extended Polyline view, used to get the information about each node description. Important for visually impaired.
 */
@interface IFPolyline : MKPolyline

- (void)setDescriptions:(NSArray *) descriptions;
- (NSString *)getDescriptionForIndex:(NSUInteger)index;
- (NSArray *)getDescriptions;

@end
