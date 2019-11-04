
module DM1( entrada, sel, D0, D1, D2,D3, D4, D5, D6, D7 );

	input [7:0] entrada;
	input [2:0] sel;
	output [7:0] D0;
	output [7:0] D1;
	output [7:0] D2;
	output [7:0] D3;
	output [7:0] D4;
	output [7:0] D5;
	output [7:0] D6;
	output [7:0] D7;
	
	reg [7:0] D0;
	reg [7:0] D1;
	reg [7:0] D2;
	reg [7:0] D3;  
	reg [7:0] D4;
	reg [7:0] D5;
	reg [7:0] D6;
	reg [7:0] D7;
	
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
