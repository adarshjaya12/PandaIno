#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "ble_adv.h"

BLECharacteristic *pCharacteristic;
BLEServer *pServer;

bool deviceConnected = false;
bool oldDeviceConnected = false;
u_int8_t txValue=0;

#define SERVICE_UUID "6d9a506c-839a-11ee-b962-0242ac120002" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" // RX characteristic UUID
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" // TX characteristic UUID

// Callback function to handle BLE events

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Client connected");
  }
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Client disconnected");
    Serial.println("Starting Advertising");
    pServer->startAdvertising();
  }
};

// Callback function to transfer data
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      Serial.println("Inside onWrite fun");
      std::string rxValue = pCharacteristic->getValue();
      Serial.println("Inside onWrite function");
      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.println("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++)
          Serial.print(rxValue[i]);

        Serial.println();
        Serial.println("*********");
      }
    }
};


void ble_setup() {
  Serial.begin(115200);
  Serial.println("1");
  // Create the BLE Server
  BLEDevice::init("Pandacat_UART_BLE");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  Serial.println("2");
  // Create the BLE Service
  BLEService* pService = pServer->createService(SERVICE_UUID);
  Serial.println("3");
  // Create the BLE Characteristic for receiving data (RX)
  BLECharacteristic* pCharacteristic_rx = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE
  );
  Serial.println("4");
  // Create the BLE Characteristic for transmitting data (TX)
  BLECharacteristic* pCharacteristic_tx= pService->createCharacteristic(
      CHARACTERISTIC_UUID_TX,
      BLECharacteristic::PROPERTY_NOTIFY
  );
  Serial.println("5");
  //pCharacteristic->setCallbacks(new MyCallbacks());
  Serial.println("6");
  //pCharacteristic_tx->addDescriptor(new BLE2902());
  // Start the service
  pService->start();
  Serial.println("7");
  // Advertise the service
  BLEAdvertising* pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("8");
  Serial.println("Waiting for a connection...");    
}
/*
void ble_tx()
{
  Serial.println("inside tx function");
  for(;txValue<10;)
  {
    //Conversion of tx value
    char txString[8];
    dtostrf(txValue,1,2,txString);
    
    //Setting the value of the characterisitc
    pCharacteristic_tx->setValue(txString);

    //notify the client
    pCharacteristic_tx->notify();
    txValue++;
    
    delay(5000);
    Serial.println("inside for loop"+ String(txString));
  }
}
*/

void ble_loop() {
  Serial.println("Inside ble loop");
  Serial.println("0");
  ble_setup();
  Serial.println("9");
  /*
  while (true)
  { 
    Serial.println("inside while");
    if(deviceConnected)
    {
      Serial.println("Device connected in Loop");
      ble_tx();
    }
    delay(5000); // bluetooth stack will go into congestion, if too many packets are sent
  }
  */
}


