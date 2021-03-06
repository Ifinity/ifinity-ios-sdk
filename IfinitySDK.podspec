Pod::Spec.new do |s|
  s.name = 'IfinitySDK'
  s.version = '0.1.7.2'
  s.platform = :ios, '8.0'
  s.source = { :git => 'https://github.com/Ifinity/ifinity-ios-sdk.git', :tag => '0.1.7.2' }
  s.summary = 'iOS sdk for ifinity beacons'
  s.homepage = 'http://getifinity.com'
  s.vendored_frameworks = 'ifinitySDK.framework'
  s.public_header_files = 'ifinitySDK.framework/**/*.h'
  s.resource = 'ifinitySDK.framework/Versions/A/Resources/ifinityDB.bundle', 'ifinitySDK.framework/Versions/A/Resources/ifinityImages.bundle'
  s.preserve_paths = 'ifinitySDK.framework'
  s.frameworks = 'MapKit', 'CoreLocation', 'CoreData', 'Security', 'CoreBluetooth'
  s.library = 'z', 'sqlite3'
  s.author  = { 'ifinity' => 'support@getifinity.com'}
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2014 Getifinity All rights reserved.
      LICENSE
  }
end
