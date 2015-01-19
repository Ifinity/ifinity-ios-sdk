//
//  IFTileOverlayRenderer.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 03.07.2013.
//  Copyright (c) 2013 GetIfinity.com. All rights reserved.
//

#import <MapKit/MapKit.h>

/**
 *  Renders tiles on the MKMapView
 */
@interface IFTileOverlayRenderer : MKOverlayRenderer
+ (NSString *)tilesCacheDir;
+ (NSString *)tilesCacheDirMapId:(NSString *)mapID tileX:(NSUInteger)tilex tileY:(NSUInteger)tiley zoomLevel:(NSUInteger)zoomLevel;
+ (void)clearTilesCache;
@end
