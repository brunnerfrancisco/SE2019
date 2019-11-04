
module unsaved (
	clk_clk,
	clk_reset_reset_n,
	pioinput_export,
	piooutput_export);	

	input		clk_clk;
	input		clk_reset_reset_n;
	input	[7:0]	pioinput_export;
	output	[7:0]	piooutput_export;
endmodule
