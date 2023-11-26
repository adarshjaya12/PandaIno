#include <Arduino.h>
#include "nimBLE.h"
#include <NimBLEDevice.h>

BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t txValue = 0;

#define SERVICE_UUID "6d9a506c-839a-11ee-b962-0242ac120002" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" // RX characteristic UUID
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" // TX characteristic UUID

class ServerCallbacks: public NimBLEServerCallbacks {
  void onConnect(NimBLEServer* pServer) {
    Serial.println("Client connected");
    deviceConnected=true;
  };
  
  void onDisconnect(NimBLEServer* pServer) {
    Serial.println("Client disconnected - start advertising");
    NimBLEDevice::startAdvertising();
    deviceConnected=false;
  };
};

/** Handler class for characteristic actions */
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++)
          Serial.print(rxValue[i]);

        Serial.println();
        Serial.println("*********");
      }
    }
};

void nimBLE_setup() {
  Serial.println("Starting NimBLE Server");

  /** sets device name */
  NimBLEDevice::init("Pandacat_NimBLE");

  pServer = NimBLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic * pTxCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX,NIMBLE_PROPERTY::NOTIFY);
                                    
  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX,NIMBLE_PROPERTY::WRITE);

  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");

  delay(20000);
  Serial.println("Tx notify");

  if(deviceConnected)
  {
    txValue=199; //test value that will be read by the BLE app.
    pTxCharacteristic->setValue(&txValue, 1);
    pTxCharacteristic->notify();
  }
  else
  {
    Serial.println("Device is not connected");
  }
}

void nimBLE_loop(){
  nimBLE_setup();
  delay(10000);
}
