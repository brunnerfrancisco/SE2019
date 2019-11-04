
module BCD2HEX(entrada, salida);

	input [3:0] entrada;
	output reg [6:0] salida;
	
	always @(entrada)
	begin
	
		case (entrada)
			4'b0000: salida = 7'b1000000; // "0"  
			4'b0001: salida = 7'b1111001; // "1" 
			4'b0010: salida = 7'b0100100; // "2" 
			4'b0011: salida = 7'b0110000; // "3" 
			4'b0100: salida = 7'b0011001; // "4" 
			4'b0101: salida = 7'b0010010; // "5" 
			4'b0110: salida = 7'b0000010; // "6" 
			4'b0111: salida = 7'b1111000; // "7" 
			4'b1000: salida = 7'b0000000; // "8"  
			4'b1001: salida = 7'b0010000; // "9" 
			default: salida = 7'b1111111; // "Apagado"
		endcase
	
	end

endmodule
