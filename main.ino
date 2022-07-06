#include <AntaresESP32HTTP.h>

#define ACCESSKEY "*************************"       // Ganti dengan access key akun Antares anda
#define WIFISSID "Www"         // Ganti dengan SSID WiFi anda
#define PASSWORD "xyz123456"     // Ganti dengan password WiFi anda

#define applicationName "SmartHome101"   // Ganti dengan application name Antares yang telah dibuat
#define deviceName "Temperature"     // Ganti dengan device Antares yang telah dibuat

AntaresESP32HTTP antares(ACCESSKEY);    // Buat objek antares

void setup() {
  Serial.begin(115200);     // Buka komunikasi serial dengan baudrate 115200
  antares.setDebug(true);   // Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
}

void loop() {
  antares.get(applicationName, deviceName);

  // Mendapatkan data individu
  int temp = antares.getInt("temperature");
  int hum = antares.getInt("humidity");
  float windsp = antares.getFloat("wind_speed");
  float rainlv = antares.getFloat("rain_level");
  String lat = antares.getString("latitude");
  String lon = antares.getString("longitude");

  // Kirim ke serial monitor
  Serial.println("Temperature: " + String(temp));
  Serial.println("Humidity: " + String(hum));
  Serial.println("Wind speed: " + String(windsp));
  Serial.println("Rain level: " + String(rainlv));
  Serial.println("Latitude: " + lat);
  Serial.println("Longitude: " + lon);
  delay(10000);
}
