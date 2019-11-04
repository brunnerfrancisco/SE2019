	component unsaved is
		port (
			clk_clk           : in  std_logic                    := 'X';             -- clk
			clk_reset_reset_n : in  std_logic                    := 'X';             -- reset_n
			pioinput_export   : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			piooutput_export  : out std_logic_vector(7 downto 0)                     -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk           => CONNECTED_TO_clk_clk,           --       clk.clk
			clk_reset_reset_n => CONNECTED_TO_clk_reset_reset_n, -- clk_reset.reset_n
			pioinput_export   => CONNECTED_TO_pioinput_export,   --  pioinput.export
			piooutput_export  => CONNECTED_TO_piooutput_export   -- piooutput.export
		);

