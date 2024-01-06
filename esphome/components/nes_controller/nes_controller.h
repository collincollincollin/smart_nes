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

  void set_a_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->a_button_sensor = sensor;
  }
  void set_b_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->b_button_sensor = sensor;
  }
  void set_select_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->select_button_sensor = sensor;
  }
  void set_start_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->start_button_sensor = sensor;
  }
  void set_up_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->up_button_sensor = sensor;
  }
  void set_down_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->down_button_sensor = sensor;
  }
  void set_left_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->left_button_sensor = sensor;
  }
  void set_right_button_sensor(binary_sensor::BinarySensor *sensor) {
        this->right_button_sensor = sensor;
  }
  // ... Define sensors for other buttons ...

 private:
  uint8_t data_pin_;
  uint8_t clock_pin_;
  uint8_t latch_pin_;
  
  binary_sensor::BinarySensor *a_button_sensor;
  binary_sensor::BinarySensor *b_button_sensor;
  binary_sensor::BinarySensor *select_button_sensor;
  binary_sensor::BinarySensor *start_button_sensor;
  binary_sensor::BinarySensor *up_button_sensor;
  binary_sensor::BinarySensor *down_button_sensor;
  binary_sensor::BinarySensor *left_button_sensor;
  binary_sensor::BinarySensor *right_button_sensor;

  byte read_nes_controller();
  void pulse_pin(uint8_t pin);
};

}  // namespace nes_controller
}  // namespace esphome
