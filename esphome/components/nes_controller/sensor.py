import esphome.config_validation as cv
import esphome.codegen as cg

# CONF_MY_REQUIRED_KEY = 'my_required_key'
DATA_PIN = 'data_pin'
CLOCK_PIN = 'clock_pin'
LATCH_PIN = 'latch_pin'

CONF_MY_OPTIONAL_KEY = 'my_optional_key'
A_BUTTON = 'A Button'
B_BUTTON = 'B Button'

CONFIG_SCHEMA = cv.Schema({
  cv.Required(DATA_PIN): cv.string,
  cv.Required(CLOCK_PIN): cv.string,
  cv.Required(LATCH_PIN): cv.string,
  cv.Optional(CONF_MY_OPTIONAL_KEY, default=10): cv.int_,
  cv.Optional(A_BUTTON, default="?"): cv.string,
  cv.Optional(B_BUTTON, default="?"): cv.string,
}).extend(cv.COMPONENT_SCHEMA)

# def to_code(config):
#     var = cg.new_Pvariable(config[CONF_ID])
#     yield cg.register_component(var)

#     cg.add(var.set_my_required_key(config[CONF_MY_REQUIRED_KEY]))