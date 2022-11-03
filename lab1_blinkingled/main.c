#include "msp.h"
#include "xlaudio.h"

int main(void) {
    WDT_A_hold(WDT_A_BASE);

    xlaudio_init();

    while (1) {
        xlaudio_errorledon();
        xlaudio_colorledoff();
        xlaudio_delay(12000000);
        xlaudio_errorledoff();
        xlaudio_colorledblue();
        xlaudio_delay(12000000);
    }

    return 1;
}
