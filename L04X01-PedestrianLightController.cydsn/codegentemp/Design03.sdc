# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\as3828\Desktop\L4\Workspace01\Design03.cydsn\Design03.cyprj
# Date: Thu, 01 Feb 2018 15:40:55 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list]


# Component constraints for C:\Users\as3828\Desktop\L4\Workspace01\Design03.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\as3828\Desktop\L4\Workspace01\Design03.cydsn\Design03.cyprj
# Date: Thu, 01 Feb 2018 15:40:52 GMT