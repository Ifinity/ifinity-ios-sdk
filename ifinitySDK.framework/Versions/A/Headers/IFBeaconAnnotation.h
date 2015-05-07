//
//  MyAnnotation.h
//  IfinitySDK
//
//  Created by GetIfinity on 24.08.2013.
//  Copyright (c) 2013 GetIfinity. All rights reserved.
//

#import <MapKit/MapKit.h>
#import "IFTransmitter.h"

/**
 *  Special beacon annotation used to hold information about beacon and it's position. It's connected with the transmitter and used to calculate user position based on the beacon location.
 */
@interface IFBeaconAnnotation : NSObject <MKAnnotation>
{
    CLLocationCoordinate2D coordinate;
}

@property (nonatomic) IFTransmitter *transmitter;

- (id) initWithCoordinate:(CLLocationCoordinate2D)coord;
- (void) setCoordinate:(CLLocationCoordinate2D)newCoordinate;
- (void) setTitle: (NSString *)newTitle;

@end
