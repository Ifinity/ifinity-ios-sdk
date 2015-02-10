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
