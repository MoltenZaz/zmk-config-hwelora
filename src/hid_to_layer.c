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
		zmk_keymap_layer_deactivate(4);
    }
	if (event->data[0]==1) {
		LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_activate(4);
    }
	if (event->data[0]==2) {
        LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_activate(8);
    }
	if (event->data[0]==3) {
        LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_deactivate(8);
    }
	if (event->data[0]==4) {
        LOG_INF("display_process_raw_hid_data - received data_type %u", event->data[0]);
		zmk_keymap_layer_to(0);
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(process_raw_hid_event, raw_hid_received_event_listener);
ZMK_SUBSCRIPTION(process_raw_hid_event, raw_hid_received_event);