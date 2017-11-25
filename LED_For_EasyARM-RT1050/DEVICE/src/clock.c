/*******************************************************************************
* -----------------------------------------------------------------------------
*									     									 
* clock.c - definitions for the arch clock interface			     			 
*									     
* -----------------------------------------------------------------------------
* Copyright (C)
* All rights reserved.
*
* Author : YunFeng Zhang
* Website: https://damon-yun.github.io/blog.github.io/
* E-mail : damonzhang92@foxmail.com
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
 * \brief arch clock interface		
 * 
 * \internal
 * \par Modification History
 * - 1.00 17-11-13  damon.zhang, first implementation.
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

/**
 * \brief  
 */
int configure_clocks(void)
{
       
    /* Disable all unused peripheral clock */
    CCM->CCGR0 = 0xFFFFFFFFU;
    CCM->CCGR1 = 0xFFFFFFFFU;
    CCM->CCGR2 = 0xFFFFFFFFU;
    CCM->CCGR3 = 0xFFFFFFFFU;
    CCM->CCGR4 = 0xFFFFFFFFU;
    CCM->CCGR5 = 0xFFFFFFFFU;
    CCM->CCGR6 = 0xFFFFFFFFU;
    
    
    CCM->CBCMR = ( CCM->CBCMR & (~CCM_CBCMR_PERIPH_CLK2_SEL_MASK)) | CCM_CBCMR_PERIPH_CLK2_SEL(0x01); /* Set PERIPH_CLK2 MUX to OSC */
    CCM->CBCDR = ( CCM->CBCDR & (~CCM_CBCDR_PERIPH_CLK_SEL_MASK)) | CCM_CBCDR_PERIPH_CLK_SEL(0x01);   /* Set PERIPH_CLK MUX to PERIPH_CLK2 */
    /* Wait until CCM internal handshake finish. */
    while (CCM->CDHIPR & (1U << CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_SHIFT))
    {
    }  
    
    /* Setting the VDD_SOC to 1.5V. It is necessary to config AHB to 600Mhz */
    DCDC->REG3 = (DCDC->REG3 & (~DCDC_REG3_TRG_MASK)) | DCDC_REG3_TRG(0x12);

    /* Configure ARM PLL to 1200M */
    CCM_ANALOG->PLL_ARM = CCM_ANALOG_PLL_ARM_ENABLE_MASK | CCM_ANALOG_PLL_ARM_DIV_SELECT(100);    
    while ((CCM_ANALOG->PLL_ARM & CCM_ANALOG_PLL_ARM_LOCK_MASK) == 0)
    {
    }
    /* Configure SYS PLL to 528M */
    CCM_ANALOG->PLL_SYS = CCM_ANALOG_PLL_SYS_ENABLE_MASK | CCM_ANALOG_PLL_SYS_DIV_SELECT(1);
    while ((CCM_ANALOG->PLL_SYS & CCM_ANALOG_PLL_SYS_LOCK_MASK) == 0)
    {
    }
    /* Configure USB1 PLL to 480M */
    CCM_ANALOG->PLL_USB1 = CCM_ANALOG_PLL_USB1_ENABLE_MASK      |
                           CCM_ANALOG_PLL_USB1_POWER_MASK       |
                           CCM_ANALOG_PLL_USB1_EN_USB_CLKS_MASK |
                           CCM_ANALOG_PLL_USB1_DIV_SELECT(0);

    while ((CCM_ANALOG->PLL_USB1 & CCM_ANALOG_PLL_USB1_LOCK_MASK) == 0)
    {
    }
    
    
    CCM->CACRR = ( CCM->CACRR & (~CCM_CACRR_ARM_PODF_MASK)) | CCM_CACRR_ARM_PODF(0x01);        /* Set ARM PODF to 1, divide by 2 600MHz */
    /* Wait until CCM internal handshake finish. */
    while (CCM->CDHIPR & (1U << CCM_CDHIPR_ARM_PODF_BUSY_SHIFT))
    {
    }
    CCM->CBCDR = ( CCM->CBCDR & (~CCM_CBCDR_AHB_PODF_MASK)) | CCM_CBCDR_AHB_PODF(0x00);        /* Set AHB PODF to 0, divide by 1 */
    /* Wait until CCM internal handshake finish. */
    while (CCM->CDHIPR & (1U << CCM_CDHIPR_AHB_PODF_BUSY_SHIFT))
    {
    }
    CCM->CBCDR = ( CCM->CBCDR & (~CCM_CBCDR_IPG_PODF_MASK)) | CCM_CBCDR_IPG_PODF(0x03);        /* Set IPG PODF to 3, divede by 4 */

    /* Set PRE_PERIPH_CLK to PLL1, 1200M */
    CCM->CBCMR = ( CCM->CBCMR & (~CCM_CBCMR_PRE_PERIPH_CLK_SEL_MASK)) | CCM_CBCMR_PRE_PERIPH_CLK_SEL(0x03); 
    /* Set PERIPH_CLK MUX to PRE_PERIPH_CLK */
    CCM->CBCDR = ( CCM->CBCDR & (~CCM_CBCMR_PRE_PERIPH_CLK_SEL_MASK)) | CCM_CBCDR_PERIPH_CLK_SEL(0x00);  
    /* Wait until CCM internal handshake finish. */
    while (CCM->CDHIPR & (1U << CCM_CDHIPR_PERIPH_CLK_SEL_BUSY_SHIFT))
    {
    }  

    return 0;    
}






/*******************************************************************************
 * main code region: function implement                                        
 ******************************************************************************/


/* end of file */


