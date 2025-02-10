#define DT_DRV_COMPAT zmk_hid_to_layer

#include <raw_hid/events.h>
#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zephyr/logging/log.h>

#include <zmk/keymap.h>
#include <zmk/behavior.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);
static int raw_hid_received_event_listener(const zmk_event_t *eh) {
    struct raw_hid_received_event *event = as_raw_hid_received_event(eh);
    if (event->data[0]==0) {
		LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_to(DEFAULT);
    }
	if (event->data[0]==1) {
		LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_to(GAMING);
    }
	if (event->data[0]==2) {
        LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_activate(ARROWS);
    }
	if (event->data[0]==3) {
        LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_deactivate(ARROWS);
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(process_raw_hid_event, raw_hid_received_event_listener);
ZMK_SUBSCRIPTION(process_raw_hid_event, raw_hid_received_event);