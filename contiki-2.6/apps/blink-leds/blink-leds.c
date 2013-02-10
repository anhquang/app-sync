#include "blink-leds.h"
PROCESS(blink_leds_proc, "Blink leds ^^");
/*-------------------------------------------------------------------*/
void blink_leds (void)
{
	process_start (&blink_leds_proc,NULL);
}
/*-------------------------------------------------------------------*/
PROCESS_THREAD(blink_leds_proc, ev, data)
{
	static struct etimer timer1;
	static struct etimer timer2;
	static struct etimer timer3;
  PROCESS_BEGIN();

  etimer_set(&timer1, INTERVAL1);
  etimer_set(&timer2, INTERVAL2);
  etimer_set(&timer3, INTERVAL3);
  while(1) {
    PROCESS_WAIT_EVENT();
    if(ev == PROCESS_EVENT_TIMER && data == &timer1) {
      etimer_reset(&timer1);
      leds_toggle(LEDS_RED);
    } else if(ev == PROCESS_EVENT_TIMER && data == &timer2) {
      etimer_reset(&timer2);
      leds_toggle(LEDS_GREEN);
    } else if(ev == PROCESS_EVENT_TIMER && data == &timer3) {
      etimer_reset(&timer3);
      leds_toggle(LEDS_YELLOW);
    }
  }
  PROCESS_END();
}
