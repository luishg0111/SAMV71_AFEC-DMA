/****************************************************************************************************/
/**
\file       TimerCounter.c
\brief      Services abstraction level - TimerCounter
\author     Luis Angel Hernandez
\version    1.1
\project     
\date       22/March/2023
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "board.h"
#include "TimerCounter.h"

#include "tc.h"
/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/

/// @brief Timer config function
/// @param  
void tc_timerConfig( void ) 
{
	/*Enable perpheral for TC0*/
	PMC_EnablePeripheral(ID_TC0);
	/*Configrue TC0 with MCK/128 in waveform mode (output) with a RC match that triggers TIOA*/
	TC_Configure(TC0, 0,
		TC_CMR_TCCLKS_TIMER_CLOCK4    //internal MCK/128 clock signal (from PMC)
		| TC_CMR_WAVE					//waveform mode
		| TC_CMR_WAVSEL_UP_RC			//count up, reset on RC match
		| TC_CMR_ACPC_TOGGLE			//toggle TIOA on RC match
	);

	/*RC compare set to trigger at 1ms
	* Function added un file tc.c */
    //MCK/2/128 = 1706nS per tick, desired period is 1mS so 586 ticks.
	tc_write_rc(TC0, 0, 586);
}

/// @brief Write to TC Register C (RC) on the selected channel.
/// @param p_tc         Module hardware register base address pointer
/// @param ul_channel   Channel to write
/// @param ul_value     Value to write
void tc_write_rc( Tc* p_tc, uint32_t ul_channel, uint32_t ul_value )
{
	p_tc->TC_CHANNEL[ul_channel].TC_RC = ul_value;
}

