/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Glenn Ruben Bakke
 * Copyright (c) 2018 Artur Pacholec
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_NRF_BLUETOOTH_BLE_DRV_H
#define MICROPY_INCLUDED_NRF_BLUETOOTH_BLE_DRV_H

#include "ble.h"

#if (BLUETOOTH_SD == 132) && (BLE_API_VERSION == 2)
#define NRF52
#endif

#define MAX_TX_IN_PROGRESS 10

#ifndef BLE_GATT_ATT_MTU_DEFAULT
    #define BLE_GATT_ATT_MTU_DEFAULT GATT_MTU_SIZE_DEFAULT
#endif

#define BLE_CONN_CFG_TAG_CUSTOM 1

#define MSEC_TO_UNITS(TIME, RESOLUTION) (((TIME) * 1000) / (RESOLUTION))
// 0.625 msecs (625 usecs)
#define ADV_INTERVAL_UNIT_FLOAT_SECS (0.000625)
#define UNIT_0_625_MS (625)
#define UNIT_10_MS    (10000)

typedef void (*ble_drv_evt_handler_t)(ble_evt_t*, void*);

typedef struct ble_drv_evt_handler_entry {
    struct ble_drv_evt_handler_entry *next;
    void *param;
    ble_drv_evt_handler_t func;
} ble_drv_evt_handler_entry_t;

void ble_drv_reset(void);
void ble_drv_add_event_handler(ble_drv_evt_handler_t func, void *param);
void ble_drv_remove_event_handler(ble_drv_evt_handler_t func, void *param);

#endif // MICROPY_INCLUDED_NRF_BLUETOOTH_BLE_DRV_H
