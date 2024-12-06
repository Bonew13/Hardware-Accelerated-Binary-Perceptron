library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity perceptron_tb is
end perceptron_tb;

architecture Behavioral of perceptron_tb is
    component perceptron
        Port (
            clk      : in STD_LOGIC;
            reset    : in STD_LOGIC;
            x1       : in INTEGER;
            x2       : in INTEGER;
            x3       : in INTEGER;
            target   : in INTEGER range 0 to 1;
            predict  : out INTEGER range 0 to 1;
            update   : in STD_LOGIC
        );
    end component;

    signal clk      : STD_LOGIC := '0';
    signal reset    : STD_LOGIC := '0';
    signal x1, x2, x3 : INTEGER := 0;
    signal target   : INTEGER range 0 to 1 := 0;
    signal predict  : INTEGER range 0 to 1;
    signal update   : STD_LOGIC := '0';

    type sample_type is record
        x1     : INTEGER;
        x2     : INTEGER;
        x3     : INTEGER;
        target : INTEGER range 0 to 1;
    end record;

    type sample_array is array (0 to 19) of sample_type;

    constant samples : sample_array := (
        (x1 => 1, x2 => 2, x3 => 9, target => 0),
        (x1 => 8, x2 => 9, x3 => 1, target => 1),
        (x1 => 2, x2 => 1, x3 => 8, target => 0),
        (x1 => 9, x2 => 8, x3 => 2, target => 1),
        (x1 => 3, x2 => 2, x3 => 7, target => 0),
        (x1 => 9, x2 => 7, x3 => 2, target => 1),
        (x1 => 2, x2 => 3, x3 => 9, target => 0),
        (x1 => 7, x2 => 8, x3 => 1, target => 1),
        (x1 => 1, x2 => 4, x3 => 8, target => 0),
        (x1 => 8, x2 => 7, x3 => 2, target => 1),
        (x1 => 2, x2 => 3, x3 => 9, target => 0),
        (x1 => 7, x2 => 8, x3 => 2, target => 1),
        (x1 => 3, x2 => 2, x3 => 8, target => 0),
        (x1 => 9, x2 => 8, x3 => 3, target => 1),
        (x1 => 4, x2 => 3, x3 => 7, target => 0),
        (x1 => 8, x2 => 9, x3 => 2, target => 1),
        (x1 => 2, x2 => 2, x3 => 9, target => 0),
        (x1 => 7, x2 => 8, x3 => 1, target => 1),
        (x1 => 3, x2 => 3, x3 => 8, target => 0),
        (x1 => 9, x2 => 7, x3 => 1, target => 1)
    );

    signal index : INTEGER := 0;

begin
    uut: perceptron
        Port map (
            clk      => clk,
            reset    => reset,
            x1       => x1,
            x2       => x2,
            x3       => x3,
            target   => target,
            predict  => predict,
            update   => update
        );

    clk_process: process
    begin
        while True loop
            clk <= not clk;
            wait for 10 ns;
        end loop;
    end process;

    test_process: process
    begin
        reset <= '1';
        wait for 20 ns;
        reset <= '0';

        for i in 0 to 19 loop
            index <= i;

            x1 <= samples(i).x1;
            x2 <= samples(i).x2;
            x3 <= samples(i).x3;
            target <= samples(i).target;

            wait for 20 ns;

            if predict /= target then
                update <= '1';
                wait for 20 ns;
                update <= '0';
            end if;

            wait for 20 ns;
        end loop;

        wait;
    end process;

end Behavioral;
