# Clock signal
set_property SEVERITY {Warning} [get_drc_checks LUTLP-1]
set_property ALLOW_COMBINATORIAL_LOOPS TRUE

set_property PACKAGE_PIN W5 [get_ports clk]							
set_property IOSTANDARD LVCMOS33 [get_ports clk]
create_clock -add -name sys_clk_pin -period 1000000000 -waveform {0 500000000} [get_ports clk]

set_property IOSTANDARD LVCMOS33 [get_ports {D[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {D[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {D[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {D[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Q[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Q[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Q[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Q[0]}]

set_property PACKAGE_PIN R2 [get_ports {D[3]}]
set_property PACKAGE_PIN T1 [get_ports {D[2]}]
set_property PACKAGE_PIN U1 [get_ports {D[1]}]
set_property PACKAGE_PIN W2 [get_ports {D[0]}]
set_property PACKAGE_PIN L1 [get_ports {Q[3]}]
set_property PACKAGE_PIN P1 [get_ports {Q[2]}]
set_property PACKAGE_PIN N3 [get_ports {Q[1]}]
set_property PACKAGE_PIN P3 [get_ports {Q[0]}]
