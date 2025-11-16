#include "stm32f4xx_hal.h"

#define INPUT_PIN                          GPIO_PIN_4
#define OUTPUT_PIN                         GPIO_PIN_5
#define GPIO_PORT                          GPIOC
#define GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOC_CLK_ENABLE()

int main(void)
{
  HAL_Init();

  GPIO_CLK_ENABLE();

  GPIO_InitTypeDef inputInitStruct;
  inputInitStruct.Pin = INPUT_PIN;
  inputInitStruct.Mode = GPIO_MODE_INPUT;
  HAL_GPIO_Init(GPIO_PORT, &inputInitStruct);

  GPIO_InitTypeDef outputInitStruct;
  outputInitStruct.Pin = OUTPUT_PIN;
  outputInitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  outputInitStruct.Pull = GPIO_NOPULL;
  outputInitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIO_PORT, &outputInitStruct);

  GPIO_PinState state = GPIO_PIN_SET;
  while (1)
  {
    GPIO_PinState inputState = HAL_GPIO_ReadPin(GPIO_PORT, INPUT_PIN);

    if (inputState == GPIO_PIN_SET)
      state = !state;

    HAL_GPIO_WritePin(GPIO_PORT, OUTPUT_PIN, state);

    HAL_Delay(100);
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}
