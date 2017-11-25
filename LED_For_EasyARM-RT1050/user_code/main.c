
/*******************************************************************************
* -----------------------------------------------------------------------------
*									     									 
* main.c - main code	 
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
#include<stdio.h>

extern int arch_cpu_init (void);
extern int green_led_init (void);
extern int green_led_on (void);
extern int green_led_off (void);


void myDelay(uint32_t ms)
{
    while(ms--) {
        //__asm("NOP"); /* delay */
    }
}

int main(int argc, char **argv)
//int main(void)
{

    arch_cpu_init();
    green_led_init();

    while(1) {
        myDelay(5000000);
        green_led_on();
        myDelay(5000000);
        green_led_off();
    }
}