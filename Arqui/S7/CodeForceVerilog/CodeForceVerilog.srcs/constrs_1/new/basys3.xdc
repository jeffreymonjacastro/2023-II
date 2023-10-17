## Clock signal

#set_property PACKAGE_PIN W5 [get_ports clk]
#set_property IOSTANDARD LVCMOS33 [get_ports clk]
#create_clock -add -name sys_clk_pin -period 1000000000 -waveform {0 500000000} [get_ports clk]

## INPUTS
#set_property PACKAGE_PIN U1 [ get_ports {pl}]
set_property PACKAGE_PIN R3 [get_ports ff]
#set_property IOSTANDARD LVCMOS33 [ get_ports {pl}]
set_property IOSTANDARD LVCMOS33 [get_ports re]
set_property IOSTANDARD LVCMOS33 [get_ports st]
set_property IOSTANDARD LVCMOS33 [get_ports m]
set_property IOSTANDARD LVCMOS33 [get_ports reset]

## OUTPUTS
set_property IOSTANDARD LVCMOS33 [get_ports P]
set_property IOSTANDARD LVCMOS33 [get_ports R]
set_property IOSTANDARD LVCMOS33 [get_ports F]

