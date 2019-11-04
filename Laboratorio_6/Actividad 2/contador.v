
module contador (	reloj,
						salida);
					

input reloj;
output	[2:0]  salida;

reg [2:0] salida;
	
always @(posedge reloj)
	begin
		salida <= salida+1;
	end
		
endmodule
