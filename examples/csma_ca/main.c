#include <stdio.h>
#include <string.h>

#include "thread.h"
#include "shell.h"
#include "shell_commands.h"

#include "cc2538_rf.h"
#include "cc2538_rf_netdev.h"

#include "net/gnrc/pktdump.h"
#include "net/gnrc/csma_sender.h"
#include "net/gnrc.h"

#include "csma_ca_settings.h"

/* Change the value of RFCORE_XREG_CCACTRL0 and RFCORE_XREG_CCACTRL1 register on 
 * 'csma_ca_settings.h' file to set the CCA theshold */

/* Call the function below to change the Minimum Backoff Exponent */
// set_csma_mac_min_be(val);

/* Call the function below to change the Maximum Backoff Exponent */
// set_csma_mac_max_be(val);

int main(void)
{
    /* *****
     * Set here the Min Backoff Exponent and Max Backoff Exponent
    ***** */
	set_csma_mac_min_be(5);
	set_csma_mac_max_be(5);

    (void) puts("Welcome to CSMA/CA test!");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
