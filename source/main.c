/********************************************************************************
 *    ___             _   _     _			
 *   / _ \ _ __   ___| |_| |__ (_)_ __ __  __
 *  | | | | '_ \ / _ \ __| '_ \| | '_ \\ \/ /
 *  | |_| | | | |  __/ |_| | | | | | | |>  < 
 *   \___/|_| |_|\___|\__|_| |_|_|_| |_/_/\_\
 *
 ********************************************************************************
 *
 * Copyright (c) 2019 Onethinx BV <info@onethinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ********************************************************************************
 *
 * Created by: Rolf Nooteboom
 *
 * Example code for Capsense on the Onethinx Core 
 * 
 * For a description please see:
 * https://github.com/onethinx/Capsense_example
 *
 ********************************************************************************/

#include "udbinit.h"
#include "project.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_GPIO_Pin_FastInit(P12_4_PORT, P12_4_NUM, CY_GPIO_DM_STRONG, 0UL, HSIOM_SEL_GPIO);
	UDBInit();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CapSense_Start();                           /* Initialize Component */
    CapSense_ScanAllWidgets();                  /* Scan all widgets */

    for(;;)
    {         /* Do this only when a scan is done */
        if(CapSense_NOT_BUSY == CapSense_IsBusy())         
        {
            CapSense_ProcessAllWidgets();       /* Process all widgets */
 
            if (CapSense_IsAnyWidgetActive())   /* Scan result verification */
            {       
                Cy_GPIO_Write(P12_4_PORT, P12_4_NUM, 1);
                /* add custom tasks to execute when touch detected */
            }
            else
                Cy_GPIO_Write(P12_4_PORT, P12_4_NUM, 0);
                
            CapSense_ScanAllWidgets();          /* Start next scan */
        }
    }
}


/* [] END OF FILE */
