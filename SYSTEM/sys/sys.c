#include "sys.h"

	 

void GPIO_Set(GPIO_TypeDef* GPIOx,u16 GPIO_Pin_x,GPIOMode_TypeDef MODE,GPIOSpeed_TypeDef IOSPEED)
{  
		GPIO_InitTypeDef  GPIO_InitStructure;
      
	
	if (GPIOx == GPIOA) {
		// Enable clock for GPIOA
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	} else if (GPIOx == GPIOB) {
		// Enable clock for GPIOB
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	} else if (GPIOx == GPIOC) {
		// Enable clock for GPIOC
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	}else if (GPIOx == GPIOD) {
		// Enable clock for GPIOD
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

	}else if (GPIOx == GPIOE) {
		// Enable clock for GPIOE
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

	}else if (GPIOx == GPIOF) {
		// Enable clock for GPIOF
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

	}else if (GPIOx == GPIOG) {
		// Enable clock for GPIOG
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

	}
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;			    
  GPIO_InitStructure.GPIO_Mode = MODE;	 
  GPIO_InitStructure.GPIO_Speed = IOSPEED; 
  GPIO_Init(GPIOx, &GPIO_InitStructure);			    
        
} 

/*---------------------GPIO array---------------------------*/
const PinDescription g_APinDescription[]=
{

  { GPIOA, GPIO_Pin_0,RCC_APB2Periph_GPIOA, ADC_Channel_0, TIM5, TIM_Channel_1},         
  { GPIOA, GPIO_Pin_1,RCC_APB2Periph_GPIOA, ADC_Channel_1, TIM2, TIM_Channel_2},        
  { GPIOA, GPIO_Pin_2,RCC_APB2Periph_GPIOA, ADC_Channel_2, TIM2, TIM_Channel_3}, 
	{ GPIOA, GPIO_Pin_3,RCC_APB2Periph_GPIOA, ADC_Channel_3, TIM2, TIM_Channel_4},           
  { GPIOA, GPIO_Pin_4,RCC_APB2Periph_GPIOA, ADC_Channel_4, NULL, NULL},          
  { GPIOA, GPIO_Pin_5,RCC_APB2Periph_GPIOA, ADC_Channel_5, NULL, NULL}, 
	{ GPIOA, GPIO_Pin_6,RCC_APB2Periph_GPIOA, ADC_Channel_6, TIM3, TIM_Channel_1},      
  { GPIOA, GPIO_Pin_7,RCC_APB2Periph_GPIOA, ADC_Channel_7, TIM3, TIM_Channel_2},       
  { GPIOA, GPIO_Pin_8,RCC_APB2Periph_GPIOA, NULL, TIM1, TIM_Channel_1}, 
	{ GPIOA, GPIO_Pin_9,RCC_APB2Periph_GPIOA, NULL, TIM1, TIM_Channel_2},           
  { GPIOA, GPIO_Pin_10,RCC_APB2Periph_GPIOA,NULL, TIM1, TIM_Channel_3},         
  { GPIOA, GPIO_Pin_11,RCC_APB2Periph_GPIOA,NULL, TIM1, TIM_Channel_4}, 
	{ GPIOA, GPIO_Pin_12,RCC_APB2Periph_GPIOA,NULL, NULL, NULL},           
  { GPIOA, GPIO_Pin_13,RCC_APB2Periph_GPIOA,NULL, NULL, NULL},        
  { GPIOA, GPIO_Pin_14,RCC_APB2Periph_GPIOA,NULL, NULL, NULL}, 
	{ GPIOA, GPIO_Pin_15,RCC_APB2Periph_GPIOA,NULL, NULL, NULL}, 
	
	{ GPIOB, GPIO_Pin_0,RCC_APB2Periph_GPIOB, ADC_Channel_8, TIM3, TIM_Channel_3},          
  { GPIOB, GPIO_Pin_1,RCC_APB2Periph_GPIOB, ADC_Channel_9, TIM3, TIM_Channel_4},          
  { GPIOB, GPIO_Pin_2,RCC_APB2Periph_GPIOB,NULL, NULL, NULL}, 
	{ GPIOB, GPIO_Pin_3,RCC_APB2Periph_GPIOB, NULL, TIM2, TIM_Channel_2},        
  { GPIOB, GPIO_Pin_4,RCC_APB2Periph_GPIOB, NULL, TIM3, TIM_Channel_1},          
  { GPIOB, GPIO_Pin_5,RCC_APB2Periph_GPIOB, NULL, TIM3, TIM_Channel_2}, 
	{ GPIOB, GPIO_Pin_6,RCC_APB2Periph_GPIOB, NULL, TIM4, TIM_Channel_1},            
  { GPIOB, GPIO_Pin_7,RCC_APB2Periph_GPIOB, NULL, TIM4, TIM_Channel_2},          
  { GPIOB, GPIO_Pin_8,RCC_APB2Periph_GPIOB, NULL, TIM10, TIM_Channel_1}, 
	{ GPIOB, GPIO_Pin_9,RCC_APB2Periph_GPIOB, NULL, TIM11, TIM_Channel_1},          
  { GPIOB, GPIO_Pin_10,RCC_APB2Periph_GPIOB, NULL, TIM2, TIM_Channel_3},          
  { GPIOB, GPIO_Pin_11,RCC_APB2Periph_GPIOB, NULL, TIM2, TIM_Channel_4}, 
	{ GPIOB, GPIO_Pin_12,RCC_APB2Periph_GPIOB,NULL, NULL, NULL},         
  { GPIOB, GPIO_Pin_13,RCC_APB2Periph_GPIOB,NULL, NULL, NULL},       
  { GPIOB, GPIO_Pin_14,RCC_APB2Periph_GPIOB, NULL, TIM12, TIM_Channel_1}, 
	{ GPIOB, GPIO_Pin_15,RCC_APB2Periph_GPIOB, NULL, TIM12, TIM_Channel_2}, 
	
	{ GPIOC, GPIO_Pin_0,RCC_APB2Periph_GPIOC, ADC_Channel_10, NULL, NULL},        
  { GPIOC, GPIO_Pin_1,RCC_APB2Periph_GPIOC, ADC_Channel_11, NULL, NULL},         
  { GPIOC, GPIO_Pin_2,RCC_APB2Periph_GPIOC, ADC_Channel_12, NULL, NULL}, 
	{ GPIOC, GPIO_Pin_3,RCC_APB2Periph_GPIOC, ADC_Channel_13, NULL, NULL},          
  { GPIOC, GPIO_Pin_4,RCC_APB2Periph_GPIOC, ADC_Channel_14, NULL, NULL},         
  { GPIOC, GPIO_Pin_5,RCC_APB2Periph_GPIOC, ADC_Channel_14, NULL, NULL}, 
	{ GPIOC, GPIO_Pin_6,RCC_APB2Periph_GPIOC, NULL, TIM8, TIM_Channel_1},          
  { GPIOC, GPIO_Pin_7,RCC_APB2Periph_GPIOC, NULL, TIM8, TIM_Channel_2},         
  { GPIOC, GPIO_Pin_8,RCC_APB2Periph_GPIOC, NULL, TIM8, TIM_Channel_3}, 
	{ GPIOC, GPIO_Pin_9,RCC_APB2Periph_GPIOC, NULL, TIM8, TIM_Channel_4},         
  { GPIOC, GPIO_Pin_10,RCC_APB2Periph_GPIOC,NULL, NULL, NULL},           
  { GPIOC, GPIO_Pin_11,RCC_APB2Periph_GPIOC,NULL, NULL, NULL}, 
	{ GPIOC, GPIO_Pin_12,RCC_APB2Periph_GPIOC,NULL, NULL, NULL},          
  { GPIOC, GPIO_Pin_13,RCC_APB2Periph_GPIOC,NULL, NULL, NULL},       
  { GPIOC, GPIO_Pin_14,RCC_APB2Periph_GPIOC,NULL, NULL, NULL}, 
	{ GPIOC, GPIO_Pin_15,RCC_APB2Periph_GPIOC,NULL, NULL, NULL}, 
	
	{ GPIOD, GPIO_Pin_0,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},            
  { GPIOD, GPIO_Pin_1,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},        
  { GPIOD, GPIO_Pin_2,RCC_APB2Periph_GPIOD,NULL, NULL, NULL}, 
	{ GPIOD, GPIO_Pin_3,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},         
  { GPIOD, GPIO_Pin_4,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},         
  { GPIOD, GPIO_Pin_5,RCC_APB2Periph_GPIOD,NULL, NULL, NULL}, 
	{ GPIOD, GPIO_Pin_6,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},          
  { GPIOD, GPIO_Pin_7,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},          
  { GPIOD, GPIO_Pin_8,RCC_APB2Periph_GPIOD,NULL, NULL, NULL}, 
	{ GPIOD, GPIO_Pin_9,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},          
  { GPIOD, GPIO_Pin_10,RCC_APB2Periph_GPIOD,NULL, NULL, NULL},          
  { GPIOD, GPIO_Pin_11,RCC_APB2Periph_GPIOD,NULL, NULL, NULL}, 
	{ GPIOD, GPIO_Pin_12,RCC_APB2Periph_GPIOD, NULL, TIM4, TIM_Channel_1},        
  { GPIOD, GPIO_Pin_13,RCC_APB2Periph_GPIOD, NULL, TIM4, TIM_Channel_2},        
  { GPIOD, GPIO_Pin_14,RCC_APB2Periph_GPIOD, NULL, TIM4, TIM_Channel_3}, 
	{ GPIOD, GPIO_Pin_15,RCC_APB2Periph_GPIOD, NULL, TIM4, TIM_Channel_4}, 
	
	{ GPIOE, GPIO_Pin_0,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},          
  { GPIOE, GPIO_Pin_1,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},          
  { GPIOE, GPIO_Pin_2,RCC_APB2Periph_GPIOE,NULL, NULL, NULL}, 
	{ GPIOE, GPIO_Pin_3,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},           
  { GPIOE, GPIO_Pin_4,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},          
  { GPIOE, GPIO_Pin_5,RCC_APB2Periph_GPIOE, NULL, TIM6, TIM_Channel_1}, 
	{ GPIOE, GPIO_Pin_6,RCC_APB2Periph_GPIOE, NULL, TIM6, TIM_Channel_2},          
  { GPIOE, GPIO_Pin_7,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},           
  { GPIOE, GPIO_Pin_8,RCC_APB2Periph_GPIOE,NULL, NULL, NULL}, 
	{ GPIOE, GPIO_Pin_9,RCC_APB2Periph_GPIOE, NULL, TIM1, TIM_Channel_1},       
  { GPIOE, GPIO_Pin_10,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},       
  { GPIOE, GPIO_Pin_11,RCC_APB2Periph_GPIOE, NULL, TIM1, TIM_Channel_2}, 
	{ GPIOE, GPIO_Pin_12,RCC_APB2Periph_GPIOE,NULL, NULL, NULL},      
  { GPIOE, GPIO_Pin_13,RCC_APB2Periph_GPIOE, NULL, TIM1, TIM_Channel_3},         
  { GPIOE, GPIO_Pin_14,RCC_APB2Periph_GPIOE, NULL, TIM1, TIM_Channel_4}, 
	{ GPIOE, GPIO_Pin_15,RCC_APB2Periph_GPIOE,NULL, NULL, NULL}, 
	
	{ GPIOF, GPIO_Pin_0,RCC_APB2Periph_GPIOF},         
  { GPIOF, GPIO_Pin_1,RCC_APB2Periph_GPIOF},          
  { GPIOF, GPIO_Pin_2,RCC_APB2Periph_GPIOF}, 
	{ GPIOF, GPIO_Pin_3,RCC_APB2Periph_GPIOF},           
  { GPIOF, GPIO_Pin_4,RCC_APB2Periph_GPIOF},           
  { GPIOF, GPIO_Pin_5,RCC_APB2Periph_GPIOF}, 
	{ GPIOF, GPIO_Pin_6,RCC_APB2Periph_GPIOF},           
  { GPIOF, GPIO_Pin_7,RCC_APB2Periph_GPIOF},         
  { GPIOF, GPIO_Pin_8,RCC_APB2Periph_GPIOF}, 
	{ GPIOF, GPIO_Pin_9,RCC_APB2Periph_GPIOF},           
  { GPIOF, GPIO_Pin_10,RCC_APB2Periph_GPIOF},          
  { GPIOF, GPIO_Pin_11,RCC_APB2Periph_GPIOF}, 
	{ GPIOF, GPIO_Pin_12,RCC_APB2Periph_GPIOF},         
  { GPIOF, GPIO_Pin_13,RCC_APB2Periph_GPIOF},          
  { GPIOF, GPIO_Pin_14,RCC_APB2Periph_GPIOF}, 
	{ GPIOF, GPIO_Pin_15,RCC_APB2Periph_GPIOF}, 	
} ;




void WFI_SET(void)
{
	__ASM volatile("wfi");		  
}

void INTX_DISABLE(void)
{		  
	__ASM volatile("cpsid i");
}

void INTX_ENABLE(void)
{
	__ASM volatile("cpsie i");		  
}

__asm void MSR_MSP(u32 addr) 
{
    MSR MSP, r0 			//set Main Stack value
    BX r14
}


void pinMode(u32 GPIO_Pinx,u32 MODE)
{  
   //u32 pinpos=0,pos=0,curpin=0;
	
	 GPIO_TypeDef *GPIO_Port = g_APinDescription[GPIO_Pinx].GPIOx;
	 uint16_t PINx = g_APinDescription[GPIO_Pinx].GPIO_Pin_x;
	 GPIO_InitTypeDef GPIO_InitStructure;
   /*---------supply clk for port-----------*/
	 RCC_APB2PeriphClockCmd(g_APinDescription[GPIO_Pinx].ulPeripheral,ENABLE);

  GPIO_InitStructure.GPIO_Pin = PINx;
	
	if (MODE == INPUT) {
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;

	} else if (MODE == INPUT_PULLUP) {
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

	} else if (MODE == INPUT_PULLDOWN) {
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;

	}else if (MODE == OUTPUT) {
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	}else if (MODE == OUTPUT_OD) {
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	} else if (MODE == AF_OD) {
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	}else if (MODE == AF_PP) {
		
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	}else if (MODE == AN_INPUT) {
		 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

	}
	GPIO_Init(GPIO_Port, &GPIO_InitStructure);  
	
        
}


void digitalWrite( uint32_t ulPin, logic ulVal )
{
  /* Handle */

   if ( ulVal == HIGH )
  {
    g_APinDescription[ulPin].GPIOx->BSRR = g_APinDescription[ulPin].GPIO_Pin_x; //SETBIT
  }
  else
  {
    g_APinDescription[ulPin].GPIOx->BRR = g_APinDescription[ulPin].GPIO_Pin_x;  // RESETBIT
  }
}


int digitalRead( uint32_t ulPin )
{
	
	
	return GPIO_ReadInputDataBit(g_APinDescription[ulPin].GPIOx, g_APinDescription[ulPin].GPIO_Pin_x);
}



