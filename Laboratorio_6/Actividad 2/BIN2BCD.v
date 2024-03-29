
module BIN2BCD( entrada, units, tens, hunds );

	input [7:0] entrada;
	output [3:0] units;
	output [3:0] tens;
	output [1:0] hunds;
	
	wire [7:0] entrada;
	
	wire C1S0;
	wire C1S1;
	wire C1S2;
	wire C1S3;
	
	wire C2S0;
	wire C2S1;
	wire C2S2;
	wire C2S3;
	
	wire C3S0;
	wire C3S1;
	wire C3S2;
	wire C3S3;
	
	wire C4S0;
	wire C4S1;
	wire C4S2;
	wire C4S3;
	
	wire C5S0;
	wire C5S1;
	wire C5S2;
	wire C5S3;
	
	wire C6S0;
	wire C6S1;
	wire C6S2;
	wire C6S3;
	
	wire C7S0;
	wire C7S1;
	wire C7S2;
	wire C7S3;
	
	CAdd C1(
		.A0(entrada[5]), 
		.A1(entrada[6]), 
		.A2(entrada[7]), 
		.A3(1'b0), 
		.S0(C1S0), 
		.S1(C1S1), 
		.S2(C1S2), 
		.S3(C1S3));
	
	CAdd C2(
		.A0(entrada[4]), 
		.A1(C1S0), 
		.A2(C1S1), 
		.A3(C1S2), 
		.S0(C2S0), 
		.S1(C2S1), 
		.S2(C2S2), 
		.S3(C2S3));
	
	CAdd C3(
		.A0(entrada[3]), 
		.A1(C2S0), 
		.A2(C2S1), 
		.A3(C2S2), 
		.S0(C3S0), 
		.S1(C3S1), 
		.S2(C3S2), 
		.S3(C3S3));
		
	CAdd C4(
		.A0(entrada[2]), 
		.A1(C3S0), 
		.A2(C3S1), 
		.A3(C3S2), 
		.S0(C4S0), 
		.S1(C4S1), 
		.S2(C4S2), 
		.S3(C4S3));
	
	CAdd C5(
		.A0(entrada[1]), 
		.A1(C4S0), 
		.A2(C4S1), 
		.A3(C4S2), 
		.S0(C5S0), 
		.S1(C5S1), 
		.S2(C5S2), 
		.S3(C5S3));
	
	CAdd C6(
		.A0(C3S3), 
		.A1(C2S3), 
		.A2(C1S3), 
		.A3(1'b0), 
		.S0(C6S0), 
		.S1(C6S1), 
		.S2(C6S2), 
		.S3(C6S3));
	
	CAdd C7(
		.A0(C4S3), 
		.A1(C6S0), 
		.A2(C6S1), 
		.A3(C6S2), 
		.S0(C7S0), 
		.S1(C7S1), 
		.S2(C7S2), 
		.S3(C7S3));
	
	assign units[0] = entrada[0];
	assign units[1] = C5S0;
	assign units[2] = C5S1;
	assign units[3] = C5S2;

	assign tens[0] = C5S3;
	assign tens[1] = C7S0;
	assign tens[2] = C7S1;
	assign tens[3] = C7S2;
	
	assign hunds[0] = C7S3;
	assign hunds[1] = C6S3;

endmodule

