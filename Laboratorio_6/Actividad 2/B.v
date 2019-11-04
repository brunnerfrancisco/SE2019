// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module B ( N1, N2, N3, N4, S1, S2, S3, S4);

	input	[7:0]  N1;
	input	[7:0]  N2;
	input	[7:0]  N3;
	input	[7:0]  N4;
	output [7:0]  S1;
	output [7:0]  S2;
	output [7:0]  S3;
	output [7:0]  S4;

	wire [7:0] sub_wire0 = N1;
	wire [7:0] sub_wire1 = N2;
	wire [7:0] sub_wire2 = N3;
	wire [7:0] sub_wire3 = N4;
	wire [7:0] sub_wire4;
	wire [7:0] sub_wire5;
	
	//always @(A or B or C or D)
	//begin

	A a0( .N1(sub_wire0), .N2(sub_wire1), .S1(sub_wire4), .S2(sub_wire5) );
		
	wire [7:0] sub_wire6;
	wire [7:0] sub_wire7;
	
	A a1( .N1(sub_wire2), .N2(sub_wire3), .S1(sub_wire6), .S2(sub_wire7) );
		
	wire [7:0] sub_wire8 = sub_wire5;
	wire [7:0] sub_wire9 = sub_wire6;
	wire [7:0] sub_wire10;
	wire [7:0] sub_wire11;
	
	A a2( .N1(sub_wire8), .N2(sub_wire9), .S1(sub_wire10), .S2(sub_wire11) );
		
	wire [7:0] sub_wire12 = sub_wire4;
	wire [7:0] sub_wire13 = sub_wire7;
	wire [7:0] sub_wire14;
	wire [7:0] sub_wire15;
	
	A a3( .N1(sub_wire12), .N2(sub_wire13), .S1(sub_wire14), .S2(sub_wire15) );
		
	wire [7:0] sub_wire16 = sub_wire14;
	wire [7:0] sub_wire17 = sub_wire10;

	A a4( .N1(sub_wire16), .N2(sub_wire17), .S1(S1), .S2(S2) );
		
	wire [7:0] sub_wire18 = sub_wire11;
	wire [7:0] sub_wire19 = sub_wire15;
	
	A a5( .N1(sub_wire18), .N2(sub_wire19), .S1(S3), .S2(S4) );
		

endmodule
