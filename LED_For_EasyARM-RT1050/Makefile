#/*******************************************************************************
#* -----------------------------------------------------------------------------
#*									     									 
#*   Makefile	     			 
#*									     
#* -----------------------------------------------------------------------------
#* Copyright (C) Damon Zhang
#* All rights reserved.
#*
#* Author : YunFeng Zhang
#* Website: https://damon-yun.github.io/blog.github.io/
#* E-mail : damonzhang92@foxmail.com
#*
#* -----------------------------------------------------------------------------
#*
#* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
#* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
#* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#*
#*******************************************************************************/

CONFIG_ARCH = arm 

CONFIG_CPU = cortex-m7

CONFIG_FPU = fpv5-sp-d16

CONFIG_FLOAT_ABI = hard

CROSS_COMPILE = arm-none-eabi-

CROSS_FLG += -nostdlib \
			 -O0 \
			 -fno-common \
			 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections \
			 -mthumb -mcpu=$(CONFIG_CPU) -mfpu=$(CONFIG_FPU) -mfloat-abi=$(CONFIG_FLOAT_ABI) \
			 -D__USE_CMSIS \
			 -D__MCUXPRESSO \
			 -DDISABLE_WDOG

INCLUDE_PATH += -IDEVICE  \
                -IDEVICE/startup \
                -IDEVICE/inc  \
				-ICMSIS/Include 


include ./user_code/Makefile
include ./DEVICE/startup/Makefile
include ./DEVICE/src/Makefile

ALL:  output.axf

output.axf: $(C_SRCS:.c=.o)
	echo $(C_SRCS)
	arm-none-eabi-gcc  -nostdlib -Xlinker -print-memory-usage -Xlinker --gc-sections -Xlinker -Map="output.map" -T ./ld/MIMXRT1052xxxxx_flexspi_nor.ld   -o "output.axf" $(C_SRCS:.c=.o)
	-arm-none-eabi-size "$@"
	-arm-none-eabi-objcopy -v -O binary "$@" "output.bin"

clean:
	-rm -rf  $(C_SRCS:.c=.o) output.axf output.bin output.map

.PHONY:clean