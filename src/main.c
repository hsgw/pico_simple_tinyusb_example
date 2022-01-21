// SPDX-License-Identifier: MIT
// (c) 2022 Takuya Urakawa(dm9records.com 5z6p.com)

#include "pico/stdlib.h"

#include "bsp/board.h"
#include "tusb.h"

static void cdc_task(void) {
  if (tud_cdc_available()) {
    uint8_t buf[64];
    uint32_t count = tud_cdc_read(buf, sizeof(buf));
    for (uint32_t i = 0; i < count; i++) {
      tud_cdc_write_char(buf[i] + 1);
    }
    tud_cdc_write_flush();
  }
}

int main() {
  board_init();
  tusb_init();

  while (1) {
    tud_task();
    cdc_task();
  }
  return 0;
}