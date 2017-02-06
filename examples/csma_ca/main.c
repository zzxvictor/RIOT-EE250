#include <stdio.h>
#include <string.h>

#include "thread.h"
#include "shell.h"
#include "shell_commands.h"

#include "cc2538_rf.h"
#include "cc2538_rf_netdev.h"

#include "net/gnrc/pktdump.h"
#include "net/gnrc.h"

#include "csma_ca_settings.h"

/* Change the value of RFCORE_XREG_CCACTRL0 and RFCORE_XREG_CCACTRL1 register on 'csma_ca_settings.h' file to set the CCA theshold */

/* Call the function below to change the Minimum Backoff Exponent */
// set_csma_mac_min_be(val);

/* Call the function below to change the Maximum Backoff Exponent */
// set_csma_mac_max_be(val);

/* Call the function below to change the channel of CC2538 */
//cc2538_set_chan(ch);

int main(void)
{
    gnrc_netreg_entry_t dump;
    dump.pid = gnrc_pktdump_pid;
    dump.demux_ctx = GNRC_NETREG_DEMUX_CTX_ALL;
    gnrc_netreg_register(GNRC_NETTYPE_UNDEF, &dump);

    /* ***** */
    /* Set here the channel, Min Backoff Exponent and Max Backoff Exponent
    /* ***** */
	//cc2538_set_chan(ch);
	//set_csma_mac_min_be(val);
	//set_csma_mac_max_be(val);

    (void) puts("Welcome to CSMA/CA test!");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
