set_property SEVERITY {Warning} [get_drc_checks LUTLP-1]
set_property ALLOW_COMBINATORIAL_LOOPS TRUE

set_property PACKAGE_PIN W5 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]
create_clock -add -name sys_clk_pin -period 1000000000 -waveform {0 500000000} [get_ports clk]

set_property PACKAGE_PIN R3 [get_ports reset]
set_property PACKAGE_PIN R2 [get_ports ff]
set_property PACKAGE_PIN U1 [get_ports pl]
set_property PACKAGE_PIN W2 [get_ports re]
set_property PACKAGE_PIN T2 [get_ports st]
set_property PACKAGE_PIN T1 [get_ports m]

set_property PACKAGE_PIN L1 [get_ports F]
set_property PACKAGE_PIN P1 [get_ports P]
set_property PACKAGE_PIN N3 [get_ports R]

set_property IOSTANDARD LVCMOS33 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports F]
set_property IOSTANDARD LVCMOS33 [get_ports ff]
set_property IOSTANDARD LVCMOS33 [get_ports m]
set_property IOSTANDARD LVCMOS33 [get_ports P]
set_property IOSTANDARD LVCMOS33 [get_ports pl]
set_property IOSTANDARD LVCMOS33 [get_ports R]
set_property IOSTANDARD LVCMOS33 [get_ports re]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports st]
