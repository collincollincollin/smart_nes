#include "nes_controller.h"
#include "esphome/core/log.h"

namespace esphome {
namespace nes_controller {

static const char *const TAG = "nes_controller";

void NESController::setup() {
  pinMode(this->data_pin_, INPUT);
  pinMode(this->clock_pin_, OUTPUT);
  pinMode(this->latch_pin_, OUTPUT);

  digitalWrite(this->clock_pin_, LOW);
  digitalWrite(this->latch_pin_, LOW);
}

void NESController::loop() {
  byte nes_register = read_nes_controller();

  this->a_button_sensor->publish_state(!bitRead(nes_register, 0));
  this->b_button_sensor->publish_state(!bitRead(nes_register, 1));
  // ... Publish state for other buttons ...

  // delay(180);  // Slight delay to prevent spam
}

void NESController::set_data_pin(uint8_t data_pin) {
  this->data_pin_ = data_pin;
}

void NESController::set_clock_pin(uint8_t clock_pin) {
  this->clock_pin_ = clock_pin;
}

void NESController::set_latch_pin(uint8_t latch_pin) {
  this->latch_pin_ = latch_pin;
}

byte NESController::read_nes_controller() {
  byte temp_data = 0xFF;

  pulse_pin(this->latch_pin_);
  
  for (int i = 0; i < 8; i++) {
    if (digitalRead(this->data_pin_) == LOW)
      bitClear(temp_data, i);

    pulse_pin(this->clock_pin_);
  }

  return temp_data;
}

void NESController::pulse_pin(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  delayMicroseconds(5);
}

}  // namespace nes_controller
}  // namespace esphome
