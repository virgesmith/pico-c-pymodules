#include "pico-utils.h"

#include "pico/stdlib.h"
#include "pico/unique_id.h"

namespace {

int init()
{
  const int LED_PIN = 25;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  return LED_PIN;
}

}

const unsigned char* id()
{
  static pico_unique_board_id_t id;
  pico_get_unique_board_id(&id);

  return id.id;
}

void onboard_led(bool onoff)
{
  static const int LED_PIN = init();
  gpio_put(LED_PIN, onoff? 1 : 0);

}


  // gpio_put(LED_PIN, 1);
  // sleep_ms(100);
  // gpio_put(LED_PIN, 0);