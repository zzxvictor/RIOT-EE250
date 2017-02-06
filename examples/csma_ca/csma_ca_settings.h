/* This file simply declared a table with CC2538 constants
 * These constants were originally on file cc2538_rf.c */

typedef struct {
    cc2538_reg_t *reg_addr;
    uint32_t value;
} init_pair_t;

const init_pair_t init_table[] = {
    {&SYS_CTRL_RCGCRFC,      0x01                     },
    {&SYS_CTRL_SCGCRFC,      0x01                     },
    {&SYS_CTRL_DCGCRFC,      0x01                     },
    {&RFCORE_XREG_CCACTRL0,  0xee                     },
    {&RFCORE_XREG_CCACTRL1,  0x1b                     },
    {&RFCORE_XREG_TXFILTCFG, 0x09                     },
    {&RFCORE_XREG_AGCCTRL1,  0x15                     },
    {&ANA_REGS_IVCTRL,       0x0b                     },
    {&RFCORE_XREG_MDMTEST1,  0x08                     },
    {&RFCORE_XREG_FSCAL1,    0x01                     },
    {&RFCORE_XREG_RXCTRL,    0x3f                     },
    {&RFCORE_XREG_MDMCTRL1,  0x14                     },
    {&RFCORE_XREG_ADCTEST0,  0x10                     },
    {&RFCORE_XREG_ADCTEST1,  0x0e                     },
    {&RFCORE_XREG_ADCTEST2,  0x03                     },
    {&RFCORE_XREG_CSPT,      0xff                     },
    {&RFCORE_XREG_MDMCTRL0,  0x85                     },
    {&RFCORE_XREG_FSCTRL,    0x55                     },
    {&RFCORE_XREG_FRMCTRL0,  AUTOCRC | AUTOACK        },
    {&RFCORE_XREG_FRMCTRL1,  0x00                     },
    {&RFCORE_XREG_SRCMATCH,  0x00                     },
    {&RFCORE_XREG_FIFOPCTRL, CC2538_RF_MAX_DATA_LEN   },
    {&RFCORE_XREG_RFIRQM0,   FIFOP | RXPKTDONE        },
    {&RFCORE_XREG_RFERRM,    STROBE_ERR | TXUNDERF | TXOVERF | RXUNDERF | RXOVERF | NLOCK},
    {NULL, 0},
};
