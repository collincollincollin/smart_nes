#include "esphome.h"

class NESController : public Component {
 public:
  // Constructor
  NESController(int data_pin, int clock_pin, int latch_pin);

  // ESPHome methods
  void setup() override;
  void loop() override;

  // Custom method to read the controller
  byte readNesController();

 private:
  int data_pin_;
  int clock_pin_;
  int latch_pin_;
  byte nes_register_;
};
