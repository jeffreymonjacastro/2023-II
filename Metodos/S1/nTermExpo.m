function [t] = nTermExpo(x, n)
    clc
    nterm = 0;
    anterior = expo(x, nterm); 
    delta = 1; 

    while (delta > 5 * 10^-n)
        actual = expo(x, nterm + 1);
        delta = abs(actual - anterior)/abs(actual);
        nterm = nterm + 1;
        anterior = actual;
    end
    t = nterm;
end