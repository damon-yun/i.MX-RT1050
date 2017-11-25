/*******************************************************************************
* -----------------------------------------------------------------------------
*									     									 
* i2c.h - definitions for the i2c-bus interface			     			 
*									     
* -----------------------------------------------------------------------------
* Copyright (C) Damon Zhang
* All rights reserved.
*
* Author : Damon Zhang
* Website: https://damon-yun.github.io/blog.github.io/
* E-mail : damoncheung@foxmail.com
*
* -----------------------------------------------------------------------------
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/

/**
 * \file
 * \brief sim spi driver
 * 
 * \internal
 * \par Modification History
 * - 1.00 16-10-13  damon.zhang, first implementation.
 * \endinternal
 */


#include <stdint.h>
#include "MIMXRT1052.h"
#include "system_MIMXRT1052.h"

/*******************************************************************************
 * Private define region: constant & MACRO defined here                              
 ******************************************************************************/

/*******************************************************************************
 * extern region: extern global variable & function prototype                 
 ******************************************************************************/

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/


/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/


/*****************************************************************************
 * Private functions
 ****************************************************************************/


/*****************************************************************************
 * Public functions
 ****************************************************************************/
extern int configure_clocks(void);
/**
 * \brief  
 */
int arch_cpu_init (void)
{

    configure_clocks();

    return 0;
}

#if 0

int green_led_init (void)   
{
    //PIO3_4 init
    *((uint32_t *)0x401F80E0U) = 0x5U;
    *((uint32_t *)0x401F82D0U) = 0x10B0u;

    /* Register reset to default value */
    GPIO1->IMR &= ~(1U << 9);

    GPIO1->DR &= ~(1U << 9);  /* Set pin output to low level.*/
    GPIO1->GDIR |= (1U << 9);

    return 0;
}

int green_led_on (void)   //PIO3_4
{
    GPIO1->DR &= ~(1U << 9);  /* Set pin output to low level.*/
    return 0;
}

int green_led_off (void)   //PIO3_4
{
    GPIO1->DR |= (1U << 9);  /* Set pin output to hight level.*/
    return 0;
}

#else

int green_led_init (void)   
{
    //PIO3_4 init
    *((uint32_t *)0x401F81E4U) = 0x5U;
    *((uint32_t *)0x401F83D4U) = 0x10B0u;

    /* Register reset to default value */
    GPIO3->IMR &= ~(1U << 4);

    GPIO3->DR &= ~(1U << 4);  /* Set pin output to low level.*/
    GPIO3->GDIR |= (1U << 4);

    return 0;
}

int green_led_on (void)   //PIO3_4
{
    GPIO3->DR &= ~(1U << 4);  /* Set pin output to low level.*/
    return 0;
}

int green_led_off (void)   //PIO3_4
{
    GPIO3->DR |= (1U << 4);  /* Set pin output to hight level.*/
    return 0;
}

#endif
/*******************************************************************************
 * main code region: function implement                                        
 ******************************************************************************/


/* end of file */


