`timescale 1ns / 1ps

module registro(
	entrada,
	reloj,
	salida
	);
					

	input	[7:0] entrada;
	input reloj;
	output [7:0] salida;

	reg [7:0] salida;
	
	always @(posedge reloj)
	begin
		salida <= entrada;
	end
		
endmodule

