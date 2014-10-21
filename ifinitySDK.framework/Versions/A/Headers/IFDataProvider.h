//
//  IFDataProvider.h
//  ifinitySDK
//
//  Created by GetIfinity on 09.10.2014.
//  Copyright (c) 2014 GetIfinity. All rights reserved.
//

#import "IFDataManager.h"

/**
 *  Base class for all DataProviders
 */
@class IFDataManager;

@interface IFDataProvider : NSObject

@property (nonatomic, strong, readonly) IFDataManager *dataManager;

/**
 *  All data providers share the same constructor.
 *
 *  @param dataManager An instance of shared manager
 *
 *  @return new instance
 */
- (instancetype)initWithDataManager:(IFDataManager *)dataManager;
@end
