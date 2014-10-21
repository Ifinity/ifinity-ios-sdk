//
//  IFTileOverlay
//  IfinitySDK
//
//  Created by GetIfinity.com on 03.07.2013.
//  Copyright (c) 2013 GetIfinity.com. All rights reserved.
//


#import <MapKit/MapKit.h>
#import <Foundation/Foundation.h>

/**
 *  Holds and calculates details about current map object
 */
@interface IFTileOverlay : NSObject <MKOverlay>
{
    CGFloat defaultAlpha;
}

@property (nonatomic, weak) NSString *mapURL;

- (NSString *)urlForPointWithX:(NSUInteger)x andY:(NSUInteger)y andZoomLevel:(NSUInteger)zoomLevel;
- (BOOL)canDrawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale;

@end
