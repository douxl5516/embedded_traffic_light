#ifndef LED_H
#define LED_H
#ifdef __cplusplus
extern "C" {
#endif
    void jmdelay(int n);
    void led_light(int dir,int time,int kind);
    void led_main();
#ifdef __cplusplus
}
#endif
#endif // LED_H
