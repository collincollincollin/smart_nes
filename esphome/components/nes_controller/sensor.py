# import esphome.config_validation as cv
# import esphome.codegen as cg

# # CONF_MY_REQUIRED_KEY = 'my_required_key'
# DATA_PIN = 'data_pin'
# CLOCK_PIN = 'clock_pin'
# LATCH_PIN = 'latch_pin'

# CONF_MY_OPTIONAL_KEY = 'my_optional_key'
# A_BUTTON = 'a_button'
# B_BUTTON = 'b_button'

# CONFIG_SCHEMA = cv.Schema({
#   cv.Required(DATA_PIN): cv.string,
#   cv.Required(CLOCK_PIN): cv.string,
#   cv.Required(LATCH_PIN): cv.string,
#   cv.Optional(CONF_MY_OPTIONAL_KEY, default=10): cv.int_,
#   cv.Optional(A_BUTTON, default="?"): cv.string,
#   cv.Optional(B_BUTTON, default="?"): cv.string,
# }).extend(cv.COMPONENT_SCHEMA)

# def to_code(config):
#     var = cg.new_Pvariable(config[CONF_ID])
#     yield cg.register_component(var)

#     cg.add(var.set_my_required_key(config[CONF_MY_REQUIRED_KEY]))


import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID

DEPENDENCIES = ['binary_sensor']

DATA_PIN = 'data_pin'
CLOCK_PIN = 'clock_pin'
LATCH_PIN = 'latch_pin'
A_BUTTON = 'a_button'
B_BUTTON = 'b_button'
# ... Add other buttons ...

nes_controller_ns = cg.esphome_ns.namespace('nes_controller')
NESController = nes_controller_ns.class_('NESController', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(NESController),
    cv.Required(DATA_PIN): cv.int_,
    cv.Required(CLOCK_PIN): cv.int_,
    cv.Required(LATCH_PIN): cv.int_,
    cv.Optional(A_BUTTON): binary_sensor.BINARY_SENSOR_SCHEMA,
    cv.Optional(B_BUTTON): binary_sensor.BINARY_SENSOR_SCHEMA,
    # ... Add schema entries for other buttons ...
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    cg.add(var.set_data_pin(config[DATA_PIN]))
    cg.add(var.set_clock_pin(config[CLOCK_PIN]))
    cg.add(var.set_latch_pin(config[LATCH_PIN]))

    if A_BUTTON in config:
        sensor = yield binary_sensor.new_binary_sensor(config[A_BUTTON])
        cg.add(var.a_button_sensor.set_binary_sensor(sensor))
    if B_BUTTON in config:
        sensor = yield binary_sensor.new_binary_sensor(config[B_BUTTON])
        cg.add(var.b_button_sensor.set_binary_sensor(sensor))
    # ... Add code generation for other buttons ...
