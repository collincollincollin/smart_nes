#pragma once

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome {
namespace nes_controller {

class NESController : public Component {
 public:
  void setup() override;
  void loop() override;

  void set_data_pin(uint8_t data_pin);
  void set_clock_pin(uint8_t clock_pin);
  void set_latch_pin(uint8_t latch_pin);

  void set_a_button_sensor(binary_sensor::BinarySensor *a_button_sensor) { this->a_button_sensor = a_button_sensor; };
  void set_b_button_sensor(binary_sensor::BinarySensor *b_button_sensor) { this->b_button_sensor = b_button_sensor; };
  // ... Define sensors for other buttons ...

 private:
  uint8_t data_pin_;
  uint8_t clock_pin_;
  uint8_t latch_pin_;

  byte read_nes_controller();
  void pulse_pin(uint8_t pin);
};

}  // namespace nes_controller
}  // namespace esphome
