#ifdef TARGET_PORTENTA_H7

#include "stdbool.h"

// SAI4
#define AUDIO_SAI                   (SAI4_Block_A)
// SCKx frequency = SAI_KER_CK / MCKDIV / 2
#define AUDIO_SAI_MCKDIV            (12)
#define AUDIO_SAI_FREQKHZ           (2048U) // 2048KHz
#define AUDIO_SAI_NBR_CHANNELS      (2) // Default number of channels.

#if defined(TARGET_PORTENTA_H7)
#define AUDIO_SAI_CK_PORT           (GPIOE)
#define AUDIO_SAI_CK_PIN            (GPIO_PIN_2)
#define AUDIO_SAI_CK_AF             (GPIO_AF10_SAI4)

#define AUDIO_SAI_D1_PORT           (GPIOB)
#define AUDIO_SAI_D1_PIN            (GPIO_PIN_2)
#define AUDIO_SAI_D1_AF             (GPIO_AF10_SAI4)
#endif

#define AUDIO_SAI_DMA_STREAM        BDMA_Channel1
#define AUDIO_SAI_DMA_REQUEST       BDMA_REQUEST_SAI4_A
#define AUDIO_SAI_DMA_IRQ           BDMA_Channel1_IRQn
#define AUDIO_SAI_DMA_IRQHandler    BDMA_Channel1_IRQHandler

#define AUDIO_SAI_CLK_ENABLE()      __HAL_RCC_SAI4_CLK_ENABLE()
#define AUDIO_SAI_CLK_DISABLE()     __HAL_RCC_SAI4_CLK_DISABLE()
#define AUDIO_SAI_DMA_CLK_ENABLE()  __HAL_RCC_BDMA_CLK_ENABLE()

#define AUDIO_IN_IRQ_PREPRIO        ((uint32_t)15)

//this is correct for 48 KHz, just a bit distortion and a bit of noise
#define PDM_BUFFER_SIZE     ((48 * 64 * 2 * 2) / 8)			//48KHz, 64 decimation, 2 channels, DoubleBuffer * 2
#define PCM_BUFFER_SIZE     (48 * 2 * 2)					//as uint16_t buffer = for 2 bytes per samples, two channels * 2, Double Buffer * 2

void py_audio_deinit();
int py_audio_init(size_t g_channels, uint32_t frequency, int gain_db, float highpass, int gen_sine);
void py_audio_gain_set(int gain_db);
void audio_pendsv_callback(void);
void py_audio_start_streaming();
void py_audio_stop_streaming();
bool isBoardRev2();

#endif
