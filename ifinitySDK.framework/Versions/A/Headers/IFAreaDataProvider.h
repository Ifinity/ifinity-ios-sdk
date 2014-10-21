//
//  IFAreaManager.h
//  IfinitySDK
//
//  Created by GetIfinity.com on 04.01.2014.
//  Copyright (c) 2014 GetIfinity.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IFMFloorplan+helper.h"
#import "IFDataProvider.h"
/**
 *  Used to retrieve all the informations about Areas within the requested range.
 */
@class IFAreaDataProvider;

@protocol IFAreaProviderDelegate <NSObject>
@optional
/**
 *  Invoked once the information about the areas will be updated
 *
 *  @param manager This manager
 *  @param areas   New Areas
 */
- (void) dataProvider:(IFAreaDataProvider *)provider didUpdateAreas:(NSArray *)areas;

/**
 *  Invoked only when we reach some API error
 *
 *  @param manager This manager
 *  @param areas   New Areas
 */
- (void) dataProvider:(IFAreaDataProvider *)provider queryError:(NSError *)error;
@end



@interface IFAreaDataProvider : IFDataProvider

@property(nonatomic, weak) id<IFAreaProviderDelegate>delegate;


/**
 *  Internal method, called always once the user position from the GPS changes radically.
 *
 *  @param lat      GPS Latitude
 *  @param lng      GPS Longitude
 *  @param distance Range
 */
- (void)queryAreasForLat: (NSNumber *)lat lng:(NSNumber *)lng distance:(NSNumber *)distance;

/**
 *  Used to get an array of polygons, useful when you want to display them on the map
 *
 *  @return An array of MKPolygons with area overlays
 */
- (NSArray *)fetchAreaOverlays;

/**
 *  Used to get an array of polygons just for one area, useful when you want to display them on the map
 *
 *  @return KPolygons with area overlay
 */
- (MKPolygon *)fetchAreaOverlay:(IFMArea *)area;

/**
 *  Get's all the areas for particular floorplan
 *
 *  @param floorplan A Floorplan
 *
 *  @return A Dictionary with all the areas
 */
- (NSMutableDictionary *)areaPathsForFloorplan:(IFMFloorplan *)floorplan;

@end
