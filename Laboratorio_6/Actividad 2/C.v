// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module C ( N1, N2, N3, N4, N5, N6, N7, N8, S1, S2, S3, S4, S5, S6, S7, S8);

	input	[7:0]  N1;
	input	[7:0]  N2;
	input	[7:0]  N3;
	input	[7:0]  N4;
	input	[7:0]  N5;
	input	[7:0]  N6;
	input	[7:0]  N7;
	input	[7:0]  N8;
	output [7:0]  S1;
	output [7:0]  S2;
	output [7:0]  S3;
	output [7:0]  S4;
	output [7:0]  S5;
	output [7:0]  S6;
	output [7:0]  S7;
	output [7:0]  S8;
	
	wire [7:0] sub_wire0 = N1;
	wire [7:0] sub_wire1 = N2;
	wire [7:0] sub_wire2 = N3;
	wire [7:0] sub_wire3 = N4;
	wire [7:0] sub_wire4 = N5;
	wire [7:0] sub_wire5 = N6;
	wire [7:0] sub_wire6 = N7;
	wire [7:0] sub_wire7 = N8;
	
	wire [7:0] sub_wire8;
	wire [7:0] sub_wire9;
	wire [7:0] sub_wire10;
	wire [7:0] sub_wire11;
	
	B b0(.N1(sub_wire0), .N2(sub_wire1), .N3(sub_wire2), .N4(sub_wire3),
		.S1(sub_wire8), .S2(sub_wire9), .S3(sub_wire10),.S4(sub_wire11));
	
	wire [7:0] sub_wire12;
	wire [7:0] sub_wire13;
	wire [7:0] sub_wire14;
   wire [7:0] sub_wire15;
	
	B b1(.N1(sub_wire4), .N2(sub_wire5), .N3(sub_wire6), .N4(sub_wire7),
		.S1(sub_wire12), .S2(sub_wire13), .S3(sub_wire14),.S4(sub_wire15));
	
	wire [7:0] sub_wire16 = sub_wire8;
	wire [7:0] sub_wire17 = sub_wire15;
	wire [7:0] sub_wire24;
	wire [7:0] sub_wire25;
	
	A a0( .N1(sub_wire16), .N2(sub_wire17), .S1(sub_wire24), .S2(sub_wire25) );
	
	wire [7:0] sub_wire18 = sub_wire9;
	wire [7:0] sub_wire19 = sub_wire14;
	wire [7:0] sub_wire26;
	wire [7:0] sub_wire27;
	
	A a1( .N1(sub_wire18), .N2(sub_wire19), .S1(sub_wire26), .S2(sub_wire27) );
	
	wire [7:0] sub_wire20 = sub_wire10;
	wire [7:0] sub_wire21 = sub_wire13;
	wire [7:0] sub_wire28;
	wire [7:0] sub_wire29;
	
	A a2( .N1(sub_wire20), .N2(sub_wire21), .S1(sub_wire28), .S2(sub_wire29) );
	
	wire [7:0] sub_wire22 = sub_wire11;
	wire [7:0] sub_wire23 = sub_wire12;
	wire [7:0] sub_wire30;
	wire [7:0] sub_wire31;
	
	A a3( .N1(sub_wire22), .N2(sub_wire23), .S1(sub_wire30), .S2(sub_wire31) );
	
	wire [7:0] sub_wire32 = sub_wire24;
	wire [7:0] sub_wire33 = sub_wire26;
	wire [7:0] sub_wire34 = sub_wire28;
	wire [7:0] sub_wire35 = sub_wire30;
	
	D d0(.N1(sub_wire32), .N2(sub_wire33), .N3(sub_wire34), .N4(sub_wire35),
		.S1(S1), .S2(S2), .S3(S3),.S4(S4));
	
	wire [7:0] sub_wire36 = sub_wire31;
	wire [7:0] sub_wire37 = sub_wire29;
	wire [7:0] sub_wire38 = sub_wire27;
	wire [7:0] sub_wire39 = sub_wire25;
	
	D d1(.N1(sub_wire36), .N2(sub_wire37), .N3(sub_wire38), .N4(sub_wire39),
		.S1(S5), .S2(S6), .S3(S7),.S4(S8));
	
endmodule
