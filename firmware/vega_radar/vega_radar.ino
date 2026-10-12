#include <Servo.h>

Servo myServo;  // ایجاد شیء سروو

// پین‌ها
const int trigPin = 10;     // Trig سنسور
const int echoPin = 11;     // Echo سنسور
const int servoPin = 9;     // سیگنال سروو
const int joystickX = A0;   // محور X جوی‌استیک
const int switchPin = 2;    // سوئیچ جوی‌استیک
const int buzzerPin = 3;    // buzzer
const int redPin = 5;       // قرمز LED
const int greenPin = 6;     // سبز LED
const int bluePin = 7;      // آبی LED (اختیاری)

// متغیرها
int mode = 0;               // 0: اتوماتیک, 1: دستی
int prevSwitchState = HIGH; // برای debounce سوئیچ
long duration;              // برای محاسبه فاصله
int distance;               // فاصله محاسبه‌شده
int servoPos = 90;          // موقعیت اولیه سروو
int servoDir = 1;           // جهت چرخش در مود اتوماتیک (1: افزایش, -1: کاهش)
const int threshold = 50;   // آستانه تشخیص (سانتی‌متر)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);  // pull-up داخلی برای سوئیچ
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  myServo.attach(servoPin);
  myServo.write(servoPos);  // موقعیت اولیه
  
  delay(500);
  Serial.begin(9600);  // برای دیباگ (اختیاری)
}

void loop() {
  // چک کردن سوئیچ برای تغییر مود
  int switchState = digitalRead(switchPin);
  if (switchState == LOW && prevSwitchState == HIGH) {
    mode = !mode;  // تغییر مود
    delay(200);    // debounce
  }
  prevSwitchState = switchState;

  // اندازه‌گیری فاصله
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000UL);
  distance = duration * 0.034 / 2;

  // کنترل LED و buzzer بر اساس فاصله
  if (distance < threshold && distance > 0) {  // تشخیص شیء
    digitalWrite(buzzerPin, HIGH);  // buzzer روشن
    setColor(255, 0, 0);            // قرمز
  } else {
    digitalWrite(buzzerPin, LOW);   // buzzer خاموش
    setColor(0, 255, 0);            // سبز
  }

  // Distance belongs to the current commanded angle.
  Serial.print(servoPos);
  Serial.print(",");
  Serial.println(distance);
  if (mode == 0) {
    servoPos += servoDir * 2;
    servoPos = constrain(servoPos, 0, 180);
    if (servoPos >= 180) servoDir = -1;
    if (servoPos <= 0) servoDir = 1;
  } else {
    servoPos = map(analogRead(joystickX), 0, 1023, 0, 180);
  }
  myServo.write(servoPos);
  delay(50);

}

// تابع برای تنظیم رنگ LED (برای PWM)
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}