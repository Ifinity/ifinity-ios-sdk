# IfinitySDK for iOS

## Installation

The easiest way to install IfinitySDK is by using CocoaPods.

```
pod 'IfinitySDK'
```

If you want to install IfinitySDK manually, you need to follow these steps:

1. Add following frameworks to your project: 'MapKit', 'CoreLocation', 'CoreData', 'Security', 'CoreBluetooth', 'libz', 'sqlite3'
2. Drag `ifinitySDK.framework` to the Framework's group of your project. Make sure "Copy items into destination group's folder" is selected.
3. Right-click 'ifinitySDK.framework' in your project, and select Show In Finder.
4. Drag the ifinityDB.bundle and ifinityImages.bundle from the Resources folder to your project. We suggest putting it into the Frameworks group. Make sure "Copy items into destination group's folder" is not selected.
5. Set the value of the Other Linker Flags build setting to $(OTHER_LDFLAGS) -ObjC as described in  [Apple Technical Q&A QA1490](https://developer.apple.com/library/mac/qa/qa1490/_index.html)


# Quick Start

## Authentication

Authentication is a must have for using the IfinitySDK. Without it, SDK won’t work or it will keep throwing exceptions. Every next step in this tutorial requires authorization. Every launch of your app will need to begin with the process showed below.


```
// obtain those parameters at the geos.zone website
#define GEOS_APP_ID @"..."
#define GEOS_SECRET @"..."

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
    [[IFDataManager sharedManager] setClientID:GEOS_APP_ID secret:GEOS_SECRET];
    return YES;
}

- (void)authenticate
{
    [[IFDataManager sharedManager] authenticateWithSuccess:^(IFOAuthCredential *credential) {
        NSLog(@"Authenticate  success.");
    }failure:^(NSError *error) {
        NSLog(@"Invalid authentication with error %@", error);
    }];
}
```


## Loading venue data

After authenticating with our API, you can load venues from geos.zone. You can do this by using single instance of `IFDataManager`, passing your current or needed location, radius and choose public or not public venue.

```
[[IFDataManager sharedManager] loadDataForLocation:[[CLLocation alloc] initWithLatitude:52 longitude:21] distance:@1000 withPublicVenues:YES successBlock:^(NSArray *venues) {
        NSLog(@"LoadDataForLocation success.");
    } failure:^(NSError *error) {
        NSLog(@"LoadDataForLocation error %@",error);
    }];

```


## Accessing local database

After determining that your data was successfully loaded, you can easily access it from your local database storage. To achieve that you need to call the data access methods of the single `DataManager` instance.

```
// fetch all venues from database
[[IFDataManager sharedManager] fetchVenuesFromCacheWithBlock:^(NSArray *venues) { ... }];

// fetch floor for specific venue
[[IFDataManager sharedManager] fetchFloorsFromCacheForVenueId:venueId block:^(NSArray *floors) { ... }];

// fetch areas for specific floor
[[IFDataManager sharedManager] fetchAreasFromCacheForFloorId:floorplanId block:^(NSArray *areas) { ... }];

// fetch areas for specific venue
[[IFDataManager sharedManager] fetchAreasFromCacheForVenueId:venueId block:^(NSArray *areas) { ... }];

// get beacons for specific floor
[floorplan.beacons enumerateObjectsUsingBlock:^(IFMBeacon * _Nonnull obj, BOOL * _Nonnull stop) { ... }];

// get content for specific area
[[IFDataManager sharedManager] fetchContentForAreaId:areaId block:^(IFMContent *content) { ... }];

// get content for specific venue
[[IFDataManager sharedManager] fetchContentForVenueId:venueId block:^(IFMContent *content) { ... }];

// fetch all push from database
[[IFPushManager sharedManager] fetchAll];
```


## Entering the venue

For detection of venues in physical world you need to access the single instance of the `IFBluetoothManager` class. This class will provide you with the information about nearby beacons state, venues you’re in, and the floor you’re on.

## Detecting many-beacons venue floor

```
- (void)viewWillAppear:(BOOL)animated
{
    [[IFBluetoothManager sharedManager] setDelegate:self];
    [[IFBluetoothManager sharedManager] startManager];
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[IFBluetoothManager sharedManager] stopManager];
    [[IFBluetoothManager sharedManager] setDelegate:nil];
}

#pragma mark - IFBluetoothManagerDelegate

- (void)manager:(IFBluetoothManager *)manager didDiscoverActiveBeaconsForVenue:(IFMVenue *)venue floorplan:(IFMFloorplan *)floorplan
{
   [self.indoorLocationManager startCheckingAreasForFloorplan:floorplan];
}

- (void)manager:(IFBluetoothManager *)manager didLostAllBeaconsForVenue:(IFMVenue *)venue
{
}

- (void)manager:(IFBluetoothManager *)manager didLostAllBeaconsForFloorplan:(IFMFloorplan *)floorplan
{
}
```


## Detecting indoor location

IfinitySDK can provide you with a specific data about the user location inside a venue: his/her position and area he/she is inside. To obtain this information, you need to get a single instance of the `IndoorLocationManager` and register the listeners for the events you want to handle.
To use the `IFIndoorLocationManager`, the `IFBluetoothManager` must be started first.

```
- (void)viewDidLoad
{
    [super viewDidLoad];

    self.indoorLocationManager = [[IFIndoorLocationManager alloc] init];
    self.indoorLocationManager.delegate = self;
}

- (void)viewWillAppear:(BOOL)animated
{
    [[IFBluetoothManager sharedManager] startManager];
    [self.indoorLocationManager startUpdatingIndoorLocation];    
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[IFBluetoothManager sharedManager] stopManager];
    [self.indoorLocationManager stopUpdatingIndoorLocation]; 
}

#pragma mark - IFIndoorLocationManagerDelegate

- (void)manager:(IFIndoorLocationManager *)manager didUpdateIndoorLocation:(CLLocation *)location
{
}

- (void)manager:(IFIndoorLocationManager *)manager didEnterArea:(IFMArea *)area
{
}

- (void)manager:(IFIndoorLocationManager *)manager didExitArea:(IFMArea *)area
{
}
```


## Push Manager

IfinitySDK allows usage of background push notification in your app easily. To do that, you need to add obeservers to NSNotificationCenter.

```
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(addPush:) name:IFPushManagerNotificationPushAdd object:nil];

[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(deletePush:) name:IFPushManagerNotificationPushDelete object:nil];

- (void)addPush:(id)sender
{
    NSDictionary *dict = [sender userInfo];
    IFMPush *push = [dict objectForKey:@"push"];
}

- (void)deletePush:(id)sender
{
    NSDictionary *dict = [sender userInfo];
    IFMPush *push = [dict objectForKey:@"push"];
}
```


## Background notifications 

To make use of background notifications, you will need to enable background location updates in Xcode. You can do this by enabling Capabilities -> Background Modes -> Location updates on project settings tab. Then you need to create a new instance of `IFBackgroundGeosController` and pass him an instance of CLLocationManagera.

```
@interface ViewController () <CLLocationManagerDelegate>
@property (nonatomic, strong) CLLocationManager *manager;
@property (nonatomic, strong) IFBackgroundGeosController *geosController;
@end

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.manager = [[CLLocationManager alloc] init];
    _geosController = [[IFBackgroundGeosController alloc] initWithLocationManager:_manager];
    _geosController.enableNotifications = YES;
    if([CLLocationManager authorizationStatus]==kCLAuthorizationStatusNotDetermined) {
        [_manager requestAlwaysAuthorization];
    }
    _manager.delegate = _geosController;
    [_manager startUpdatingLocation];
}
```


If you want to handle background push notifications, you will need to add some additional observers to NSNotificationCenter.



```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(addPush:) name:IFPushManagerNotificationPushAreaBackgroundAdd object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(addPush:) name:IFPushManagerNotificationPushVenueBackgroundAdd object:nil];

    if (launchOptions[UIApplicationLaunchOptionsLocalNotificationKey]) {
        UILocalNotification *localNotification = launchOptions[UIApplicationLaunchOptionsLocalNotificationKey];
        [[IFPushManager sharedManager] addReceiveLocalNotification:localNotification.userInfo];
    }
    return YES;
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
 {
    [[IFPushManager sharedManager] addReceiveLocalNotification:notification.userInfo];
}

- (void)addPush:(id)sender
{
    NSDictionary *dict = [sender userInfo];
    IFMPush *push = [dict objectForKey:@"push"];
}
```



## Sample project

There are two projects on our github account, that should help you start with our SDK, you will find them below for both Swift and Objective-C. 

- Swift: https://github.com/Ifinity/ifinity-swift-example 
- Objective-C: https://github.com/Ifinity/ifinity-objc-example
