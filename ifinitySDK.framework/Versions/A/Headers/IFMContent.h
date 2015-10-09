//
//  IFMContent.h
//  ifinitySDK
//
//  Created by Mario on 16.09.2015.
//  Copyright (c) 2015 GetIfinity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

enum {
    IFMContentTypeNone = 0,
    IFMContentTypeHtml = 1,
    IFMContentTypeOpenUrl = 2
};
typedef int16_t IFMContentType;

@class IFMArea, IFMContentImage, IFMPushContent, IFMVenue;

@interface IFMContent : NSManagedObject

@property (nonatomic, retain) NSString * content_short;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * notification;
@property (nonatomic, retain) NSNumber * remote_id;
@property (nonatomic, assign) IFMContentType type;
@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSSet *areas;
@property (nonatomic, retain) IFMContentImage *icon;
@property (nonatomic, retain) IFMPushContent *pushContent;
@property (nonatomic, retain) IFMVenue *venue;
@end

@interface IFMContent (CoreDataGeneratedAccessors)

- (void)addAreasObject:(IFMArea *)value;
- (void)removeAreasObject:(IFMArea *)value;
- (void)addAreas:(NSSet *)values;
- (void)removeAreas:(NSSet *)values;

@end
