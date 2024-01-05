// C code
// Mengontrol LED dan servo dengan Arduino
// LED terhubung ke pin 10 dan 13
// Servo terhubung ke pin 3
// Servo berputar dari 0 derajat ke 180 derajat dan kembali
// LED menyala saat servo bergerak dan mati saat servo berhenti

// Inisialisasi pin
const byte ledPin1 = 10;
const byte ledPin2 = 13;
const byte servoPin = 3;

// Inisialisasi variabel
int angle; // sudut yang diinginkan
int pulse; // lebar pulsa dalam mikrodetik

void setup() {
  // Inisialisasi serial monitor
  Serial.begin(9600);
  // Set pin sebagai output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(servoPin, OUTPUT);
}

void loop() {
  Serial.println(analogRead(servoPin)); //Variabel untuk menampilkan status servo ke serial monitor,Belajar variabel ini pada parrt kali ini
  // Nyalakan LED 2
  digitalWrite(ledPin2, HIGH);
  // Servo berputar dari 0 derajat ke 180 derajat
  for (angle = 0; angle <= 180; angle++) {
    // Hitung lebar pulsa berdasarkan sudut
    pulse = map(angle, 0, 180, 600, 2400);
    // Kirim pulsa ke servo
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse); //KOde Program Delay Khusus Servo
    digitalWrite(servoPin, LOW);
    // Tunggu 20 ms untuk siklus segar servo
    delay(20);
  }
  // Matikan LED 2
  digitalWrite(ledPin2, LOW);
  // Tunggu 3 detik
  delay(3000);
  
  
  // Nyalakan LED 1
  digitalWrite(ledPin1, HIGH);
  // Servo berputar dari 180 derajat ke 0 derajat
  for (angle = 180; angle >= 0; angle--) {
    // Hitung lebar pulsa berdasarkan sudut
    pulse = map(angle, 0, 180, 600, 2400);
    // Kirim pulsa ke servo
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(servoPin, LOW);
    // Tunggu 20 ms untuk siklus segar servo
    delay(20);
  }
  // Matikan LED 1
  digitalWrite(ledPin1, LOW);
  // Tunggu 3 detik
  delay(3000);
}
