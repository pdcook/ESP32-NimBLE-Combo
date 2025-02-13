#define USE_NIMBLE

#ifndef ESP32_BLE_KEYBOARD_OUTPUT_CALLBACKS_H
#define ESP32_BLE_KEYBOARD_OUTPUT_CALLBACKS_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#if defined(USE_NIMBLE)

#include <NimBLEServer.h>
#include "NimBLECharacteristic.h"

#define BLEDevice                  NimBLEDevice
#define BLEServerCallbacks         NimBLEServerCallbacks
#define BLECharacteristicCallbacks NimBLECharacteristicCallbacks
#define BLEHIDDevice               NimBLEHIDDevice
#define BLECharacteristic          NimBLECharacteristic
#define BLEAdvertising             NimBLEAdvertising
#define BLEServer                  NimBLEServer

#else

#include <BLEServer.h>
#include "BLE2902.h"
#include "BLECharacteristic.h"

#endif // USE_NIMBLE

class KeyboardOutputCallbacks : public BLECharacteristicCallbacks
{
public:
  KeyboardOutputCallbacks(void);
  void onWrite(BLECharacteristic* me);
};

#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_KEYBOARD_OUTPUT_CALLBACKS_H
