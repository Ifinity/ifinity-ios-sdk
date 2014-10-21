//
//  MyAnnotation.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 24.08.2013.
//  Copyright (c) 2013 GetIfinity.com. All rights reserved.
//

#import <MapKit/MapKit.h>
#import "IFTransmiter.h"

/**
 *  Special beacon annotation used to hold information about beacon and it's position. It's connected with the transmiter and used to calculate user position based on the beacon location.
 */
@interface IFBeaconAnnotation : NSObject <MKAnnotation>
{
    CLLocationCoordinate2D coordinate;
}

@property (nonatomic) IFTransmiter *transmiter;

- (id) initWithCoordinate:(CLLocationCoordinate2D)coord;
- (void) setCoordinate:(CLLocationCoordinate2D)newCoordinate;
- (void) setTitle: (NSString *)newTitle;

@end