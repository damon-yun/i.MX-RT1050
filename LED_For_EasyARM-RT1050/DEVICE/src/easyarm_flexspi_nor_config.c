/*******************************************************************************
* -----------------------------------------------------------------------------
*									     									 
* i2c.h - definitions for the i2c-bus interface			     			 
*									     
* -----------------------------------------------------------------------------
* Copyright (C)  
* All rights reserved.
*
* Author : YunFeng Zhang
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
 * - 1.00 17-11-18  yunfeng.zhang, first implementation.
 * \endinternal
 */


#include "imxrt_boot_config.h"

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

AT_BOOT_CONFIG_SECTION(const flexspi_boot_nor_flash_config_t easyarm_flexspi_nor_config)  = {
	.memCfg = {

		.Tag = 0x42464346,   /* ascii:” FCFB” */
		.Version = 0x56010400,
		
		.readSampleClkSrc = 0x00,
		.dataHoldTime = 0x03,
		.dataSetupTime = 0x03,
		.columnAdressWidth = 0x00,

		.deviceModeCfgEnable = 0x00,    /* 0x10 ~ 0x3F  = 0x00 */
		.waitTimeCfgCommands = 0x00,

		.controllerMiscOption = 0x00000051,
		.deviceType = 0x00,
		.sflashPadType = 0x04,
		.serialClkFreq = 0x06,
		.lutCustomSeqEnable = 0x00,

		.sflashA1Size = 0x04000000,
		.sflashA2Size = 0x00000000,
		.sflashB1Size = 0x00000000,
		.sflashB2Size = 0x00000000,
		
		.dataValidTime = 0x00000000,
		.busyOffset = 0x000f,
		.busyBitPolarity = 0x0001,

#if 0
		/* LUT sequence definition for Serial NOR */
		
		/* Read Data */
		.lookupTable[0] = 0x0818046B,	
		.lookupTable[1] = 0x26043208,

		.lookupTable[2] = 0x00000000,
		.lookupTable[3] = 0x00000000,

		/* Read Status */	
		.lookupTable[4] = 0x24040405,	
		
		.lookupTable[5] = 0x00000000,
		.lookupTable[6] = 0x00000000,
		.lookupTable[7] = 0x00000000,
		.lookupTable[8] = 0x00000000,
		.lookupTable[9] = 0x00000000,
		.lookupTable[10] = 0x00000000,
		.lookupTable[11] = 0x00000000,

		/* Write Enable */
		.lookupTable[12] = 0x00000406,	
		.lookupTable[13] = 0x00000000,
		.lookupTable[14] = 0x00000000,
		.lookupTable[15] = 0x00000000,
		.lookupTable[16] = 0x00000000,
		.lookupTable[17] = 0x00000000,
		.lookupTable[18] = 0x00000000,
		.lookupTable[19] = 0x00000000,

		/* Erase Sector  */
		.lookupTable[20] = 0x08180420,	
		
		.lookupTable[21] = 0x00000000,
		.lookupTable[22] = 0x00000000,
		.lookupTable[23] = 0x00000000,
		.lookupTable[24] = 0x00000000,
		.lookupTable[25] = 0x00000000,
		.lookupTable[26] = 0x00000000,
		.lookupTable[27] = 0x00000000,
		.lookupTable[28] = 0x00000000,
		.lookupTable[29] = 0x00000000,
		.lookupTable[30] = 0x00000000,
		.lookupTable[31] = 0x00000000,
		.lookupTable[32] = 0x00000000,
		.lookupTable[33] = 0x00000000,
		.lookupTable[34] = 0x00000000,
		.lookupTable[35] = 0x00000000,

		/* program page */
		.lookupTable[36] = 0x08180438,	
		.lookupTable[37] = 0x00002204,
		
		.lookupTable[38] = 0x00000000,
		.lookupTable[39] = 0x00000000,
		.lookupTable[40] = 0x00000000,
		.lookupTable[41] = 0x00000000,
		.lookupTable[42] = 0x00000000,
		.lookupTable[43] = 0x00000000,

		/* Chip Erase */
		.lookupTable[44] = 0x00000000,	
		.lookupTable[45] = 0x00000000,
		.lookupTable[46] = 0x00000000,
		.lookupTable[47] = 0x00000000,
		.lookupTable[48] = 0x00000000,
		.lookupTable[49] = 0x00000000,
		.lookupTable[50] = 0x00000000,
		.lookupTable[51] = 0x00000000,
		.lookupTable[52] = 0x00000000,
		.lookupTable[53] = 0x00000000,
		.lookupTable[54] = 0x00000000,
		.lookupTable[55] = 0x00000000,
		.lookupTable[56] = 0x00000000,
		.lookupTable[57] = 0x00000000,
		.lookupTable[58] = 0x00000000,
		.lookupTable[59] = 0x00000000,
		/*  60 ~ 63 = 0x00000000 */

		.lutCustomSeq[0] = 0x00000000,
		.lutCustomSeq[1] = 0x00000102,
		.lutCustomSeq[2] = 0x00000302,
		.lutCustomSeq[3] = 0x00000504,
		.lutCustomSeq[4] = 0x00000902,
		.lutCustomSeq[5] = 0x00000B04,
		
		.lutCustomSeq[6] = 0x00000000,
		.lutCustomSeq[7] = 0x00000000,
		.lutCustomSeq[8] = 0x00000000,
		.lutCustomSeq[9] = 0x00000000,
		.lutCustomSeq[10] = 0x00000000,
		.lutCustomSeq[11] = 0x00000000,
#else
		/* LUT sequence definition for Serial NOR */
		/* Read Data */
        .nor_lut_seq = {
            .Read_LUT[0] = 0x0818046B,	
            .Read_LUT[1] = 0x26043208,
            .Read_LUT[2] = 0x00000000,
            .Read_LUT[3] = 0x00000000,            
        
            /* Read Status */	
            .ReadStatus_LUT[0] = 0x24040405,	
            .ReadStatus_LUT[1] = 0x00000000,
            //.lookupTable[2 ~ 7] = 0x00000000,

            /* Write Enable */
            .WriteEnable_LUT[0] = 0x00000406,	
            .WriteEnable_LUT[1] = 0x00000000,
            //.lookupTable[2~7] = 0x00000000,

            /* Erase Sector  */
            .EraseSector_LUT[0] = 0x08180420,	
            .EraseSector_LUT[1] = 0x00000000,
            //.EraseSector_LUT[2~15] = 0x00000000,

            /* program page */
            .PageProgram_LUT[0] = 0x08180438,	
            .PageProgram_LUT[1] = 0x00002204,
            //.PageProgram_LUT[2~7] = 0x00000000,

            /* Chip Erase */
            .ChipErase_LUT[0] = 0x00000000,	
            .ChipErase_LUT[1] = 0x00000000,
            //.ChipErase_LUT[2~15] = 0x00000000,

            .Dummy_LUT[0] = 0x00000000,
            .Dummy_LUT[1] = 0x00000000,
            //.Dummy_LUT[2~3] = 0x00000000,
            /*  60 ~ 63 = 0x00000000 */
        },
        
        /* LUT sequence Index in lookup table definition for Serial NOR */
        .nor_lut_index = {
            .Read_index 		= 0x00000000,
            .ReadStatus_index 	= 0x00000102,
            .WriteEnable_index 	= 0x00000302,
            .EraseSector_index 	= 0x00000504,
            .PageProgram_index 	= 0x00000902,
            .ChipErase_index 	= 0x00000B04,
        },
#endif
	},
	.pageSize 			= 0x00000100,
	.sectorSize 		= 0x0001000,
	.ipCmdSerialClkFreq = 0x00000001,
};

AT_BOOT_IVT_DATA_SECTION(const boot_image_data_structure_t easyarm_flexspi_nor_boot_data) = {
	
	.start 	= 0x60000000,
	.length = 0x00800000,
	.plugin = 0x00000000,
};

AT_BOOT_IVT_SECTION(const boot_image_ivt_t easyarm_flexspi_nor_ivt) = {
	
    .header 	= BOOT_IMAGE_HADER(0xD1, 0x0020, 0x41),
	.entry		= 0x60002000,  //app start
	.dcd 		= 0x00000000,
	.boot_data 	= ((uint32_t)(&easyarm_flexspi_nor_boot_data)),
	.self 		= 0x60001000,
	.csf 		= 0x00000000,

	.reserved1	= 0x00000000,
	.reserved2 	= 0x00000000,
};

/*******************************************************************************
 * main code region: function implement                                        
 ******************************************************************************/


/* end of file */


