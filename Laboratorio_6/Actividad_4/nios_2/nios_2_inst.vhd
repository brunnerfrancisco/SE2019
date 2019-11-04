	component nios_2 is
		port (
			clk_clk             : in  std_logic                    := 'X';             -- clk
			pio_input_0_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_1_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_2_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_3_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_4_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_5_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_6_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_input_7_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pio_output_0_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_1_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_2_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_3_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_4_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_5_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_6_export : out std_logic_vector(7 downto 0);                    -- export
			pio_output_7_export : out std_logic_vector(7 downto 0);                    -- export
			pioinput_export     : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			piooutput_export    : out std_logic_vector(7 downto 0);                    -- export
			reset_reset_n       : in  std_logic                    := 'X'              -- reset_n
		);
	end component nios_2;

	u0 : component nios_2
		port map (
			clk_clk             => CONNECTED_TO_clk_clk,             --          clk.clk
			pio_input_0_export  => CONNECTED_TO_pio_input_0_export,  --  pio_input_0.export
			pio_input_1_export  => CONNECTED_TO_pio_input_1_export,  --  pio_input_1.export
			pio_input_2_export  => CONNECTED_TO_pio_input_2_export,  --  pio_input_2.export
			pio_input_3_export  => CONNECTED_TO_pio_input_3_export,  --  pio_input_3.export
			pio_input_4_export  => CONNECTED_TO_pio_input_4_export,  --  pio_input_4.export
			pio_input_5_export  => CONNECTED_TO_pio_input_5_export,  --  pio_input_5.export
			pio_input_6_export  => CONNECTED_TO_pio_input_6_export,  --  pio_input_6.export
			pio_input_7_export  => CONNECTED_TO_pio_input_7_export,  --  pio_input_7.export
			pio_output_0_export => CONNECTED_TO_pio_output_0_export, -- pio_output_0.export
			pio_output_1_export => CONNECTED_TO_pio_output_1_export, -- pio_output_1.export
			pio_output_2_export => CONNECTED_TO_pio_output_2_export, -- pio_output_2.export
			pio_output_3_export => CONNECTED_TO_pio_output_3_export, -- pio_output_3.export
			pio_output_4_export => CONNECTED_TO_pio_output_4_export, -- pio_output_4.export
			pio_output_5_export => CONNECTED_TO_pio_output_5_export, -- pio_output_5.export
			pio_output_6_export => CONNECTED_TO_pio_output_6_export, -- pio_output_6.export
			pio_output_7_export => CONNECTED_TO_pio_output_7_export, -- pio_output_7.export
			pioinput_export     => CONNECTED_TO_pioinput_export,     --     pioinput.export
			piooutput_export    => CONNECTED_TO_piooutput_export,    --    piooutput.export
			reset_reset_n       => CONNECTED_TO_reset_reset_n        --        reset.reset_n
		);

