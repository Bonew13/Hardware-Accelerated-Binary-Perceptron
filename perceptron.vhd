library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity perceptron is
    Port (
        clk      : in STD_LOGIC;
        reset    : in STD_LOGIC;
        x1       : in INTEGER;
        x2       : in INTEGER;
        x3       : in INTEGER;
        target   : in INTEGER range 0 to 1; 
        predict  :out INTEGER range 0 to 1; 
        update   : in STD_LOGIC 
    );
end perceptron;

architecture Behavioral of perceptron is
    signal w1, w2, w3, b : INTEGER := 0; 
    signal predict_internal : INTEGER range 0 to 1; 
    signal sum           : INTEGER;
    signal y             : INTEGER range -1 to 1; 
begin
    
    predict <= predict_internal;

    process(clk)
    begin
        if rising_edge(clk) then
            
            sum <= (w1 * x1 + w2 * x2 + w3 * x3 + b);
            if sum>0 then
                predict_internal <= 1;
            else
                predict_internal <= 0;
            end if;

            if update = '1' then
                if target /= predict_internal then
                    
                    w1 <= w1 + (target - predict_internal) * x1;
                    w2 <= w2 + (target - predict_internal) * x2;
                    w3 <= w3 + (target - predict_internal) * x3;
                    b  <= b + (target - predict_internal);
                end if;
            end if;
        end if;
    end process;
end Behavioral;