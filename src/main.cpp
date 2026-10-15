#include <Arduino.h>

// Визначаємо цифровий пін, до якого підключимо зовнішній світлодіод.
// Суфікс _OUT одразу підказує, що цей пін працює на вихід.
// #define LED_OUT 15
constexpr uint8_t BLUE_LED = 15; // Визначаємо пін для світлodіod
constexpr uint8_t RED_LED = 16; // Визначаємо пін для світlodіod
constexpr uint16_t BLINK_SPEED = 150; // Визначаємо швидкість блимання (мс)

void setup() {
    // Налаштовуємо пін як вихід (OUTPUT), щоб контролер міг подавати на нього напругу
    pinMode(BLUE_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    Serial.begin(115200); // Ініціалізуємо серійний порт для виводу інформації
}

void led(uint8_t pin, bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
    Serial.print("Світлодіод на піні ");
    Serial.print(pin);
    Serial.print(state ? " увімкнено" : " вимкнено");
    Serial.println();
}

void program(uint8_t pin) {
    led(pin, true); // Вмикаємо синій світлoдіod (подаємо 3.3 В)
    delay(BLINK_SPEED); // Чекаємо 0.15 секунду (150 мілісекунд)
    led(pin, false); // Вимикаємо синій світlodіod  (подаємо 0 В)
    delay(BLINK_SPEED); // Чекаємо 0.15 секунду (150 мілісекунд)

}

void loop() {
    // Синій: перший спалах
    program(BLUE_LED);  // Вмикаємо та вимикаємо синій світлoдіod
 
    // Синій: другий спалах
    program(BLUE_LED);  // Вмикаємо та вимикаємо синій світлoдіod

    // Червоний: перший спалах
    program(RED_LED);  // Вмикаємо та вимикаємо червоний світлoдіod

    // Червоний: другий спалах
    program(RED_LED);  // Вмикаємо та вимикаємо червоний світлoдіod
    
    delay(300);
}