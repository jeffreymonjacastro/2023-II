exacto = exp(-5);

aprox1 = expo(-5, 19);
aprox2 = 1/expo(5, 19);

delta1 = abs(exacto - aprox1)/abs(exacto) * 100;
delta2 = abs(exacto - aprox2)/abs(exacto) * 100;