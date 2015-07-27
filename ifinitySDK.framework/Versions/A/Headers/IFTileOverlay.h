//
//  IFTileOverlay
//  IfinitySDK
//
//  Created by GetIfinity on 03.07.2013.
//  Copyright (c) 2013 GetIfinity. All rights reserved.
//


#import <MapKit/MapKit.h>
#import <Foundation/Foundation.h>
#import "IFAPIModel.h"

/**
 *  Holds and calculates details about current map object
 */
@interface IFTileOverlay : NSObject <MKOverlay>
@property (nonatomic, weak) NSString *mapURL;
@property (nonatomic) int index;
@property (nonatomic) IFFloorplanTileStatus status;

- (NSString *)urlForPointWithX:(NSUInteger)x andY:(NSUInteger)y andZoomLevel:(NSUInteger)zoomLevel;
- (BOOL)canDrawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale;

@end
