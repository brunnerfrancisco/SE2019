
module nios_2 (
	clk_clk,
	pio_input_0_export,
	pio_input_1_export,
	pio_input_2_export,
	pio_input_3_export,
	pio_input_4_export,
	pio_input_5_export,
	pio_input_6_export,
	pio_input_7_export,
	pio_output_0_export,
	pio_output_1_export,
	pio_output_2_export,
	pio_output_3_export,
	pio_output_4_export,
	pio_output_5_export,
	pio_output_6_export,
	pio_output_7_export,
	pioinput_export,
	piooutput_export,
	reset_reset_n);	

	input		clk_clk;
	input	[7:0]	pio_input_0_export;
	input	[7:0]	pio_input_1_export;
	input	[7:0]	pio_input_2_export;
	input	[7:0]	pio_input_3_export;
	input	[7:0]	pio_input_4_export;
	input	[7:0]	pio_input_5_export;
	input	[7:0]	pio_input_6_export;
	input	[7:0]	pio_input_7_export;
	output	[7:0]	pio_output_0_export;
	output	[7:0]	pio_output_1_export;
	output	[7:0]	pio_output_2_export;
	output	[7:0]	pio_output_3_export;
	output	[7:0]	pio_output_4_export;
	output	[7:0]	pio_output_5_export;
	output	[7:0]	pio_output_6_export;
	output	[7:0]	pio_output_7_export;
	input	[7:0]	pioinput_export;
	output	[7:0]	piooutput_export;
	input		reset_reset_n;
endmodule
