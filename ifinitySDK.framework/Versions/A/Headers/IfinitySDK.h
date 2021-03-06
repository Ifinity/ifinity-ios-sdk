//
//  IFinitySDK.h
//  IFinitySDK
//
//  Created by GetIfinity on 13.10.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#define IFINITY_SDK_VERSION_STRING @"0.1.6.8"
#define IFINITY_SDK_VERSION 10068


#import "IFDataManager.h"
#import "IFBluetoothManager.h"
#import "IFLocationManager.h"
#import "IFIndoorLocationManager.h"

#import "IFTransmitter.h"

///
/// Components
///
#import "IFBeaconAnnotation.h"
#import "IFBeaconAnnotationView.h"
#import "IFLocation.h"
#import "IFPolyline.h"
#import "IFRouteDetails.h"
#import "IFTileOverlay.h"
#import "IFTileOverlayRenderer.h"

///
/// Models
///
#import "IFMAlert.h"
#import "IFMArea.h"
#import "IFMAreaPoint.h"
#import "IFMBeacon.h"
#import "IFMContent.h"
#import "IFMFloorplan.h"
#import "IFMVenue.h"


extern int if_ifinity_sdk_version();

extern void custom_api_ifinity_url(NSString *url);
extern NSString* custom_api_ifinity_is_url();