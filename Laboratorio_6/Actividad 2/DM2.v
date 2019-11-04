
module DM2( entrada, sel, D0, D1, D2,D3, D4, D5, D6, D7 );

	input entrada;
	input [2:0] sel;
	output D0;
	output D1;
	output D2;
	output D3;
	output D4;
	output D5;
	output D6;
	output D7;
	
	reg D0;
	reg D1;
	reg D2;
	reg D3;  
	reg D4;
	reg D5;
	reg D6;
	reg D7;
	
	always @(entrada or sel)
	begin
		case (sel)
			3'b000 : 
				begin
					D0 = entrada;
					D1 = 0;
					D2 = 0;
					D3 = 0;
					D4 = 0;
					D5 = 0;
					D6 = 0;
					D7 = 0;
				end
			3'b001 : 
				begin
					D0 = 0;
					D1 = entrada;
					D2 = 0;
					D3 = 0;
					D4 = 0;
					D5 = 0;
					D6 = 0;
					D7 = 0;
				end
			3'b010 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = entrada;
					D3 = 0;
					D4 = 0;
					D5 = 0;
					D6 = 0;
					D7 = 0;
				end
			3'b011 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = 0;
					D3 = entrada;
					D4 = 0;
					D5 = 0;
					D6 = 0;
					D7 = 0;
				end
			3'b100 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = 0;
					D3 = 0;
					D4 = entrada;
					D5 = 0;
					D6 = 0;
					D7 = 0;
				end
			3'b101 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = 0;
					D3 = 0;
					D4 = 0;
					D5 = entrada;
					D6 = 0;
					D7 = 0;
				end
			3'b110 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = 0;
					D3 = 0;
					D4 = 0;
					D5 = 0;
					D6 = entrada;
					D7 = 0;
				end
			3'b111 : 
				begin
					D0 = 0;
					D1 = 0;
					D2 = 0;
					D3 = 0;
					D4 = 0;
					D5 = 0;
					D6 = 0;
					D7 = entrada;
				end
		endcase
	end

	 
endmodule
