/****************************************************************************************************/
/**
\file       TimerCounter.H
\brief      Services abstraction level - TimerCounter header file
\author     Luis Angel Hernandez
\version    1.1
\project     
\date       22/March/2023
*/

#ifndef __TIMERCOUNTER_H        /*prevent duplicated includes*/
#define __TIMERCOUNTER_H

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
#include "compiler.h"
#include "board.h"

/** Used modules */
#include "tc.h"
/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/
void tc_timerConfig( void );
void tc_write_rc( Tc* p_tc, uint32_t ul_channel, uint32_t ul_value );
/**************************************************************************************************/

#endif /* __TIMERCOUNTER_H */