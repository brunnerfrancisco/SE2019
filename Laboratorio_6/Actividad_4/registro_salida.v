`timescale 1ns / 1ps

module registro_salida(
	entrada,
	salida
	);
					

	input	[7:0] entrada;
	output [7:0] salida;

	reg [7:0] salida;
	
	always@(*)
	begin
		salida <= entrada;
	end
		
endmodule
