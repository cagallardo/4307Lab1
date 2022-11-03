#include "msp.h"
#include "xlaudio.h"
#include "xlaudio_armdsp.h"

int level = 0;

uint16_t processSample(uint16_t x) {
    if (level >= 99)
        level = 0;
    else
        level = level + 1;

    return xlaudio_f32_to_dac14(0.001f * level);
}

int main(void) {
    WDT_A_hold(WDT_A_BASE);

    xlaudio_init_intr(FS_16000_HZ, XLAUDIO_MIC_IN, processSample);
    xlaudio_run();

    return 1;
}
