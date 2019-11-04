
module CAdd (A0,A1,A2,A3,S0,S1,S2,S3);

	input A0;
	input A1;
	input A2;
	input A3;
	output reg S0;
	output reg S1;
	output reg S2;
	output reg S3;
	
	always@(*)
		begin
			S0 = ((~A3 && ~A2 && A0) || (A2 && A1 && ~A0) | (A3 && ~A1 && ~A0));
			S1 = ((A1 && A0) || (A3 && ~A1 && ~A0) || (~A3 && ~A2 && A1));
			S2 = ((A2 && ~A1 && ~A0) || (A3 && A0));
			S3 = (A3 || (A2 && A0) || (A2 && A1));	
		end

endmodule
