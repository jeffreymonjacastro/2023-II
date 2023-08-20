function [S, n] = terminos(cota)
    clc
    S = 0; k = 0;

    while (S <= cota)
        k = k + 1;
        S = S + 1/sqrt(k);
    end

    %n = k;
end