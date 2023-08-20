function [S] = suma(n)
    clc
    S = 0;
    for k = 1:n
        S = S + 1/k;
    end
end