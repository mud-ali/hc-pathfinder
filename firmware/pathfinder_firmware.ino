const int led_top = 5;
const int led_right = 6;
const int led_bottom = 11;
const int led_left = 7;

const int button_up = 1;
const int button_right = 3;
const int button_down = 4;
const int button_left = 2;

int delayDuration = 500;
int direction = 1; // clockwise

int led_order[] = {5, 6, 7, 11};
int LED_COUNT = 4;

int current_led = 0;
unsigned long last_time = 0;

void setup() {
  pinMode(led_bottom, OUTPUT);
  pinMode(led_top, OUTPUT);
  pinMode(led_right, OUTPUT);
  pinMode(led_left, OUTPUT);

  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_left, INPUT_PULLUP);
  pinMode(button_right, INPUT_PULLUP);

  last_time = millis();
}

void loop() {
  if (digitalRead(button_down)) delayDuration = min(delayDuration+100, 1000);
  else if (digitalRead(button_up)) delayDuration = max(delayDuration-100, 100);

  if (digitalRead(button_left)) direction = -1;
  else if (digitalRead(button_right)) direction = 1;

  digitalWrite(led_order[current_led], HIGH);

  if (millis() >= last_time + delayDuration) {
    digitalWrite(led_order[current_led], LOW);
    current_led = get_next_led_index(current_led);
    last_time = millis();
  }
}

int get_next_led_index(int current_index) {
  return (current_index+direction) % LED_COUNT;
}

