// ——— Auxiliares ———
bool addressEqual(const DeviceAddress a, const DeviceAddress b) {
  for (uint8_t i = 0; i < 8; i++)
    if (a[i] != b[i]) return false;
  return true;
}

void printAddress(const DeviceAddress addr) {
  for (uint8_t i = 0; i < 8; i++) {
    if (addr[i] < 16) SerialUSB.print('0');
    SerialUSB.print(addr[i], HEX);
  }
}

// ——— Actualiza el mapeo en FlashStorage ———
void updateSensorMap() {
  uint8_t detected = sensors.getDeviceCount();
  SensorMap sm = sensorMapStorage.read();

  if (detected == 0) {
    // Borra mapeo si no hay sensores
    if (sm.count > 0) {
      SensorMap empty = { 0, { { 0 } } };
      sensorMapStorage.write(empty);
      sm = empty;
      SerialUSB.println(">> Mapeo borrado (no hay sensores)");
    }
  } else {
    // Agrega nuevos sensores manteniendo el orden anterior
    bool changed = false;
    for (uint8_t i = 0; i < detected && sm.count < MAX_SENSORS; i++) {
      DeviceAddress addr;
      if (!sensors.getAddress(addr, i)) continue;

      bool found = false;
      for (uint8_t j = 0; j < sm.count; j++) {
        if (addressEqual(sm.addr[j], addr)) {
          found = true;
          break;
        }
      }
      if (!found) {
        memcpy(sm.addr[sm.count], addr, sizeof(DeviceAddress));
        sm.count++;
        changed = true;
        SerialUSB.print(">> Añadido sensor: ");
        printAddress(addr);
        SerialUSB.println();
      }
    }
    if (changed) {
      sensorMapStorage.write(sm);
      SerialUSB.print(">> Mapeo actualizado. Total sensores: ");
      SerialUSB.println(sm.count);
    }
  }

  // Copia a RAM
  sensorCount = sm.count;
  for (uint8_t i = 0; i < sensorCount; i++) {
    memcpy(sensorMapArr[i], sm.addr[i], sizeof(DeviceAddress));
  }
}

