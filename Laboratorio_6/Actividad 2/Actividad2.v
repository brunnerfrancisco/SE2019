
module Actividad2(


	//////////// SEG7 //////////
	output		     [6:0]		HEX0,
	output		     [6:0]		HEX1,
	output		     [6:0]		HEX2,
	output		     [6:0]		HEX3,
	output		     [6:0]		HEX4,
	output		     [6:0]		HEX5,

	//////////// KEY //////////
	input 		     [3:0]		KEY,

	//////////// LED //////////
	output		     [9:0]		LEDR,

	//////////// SW //////////
	input 		     [7:0]		SW
);


wire [2:0] Cin1;
wire [2:0] Cout1;

wire [7:0] sub_wire0;
wire [7:0] sub_wire1;
wire [7:0] sub_wire2;
wire [7:0] sub_wire3;
wire [7:0] sub_wire4;
wire [7:0] sub_wire5;
wire [7:0] sub_wire6;
wire [7:0] sub_wire7;

wire [7:0] in_C0;
wire [7:0] in_C1;
wire [7:0] in_C2;
wire [7:0] in_C3;
wire [7:0] in_C4;
wire [7:0] in_C5;
wire [7:0] in_C6;
wire [7:0] in_C7;

wire [7:0] out_C0;
wire [7:0] out_C1;
wire [7:0] out_C2;
wire [7:0] out_C3;
wire [7:0] out_C4;
wire [7:0] out_C5;
wire [7:0] out_C6;
wire [7:0] out_C7;

wire [7:0] leds;

wire [3:0] units;
wire [3:0] tens;
wire [1:0] hunds;

wire sub_w0;
wire sub_w1;
wire sub_w2;
wire sub_w3;
wire sub_w4;
wire sub_w5;
wire sub_w6;
wire sub_w7;

contador cin(.reloj(KEY[3]), .salida(Cin1));

contador cout(.reloj(KEY[1]), .salida(Cout1));

DM1 dm1(.entrada(SW), .sel(Cin1), 
	.D0(sub_wire0), 
	.D1(sub_wire1), 
	.D2(sub_wire2), 
	.D3(sub_wire3), 
	.D4(sub_wire4), 
	.D5(sub_wire5), 
	.D6(sub_wire6), 
	.D7(sub_wire7));

DM2 dm2(.entrada(KEY[2]), .sel(Cin1), 
	.D0(sub_w0), 
	.D1(sub_w1), 
	.D2(sub_w2), 
	.D3(sub_w3), 
	.D4(sub_w4), 
	.D5(sub_w5), 
	.D6(sub_w6), 
	.D7(sub_w7));

registro l0( .entrada(sub_wire0), .reloj(sub_w0), .salida(in_C0) );

registro l1( .entrada(sub_wire1), .reloj(sub_w1), .salida(in_C1) );

registro l2( .entrada(sub_wire2), .reloj(sub_w2), .salida(in_C2) );

registro l3( .entrada(sub_wire3), .reloj(sub_w3), .salida(in_C3) );

registro l4( .entrada(sub_wire4), .reloj(sub_w4), .salida(in_C4) );

registro l5( .entrada(sub_wire5), .reloj(sub_w5), .salida(in_C5) );

registro l6( .entrada(sub_wire6), .reloj(sub_w6), .salida(in_C6) );

registro l7( .entrada(sub_wire7), .reloj(sub_w7), .salida(in_C7) );

C c1(
	.N1(in_C0), 
	.N2(in_C1), 
	.N3(in_C2), 
	.N4(in_C3), 
	.N5(in_C4), 
	.N6(in_C5), 
	.N7(in_C6), 
	.N8(in_C7), 
	.S1(out_C0), 
	.S2(out_C1), 
	.S3(out_C2), 
	.S4(out_C3), 
	.S5(out_C4), 
	.S6(out_C5), 
	.S7(out_C6), 
	.S8(out_C7));

MS ms_1(
	.data0x(out_C0), 
	.data1x(out_C1), 
	.data2x(out_C2), 
	.data3x(out_C3), 
	.data4x(out_C4), 
	.data5x(out_C5), 
	.data6x(out_C6), 
	.data7x(out_C7), 
	.sel(Cout1), 
	.result(leds));
	
assign LEDR = leds;

BIN2BCD bin2bcd( .entrada(leds), .units(units), .tens(tens), .hunds(hunds) );

BCD2HEX bin2hexUnits(.entrada(units), .salida(HEX0));

BCD2HEX bin2hexTens(.entrada(tens), .salida(HEX1));

BCD2HEX bin2hexHunds(.entrada(hunds), .salida(HEX2));

	assign HEX5[6:0] = 7'b1111111;
	assign HEX4[6:0] = 7'b1111111;
	assign HEX3[6:0] = 7'b1111111;


endmodule
