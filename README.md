IfinitySDK for iOS
=======


Installation
-------------------

The easiest way to install IfinitySDK is by using CocoaPods.

```
pod 'IfinitySDK'
```

If you want to install IfinitySDK manually, you need to follow these steps:

1. Add following frameworks to your project: 'MapKit', 'CoreLocation', 'CoreData', 'Security', 'CoreBluetooth', 'libz'
2. Drag `ifinitySDK.framework` to the Framework's group of your project. Make sure "Copy items into destination group's folder" is selected.
3. Right-click 'ifinitySDK.framework' in your project, and select Show In Finder.
4. Drag the ifinityDB.bundle from the Resources folder to your project. We suggest putting it into the Frameworks group. Make sure "Copy items into destination group's folder" is not selected.
5. Set the value of the Other Linker Flags build setting to $(OTHER_LDFLAGS) -ObjC as described in  [Apple Technical Q&A QA1490](https://developer.apple.com/library/mac/qa/qa1490/_index.html)


