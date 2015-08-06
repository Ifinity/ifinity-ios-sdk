## 0.1.6.5

- Update methods add beacon or update beacon (floorId is opcional)
- floor label change typ from NSString to NSNumber
- Bugfixs

## 0.1.6.4

- update compas
- TranslationCoordinate change from center floor to center venue
- bluetooth add function venueAndFloorDetected when is not lost strong transmitter
- update camera distance
- Bugfixs

## 0.1.6.3

- Update structur stats
- New method in `IFBluetoothManagerDelegate` for detecting change of state in `didLostAllBeaconsForFloorplan` and ` didLostAllBeaconsForVenue`
- Push manager remote push
- Bugfixs
- Update methods indoor navigation type transport
- Change distance load data venues
- New property in `IFIndoorMapController` to `shouldAddAreasToMap`.
- New property in `IFIndoorMapController` to `nextNodeWarrning`.

## 0.1.6.2

- Stats system
- Add push to manager list only when it is content

## 0.1.6.1

- Critical bugfix bundle image

## 0.1.6

- push background update only inactive
- custom api url
- coredata push structure
- push manager class
- background push - add push manager
- local push notification open
- background push add authenticate

## 0.1.5

- IFIndoorMapController mapview public delegate
- IFIndoorMapController location manager public manager
- public fill from json model api
- background push venue
- create venue one beacon

## 0.1.4.1

- Critical bugfix, missing header files

## 0.1.4

- IFIndoorMapController -  new & fresh utility class to easy implementing indoor navigation. 
- Bugfixes

## 0.1.3.1

- Critical bugfix

## 0.1.3

- New images sizes in venues and contents.
- Calculate full route length from current point.
- Get routes not only as polygon but also with nodes descriptions/types.
- Get data from cache in async way
- Render temporary map tiles if floorplan is not yet ready. IFTilesOverlay can pass information if map is ready or not.   
- Methods to fetch venues and areas from cache.
- Bugfixes
  
## 0.1.2

- Start/stop BLE scan on application enter background / become active only when scan is running.
- Fix error with token expired after app restart
- New method to reset current location in IFLocationManager. It helps to solve some edge cases, for example when you want to force a data refresh.
- Only one beacon is required to floorplan detection. 
- IFIndoorLocationManager has an additional param for startCheckingAreasForFloorplan
- Fix problem with ble scan starting when app go from backgound to active state.
- Refactoring entities names, Place => Venue.
- In IFDataManager load public + private or only private venues.  
- Bugfixes 

## 0.1.1 

- New property in `IFTransmitter` to get `CBPeripheral` object for transmitter. 
- Removed dataproviders classes. 
- Removed unused methods in IFLocationManager
- New method in `IFBluetoothManagerDelegate` for detecting change of state in `CBCentralManager` - `manager:didUpdateCentralManagerState:`. 
- New property in `IFBluetoothManager` to get current `CBCentralManagerState`.
- Misc bugs found since last release :)

## 0.1.0 

Initial release
