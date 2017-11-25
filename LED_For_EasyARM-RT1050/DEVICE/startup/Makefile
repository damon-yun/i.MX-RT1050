
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

C_SRCS += ./DEVICE/startup/startup_mimxrt1052.c \
          ./DEVICE/startup/system_MIMXRT1052.c


#./startup/%.o: ./startup/%.c
#	$(CROSS_COMPILE)gcc $(CROSS_FLG) -Istartup -ICMSIS/Include -o "$@" "$<"

./%.o: ./%.c
	$(CROSS_COMPILE)gcc $(CROSS_FLG) $(INCLUDE_PATH)  -o "$@" "$<"

